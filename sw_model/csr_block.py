# CSR Block
#
# Memory-mapped control and status registers. The host writes matrix dimensions
# (M, K, N) and the base addresses of A, B, C in host RAM, then asserts start
# to kick off computation. The Tile Sequencer FSM reads these to drive the
# tiling loop and asserts interrupt when all output tiles are done.

from signal import Signal

class CSRBlock:

    def __init__(self):
        self.M      = 0  # rows of A / rows of C
        self.K      = 0  # cols of A / rows of B (inner dimension)
        self.N      = 0  # cols of B / cols of C
        self.addr_a = 0  # base address of A in host RAM
        self.addr_b = 0  # base address of B in host RAM
        self.addr_c = 0  # base address of C in host RAM

        self.start     = Signal(0)  # host asserts to begin computation
        self.interrupt = Signal(0)  # FSM asserts when all output tiles are done
