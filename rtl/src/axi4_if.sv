interface axi4_if #(
    parameter ADDR_WIDTH = 64,
    parameter DATA_WIDTH = 128,
    parameter ID_WIDTH   = 4,
    parameter LEN_WIDTH  = 8
) (
    input logic aclk,
    input logic aresetn
);

    // Write address channel
    logic                    awvalid;
    logic                    awready;
    logic [ID_WIDTH-1:0]     awid;
    logic [ADDR_WIDTH-1:0]   awaddr;
    logic [LEN_WIDTH-1:0]    awlen;
    logic [2:0]              awsize;
    logic [1:0]              awburst;

    // Write data channel
    logic                    wvalid;
    logic                    wready;
    logic [DATA_WIDTH-1:0]   wdata;
    logic [DATA_WIDTH/8-1:0] wstrb;
    logic                    wlast;

    // Write response channel
    logic                    bvalid;
    logic                    bready;
    logic [ID_WIDTH-1:0]     bid;
    logic [1:0]              bresp;

    // Read address channel
    logic                    arvalid;
    logic                    arready;
    logic [ID_WIDTH-1:0]     arid;
    logic [ADDR_WIDTH-1:0]   araddr;
    logic [LEN_WIDTH-1:0]    arlen;
    logic [2:0]              arsize;
    logic [1:0]              arburst;

    // Read data channel
    logic                    rvalid;
    logic                    rready;
    logic [ID_WIDTH-1:0]     rid;
    logic [DATA_WIDTH-1:0]   rdata;
    logic [1:0]              rresp;
    logic                    rlast;

    modport master (
        input  aclk, aresetn,
        output awvalid, awid, awaddr, awlen, awsize, awburst,
        input  awready,
        output wvalid, wdata, wstrb, wlast,
        input  wready,
        input  bvalid, bid, bresp,
        output bready,
        output arvalid, arid, araddr, arlen, arsize, arburst,
        input  arready,
        input  rvalid, rid, rdata, rresp, rlast,
        output rready
    );

    modport slave (
        input  aclk, aresetn,
        input  awvalid, awid, awaddr, awlen, awsize, awburst,
        output awready,
        input  wvalid, wdata, wstrb, wlast,
        output wready,
        output bvalid, bid, bresp,
        input  bready,
        input  arvalid, arid, araddr, arlen, arsize, arburst,
        output arready,
        output rvalid, rid, rdata, rresp, rlast,
        input  rready
    );

endinterface
