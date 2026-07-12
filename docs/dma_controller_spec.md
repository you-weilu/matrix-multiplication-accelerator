# DMA Controller Spec

The DMA Controller is the bridge between the Tile Sequencer FSM and the Xilinx XDMA IP core. It translates high-level tile fetch and writeback requests from the FSM into AXI4-Lite descriptor writes to XDMA's H2C (Host-to-Card) and C2H (Card-to-Host) control interfaces, which in turn generate the PCIe TLPs that move data to and from host RAM.

The FSM never touches XDMA directly. It only pulses `fill_start` or `writeback_start` and holds the current tile indices steady; the DMA Controller handles all AXI4-Lite sequencing and address computation.

---

## Interface

| Signal | Width | Direction | Description |
|--------|-------|-----------|-------------|
| clk, rst_n | 1 | Input | Clock and active-low reset |
| fill_start | 1 | Input | Pulse from FSM: begin H2C fetch of next A and B tiles |
| writeback_start | 1 | Input | Pulse from FSM: begin C2H writeback of completed C tile |
| tile_i | 8 | Input | Current output tile row index (from FSM) |
| tile_j | 8 | Input | Current output tile column index (from FSM) |
| k_tile | 8 | Input | Current K-tile index (from FSM) |
| base_addr_a | 64 | Input | Host RAM base address of matrix A (from CSR) |
| base_addr_b | 64 | Input | Host RAM base address of matrix B (from CSR) |
| base_addr_c | 64 | Input | Host RAM base address of matrix C (from CSR) |
| fill_weight_done | 1 | Output | Pulses when B tile H2C transfer completes |
| fill_act_done | 1 | Output | Pulses when A tile H2C transfer completes |
| writeback_done | 1 | Output | Pulses when C tile C2H transfer completes |
| h2c_axi | AXI4-Lite master | Output | Writes H2C descriptors to XDMA |
| c2h_axi | AXI4-Lite master | Output | Writes C2H descriptors to XDMA |

---

## H2C: Tile Fetch

Triggered by `fill_start`. The DMA Controller programs two back-to-back XDMA H2C descriptors — one for the B (weight) tile and one for the A (activation) tile — then waits for XDMA to assert completion on each channel.

### Address computation

Each tile is 16×16 INT8 = 256 bytes.

**Weight tile (matrix B):**
```
src_addr_b = base_addr_b + (tile_j * k_tiles + k_tile) * 256
dst_addr   = AXI address of inactive weight ping-pong buffer
```

**Activation tile (matrix A):**
```
src_addr_a = base_addr_a + (tile_i * k_tiles + k_tile) * 256
dst_addr   = AXI address of inactive activation ping-pong buffer
```

### Sequence

For each tile (weight and activation independently):
1. Write source address low/high to XDMA H2C src registers
2. Write destination AXI address to XDMA H2C dst registers
3. Write length (256) and control bits to trigger the transfer
4. Wait for XDMA H2C completion
5. Assert `fill_weight_done` or `fill_act_done` for one cycle

Both transfers can be issued in parallel if XDMA exposes two independent H2C channels.

---

## C2H: Tile Writeback

Triggered by `writeback_start` (pulsed by the FSM after `tile_done` from the accumulator bank). The DMA Controller programs one XDMA C2H descriptor to move the completed 16×16 INT32 output tile (256 bytes × 4 = 1024 bytes) from the output buffer back to host RAM.

### Address computation

Each output tile is 16×16 INT32 = 1024 bytes.

```
dst_addr_c = base_addr_c + (tile_i * n_tiles + tile_j) * 1024
src_addr   = AXI address of output buffer
```

### Sequence

1. Write source AXI address (output buffer) to XDMA C2H src registers
2. Write destination address low/high to XDMA C2H dst registers
3. Write length (1024) and control bits to trigger the transfer
4. Wait for XDMA C2H completion
5. Assert `writeback_done` for one cycle

---

## Relationship to XDMA

XDMA exposes an AXI4-Lite slave port for descriptor programming. The DMA Controller is an AXI4-Lite master that writes to this port. Once a descriptor is written and the go bit is set, XDMA autonomously generates the PCIe TLPs to fetch or write the data, then signals completion.

The DMA Controller does not implement any PCIe logic itself — it only translates tile indices and base addresses into the register writes that XDMA expects.

---

## Interaction with the rest of the design

```
CSR Block  ──base_addr_a/b/c──────────────────┐
                                               ▼
FSM ──fill_start, writeback_start──► DMA Controller ──AXI4-Lite──► XDMA
FSM ──tile_i, tile_j, k_tile──────►                                  │
                                                                      │ PCIe
FSM ◄──fill_weight_done────────────────────────────────── XDMA ◄─────┘
FSM ◄──fill_act_done
FSM ◄──writeback_done
```
