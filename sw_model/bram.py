# BRAM
# Description: generic 16x16 block RAM.
#
# Instantiated three times in top.py:
# Weight BRAM     (written by Parser, read by Systolic Data Setup)
# Activation BRAM (written by Parser, read by Systolic Data Setup)
# Output BRAM     (written by Accumulator Bank, read by Control FSM for readback)
#
# In hardware each instance maps to a Xilinx Simple Dual Port BRAM: one
# write-only port and one read-only port, allowing simultaneous read and write
# from different modules.

class BRAM:
    ROWS = 16
    COLS = 16

    def __init__(self):
        self._mem = [[0] * self.COLS for _ in range(self.ROWS)]

    def read(self, row):
        return self._mem[row]

    def write(self, row, data):
        self._mem[row] = data
