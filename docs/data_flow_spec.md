# Data Flow Specification

This document records top-level design decisions for the accelerator data flow. It is a living document — open decisions are marked TBD and will be filled in as the design matures.

---

## Matrix dimensions

- Fixed 16×16 INT8 matrix multiplication (C = A × B)
- No tiling — the accelerator always operates on exactly one 16×16 matrix per operand

---

## Host-to-FPGA packet format (UDP payload)

The host sends data to the accelerator over UDP. Each UDP payload has the following structure:

| Field   | Size     | Description                             |
|---------|----------|-----------------------------------------|
| Opcode  | 2 bits   | Command type (see opcodes below)        |
| Address | 4 bits   | Row index (0–15) within the target BRAM |
| Data    | 16 bytes | One row of INT8 values (LOAD only)      |

### Opcodes

| Opcode      | Encoding | Payload | Description                        |
|-------------|----------|---------|------------------------------------|
| LOAD_WEIGHT | 00       | Yes     | Write one row into Weight BRAM     |
| LOAD_ACT    | 01       | Yes     | Write one row into Activation BRAM |
| RESET       | 10       | No      | Reset FSM and clear both BRAMs     |

### Compute trigger

Compute starts automatically once both BRAMs are fully loaded (all 16 rows written to each). No explicit RUN command is needed — the FSM tracks write counts for each BRAM and triggers compute when both reach 16.

### Result readback

Results are pushed back to the host automatically when compute is done. The FSM streams the full 16×16 result matrix from the Output BRAM through the TX FIFO and MAC back to the host over UDP. The host listens on a UDP socket and receives the result packet without needing to send a request. This is functionally equivalent to a hardware interrupt — the arriving UDP packet wakes up the host application.

### Variable-length packets

Data packets (LOAD_WEIGHT, LOAD_ACT) carry a 16-byte payload. RESET carries no payload. `tlast` is used as the frame-end signal rather than hardcoding a byte count in the parser.

---

## Ethernet framing and header stripping

The host OS wraps the UDP payload in the standard network stack before transmission:

```
| Ethernet header (14B) | IP header (20B) | UDP header (8B) | Our payload |
```

The Ethernet MAC IP core (Xilinx TEMAC) strips the Ethernet header (14B) and places the remainder on AXI-Stream. The **parser** is responsible for stripping the IP header (20B) and UDP header (8B) — a fixed 28-byte skip — before decoding the opcode, address, and data fields.

The MAC class in the sw model mirrors this: it streams bytes onto AXI-Stream with no header awareness. All protocol decoding lives in the parser.

On the TX path, our logic must assert `tlast` on the last byte of each outgoing packet to signal frame end to the MAC.

---

## Open decisions

- FPGA-to-host packet format (response payload layout)
