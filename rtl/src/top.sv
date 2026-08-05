// Top-level module for the matrix multiplication accelerator.
//
// Clock and reset are sourced from the csr_axi interface (XDMA's axi_aclk /
// axi_aresetn). All other modules share these signals.
//
// AXI base addresses for the on-card slave ports must match the assignments
// made in Vivado's address editor. Override the parameters when packaging
// the IP or when the block design assigns different addresses.

module top #(
    parameter logic [63:0] PP_WEIGHT_AXI_BASE  = 64'h0000_0000_44A0_0000, // 64KB: 0x44A00000–0x44A0FFFF
    parameter logic [63:0] PP_ACT_AXI_BASE     = 64'h0000_0000_44A1_0000, // 64KB: 0x44A10000–0x44A1FFFF
    parameter logic [63:0] OUTPUT_BUF_AXI_BASE = 64'h0000_0000_44A2_0000  // 64KB: 0x44A20000–0x44A2FFFF
) (
    // CSR AXI4-Lite slave — clock and reset sourced from this interface
    axi_lite_if.slave  csr_axi,

    // XDMA AXI4-Lite slave — DMA controller writes Run bit here at startup
    axi_lite_if.master s_axil,

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

    // C2H ch0 descriptor bypass: output tile (matrix C)
    input  logic        c2h_dsc_byp_ready_0,
    output logic        c2h_dsc_byp_load_0,
    output logic [63:0] c2h_dsc_byp_src_addr_0,
    output logic [63:0] c2h_dsc_byp_dst_addr_0,
    output logic [27:0] c2h_dsc_byp_len_0,
    output logic [15:0] c2h_dsc_byp_ctl_0,

    // XDMA channel status: bit 3 pulses one cycle on descriptor done
    input  logic [7:0]  h2c_sts_0,
    input  logic [7:0]  h2c_sts_1,
    input  logic [7:0]  c2h_sts_0,

    // AXI4 slave: XDMA H2C ch0 writes weight tile data into ping-pong buffer
    axi4_if.slave  fill_weight_axi,

    // AXI4 slave: XDMA H2C ch1 writes activation tile data into ping-pong buffer
    axi4_if.slave  fill_act_axi,

    // AXI4 slave: XDMA C2H ch0 reads output tile data from output buffer
    axi4_if.slave  c2h_axi
);

    logic clk, rst_n;
    assign clk   = csr_axi.aclk;
    assign rst_n = csr_axi.aresetn;

    // -----------------------------------------------------------------------
    // Internal signals
    // -----------------------------------------------------------------------

    // CSR <--> tile sequencer
    logic        go;
    logic [7:0]  m_tiles, n_tiles, k_tiles;
    logic [63:0] base_addr_a, base_addr_b, base_addr_c;
    logic        ts_busy, ts_done;

    // Tile sequencer <--> DMA controller
    logic        fill_start, writeback_start;
    logic [7:0]  tile_i, tile_j, k_tile;
    logic        writeback_done, init_done;

    // Tile sequencer <--> ping-pong buffers
    logic swap, fill_weight_done, fill_act_done;

    // Tile sequencer <--> SDS
    logic start, pass_done;

    // Tile sequencer / SDS <--> accumulator bank
    logic final_pass, row_valid;

    // Accumulator bank <--> tile sequencer
    logic tile_done;

    // SDS <--> ping-pong buffers
    logic [3:0] weight_buf_addr, act_buf_addr;
    logic [7:0] weight_buf_data [15:0], act_buf_data [15:0];

    // SDS <--> systolic array
    logic [7:0] weight_in [15:0], act_in [15:0];
    logic       weight_load_en;

    // Systolic array <--> accumulator bank
    logic [31:0] col_out [15:0];

    // Accumulator bank <--> output buffer
    logic        buf_wen;
    logic [3:0]  buf_row;
    logic [31:0] buf_data [15:0];

    // -----------------------------------------------------------------------
    // Instantiations
    // -----------------------------------------------------------------------

    csr_block u_csr (
        .csr_axi    (csr_axi),
        .go         (go),
        .m_tiles    (m_tiles),
        .n_tiles    (n_tiles),
        .k_tiles    (k_tiles),
        .ts_busy    (ts_busy),
        .ts_done    (ts_done),
        .base_addr_a(base_addr_a),
        .base_addr_b(base_addr_b),
        .base_addr_c(base_addr_c)
    );

    tile_sequencer_fsm u_ts (
        .clk             (clk),
        .rst_n           (rst_n),
        .go              (go),
        .m_tiles         (m_tiles),
        .n_tiles         (n_tiles),
        .k_tiles         (k_tiles),
        .swap            (swap),
        .fill_weight_done(fill_weight_done),
        .fill_act_done   (fill_act_done),
        .start           (start),
        .pass_done       (pass_done),
        .final_pass      (final_pass),
        .tile_done       (tile_done),
        .ts_busy         (ts_busy),
        .ts_done         (ts_done),
        .tile_i          (tile_i),
        .tile_j          (tile_j),
        .k_tile          (k_tile),
        .fill_start      (fill_start),
        .writeback_start (writeback_start),
        .writeback_done  (writeback_done),
        .init_done       (init_done)
    );

    dma_controller u_dma (
        .clk                     (clk),
        .rst_n                   (rst_n),
        .fill_start              (fill_start),
        .writeback_start         (writeback_start),
        .tile_i                  (tile_i),
        .tile_j                  (tile_j),
        .k_tile                  (k_tile),
        .base_addr_a             (base_addr_a),
        .base_addr_b             (base_addr_b),
        .base_addr_c             (base_addr_c),
        .k_tiles                 (k_tiles),
        .n_tiles                 (n_tiles),
        .pp_weight_axi_base      (PP_WEIGHT_AXI_BASE),
        .pp_act_axi_base         (PP_ACT_AXI_BASE),
        .output_buf_axi_base     (OUTPUT_BUF_AXI_BASE),
        .writeback_done          (writeback_done),
        .init_done               (init_done),
        .s_axil                  (s_axil),
        .h2c_dsc_byp_ready_0    (h2c_dsc_byp_ready_0),
        .h2c_dsc_byp_load_0     (h2c_dsc_byp_load_0),
        .h2c_dsc_byp_src_addr_0 (h2c_dsc_byp_src_addr_0),
        .h2c_dsc_byp_dst_addr_0 (h2c_dsc_byp_dst_addr_0),
        .h2c_dsc_byp_len_0      (h2c_dsc_byp_len_0),
        .h2c_dsc_byp_ctl_0      (h2c_dsc_byp_ctl_0),
        .h2c_dsc_byp_ready_1    (h2c_dsc_byp_ready_1),
        .h2c_dsc_byp_load_1     (h2c_dsc_byp_load_1),
        .h2c_dsc_byp_src_addr_1 (h2c_dsc_byp_src_addr_1),
        .h2c_dsc_byp_dst_addr_1 (h2c_dsc_byp_dst_addr_1),
        .h2c_dsc_byp_len_1      (h2c_dsc_byp_len_1),
        .h2c_dsc_byp_ctl_1      (h2c_dsc_byp_ctl_1),
        .c2h_dsc_byp_ready_0    (c2h_dsc_byp_ready_0),
        .c2h_dsc_byp_load_0     (c2h_dsc_byp_load_0),
        .c2h_dsc_byp_src_addr_0 (c2h_dsc_byp_src_addr_0),
        .c2h_dsc_byp_dst_addr_0 (c2h_dsc_byp_dst_addr_0),
        .c2h_dsc_byp_len_0      (c2h_dsc_byp_len_0),
        .c2h_dsc_byp_ctl_0      (c2h_dsc_byp_ctl_0),
        .h2c_sts_0               (h2c_sts_0),
        .h2c_sts_1               (h2c_sts_1),
        .c2h_sts_0               (c2h_sts_0)
    );

    pingpong_buffers u_pp (
        .clk             (clk),
        .rst_n           (rst_n),
        .swap            (swap),
        .fill_weight_done(fill_weight_done),
        .fill_act_done   (fill_act_done),
        .fill_weight_axi (fill_weight_axi),
        .fill_act_axi    (fill_act_axi),
        .weight_buf_addr (weight_buf_addr),
        .weight_buf_data (weight_buf_data),
        .act_buf_addr    (act_buf_addr),
        .act_buf_data    (act_buf_data)
    );

    systolic_data_setup u_sds (
        .clk            (clk),
        .rst_n          (rst_n),
        .start          (start),
        .pass_done      (pass_done),
        .weight_buf_addr(weight_buf_addr),
        .weight_buf_data(weight_buf_data),
        .act_buf_addr   (act_buf_addr),
        .act_buf_data   (act_buf_data),
        .weight_in      (weight_in),
        .weight_load_en (weight_load_en),
        .act_in         (act_in),
        .row_valid      (row_valid)
    );

    systolic_array u_sa (
        .clk           (clk),
        .rst_n         (rst_n),
        .weight_load_en(weight_load_en),
        .weight_in     (weight_in),
        .act_in        (act_in),
        .col_out       (col_out)
    );

    accumulator_bank u_acc (
        .clk       (clk),
        .rst_n     (rst_n),
        .col_in    (col_out),
        .row_valid (row_valid),
        .final_pass(final_pass),
        .buf_data  (buf_data),
        .buf_row   (buf_row),
        .buf_wen   (buf_wen),
        .tile_done (tile_done)
    );

    output_buffer u_outbuf (
        .clk     (clk),
        .rst_n   (rst_n),
        .buf_wen (buf_wen),
        .buf_row (buf_row),
        .buf_data(buf_data),
        .c2h_axi (c2h_axi)
    );

endmodule
