# Tile Sequencer FSM
#
# Autonomous tiling loop controller. Reads M, K, N and host RAM base addresses
# from the CSR Block, then sequences the full matrix multiply tile loop without host CPU
# involvement. For each output tile (ti, tj), iterates over K-tiles (tk):
#   1. FETCH:     load the next weight and activation tiles into shadow ping-pong
#                 buffers and flip, then signal DataSetup to start
#   2. COMPUTE:   wait for DataSetup done
#   3. WRITEBACK: on the final K-tile, wait for tile_done from the Accumulator
#                 Bank, then copy the completed tile from the Output Buffer back
#                 to the correct offset in host RAM
# When all output tiles are done, asserts interrupt in the CSR Block.
#
# In the sw model, host RAM is represented as Python lists. load() and flip()
# on the ping-pong buffers stand in for XDMA DMA transfers.

class TileSequencerFSM:
    TILE = 16

    def __init__(self, csr, weight_buf, act_buf, data_setup, acc_bank, output_buf,
                 host_a, host_b, host_c):
        self._csr        = csr
        self._weight_buf = weight_buf
        self._act_buf    = act_buf
        self._data_setup = data_setup
        self._acc_bank   = acc_bank
        self._output_buf = output_buf
        self._host_a     = host_a  # M x K INT8 matrix (activations)
        self._host_b     = host_b  # K x N INT8 matrix (weights)
        self._host_c     = host_c  # M x N INT32 matrix (output, written in place)

        self._state = 'IDLE'
        self._ti    = 0  # output tile row index
        self._tj    = 0  # output tile col index
        self._tk    = 0  # K-tile index

    def _num_tiles(self, dim):
        return (dim + self.TILE - 1) // self.TILE

    def _extract_tile(self, matrix, row0, col0, nrows, ncols):
        # extract a TILE x TILE submatrix, zero-padding if near the edge
        tile = [[0] * self.TILE for _ in range(self.TILE)]
        for r in range(self.TILE):
            for c in range(self.TILE):
                mr, mc = row0 + r, col0 + c
                if mr < nrows and mc < ncols:
                    tile[r][c] = matrix[mr][mc]
        return tile

    def tick(self):
        M, K, N = self._csr.M, self._csr.K, self._csr.N
        Ti = self._num_tiles(M)
        Tk = self._num_tiles(K)
        Tj = self._num_tiles(N)

        if self._state == 'IDLE':
            if self._csr.start.val:
                self._ti = self._tj = self._tk = 0
                self._state = 'FETCH'

        elif self._state == 'FETCH':
            # load weight tile (from B) and activation tile (from A) into shadow buffers
            w_tile = self._extract_tile(self._host_b,
                                        self._tk * self.TILE, self._tj * self.TILE, K, N)
            a_tile = self._extract_tile(self._host_a,
                                        self._ti * self.TILE, self._tk * self.TILE, M, K)
            self._weight_buf.load(w_tile)
            self._act_buf.load(a_tile)
            self._weight_buf.flip()
            self._act_buf.flip()

            self._acc_bank.final_pass.val = 1 if self._tk == Tk - 1 else 0
            self._data_setup.start.val    = 1
            self._state = 'COMPUTE'

        elif self._state == 'COMPUTE':
            self._data_setup.start.val = 0
            if self._data_setup.done.val:
                if self._acc_bank.final_pass.val:
                    self._state = 'WRITEBACK'
                else:
                    self._tk   += 1
                    self._state = 'FETCH'

        elif self._state == 'WRITEBACK':
            if self._output_buf.ready.val:
                tile = self._output_buf.read()
                row0, col0 = self._ti * self.TILE, self._tj * self.TILE
                for r in range(self.TILE):
                    for c in range(self.TILE):
                        mr, mc = row0 + r, col0 + c
                        if mr < M and mc < N:
                            self._host_c[mr][mc] = tile[r][c]

                # advance to next output tile
                self._tk  = 0
                self._tj += 1
                if self._tj == Tj:
                    self._tj  = 0
                    self._ti += 1
                if self._ti == Ti:
                    self._state = 'DONE'
                else:
                    self._state = 'FETCH'

        elif self._state == 'DONE':
            self._csr.interrupt.val = 1
