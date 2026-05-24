# Systolic Data Setup Spec

## Overview

The Systolic Data Setup is a timing and sequencing controller that sits between the BRAMs and the systolic array. It operates on one 16×16 tile at a time, reading from the Weight and Activation BRAMs and driving the array inputs with correct timing for weight-stationary dataflow.

It contains a 256-byte internal working buffer that holds the current activation tile, copied directly from the Activation BRAM during pre-load. This gives the SDS random access to any element of the tile, which is needed to feed columns of A into rows of the array with skewing.

It operates in two phases per tile, triggered by the Control FSM:
1. **Pre-load (16 cycles)** — weight loading and activation pre-load run in parallel
2. **Activation feeding (31 cycles)** — skewed activation feeding from working buffer into array

---

## Phase 1a: Weight Loading (16 cycles)

Weights are loaded by reading the Weight BRAM and feeding values into the top of each array column. The columns act as shift register chains — values shift downward one PE per cycle.

Rows are read in reverse order so that PE[i][j] ends up holding B[i][j]:

| Cycle | BRAM row read | Value entering top of column j |
|-------|---------------|--------------------------------|
| 0     | row 15        | B[15][j]                       |
| 1     | row 14        | B[14][j]                       |
| ...   | ...           | ...                            |
| 15    | row 0         | B[0][j]                        |

After 16 cycles all PEs hold their weights. All 16 columns load simultaneously — 16 values enter the array each cycle.

---

## Phase 1b: Activation Pre-load (16 cycles, parallel with Phase 1a)

The SDS reads Activation BRAM addresses 0–15 sequentially and copies each row directly into the working buffer. The buffer uses [row][col] indexing matching the activation matrix:

```
Cycle t: read BRAM[t] → buffer[t][0..15] = A[t][0..15]
```

After 16 cycles, buffer[i][j] = A[i][j] for all i, j. The buffer is a direct copy of the tile. Phases 1a and 1b share the same 16-cycle window.

---

## Phase 2: Activation Feeding (31 cycles)

For computing C = A × B, array row k must receive column k of A: the sequence A[0][k], A[1][k], ..., A[15][k]. The SDS reads this from the buffer by indexing across rows at column k.

Rows are staggered by one cycle per row i.e. Row k starts k cycles after row 0. This diagonal skewing ensures each activation element meets the correct weight and in-flight partial sum at each PE.

At cycle t (0-indexed from start of this phase), array row k receives:
- buffer[t-k][k] = A[t-k][k] if t >= k, else 0

| Row k | Starts at cycle | Sequence fed into array          |
|-------|-----------------|----------------------------------|
| 0     | 0               | A[0][0], A[1][0], ..., A[15][0]  |
| 1     | 1               | A[0][1], A[1][1], ..., A[15][1]  |
| k     | k               | A[0][k], A[1][k], ..., A[15][k]  |
| 15    | 15              | A[0][15], ..., A[15][15]         |

Total duration: 16 data cycles + 15 skew cycles = 31 cycles.

---

## Tiling

For matrices larger than 16×16, the Control FSM drives the SDS through multiple tile passes. The SDS has no knowledge of tiling state and processes exactly one 16×16 tile per invocation. The Control FSM selects the correct tile addresses in the Weight and Activation BRAMs for each pass. The working buffer is overwritten each tile pass.

Total cycles per tile pass: 16 (pre-load) + 31 (feeding) = 47 cycles. The partial sum drain overlaps with the tail of feeding.
