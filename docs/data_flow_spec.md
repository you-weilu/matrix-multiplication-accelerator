# Data Flow Specification

This document records top-level design decisions for the accelerator data flow. It is a living document — open decisions are marked TBD and will be filled in as the design matures.

---

## Matrix dimensions

- Fixed 16×16 INT8 matrix multiplication (C = A × B)
- No tiling — the accelerator always operates on exactly one 16×16 matrix per operand

---

## Host-to-FPGA packet format (UDP payload)

The host sends data to the accelerator over UDP. Each UDP payload has the following structure:

| Field   | Size    | Description                                  |
|---------|---------|----------------------------------------------|
| Opcode  | TBD     | Command type (see opcodes below)             |
| Address | 4 bits  | Row index (0–15) within the target BRAM      |
| Data    | 16 bytes | One row of INT8 values (absent for RUN/READ) |

### Opcodes

| Opcode        | Payload | Description                          |
|---------------|---------|--------------------------------------|
| LOAD_WEIGHT   | Yes     | Write one row into Weight BRAM       |
| LOAD_ACT      | Yes     | Write one row into Activation BRAM   |
| RUN           | No      | Trigger matrix multiplication        |
| READ_OUTPUT   | No      | Request result readback from FPGA    |

Exact opcode encoding (bit width and values) is TBD.

### Variable-length packets

Packets are variable-length. Data packets (LOAD_WEIGHT, LOAD_ACT) carry a 16-byte payload. Command-only packets (RUN, READ_OUTPUT) carry no payload and are shorter. `tlast` is used as the frame-end signal rather than hardcoding a byte count in the parser.

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

- Opcode bit width and encoding
- Compute trigger: does RUN need to be explicit, or does the FSM start automatically once both BRAMs are fully loaded?
- Weight stationarity: can weights be loaded once and reused across multiple activation inputs, or is it always load-weights → load-activations → run?
- Result readback: is it host-initiated (READ_OUTPUT command) or does the accelerator push results automatically when compute is done?
- FPGA-to-host packet format (response payload layout)
