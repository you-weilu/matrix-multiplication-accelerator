# Accumulator Bank Spec

The Accumulator Bank collects partial sums flowing out of the bottom of each Systolic Array column during compute. It contains 16 accumulators (one per column), each holding a 32-bit value to prevent overflow from accumulating INT8 products. Once all partial sums for a column have been received, the final result is written to the corresponding row of the Output BRAM.
