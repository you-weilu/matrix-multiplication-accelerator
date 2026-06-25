# Accumulator Bank
#
# Accumulates partial sums from the systolic array bottom across all K-tile
# passes for a single output tile. Each cycle, one row of 16 INT32 partial
# sums drains from the array and is added to the corresponding accumulator row.
# On the final K-tile pass, the completed 16x16 INT32 tile is written to the
# Output Buffer and the accumulators are cleared for the next output tile.

from signal import Signal

class AccumulatorBank:

    def __init__(self, partial_in: Signal, row_valid: Signal, final_pass: Signal,
                 tile_done: Signal, rst: Signal, output_buf):
        self.partial_in = partial_in   # 16 INT32 values, one output row
        self.row_valid  = row_valid    # high each cycle a row drains from array
        self.final_pass = final_pass   # high on last K-tile pass for current tile
        self.tile_done  = tile_done    # pulsed when tile write to output buffer completes
        self.rst        = rst
        self.output_buf = output_buf

        self.acc = [[0] * 16 for _ in range(16)]
        self.row = 0

    def tick(self):
        if self.rst.val:
            self.acc           = [[0] * 16 for _ in range(16)] # array of array of 16 0s
            self.row           = 0
            self.tile_done.val = 0
            return

        self.tile_done.val = 0

        if not self.row_valid.val:
            return

        for col in range(16):
            self.acc[self.row][col] += self.partial_in.val[col]

        if self.final_pass.val and self.row == 15:
            self.output_buf.write(self.acc)
            self.acc           = [[0] * 16 for _ in range(16)]
            self.tile_done.val = 1

        self.row = (self.row + 1) % 16
