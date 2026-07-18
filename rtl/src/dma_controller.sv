// DMA Controller
//
// Translates tile fetch and writeback requests from the Tile Sequencer FSM into
// XDMA descriptor bypass pushes. Uses descriptor bypass mode: src_addr, dst_addr,
// len, and ctl are driven directly onto XDMA's fabric bypass bus rather than being
// written to host memory for XDMA to fetch over PCIe (which would waste a roundtrip).
//
// Initialization: at reset release, writes the Run bit to H2C ch0, H2C ch1, and
// C2H ch0 control registers via s_axil. XDMA ignores bypass descriptors until Run=1.
// s_axil is idle after this one-time setup.
//
// On fill_start: pushes one descriptor to H2C ch0 (weight tile, matrix B) and one
// to H2C ch1 (activation tile, matrix A) by asserting dsc_byp_load when XDMA's
// dsc_byp_ready is high. Both channels run concurrently; XDMA interleaves their
// PCIe reads round-robin. XDMA writes each tile to the inactive ping-pong buffer
// via AXI4; the ping-pong buffers assert fill_weight_done/fill_act_done when their
// AXI4 write handshake completes. h2c_sts_x[3] pulses one cycle on descriptor done.
//
// On writeback_start: pushes one descriptor to C2H ch0. XDMA reads the output
// buffer via AXI4 and writes the tile to host RAM. c2h_sts_0[3] pulses one cycle
// on completion; the DMA Controller registers this and asserts writeback_done.
//
// Address computation:
//   Weight tile (H2C ch0):     src = base_addr_b + (tile_j * k_tiles + k_tile) * 256
//   Activation tile (H2C ch1): src = base_addr_a + (tile_i * k_tiles + k_tile) * 256
//   Output tile (C2H ch0):     dst = base_addr_c + (tile_i * n_tiles + tile_j) * 1024
//
// Descriptor ctl field is always 16'h0003 (Stop=1, Completed=1) for single-descriptor
// transfers. Magic, Nxt_adj, and Nxt_adr fields are not used in bypass mode.

module dma_controller (
    input  logic        clk, rst_n,

    // FSM control
    input  logic        fill_start,
    input  logic        writeback_start,
    input  logic [7:0]  tile_i,
    input  logic [7:0]  tile_j,
    input  logic [7:0]  k_tile,

    // CSR base addresses and dimensions
    input  logic [63:0] base_addr_a,
    input  logic [63:0] base_addr_b,
    input  logic [63:0] base_addr_c,
    input  logic [7:0]  k_tiles,
    input  logic [7:0]  n_tiles,

    // Completion signal to FSM (fill_weight_done/fill_act_done come from ping-pong buffers)
    output logic        writeback_done,

    // AXI4-Lite master: one-time init only (writes Run bit to H2C ch0/ch1, C2H ch0)
    axi_lite_if.master  s_axil,

    // H2C ch0 descriptor bypass: weight tile (matrix B)
    input  logic        h2c_dsc_byp_ready_0,
    output logic        h2c_dsc_byp_load_0,
    output logic [63:0] h2c_dsc_byp_src_addr_0,
    output logic [63:0] h2c_dsc_byp_dst_addr_0,
    output logic [27:0] h2c_dsc_byp_len_0,
    output logic [15:0] h2c_dsc_byp_ctl_0,

    // H2C ch1 descriptor bypass: activation tile (matrix A)
    input  logic        h2c_dsc_byp_ready_1,
    output logic        h2c_dsc_byp_load_1,
    output logic [63:0] h2c_dsc_byp_src_addr_1,
    output logic [63:0] h2c_dsc_byp_dst_addr_1,
    output logic [27:0] h2c_dsc_byp_len_1,
    output logic [15:0] h2c_dsc_byp_ctl_1,

    // C2H ch0 descriptor bypass: output tile writeback (matrix C)
    input  logic        c2h_dsc_byp_ready_0,
    output logic        c2h_dsc_byp_load_0,
    output logic [63:0] c2h_dsc_byp_src_addr_0,
    output logic [63:0] c2h_dsc_byp_dst_addr_0,
    output logic [27:0] c2h_dsc_byp_len_0,
    output logic [15:0] c2h_dsc_byp_ctl_0,

    // XDMA channel status: bit 3 pulses one cycle when descriptor completes
    input  logic [7:0]  h2c_sts_0,
    input  logic [7:0]  h2c_sts_1,
    input  logic [7:0]  c2h_sts_0
);

    




endmodule
