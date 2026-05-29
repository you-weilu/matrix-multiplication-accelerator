# Data Flow Specification

This document records top-level design decisions for the accelerator data flow. It is a living document — open decisions are marked TBD and will be filled in as the design matures.

---

## Matrix dimensions

- INT8 matrix multiplication: C = A × B
- The systolic array is fixed 16×16, but the accelerator supports matrices of arbitrary size in all dimensions (M×K multiplied by K×N)
- Maximum supported dimensions: 240×240 for M, K, and N (240 = 15×16, giving a maximum of 15 tile blocks per dimension)
- All dimensions must be multiples of 16. Non-multiples must be zero-padded by the host to the next multiple of 16 before sending. The host discards the corresponding padded rows/columns from the output.
- Large matrices are tiled into 16×16 blocks; the Control FSM and SDS handle all tiling on-chip after the host loads the full matrices.

---

## BRAM organization

Weight and Activation BRAMs each hold one full matrix (up to 240×240 INT8 = 57,600 bytes). Each row is 240 bytes wide, which is exactly 15 chunks of 16 bytes. Each BRAM is organized as a flat array of 16-byte words:

```
address = row_index × 15 + col_chunk
```

where `row_index` is 0–239 and `col_chunk` is 0–14. Total: 3600 addresses × 128 bits = 57,600 bytes per BRAM.

Output uses a double buffer: two 16×16 INT32 tiles (1 KB each, 2 KB total). While the Accumulator Bank writes a completed tile into one buffer, the Control FSM streams the other buffer to the TX FIFO. The roles of the two buffers swap after each output tile.

---

## Host-to-FPGA packet format (UDP payload)

The host sends data to the accelerator over UDP. LOAD packets carry 16 rows of matrix data per packet (a row stripe), which at 240 bytes per row gives a 3,840-byte payload. This exceeds standard Ethernet MTU and requires **jumbo frames** to be enabled on both the host NIC and the FPGA MAC (9,000-byte MTU is sufficient).

Each UDP payload has the following structure:

| Field      | Size       | Description                                   |
|------------|------------|-----------------------------------------------|
| Opcode     | 1 byte     | Upper 2 bits = opcode, lower 6 bits = padding |
| Start row  | 1 byte     | Row index of the first row in this stripe (0–239) |
| Data       | 16×N bytes | 16 consecutive matrix rows, tlast-delimited   |

The parser does not track individual row boundaries within the payload — it writes 16-byte chunks to consecutive BRAM addresses starting from `start_row × 15`, incrementing the address each chunk until tlast.

Activation data is sent in natural row-major format — no pre-transformation required from the host.

### Opcodes

| Opcode      | Encoding | Payload      | Description                             |
|-------------|----------|--------------|-----------------------------------------|
| LOAD_WEIGHT | 00       | Yes (16 rows)| Write a row stripe into Weight BRAM     |
| LOAD_ACT    | 01       | Yes (16 rows)| Write a row stripe into Activation BRAM |
| RESET       | 10       | No           | Reset FSM and clear both BRAMs          |
| COMPUTE     | 11       | 3 bytes      | Start computation with given dimensions |

The COMPUTE packet payload is 3 bytes: M_tiles, K_tiles, N_tiles (1–15 each, 4 bits used), representing the number of 16×16 tile blocks in each dimension. For example, a 32×48×32 multiply sends M_tiles=2, K_tiles=3, N_tiles=2.

### Compute trigger

Compute starts when the parser receives a COMPUTE packet. The parser forwards M_tiles, K_tiles, and N_tiles to the Control FSM, which uses them to sequence all tile passes. The host is responsible for ensuring both BRAMs are fully loaded before sending COMPUTE.

### Result readback

Results are pushed back to the host one tile at a time as each output tile completes, in row-major order (C[0][0], C[0][1], ..., C[1][0], ...). The FSM streams each completed 16×16 INT32 tile (1 KB) from the active output buffer through the TX FIFO and MAC back to the host over UDP. The host places each tile at the correct offset to reconstruct the full output matrix.

### Variable-length packets

LOAD packets carry a fixed 16-row payload at the agreed matrix width. COMPUTE carries a fixed 3-byte payload. RESET carries no payload. `tlast` is used as the frame-end signal for all packets.

---

## Ethernet framing and header stripping

```
| Ethernet header (14B) | IP header (20B) | UDP header (8B) | Our payload |
```

The Ethernet MAC IP core strips the Ethernet header and places the remainder on AXI-Stream. The parser strips the IP and UDP headers — a fixed 28-byte skip — before decoding the opcode, start row, and data fields.

On the TX path, `tlast` must be asserted on the last byte of each outgoing packet.

---

## Tiling and multi-pass computation

The host loads the full weight matrix B and activation matrix A into their respective BRAMs before compute begins. All tiling is handled on-chip.

For each output tile C[ti][tj], the Control FSM iterates over the K dimension:

1. Select weight tile B[tk][tj]: BRAM addresses (tk×16 + r) × 15 + tj for r in 0..15
2. Select activation tile A[ti][tk]: BRAM addresses (ti×16 + r) × 15 + tk for r in 0..15
3. Provide tile offsets (ti, tk, tj) to the SDS; trigger tile pass
4. Signal the Accumulator Bank to accumulate the partial result
5. Repeat for all K tiles (tk = 0..K_tiles-1)
6. After the final K tile, the Accumulator Bank writes the completed tile into the inactive output buffer; buffers swap
7. Stream the completed buffer to the host; advance to the next output tile (ti, tj)

Partial sums exit the bottom of the systolic array continuously during activation feeding — there is no separate drain phase.

---

## Open decisions

- FPGA-to-host packet format (response payload layout for result readback)
