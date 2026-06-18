# Data Flow Specification

This document records top-level design decisions for the accelerator data flow. It is a living document; open decisions are marked TBD and will be filled in as the design matures.

---

## Matrix dimensions

- INT8 matrix multiplication: C = A × B, where A is M×K and B is K×N, producing C as M×N INT32
- The systolic array is fixed 16×16; arbitrary matrix sizes are supported by tiling
- No hard upper bound on M, K, or N; the full matrices live in host RAM
- All dimensions must be multiples of 16. Non-multiples must be zero-padded by the host to the next multiple of 16. The host discards the corresponding padded rows/columns from the output.

---

## Memory organization

### Host RAM

The full matrices A, B, and C reside in host RAM as flat row-major arrays of the appropriate element type (INT8 for A and B, INT32 for C). The host writes the physical base addresses of each matrix into the CSR Block before asserting START.

### On-chip ping-pong buffers

The FPGA holds only enough storage for two 16×16 tiles per operand:

| Buffer | Count | Size each | Total |
|--------|-------|-----------|-------|
| Weight Buffer | 2 (ping-pong) | 256 bytes (16×16 × INT8) | 512 bytes |
| Activation Buffer | 2 (ping-pong) | 256 bytes (16×16 × INT8) | 512 bytes |
| Output Buffer | 1 | 1 KB (16×16 × INT32) | 1 KB |

Ping-pong operation: while the Systolic Data Setup reads the *active* weight and activation buffers, XDMA loads the *next* tile pair into the *shadow* buffers. The Tile Sequencer FSM swaps active/shadow roles after each tile pass completes.

---

## CSR register map

The host configures the accelerator by writing to memory-mapped registers in the CSR Block, accessible over PCIe via the XDMA AXI-Lite slave port.

| Offset | Name | Width | Description |
|--------|------|-------|-------------|
| 0x00 | M_TILES | 16 bits | Number of 16-row tile blocks in the M dimension (1–N) |
| 0x04 | K_TILES | 16 bits | Number of 16-deep tile blocks in the K dimension (1–N) |
| 0x08 | N_TILES | 16 bits | Number of 16-column tile blocks in the N dimension (1–N) |
| 0x10 | A_BASE_ADDR | 64 bits | Base address of matrix A in host RAM |
| 0x18 | B_BASE_ADDR | 64 bits | Base address of matrix B in host RAM |
| 0x20 | C_BASE_ADDR | 64 bits | Base address of matrix C in host RAM |
| 0x28 | CONTROL | 1 bit | Write 1 to START; self-clearing |
| 0x2C | STATUS | 1 bit | Read 1 when DONE (interrupt flag); write 1 to clear |

The host writes all dimension and address registers, then writes CONTROL=1. The FSM begins immediately and the host does not need to touch the accelerator again until it receives the interrupt.

---

## Tiling and autonomous sequencing

The Tile Sequencer FSM iterates over all output tiles in row-major order (ti = 0..M_TILES-1, tj = 0..N_TILES-1). For each output tile C[ti][tj]:

1. **K-tile loop** (tk = 0..K_TILES-1):
   a. Command XDMA to fetch weight tile B[tk][tj] from `B_BASE_ADDR + (tk*16*N + tj*16)` into the shadow Weight Buffer
   b. Command XDMA to fetch activation tile A[ti][tk] from `A_BASE_ADDR + (ti*16*K + tk*16)` into the shadow Activation Buffer
   c. Wait for DMA complete; swap active/shadow buffers
   d. Trigger one tile pass through the Systolic Data Setup → Systolic Array → Accumulator Bank pipeline
   e. Signal Accumulator Bank: intermediate accumulation (hold) unless tk == K_TILES-1 (final pass)

2. After the final K-tile pass, the Accumulator Bank writes the completed 16×16 INT32 tile into the Output Buffer and clears its accumulators.

3. Command XDMA to write the Output Buffer to `C_BASE_ADDR + (ti*16*N + tj*16)*4` in host RAM.

4. Advance to the next output tile (tj++, wrap to next ti row).

5. After all output tiles are written, assert the STATUS DONE interrupt.

### Double-buffering overlap

DMA fetch for tile (tk+1) overlaps with compute for tile tk. The FSM issues the next DMA command immediately after swapping buffers, before the compute pipeline finishes. The design is compute-bound: the systolic array is active nearly 100% of the time.

---

## Tile addressing in host RAM (row-major)

For matrices stored in row-major order with full row stride:

```
A tile [ti][tk]: base = A_BASE_ADDR + (ti * 16 * K_full + tk * 16)
B tile [tk][tj]: base = B_BASE_ADDR + (tk * 16 * N_full + tj * 16)
C tile [ti][tj]: base = C_BASE_ADDR + (ti * 16 * N_full + tj * 16) * sizeof(int32)
```

where `K_full = K_TILES * 16` and `N_full = N_TILES * 16`.

Each tile is 16 non-contiguous rows of 16 elements. The XDMA 2D transfer mode is used to fetch/write each tile without copying the full matrix row into a temporary buffer (TBD based on XDMA scatter-gather capability).

---

## Open decisions

- XDMA transfer mode for non-contiguous tile rows (scatter-gather vs. per-row 1D DMA)
- AXI clock domain crossing strategy between XDMA and the compute pipeline
- Exact interrupt delivery mechanism (MSI vs. MSI-X)
