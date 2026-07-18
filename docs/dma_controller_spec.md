# DMA Controller Spec

The DMA Controller is the bridge between the Tile Sequencer FSM and the Xilinx XDMA IP core. It translates high-level tile fetch and writeback requests from the FSM into descriptor pushes on XDMA's H2C and C2H descriptor bypass buses, which in turn generate the PCIe TLPs that move data to and from host RAM.

The FSM never touches XDMA directly. It only pulses `fill_start` or `writeback_start` and holds the current tile indices steady; the DMA Controller handles all address computation and descriptor submission.

**Descriptor bypass mode:** Rather than writing descriptor structs to host RAM and pointing XDMA at them (which would require an extra PCIe roundtrip to fetch the descriptor), the DMA Controller uses XDMA's descriptor bypass interface. It drives src_addr, dst_addr, len, and ctl directly onto fabric wires and pulses `dsc_byp_load` when XDMA asserts `dsc_byp_ready`. XDMA immediately queues the descriptor without any host-side involvement.

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
| k_tiles | 8 | Input | Number of K-dimension tiles (from CSR) |
| n_tiles | 8 | Input | Number of column tiles in C (from CSR) |
| writeback_done | 1 | Output | Pulses when C2H transfer completes |
| s_axil | AXI4-Lite master | Output | One-time init: writes Run bit to H2C ch0/ch1 and C2H ch0 control registers at startup |
| h2c_dsc_byp_ready_0 | 1 | Input | XDMA H2C ch0 ready to accept descriptor (weight) |
| h2c_dsc_byp_load_0 | 1 | Output | Push descriptor into H2C ch0 |
| h2c_dsc_byp_src_addr_0 | 64 | Output | Host RAM address of weight tile |
| h2c_dsc_byp_dst_addr_0 | 64 | Output | Card AXI address of inactive weight ping-pong buffer |
| h2c_dsc_byp_len_0 | 28 | Output | Transfer length in bytes (256) |
| h2c_dsc_byp_ctl_0 | 16 | Output | Descriptor control: Stop=1, Completed=1 → 16'h0003 |
| h2c_dsc_byp_ready_1 | 1 | Input | XDMA H2C ch1 ready to accept descriptor (activation) |
| h2c_dsc_byp_load_1 | 1 | Output | Push descriptor into H2C ch1 |
| h2c_dsc_byp_src_addr_1 | 64 | Output | Host RAM address of activation tile |
| h2c_dsc_byp_dst_addr_1 | 64 | Output | Card AXI address of inactive activation ping-pong buffer |
| h2c_dsc_byp_len_1 | 28 | Output | Transfer length in bytes (256) |
| h2c_dsc_byp_ctl_1 | 16 | Output | Descriptor control: Stop=1, Completed=1 → 16'h0003 |
| c2h_dsc_byp_ready_0 | 1 | Input | XDMA C2H ch0 ready to accept descriptor (writeback) |
| c2h_dsc_byp_load_0 | 1 | Output | Push descriptor into C2H ch0 |
| c2h_dsc_byp_src_addr_0 | 64 | Output | Card AXI address of output buffer |
| c2h_dsc_byp_dst_addr_0 | 64 | Output | Host RAM address to write C tile to |
| c2h_dsc_byp_len_0 | 28 | Output | Transfer length in bytes (1024) |
| c2h_dsc_byp_ctl_0 | 16 | Output | Descriptor control: Stop=1, Completed=1 → 16'h0003 |
| h2c_sts_0 | 8 | Input | XDMA H2C ch0 status; bit 3 pulses one cycle on descriptor done |
| h2c_sts_1 | 8 | Input | XDMA H2C ch1 status; bit 3 pulses one cycle on descriptor done |
| c2h_sts_0 | 8 | Input | XDMA C2H ch0 status; bit 3 pulses one cycle on descriptor done |

---

## Initialization

At reset release, before any transfers, the DMA Controller writes the Run bit (bit 0 of Channel Control register 0x0004) to H2C ch0, H2C ch1, and C2H ch0 via the `s_axil` AXI4-Lite master. XDMA will not accept bypass descriptors until the Run bit is set. This is a one-time write per channel; `s_axil` is otherwise idle.

The per-channel register addresses (via the AXI4-Lite slave address map) follow the format `{Target[15:12], Channel[11:8], ByteOffset[7:0]}`:
- H2C ch0 Control: `32'h0000_0004`
- H2C ch1 Control: `32'h0000_1004` (channel field = 1)
- C2H ch0 Control: `32'h0001_0004` (target field = C2H)

---

## H2C: Tile Fetch

Triggered by `fill_start`. The DMA Controller computes src and dst addresses for both tiles and pushes one descriptor to H2C ch0 (weight) and one to H2C ch1 (activation) by asserting the respective bypass buses when XDMA's `ready` is high. Both channels are independent and XDMA runs them concurrently, interleaving PCIe read requests round-robin.

### Address computation

Each tile is 16×16 INT8 = 256 bytes.

**Weight tile (matrix B) → H2C ch0:**
```
src_addr = base_addr_b + (tile_j * k_tiles + k_tile) * 256   // host RAM
dst_addr = AXI address of inactive weight ping-pong buffer    // card AXI
len      = 256
ctl      = 16'h0003  (Stop=1, Completed=1)
```

**Activation tile (matrix A) → H2C ch1:**
```
src_addr = base_addr_a + (tile_i * k_tiles + k_tile) * 256   // host RAM
dst_addr = AXI address of inactive activation ping-pong buffer // card AXI
len      = 256
ctl      = 16'h0003
```

### Sequence

For each channel independently:
1. Wait for `h2c_dsc_byp_ready_x` to be high
2. Drive src_addr, dst_addr, len, ctl onto the bypass bus and assert `h2c_dsc_byp_load_x` for one cycle
3. XDMA latches the descriptor and begins fetching tile data from host RAM over PCIe
4. XDMA writes the tile to the ping-pong buffer via AXI4; the ping-pong buffer asserts `fill_weight_done` or `fill_act_done` when its AXI4 write handshake completes
5. `h2c_sts_x[3]` pulses for one cycle when XDMA marks the descriptor done (used internally to gate the next fill)

Both descriptors can be pushed in the same cycle if both channels assert ready simultaneously.

---

## C2H: Tile Writeback

Triggered by `writeback_start`. The DMA Controller pushes one descriptor to C2H ch0 to move the completed 16×16 INT32 output tile (1024 bytes) from the output buffer back to host RAM.

### Address computation

Each output tile is 16×16 INT32 = 1024 bytes.

```
src_addr = AXI address of output buffer                          // card AXI
dst_addr = base_addr_c + (tile_i * n_tiles + tile_j) * 1024     // host RAM
len      = 1024
ctl      = 16'h0003  (Stop=1, Completed=1)
```

### Sequence

1. Wait for `c2h_dsc_byp_ready_0` to be high
2. Drive src_addr, dst_addr, len, ctl and assert `c2h_dsc_byp_load_0` for one cycle
3. XDMA reads the output buffer via AXI4 and writes tile data to host RAM over PCIe
4. `c2h_sts_0[3]` pulses for one cycle when XDMA marks the descriptor done
5. Assert `writeback_done` for one cycle

---

## Relationship to XDMA

XDMA exposes:
- A descriptor bypass bus per channel (`h2c_dsc_byp_*`, `c2h_dsc_byp_*`): the DMA Controller is the producer; it drives descriptor fields directly onto the fabric
- A channel status port per channel (`h2c_sts_x`, `c2h_sts_x`): bit 3 pulses one cycle on descriptor completion, used for `writeback_done` and internal H2C done tracking
- An AXI4-Lite slave (`s_axil`): used only at startup to write the Run bit; not touched during normal operation

The DMA Controller does not implement any PCIe logic. It only computes tile addresses, issues bypass descriptors, and monitors completion status.

---

## Interaction with the rest of the design

```
CSR Block  ──base_addr_a/b/c──────────────────┐
                                               ▼
FSM ──fill_start, writeback_start──► DMA Controller ──dsc_byp buses──► XDMA
FSM ──tile_i, tile_j, k_tile──────►             └──s_axil (init)──────►      │
                                                                              │ PCIe
FSM ◄──fill_weight_done────────────────────────────── ping-pong buf ◄─ XDMA ◄┘
FSM ◄──fill_act_done
FSM ◄──writeback_done◄─────────────────────────────── DMA Controller (c2h_sts_0[3])
```
