// Compute pipeline wrapper for simulation.
//
// Instantiates everything except the DMA controller and XDMA. The testbench
// acts as the DMA proxy: it drives init_done=1, writes tile data directly to
// the ping-pong buffer AXI slaves when fill_start fires, reads from the output
// buffer AXI slave when writeback_start fires, and drives writeback_done.
//
// Port prefixes:
//   csr_*  — CSR AXI4-Lite (testbench configures m/n/k_tiles, base addresses, go)
//   fw_*   — fill_weight AXI4 write port (testbench writes weight tiles)
//   fa_*   — fill_act AXI4 write port (testbench writes activation tiles)
//   ob_*   — output buffer AXI4 read port (testbench reads completed output tiles)

module compute_pipeline_wrap (
    input  logic clk, rst_n,

    // CSR AXI4-Lite (flat)
    input  logic [31:0] csr_awaddr,
    input  logic [2:0]  csr_awprot,
    input  logic        csr_awvalid,
    output logic        csr_awready,
    input  logic [31:0] csr_wdata,
    input  logic [3:0]  csr_wstrb,
    input  logic        csr_wvalid,
    output logic        csr_wready,
    output logic [1:0]  csr_bresp,
    output logic        csr_bvalid,
    input  logic        csr_bready,
    input  logic [31:0] csr_araddr,
    input  logic [2:0]  csr_arprot,
    input  logic        csr_arvalid,
    output logic        csr_arready,
    output logic [31:0] csr_rdata,
    output logic [1:0]  csr_rresp,
    output logic        csr_rvalid,
    input  logic        csr_rready,

    // Ping-pong weight AXI4 write port (flat)
    input  logic         fw_awvalid,
    input  logic [3:0]   fw_awid,
    input  logic [63:0]  fw_awaddr,
    input  logic [7:0]   fw_awlen,
    input  logic [2:0]   fw_awsize,
    input  logic [1:0]   fw_awburst,
    output logic         fw_awready,
    input  logic         fw_wvalid,
    input  logic [127:0] fw_wdata,
    input  logic [15:0]  fw_wstrb,
    input  logic         fw_wlast,
    output logic         fw_wready,
    output logic         fw_bvalid,
    output logic [3:0]   fw_bid,
    output logic [1:0]   fw_bresp,
    input  logic         fw_bready,

    // Ping-pong activation AXI4 write port (flat)
    input  logic         fa_awvalid,
    input  logic [3:0]   fa_awid,
    input  logic [63:0]  fa_awaddr,
    input  logic [7:0]   fa_awlen,
    input  logic [2:0]   fa_awsize,
    input  logic [1:0]   fa_awburst,
    output logic         fa_awready,
    input  logic         fa_wvalid,
    input  logic [127:0] fa_wdata,
    input  logic [15:0]  fa_wstrb,
    input  logic         fa_wlast,
    output logic         fa_wready,
    output logic         fa_bvalid,
    output logic [3:0]   fa_bid,
    output logic [1:0]   fa_bresp,
    input  logic         fa_bready,

    // Output buffer AXI4 read port (flat)
    input  logic         ob_arvalid,
    input  logic [3:0]   ob_arid,
    input  logic [63:0]  ob_araddr,
    input  logic [7:0]   ob_arlen,
    input  logic [2:0]   ob_arsize,
    input  logic [1:0]   ob_arburst,
    output logic         ob_arready,
    output logic         ob_rvalid,
    output logic [3:0]   ob_rid,
    output logic [127:0] ob_rdata,
    output logic [1:0]   ob_rresp,
    output logic         ob_rlast,
    input  logic         ob_rready,

    // DMA proxy interface (testbench drives)
    input  logic        init_done,
    input  logic        writeback_done,
    output logic        fill_start,
    output logic        writeback_start,
    output logic [7:0]  tile_i,
    output logic [7:0]  tile_j,
    output logic [7:0]  k_tile,
    output logic        ts_done,
    output logic        ts_busy
);

    // -----------------------------------------------------------------------
    // Interface instantiations
    // -----------------------------------------------------------------------

    axi_lite_if #(.ADDR_WIDTH(32), .DATA_WIDTH(32)) csr_axi (.aclk(clk), .aresetn(rst_n));
    axi4_if #(.ADDR_WIDTH(64), .DATA_WIDTH(128), .ID_WIDTH(4), .LEN_WIDTH(8)) fill_weight_axi (.aclk(clk), .aresetn(rst_n));
    axi4_if #(.ADDR_WIDTH(64), .DATA_WIDTH(128), .ID_WIDTH(4), .LEN_WIDTH(8)) fill_act_axi    (.aclk(clk), .aresetn(rst_n));
    axi4_if #(.ADDR_WIDTH(64), .DATA_WIDTH(128), .ID_WIDTH(4), .LEN_WIDTH(8)) c2h_axi         (.aclk(clk), .aresetn(rst_n));

    // CSR AXI-Lite wiring
    assign csr_axi.awaddr  = csr_awaddr;   assign csr_axi.awprot  = csr_awprot;
    assign csr_axi.awvalid = csr_awvalid;  assign csr_awready     = csr_axi.awready;
    assign csr_axi.wdata   = csr_wdata;    assign csr_axi.wstrb   = csr_wstrb;
    assign csr_axi.wvalid  = csr_wvalid;   assign csr_wready      = csr_axi.wready;
    assign csr_bresp       = csr_axi.bresp; assign csr_bvalid     = csr_axi.bvalid;
    assign csr_axi.bready  = csr_bready;
    assign csr_axi.araddr  = csr_araddr;   assign csr_axi.arprot  = csr_arprot;
    assign csr_axi.arvalid = csr_arvalid;  assign csr_arready     = csr_axi.arready;
    assign csr_rdata       = csr_axi.rdata; assign csr_rresp      = csr_axi.rresp;
    assign csr_rvalid      = csr_axi.rvalid; assign csr_axi.rready = csr_rready;

    // fill_weight_axi wiring (write only; read channels tied off)
    assign fill_weight_axi.awvalid = fw_awvalid; assign fill_weight_axi.awid    = fw_awid;
    assign fill_weight_axi.awaddr  = fw_awaddr;  assign fill_weight_axi.awlen   = fw_awlen;
    assign fill_weight_axi.awsize  = fw_awsize;  assign fill_weight_axi.awburst = fw_awburst;
    assign fw_awready              = fill_weight_axi.awready;
    assign fill_weight_axi.wvalid  = fw_wvalid;  assign fill_weight_axi.wdata   = fw_wdata;
    assign fill_weight_axi.wstrb   = fw_wstrb;   assign fill_weight_axi.wlast   = fw_wlast;
    assign fw_wready               = fill_weight_axi.wready;
    assign fw_bvalid               = fill_weight_axi.bvalid; assign fw_bid  = fill_weight_axi.bid;
    assign fw_bresp                = fill_weight_axi.bresp;
    assign fill_weight_axi.bready  = fw_bready;
    assign fill_weight_axi.arvalid = 0; assign fill_weight_axi.arid    = 0;
    assign fill_weight_axi.araddr  = 0; assign fill_weight_axi.arlen   = 0;
    assign fill_weight_axi.arsize  = 0; assign fill_weight_axi.arburst = 0;
    assign fill_weight_axi.rready  = 0;

    // fill_act_axi wiring (write only; read channels tied off)
    assign fill_act_axi.awvalid = fa_awvalid; assign fill_act_axi.awid    = fa_awid;
    assign fill_act_axi.awaddr  = fa_awaddr;  assign fill_act_axi.awlen   = fa_awlen;
    assign fill_act_axi.awsize  = fa_awsize;  assign fill_act_axi.awburst = fa_awburst;
    assign fa_awready           = fill_act_axi.awready;
    assign fill_act_axi.wvalid  = fa_wvalid;  assign fill_act_axi.wdata   = fa_wdata;
    assign fill_act_axi.wstrb   = fa_wstrb;   assign fill_act_axi.wlast   = fa_wlast;
    assign fa_wready            = fill_act_axi.wready;
    assign fa_bvalid            = fill_act_axi.bvalid; assign fa_bid  = fill_act_axi.bid;
    assign fa_bresp             = fill_act_axi.bresp;
    assign fill_act_axi.bready  = fa_bready;
    assign fill_act_axi.arvalid = 0; assign fill_act_axi.arid    = 0;
    assign fill_act_axi.araddr  = 0; assign fill_act_axi.arlen   = 0;
    assign fill_act_axi.arsize  = 0; assign fill_act_axi.arburst = 0;
    assign fill_act_axi.rready  = 0;

    // c2h_axi wiring (read only; write channels tied off)
    assign c2h_axi.arvalid = ob_arvalid; assign c2h_axi.arid    = ob_arid;
    assign c2h_axi.araddr  = ob_araddr;  assign c2h_axi.arlen   = ob_arlen;
    assign c2h_axi.arsize  = ob_arsize;  assign c2h_axi.arburst = ob_arburst;
    assign ob_arready      = c2h_axi.arready;
    assign ob_rvalid       = c2h_axi.rvalid;  assign ob_rid   = c2h_axi.rid;
    assign ob_rdata        = c2h_axi.rdata;   assign ob_rresp = c2h_axi.rresp;
    assign ob_rlast        = c2h_axi.rlast;
    assign c2h_axi.rready  = ob_rready;
    assign c2h_axi.awvalid = 0; assign c2h_axi.awid    = 0;
    assign c2h_axi.awaddr  = 0; assign c2h_axi.awlen   = 0;
    assign c2h_axi.awsize  = 0; assign c2h_axi.awburst = 0;
    assign c2h_axi.wvalid  = 0; assign c2h_axi.wdata   = 0;
    assign c2h_axi.wstrb   = 0; assign c2h_axi.wlast   = 0;
    assign c2h_axi.bready  = 0;

    // -----------------------------------------------------------------------
    // Internal signals
    // -----------------------------------------------------------------------

    logic        go;
    logic [7:0]  m_tiles, n_tiles, k_tiles;
    logic [63:0] base_addr_a, base_addr_b, base_addr_c;
    logic        ts_busy_i, ts_done_i;
    logic        swap, fill_weight_done, fill_act_done;
    logic        start, pass_done;
    logic        final_pass, row_valid, tile_done;
    logic [3:0]  weight_buf_addr, act_buf_addr;
    logic [7:0]  weight_buf_data [15:0], act_buf_data [15:0];
    logic [7:0]  weight_in [15:0], act_in [15:0];
    logic        weight_load_en;
    logic [31:0] col_out [15:0];
    logic        buf_wen;
    logic [3:0]  buf_row;
    logic [31:0] buf_data [15:0];

    assign ts_busy = ts_busy_i;
    assign ts_done = ts_done_i;

    // -----------------------------------------------------------------------
    // Instantiations
    // -----------------------------------------------------------------------

    csr_block u_csr (
        .csr_axi    (csr_axi),
        .go         (go),
        .m_tiles    (m_tiles),
        .n_tiles    (n_tiles),
        .k_tiles    (k_tiles),
        .ts_busy    (ts_busy_i),
        .ts_done    (ts_done_i),
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
        .ts_busy         (ts_busy_i),
        .ts_done         (ts_done_i),
        .tile_i          (tile_i),
        .tile_j          (tile_j),
        .k_tile          (k_tile),
        .fill_start      (fill_start),
        .writeback_start (writeback_start),
        .writeback_done  (writeback_done),
        .init_done       (init_done)
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
