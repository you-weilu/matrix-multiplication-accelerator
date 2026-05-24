# Accumulator Bank Spec

The Accumulator Bank collects partial sums flowing out of the bottom of the systolic array and accumulates them across K-dimension tile passes to produce final output tiles.

---

## Structure

16 accumulators, one per array column. Each holds a 32-bit value to prevent overflow.

Worst case for 256×256 matrices: K = 256, so 16 K-tile passes. Each tile contributes a partial sum of 16 INT8×INT8 products. Maximum product = 127×127 = 16,129 (fits in 15 bits). Maximum accumulator value = 16,129 × 16 PEs × 16 K-tile passes = 4,129,024, which fits in 22 bits. 32-bit accumulators provide ample headroom.

---

## Operation

For each output tile C[ti][tj], the K dimension is iterated by the Control FSM. On each K-tile pass, partial sums drain out of the bottom of each array column continuously during activation feeding. The bank adds each incoming value to the running 32-bit accumulator for that column.

The Control FSM signals whether each tile pass is an intermediate accumulation or the final K-tile pass:

- **Intermediate pass**: add incoming partial sums to accumulators, hold
- **Final pass**: add incoming partial sums, then write the completed 16×16 output tile row by row to Output BRAM and clear accumulators for the next output tile

Since we have a weight stationary systolic array, there is no separate drain phase as partial sums exit the array naturally as activations flow through.
