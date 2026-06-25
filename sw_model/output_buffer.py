# Output Buffer
#
# 1 KB register buffer holding one completed 16x16 INT32 output tile
# pending XDMA writeback. The Accumulator Bank writes into it via write()
# after the final K-tile pass. The Tile Sequencer FSM reads it via read()
# to DMA the result back to host RAM.

from signal import Signal

class OutputBuffer:

    def __init__(self):
        self._tile = [[0] * 16 for _ in range(16)]
        self.ready = Signal(0)  # 1 when a completed tile is waiting for writeback

    def write(self, tile):
        for r in range(16):
            self._tile[r] = tile[r][:]
        self.ready.val = 1

    def read(self):
        self.ready.val = 0
        return self._tile
