# Parser Spec

The Parser reads AXI-Stream data from the RX FIFO and decodes incoming UDP packets. It skips the first 28 bytes (20B IP header + 8B UDP header), then extracts the opcode. For LOAD opcodes it reads a start row address then streams the 16-row payload into the target BRAM in 16-byte chunks using tlast as the packet delimiter. For COMPUTE it reads three dimension bytes and pulses the Control FSM. For RESET it pulses the Control FSM immediately.

---

## Interface

| Signal         | Width    | Direction | Description                                          |
|----------------|----------|-----------|------------------------------------------------------|
| tdata          | 8 bits   | Input     | AXI-Stream data byte from RX FIFO                    |
| tvalid         | 1 bit    | Input     | AXI-Stream valid from RX FIFO                        |
| tready         | 1 bit    | Output    | AXI-Stream ready to RX FIFO                          |
| tlast          | 1 bit    | Input     | AXI-Stream end of frame from RX FIFO                 |
| bram_we        | 1 bit    | Output    | Write enable to target BRAM                          |
| bram_addr      | 12 bits  | Output    | Flat BRAM address (see addressing below)             |
| bram_data      | 128 bits | Output    | 16-byte chunk to target BRAM                         |
| bram_sel       | 1 bit    | Output    | BRAM select: 0 = Weight, 1 = Activation              |
| rst_out        | 1 bit    | Output    | Pulse to Control FSM on RESET opcode                 |
| compute_out    | 1 bit    | Output    | Pulse to Control FSM on COMPUTE opcode               |
| m_tiles        | 4 bits   | Output    | Row tile count from COMPUTE packet (1–15)            |
| k_tiles        | 4 bits   | Output    | K tile count from COMPUTE packet (1–15)              |
| n_tiles        | 4 bits   | Output    | Column tile count from COMPUTE packet (1–15)         |
| rst            | 1 bit    | Input     | Global reset (active high)                           |

### BRAM addressing

Each matrix row is 240 bytes = 15 chunks of 16 bytes. The flat BRAM address for a given row and chunk is:

```
bram_addr = start_row × 15 + chunk_counter
```

The parser initializes `chunk_counter` to 0 when it reads the start row address, then increments it by 1 each time a 16-byte chunk is written. Row boundaries within the packet are handled automatically — the parser does not track them explicitly.

`compute_out`, `m_tiles`, `k_tiles`, and `n_tiles` are all valid on the same cycle that `compute_out` is pulsed.

---

## Packet layout

After the 28-byte IP+UDP header skip:

```
Byte 28: [ opcode (bits 7–6) | padding (bits 5–0) ]

LOAD_WEIGHT / LOAD_ACT:
  Byte 29:        start row address (8 bits, 0–239)
  Bytes 30–tlast: 16 consecutive matrix rows (16 × 240 = 3,840 bytes)
                  Requires jumbo frames (exceeds standard 1,500-byte MTU)

COMPUTE:
  Byte 29: M_tiles (lower 4 bits, 1–15)
  Byte 30: K_tiles (lower 4 bits, 1–15)
  Byte 31: N_tiles (lower 4 bits, 1–15), tlast asserted here

RESET:
  No payload, tlast asserted on byte 28
```

### Opcodes

| Opcode      | Encoding | Payload                       |
|-------------|----------|-------------------------------|
| LOAD_WEIGHT | 00       | Start row + 16 rows of data   |
| LOAD_ACT    | 01       | Start row + 16 rows of data   |
| RESET       | 10       | None                          |
| COMPUTE     | 11       | M_tiles, K_tiles, N_tiles     |

---

## Internal state machine

The parser moves through states on each valid AXI-Stream beat (tvalid && tready):

### IDLE
Resting state. Parser asserts tready=1. When tvalid=1 a handshake occurs and the parser transitions to SKIP_HEADER on that beat, consuming the first byte.

### SKIP_HEADER
Counts through the first 28 bytes (IP + UDP headers) and discards them. Transitions to READ_OPCODE when the counter reaches 28.

### READ_OPCODE
Reads one byte, extracts the opcode from bits 7–6:
- LOAD_WEIGHT or LOAD_ACT → READ_ADDR
- COMPUTE → READ_DIMS
- RESET → assert rst_out, return to IDLE

### READ_ADDR
Reads one byte as the 8-bit start row address. Sets `chunk_counter = start_row × 15`. Transitions to READ_DATA.

### READ_DATA
Accumulates incoming bytes into a 16-byte chunk buffer. Every time 16 bytes have been collected, the parser asserts bram_we for one cycle, writing the chunk to the target BRAM at `bram_addr = chunk_counter`, then increments `chunk_counter` and clears the buffer. If tlast arrives on the 16th byte of a chunk the write completes and the parser returns to IDLE. If tlast arrives before the 16th byte the partial chunk is discarded and the parser returns to IDLE (truncated packet).

### READ_DIMS
Reads three consecutive bytes as M_tiles, K_tiles, N_tiles (lower 4 bits of each byte). On the third byte, asserts compute_out for one cycle with all three values valid, then returns to IDLE. If tlast arrives before the third byte the packet is truncated and compute_out is not asserted.

---

## tlast handling

tlast is the primary signal that ends a packet. A well-formed LOAD packet has tlast on the last byte of the 240th chunk (byte 3,839 of the payload). A well-formed COMPUTE packet has tlast on the N_tiles byte. If tlast arrives early in any state, the parser discards partial state and returns to IDLE without asserting compute_out or bram_we for incomplete chunks.

As an optional enhancement, the parser could signal the Control FSM to send a NACK on truncated packets so the host can retransmit. Not implemented in the initial version.

---

## Reset behavior

On global reset (rst): parser returns to IDLE, all counters, the chunk buffer, and dimension registers are cleared.
