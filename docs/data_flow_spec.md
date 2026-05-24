# Data Flow Specification

This document records top-level design decisions for the accelerator data flow. It is a living document — open decisions are marked TBD and will be filled in as the design matures.

---

## Matrix dimensions

- INT8 matrix multiplication: C = A × B
- The systolic array is fixed 16×16, but the accelerator supports matrices of arbitrary size that are multiples of 16 in all dimensions (M×K multiplied by K×N)
- Large matrices are tiled into 16×16 blocks; the Control FSM sequences tile passes through the array
- Maximum supported dimensions: 256×256 for M, K, and N
- Weight and Activation BRAMs each hold one 16×16 tile (256 bytes); for 256×256 matrices, the host reloads tiles across passes
- Output BRAM holds one 16×16 output tile (256 × 4 = 1 KB, 32-bit elements)

---

## Host-to-FPGA packet format (UDP payload)

The host sends data to the accelerator over UDP. Each UDP payload has the following structure:

| Field   | Size     | Description                             |
|---------|----------|-----------------------------------------|
| Opcode  | 2 bits   | Command type (see opcodes below)        |
| Address | 4 bits   | Row index within the target BRAM        |
| Data    | 16 bytes | One row of INT8 values (LOAD only)      |

Activation data is sent in natural row-major format — no pre-transformation required from the host.

### Opcodes

| Opcode      | Encoding | Payload | Description                        |
|-------------|----------|---------|------------------------------------|
| LOAD_WEIGHT | 00       | Yes     | Write one row into Weight BRAM     |
| LOAD_ACT    | 01       | Yes     | Write one row into Activation BRAM |
| RESET       | 10       | No      | Reset FSM and clear both BRAMs     |

Note: the current 4-bit address field covers one 16×16 tile (rows 0–15). For 256×256 matrices the host addresses up to 256 rows, so the address field must be extended to 8 bits.

### Compute trigger

Compute starts automatically once both BRAMs are fully loaded. The FSM tracks write counts for each BRAM and triggers compute when both reach the expected row count.

### Result readback

Results are pushed back to the host automatically when compute is done. The FSM streams the result matrix from the Output BRAM through the TX FIFO and MAC back to the host over UDP.

### Variable-length packets

Data packets carry a 16-byte payload. RESET carries no payload. `tlast` is used as the frame-end signal.

---

## Ethernet framing and header stripping

```
| Ethernet header (14B) | IP header (20B) | UDP header (8B) | Our payload |
```

The Ethernet MAC IP core strips the Ethernet header and places the remainder on AXI-Stream. The parser strips the IP and UDP headers — a fixed 28-byte skip — before decoding the opcode, address, and data fields.

On the TX path, `tlast` must be asserted on the last byte of each outgoing packet.

---

## Tiling and multi-pass computation

For matrices larger than 16×16, the accelerator performs multiple tile passes. For each output tile C[ti][tj], the Control FSM iterates over the K dimension:

1. Load the weight tile B[tk][tj] and activation tile A[ti][tk] into their BRAMs
2. Trigger the SDS to pre-load and feed the tile through the array
3. Signal the Accumulator Bank to accumulate the partial result
4. Repeat for all K tiles
5. After the final K tile, the Accumulator Bank writes the completed output tile to Output BRAM

Partial sums exit the bottom of the systolic array continuously during activation feeding — there is no separate drain phase. Results flow out naturally and the PEs never need to be flushed.

---

## Open decisions

- FPGA-to-host packet format (response payload layout)
- Packet protocol extension for tiling (8-bit address field encoding and framing)
