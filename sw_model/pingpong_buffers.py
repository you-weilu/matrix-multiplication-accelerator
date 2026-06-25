# Ping-Pong Buffers
#
# A pair of 256-byte register buffers (16x16 INT8) used for double-buffering
# weight and activation tiles. While the Systolic Data Setup reads from the
# active buffer, the Tile Sequencer FSM loads the next tile into the shadow
# buffer via XDMA. flip() swaps active and shadow between tile passes.
#
# Instantiated twice: once for weights, once for activations.

class PingPongBuffer:

    def __init__(self):
        self._bufs   = [[[0] * 16 for _ in range(16)],
                        [[0] * 16 for _ in range(16)]]
        self._active = 0  # index of the buffer currently being read by DataSetup

    def read(self, row):
        return self._bufs[self._active][row]

    def load(self, tile):
        # load a full 16x16 tile into the shadow buffer
        shadow = 1 - self._active # shadow: buffer not being read by data setup
        for r in range(16):
            self._bufs[shadow][r] = list(tile[r])

    def flip(self):
        self._active = 1 - self._active
