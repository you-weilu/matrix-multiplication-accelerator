# Accumulator Bank Spec

The Accumulator Bank collects partial sums flowing out of the bottom of the systolic array and accumulates them across K-dimension tile passes to produce final output tiles.

---

## Structure

16 accumulators, one per array column. Each holds a 32-bit value to prevent overflow.

Worst case: large K dimension, up to K_TILES tile passes. Each tile contributes partial sums of 16 INT8×INT8 products. Maximum single-PE product = 127×127 = 16,129 (fits in 15 bits). Maximum accumulator value = 16,129 × 16 PEs × K_TILES passes — 32-bit accumulators provide ample headroom for any practical K.

---

## Operation

For each output tile C[ti][tj], the K dimension is iterated by the Tile Sequencer FSM. On each K-tile pass, partial sums drain out of the bottom of each array column continuously during activation feeding. The bank adds each incoming value to the running 32-bit accumulator for that column.

The Tile Sequencer FSM signals whether each tile pass is an intermediate accumulation or the final K-tile pass:

- **Intermediate pass**: add incoming partial sums to accumulators, hold
- **Final pass**: add incoming partial sums, then write the completed 16×16 output tile row by row into the Output Buffer and clear accumulators for the next output tile

The Output Buffer is a 1 KB register buffer (16×16 × INT32). After the Accumulator Bank writes a completed tile into it, the Tile Sequencer FSM commands XDMA to DMA it back to the correct offset in host RAM.

Since we have a weight-stationary systolic array, there is no separate drain phase — partial sums exit the array naturally as activations flow through.
