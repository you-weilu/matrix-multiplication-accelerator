// DMA Controller
//
// Translates tile fetch and writeback requests from the Tile Sequencer FSM into
// AXI4-Lite descriptor writes to XDMA's H2C and C2H control interfaces.
//
// On fill_start: programs two XDMA H2C descriptors — one for the B (weight) tile
// and one for the A (activation) tile — using tile_i, tile_j, k_tile and the CSR
// base addresses to compute the source addresses in host RAM. Asserts
// fill_weight_done and fill_act_done (sticky) when each transfer completes;
// these are cleared by swap from the ping-pong buffers.
//
// On writeback_start: programs one XDMA C2H descriptor to send the completed
// output tile from the output buffer back to host RAM at the correct offset in C.
// Asserts writeback_done when the transfer completes.
//
// Address computation:
//   Weight tile:     base_addr_b + (tile_j * k_tiles + k_tile) * 256
//   Activation tile: base_addr_a + (tile_i * k_tiles + k_tile) * 256
//   Output tile:     base_addr_c + (tile_i * n_tiles + tile_j) * 1024
//
// Each tile is 16x16 INT8 = 256 bytes (A and B); output tile is 16x16 INT32 = 1024 bytes.

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

    // Completion signals to ping-pong buffers (sticky, cleared by swap)
    output logic        fill_weight_done,
    output logic        fill_act_done,

    // Completion signal to FSM
    output logic        writeback_done,

    // AXI4-Lite master ports to XDMA H2C and C2H control interfaces
    axi_lite_if.master  h2c_axi,
    axi_lite_if.master  c2h_axi
);

endmodule
