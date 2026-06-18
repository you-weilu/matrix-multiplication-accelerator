# Accumulator Bank
#
# Description: accumulates partial sums from the systolic array bottom across
# all K-tile passes for a single output tile C[ti][tj]. Each cycle, one row
# of 16 INT32 partial sums drains from the array and is added to the
# corresponding row in the 16x16 accumulator buffer. The Control FSM signals
# final_pass on the last K-tile pass, which triggers the bank to write the
# completed tile to the inactive output buffer and clear the accumulators for
# the next output tile.

from signal import Signal

class AccumulatorBank:

    def __init__(self, partial_in: Signal, row_valid: Signal, final_pass: Signal,
                 buf_sel: Signal, buf_written: Signal, rst: Signal):
        self.partial_in  = partial_in   # 16 INT32 values, one output row
        self.row_valid   = row_valid    # high each cycle a row drains from array
        self.final_pass  = final_pass   # high on last K-tile pass for current tile
        self.buf_sel     = buf_sel      # 0 = write to buf_a, 1 = write to buf_b
        self.buf_written = buf_written  # pulsed when tile write completes
        self.rst         = rst

        self.acc   = [[0] * 16 for _ in range(16)]  # 16x16 INT32 accumulator
        self.buf_a = [[0] * 16 for _ in range(16)]
        self.buf_b = [[0] * 16 for _ in range(16)]
        self.row   = 0 # current output row being accumulated

    def tick(self):
        if self.rst.val:
            self.acc             = [[0] * 16 for _ in range(16)]
            self.row             = 0
            self.buf_written.val = 0
            return

        self.buf_written.val = 0

        if not self.row_valid.val:
            return

        for col in range(16):
            self.acc[self.row][col] += self.partial_in.val[col]

        if self.final_pass.val and self.row == 15:
            buf = self.buf_a if self.buf_sel.val == 0 else self.buf_b
            for r in range(16):
                buf[r] = self.acc[r][:]
            self.acc             = [[0] * 16 for _ in range(16)]
            self.buf_written.val = 1

        self.row = (self.row + 1) % 16
