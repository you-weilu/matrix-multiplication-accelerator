// Wrapper that flattens axi_lite_if for cocotb/Verilator.
module dma_controller_wrap (
    input  logic        clk,
    input  logic        rst_n,

    // FSM control
    input  logic        fill_start,
    input  logic        writeback_start,
    input  logic [7:0]  tile_i,
    input  logic [7:0]  tile_j,
    input  logic [7:0]  k_tile,

    // CSR inputs
    input  logic [63:0] base_addr_a,
    input  logic [63:0] base_addr_b,
    input  logic [63:0] base_addr_c,
    input  logic [7:0]  k_tiles,
    input  logic [7:0]  n_tiles,

    // Card-side AXI base addresses
    input  logic [63:0] pp_weight_axi_base,
    input  logic [63:0] pp_act_axi_base,
    input  logic [63:0] output_buf_axi_base,

    // Outputs to FSM
    output logic        writeback_done,
    output logic        init_done,

    // AXI4-Lite (flattened master outputs / slave inputs)
    output logic        axil_awvalid,
    input  logic        axil_awready,
    output logic [31:0] axil_awaddr,
    output logic [2:0]  axil_awprot,

    output logic        axil_wvalid,
    input  logic        axil_wready,
    output logic [31:0] axil_wdata,
    output logic [3:0]  axil_wstrb,

    input  logic        axil_bvalid,
    output logic        axil_bready,
    input  logic [1:0]  axil_bresp,

    output logic        axil_arvalid,
    input  logic        axil_arready,
    output logic [31:0] axil_araddr,
    output logic [2:0]  axil_arprot,

    input  logic        axil_rvalid,
    output logic        axil_rready,
    input  logic [31:0] axil_rdata,
    input  logic [1:0]  axil_rresp,

    // H2C ch0 descriptor bypass
    input  logic        h2c_dsc_byp_ready_0,
    output logic        h2c_dsc_byp_load_0,
    output logic [63:0] h2c_dsc_byp_src_addr_0,
    output logic [63:0] h2c_dsc_byp_dst_addr_0,
    output logic [27:0] h2c_dsc_byp_len_0,
    output logic [15:0] h2c_dsc_byp_ctl_0,

    // H2C ch1 descriptor bypass
    input  logic        h2c_dsc_byp_ready_1,
    output logic        h2c_dsc_byp_load_1,
    output logic [63:0] h2c_dsc_byp_src_addr_1,
    output logic [63:0] h2c_dsc_byp_dst_addr_1,
    output logic [27:0] h2c_dsc_byp_len_1,
    output logic [15:0] h2c_dsc_byp_ctl_1,

    // C2H ch0 descriptor bypass
    input  logic        c2h_dsc_byp_ready_0,
    output logic        c2h_dsc_byp_load_0,
    output logic [63:0] c2h_dsc_byp_src_addr_0,
    output logic [63:0] c2h_dsc_byp_dst_addr_0,
    output logic [27:0] c2h_dsc_byp_len_0,
    output logic [15:0] c2h_dsc_byp_ctl_0,

    // XDMA channel status
    input  logic [7:0]  h2c_sts_0,
    input  logic [7:0]  h2c_sts_1,
    input  logic [7:0]  c2h_sts_0
);

    axi_lite_if #(.ADDR_WIDTH(32), .DATA_WIDTH(32)) axil (.aclk(clk), .aresetn(rst_n));

    // Connect flat ports to interface
    assign axil.awready = axil_awready;
    assign axil.wready  = axil_wready;
    assign axil.bvalid  = axil_bvalid;
    assign axil.bresp   = axil_bresp;
    assign axil.arready = axil_arready;
    assign axil.rvalid  = axil_rvalid;
    assign axil.rdata   = axil_rdata;
    assign axil.rresp   = axil_rresp;

    assign axil_awvalid = axil.awvalid;
    assign axil_awaddr  = axil.awaddr;
    assign axil_awprot  = axil.awprot;
    assign axil_wvalid  = axil.wvalid;
    assign axil_wdata   = axil.wdata;
    assign axil_wstrb   = axil.wstrb;
    assign axil_bready  = axil.bready;
    assign axil_arvalid = axil.arvalid;
    assign axil_araddr  = axil.araddr;
    assign axil_arprot  = axil.arprot;
    assign axil_rready  = axil.rready;

    dma_controller dut (
        .clk                   (clk),
        .rst_n                 (rst_n),
        .fill_start            (fill_start),
        .writeback_start       (writeback_start),
        .tile_i                (tile_i),
        .tile_j                (tile_j),
        .k_tile                (k_tile),
        .base_addr_a           (base_addr_a),
        .base_addr_b           (base_addr_b),
        .base_addr_c           (base_addr_c),
        .k_tiles               (k_tiles),
        .n_tiles               (n_tiles),
        .pp_weight_axi_base    (pp_weight_axi_base),
        .pp_act_axi_base       (pp_act_axi_base),
        .output_buf_axi_base   (output_buf_axi_base),
        .writeback_done        (writeback_done),
        .init_done             (init_done),
        .s_axil                (axil.master),
        .h2c_dsc_byp_ready_0  (h2c_dsc_byp_ready_0),
        .h2c_dsc_byp_load_0   (h2c_dsc_byp_load_0),
        .h2c_dsc_byp_src_addr_0(h2c_dsc_byp_src_addr_0),
        .h2c_dsc_byp_dst_addr_0(h2c_dsc_byp_dst_addr_0),
        .h2c_dsc_byp_len_0    (h2c_dsc_byp_len_0),
        .h2c_dsc_byp_ctl_0    (h2c_dsc_byp_ctl_0),
        .h2c_dsc_byp_ready_1  (h2c_dsc_byp_ready_1),
        .h2c_dsc_byp_load_1   (h2c_dsc_byp_load_1),
        .h2c_dsc_byp_src_addr_1(h2c_dsc_byp_src_addr_1),
        .h2c_dsc_byp_dst_addr_1(h2c_dsc_byp_dst_addr_1),
        .h2c_dsc_byp_len_1    (h2c_dsc_byp_len_1),
        .h2c_dsc_byp_ctl_1    (h2c_dsc_byp_ctl_1),
        .c2h_dsc_byp_ready_0  (c2h_dsc_byp_ready_0),
        .c2h_dsc_byp_load_0   (c2h_dsc_byp_load_0),
        .c2h_dsc_byp_src_addr_0(c2h_dsc_byp_src_addr_0),
        .c2h_dsc_byp_dst_addr_0(c2h_dsc_byp_dst_addr_0),
        .c2h_dsc_byp_len_0    (c2h_dsc_byp_len_0),
        .c2h_dsc_byp_ctl_0    (c2h_dsc_byp_ctl_0),
        .h2c_sts_0             (h2c_sts_0),
        .h2c_sts_1             (h2c_sts_1),
        .c2h_sts_0             (c2h_sts_0)
    );

endmodule
