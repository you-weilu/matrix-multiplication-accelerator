// Wrapper that flattens axi_lite_if into plain ports for cocotb/icarus.
module csr_block_wrap (
    input  logic        clk,
    input  logic        rst_n,

    // AXI4-Lite write address channel
    input  logic [31:0] awaddr,
    input  logic [2:0]  awprot,
    input  logic        awvalid,
    output logic        awready,

    // AXI4-Lite write data channel
    input  logic [31:0] wdata,
    input  logic [3:0]  wstrb,
    input  logic        wvalid,
    output logic        wready,

    // AXI4-Lite write response channel
    output logic [1:0]  bresp,
    output logic        bvalid,
    input  logic        bready,

    // AXI4-Lite read address channel
    input  logic [31:0] araddr,
    input  logic [2:0]  arprot,
    input  logic        arvalid,
    output logic        arready,

    // AXI4-Lite read data channel
    output logic [31:0] rdata,
    output logic [1:0]  rresp,
    output logic        rvalid,
    input  logic        rready,

    // FSM outputs
    output logic        go,
    output logic [7:0]  m_tiles,
    output logic [7:0]  n_tiles,
    output logic [7:0]  k_tiles,

    // FSM inputs
    input  logic        ts_busy,
    input  logic        ts_done
);

    axi_lite_if #(.ADDR_WIDTH(32), .DATA_WIDTH(32)) csr_axi (.aclk(clk), .aresetn(rst_n));

    assign csr_axi.awaddr  = awaddr;
    assign csr_axi.awprot  = awprot;
    assign csr_axi.awvalid = awvalid;
    assign awready         = csr_axi.awready;

    assign csr_axi.wdata   = wdata;
    assign csr_axi.wstrb   = wstrb;
    assign csr_axi.wvalid  = wvalid;
    assign wready          = csr_axi.wready;

    assign bresp           = csr_axi.bresp;
    assign bvalid          = csr_axi.bvalid;
    assign csr_axi.bready  = bready;

    assign csr_axi.araddr  = araddr;
    assign csr_axi.arprot  = arprot;
    assign csr_axi.arvalid = arvalid;
    assign arready         = csr_axi.arready;

    assign rdata           = csr_axi.rdata;
    assign rresp           = csr_axi.rresp;
    assign rvalid          = csr_axi.rvalid;
    assign csr_axi.rready  = rready;

    csr_block dut (
        .csr_axi(csr_axi),
        .go     (go),
        .m_tiles(m_tiles),
        .n_tiles(n_tiles),
        .k_tiles(k_tiles),
        .ts_busy(ts_busy),
        .ts_done(ts_done)
    );

endmodule
