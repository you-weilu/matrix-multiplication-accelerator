# Data Flow Specification

This document records top-level design decisions for the accelerator data flow. It is a living document — open decisions are marked TBD and will be filled in as the design matures.

---

## Matrix dimensions

- INT8 matrix multiplication: C = A × B
- The systolic array is fixed 16×16, but the accelerator supports matrices of arbitrary size that are multiples of 16 in all dimensions (M×K multiplied by K×N)
- Large matrices are tiled into 16×16 blocks; the Control FSM and SDS handle all tiling on-chip after the host loads the full matrices
- Maximum supported dimensions: 256×256 for M, K, and N

---

## BRAM organization

Weight and Activation BRAMs each hold one full matrix (up to 256×256 INT8 = 65536 bytes). Each BRAM is organized as a flat array of 16-byte words:

```
address = row_index × 16 + col_chunk
```

where `row_index` is 0–255 and `col_chunk` is 0–15 (selecting a 16-byte column slice within the row). Total: 4096 addresses × 128 bits = 65536 bytes per BRAM.

Output BRAM holds one 16×16 output tile (256 × 4 = 1 KB, 32-bit elements). Results are streamed to the host one tile at a time in row-major order (C[0][0], C[0][1], ..., C[1][0], ...). The host reconstructs the full output matrix by placing each received tile at the correct offset.

---

## Host-to-FPGA packet format (UDP payload)

The host sends data to the accelerator over UDP. Each UDP payload has the following structure:

| Field   | Size     | Description                             |
|---------|----------|-----------------------------------------|
| Opcode  | 2 bits   | Command type (see opcodes below)        |
| Padding | 6 bits   | Reserved, set to zero                   |
| Address | 8 bits   | Row index within the target BRAM (0–255)|
| Data    | N bytes  | One full matrix row, tlast-delimited    |

For LOAD opcodes the data payload is a full row of INT8 values. `tlast` marks the last byte of the row — the parser does not assume a fixed payload length. COMPUTE and RESET packets have fixed-length payloads described below.

Activation data is sent in natural row-major format — no pre-transformation required from the host.

### Opcodes

| Opcode      | Encoding | Payload   | Description                          |
|-------------|----------|-----------|--------------------------------------|
| LOAD_WEIGHT | 00       | Yes       | Write one row into Weight BRAM       |
| LOAD_ACT    | 01       | Yes       | Write one row into Activation BRAM   |
| RESET       | 10       | No        | Reset FSM and clear both BRAMs       |
| COMPUTE     | 11       | 3 bytes   | Start computation with given dimensions |

The COMPUTE packet payload is 3 bytes: M_tiles, K_tiles, N_tiles (1–16 each), representing the number of 16×16 tile blocks in each dimension. For example, a 32×64×32 multiply sends M_tiles=2, K_tiles=4, N_tiles=2.

### Compute trigger

Compute starts when the parser receives a COMPUTE packet. The parser forwards M_tiles, K_tiles, and N_tiles to the Control FSM, which uses them to sequence all tile passes. The host is responsible for ensuring both BRAMs are fully loaded before sending COMPUTE.

### Result readback

Results are pushed back to the host one tile at a time as each output tile completes, in row-major order. The FSM streams each completed 16×16 INT32 tile (1 KB) from the Output BRAM through the TX FIFO and MAC back to the host over UDP. The host places each tile at the correct offset in the output matrix — no knowledge of internal tiling is required beyond tile row-major ordering.

### Variable-length packets

LOAD packets carry a variable-length payload (one full matrix row). COMPUTE carries a fixed 3-byte payload. RESET carries no payload. `tlast` is used as the frame-end signal for all packets.

---

## Ethernet framing and header stripping

```
| Ethernet header (14B) | IP header (20B) | UDP header (8B) | Our payload |
```

The Ethernet MAC IP core strips the Ethernet header and places the remainder on AXI-Stream. The parser strips the IP and UDP headers — a fixed 28-byte skip — before decoding the opcode, address, and data fields.

On the TX path, `tlast` must be asserted on the last byte of each outgoing packet.

---

## Tiling and multi-pass computation

The host loads the full weight matrix B and activation matrix A into their respective BRAMs before compute begins. All tiling is handled on-chip.

For each output tile C[ti][tj], the Control FSM iterates over the K dimension:

1. Select weight tile B[tk][tj]: BRAM addresses (tk×16 + r) × 16 + tj for r in 0..15
2. Select activation tile A[ti][tk]: BRAM addresses (ti×16 + r) × 16 + tk for r in 0..15
3. Provide tile offsets (ti, tk, tj) to the SDS; trigger tile pass
4. Signal the Accumulator Bank to accumulate the partial result
5. Repeat for all K tiles (tk = 0..K/16-1)
6. After the final K tile, the Accumulator Bank writes the completed output tile to Output BRAM
7. Stream the output tile to the host; advance to the next output tile (ti, tj)

Partial sums exit the bottom of the systolic array continuously during activation feeding — there is no separate drain phase.

---

## Open decisions

- FPGA-to-host packet format (response payload layout for result readback)
