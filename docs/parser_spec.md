# Parser Spec

The Parser reads AXI-Stream data from the RX FIFO and decodes incoming UDP packets. It skips the first 28 bytes (20B IP header + 8B UDP header), then extracts the opcode and row address from a single packed byte, followed by 16 bytes of data payload for LOAD opcodes. Based on the opcode it routes the completed row to the correct BRAM or signals the Control FSM to reset.

---

## Interface

| Signal         | Width    | Direction | Description                              |
|----------------|----------|-----------|------------------------------------------|
| tdata          | 8 bits   | Input     | AXI-Stream data byte from RX FIFO        |
| tvalid         | 1 bit    | Input     | AXI-Stream valid from RX FIFO            |
| tready         | 1 bit    | Output    | AXI-Stream ready to RX FIFO              |
| tlast          | 1 bit    | Input     | AXI-Stream end of frame from RX FIFO     |
| bram_we        | 1 bit    | Output    | Write enable to target BRAM              |
| bram_addr      | 4 bits   | Output    | Row address to target BRAM (0-15)        |
| bram_data      | 128 bits | Output    | Row data to target BRAM (16 × INT8)      |
| bram_sel       | 1 bit    | Output    | BRAM select: 0 = Weight, 1 = Activation  |
| rst_out        | 1 bit    | Output    | Pulse to Control FSM on RESET opcode     |
| rst            | 1 bit    | Input     | Global reset (active high)               |

---

## Packet layout

After the 28-byte IP+UDP header skip:

```
Byte 28: [ opcode (bits 7-6) | address (bits 5-2) | padding (bits 1-0) ]
Bytes 29-44: data payload (16 bytes, LOAD opcodes only)
```

### Opcodes

| Opcode      | Encoding | Payload |
|-------------|----------|---------|
| LOAD_WEIGHT | 00       | Yes     |
| LOAD_ACT    | 01       | Yes     |
| RESET       | 10       | No      |

## Internal state machine

The parser moves through five states on each valid AXI-Stream beat (tvalid && tready):

### IDLE
Resting state. Parser asserts tready=1 to signal it is ready to accept data. When the RX FIFO asserts tvalid=1, a handshake occurs and the parser transitions to SKIP_HEADER on that beat, consuming the first byte. All error recovery and normal completion paths return here.

### SKIP_HEADER
Counts through the first 28 bytes (IP + UDP headers) and discards them. Transitions to READ_OPCODE when counter reaches 28.

### READ_OPCODE
Reads one byte, extracts opcode and address using shift and mask. Transitions to READ_DATA if opcode is LOAD_WEIGHT or LOAD_ACT. Asserts rst_out and returns to IDLE if opcode is RESET.

### READ_DATA
Accumulates 16 bytes into an internal row buffer, one byte per cycle. Increments a byte counter each cycle. Transitions to WRITE when 16 bytes have been received.

### WRITE
Writes the completed row buffer to the correct BRAM (weight or activation) at the row address extracted in READ_OPCODE. Returns to IDLE on the next cycle.

---

## tlast handling

If tlast is asserted at any point before the parser has finished reading the expected number of bytes, the packet is treated as truncated. The partial data is discarded and the parser returns to IDLE.

As an optional enhancement, the parser could signal the Control FSM to send a NACK (negative acknowledgement) packet back to the host when a truncated packet is detected. The host would then know to retransmit. This is not implemented in the initial version but is a natural extension for improved reliability.

---

## Reset behavior

On global reset (rst): parser returns to IDLE, byte counters and row buffer are cleared.
