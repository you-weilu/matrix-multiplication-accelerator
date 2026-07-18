// Wrapper that flattens axi4_if into plain ports for cocotb/verilator.
module output_buffer_wrap (
    input  logic         clk, rst_n,

    // Write port from accumulator bank
    input  logic         buf_wen,
    input  logic [3:0]   buf_row,
    input  logic [31:0]  buf_data [15:0],

    // AXI4 read address channel (testbench drives)
    input  logic         arvalid,
    input  logic [3:0]   arid,
    input  logic [63:0]  araddr,
    input  logic [7:0]   arlen,
    input  logic [2:0]   arsize,
    input  logic [1:0]   arburst,
    output logic         arready,

    // AXI4 read data channel (DUT drives)
    output logic         rvalid,
    output logic [3:0]   rid,
    output logic [127:0] rdata,
    output logic [1:0]   rresp,
    output logic         rlast,
    input  logic         rready
);
    axi4_if #(.ADDR_WIDTH(64), .DATA_WIDTH(128), .ID_WIDTH(4), .LEN_WIDTH(8)) c2h_axi (
        .aclk(clk), .aresetn(rst_n)
    );

    assign c2h_axi.arvalid = arvalid;
    assign c2h_axi.arid    = arid;
    assign c2h_axi.araddr  = araddr;
    assign c2h_axi.arlen   = arlen;
    assign c2h_axi.arsize  = arsize;
    assign c2h_axi.arburst = arburst;
    assign arready         = c2h_axi.arready;

    assign rvalid          = c2h_axi.rvalid;
    assign rid             = c2h_axi.rid;
    assign rdata           = c2h_axi.rdata;
    assign rresp           = c2h_axi.rresp;
    assign rlast           = c2h_axi.rlast;
    assign c2h_axi.rready  = rready;

    // Tie off write channels — testbench never writes to the output buffer
    assign c2h_axi.awvalid = 0;
    assign c2h_axi.awid    = 0;
    assign c2h_axi.awaddr  = 0;
    assign c2h_axi.awlen   = 0;
    assign c2h_axi.awsize  = 0;
    assign c2h_axi.awburst = 0;
    assign c2h_axi.wvalid  = 0;
    assign c2h_axi.wdata   = 0;
    assign c2h_axi.wstrb   = 0;
    assign c2h_axi.wlast   = 0;
    assign c2h_axi.bready  = 0;

    output_buffer dut (
        .clk     (clk),
        .rst_n   (rst_n),
        .buf_wen (buf_wen),
        .buf_row (buf_row),
        .buf_data(buf_data),
        .c2h_axi (c2h_axi)
    );

endmodule
