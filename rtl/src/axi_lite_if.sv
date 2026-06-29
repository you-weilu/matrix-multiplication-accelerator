interface axi_lite_if #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32
) (
    input logic aclk,
    input logic aresetn
);

    // Write address channel
    logic                    awvalid;
    logic                    awready;
    logic [ADDR_WIDTH-1:0]   awaddr;
    logic [2:0]              awprot;

    // Write data channel
    logic                    wvalid;
    logic                    wready;
    logic [DATA_WIDTH-1:0]   wdata;
    logic [DATA_WIDTH/8-1:0] wstrb;

    // Write response channel
    logic                    bvalid;
    logic                    bready;
    logic [1:0]              bresp;

    // Read address channel
    logic                    arvalid;
    logic                    arready;
    logic [ADDR_WIDTH-1:0]   araddr;
    logic [2:0]              arprot;

    // Read data channel
    logic                    rvalid;
    logic                    rready;
    logic [DATA_WIDTH-1:0]   rdata;
    logic [1:0]              rresp;

    modport master (
        input  aclk, aresetn,
        output awvalid, awaddr, awprot,
        input  awready,
        output wvalid, wdata, wstrb,
        input  wready,
        input  bvalid, bresp,
        output bready,
        output arvalid, araddr, arprot,
        input  arready,
        input  rvalid, rdata, rresp,
        output rready
    );

    modport slave (
        input  aclk, aresetn,
        input  awvalid, awaddr, awprot,
        output awready,
        input  wvalid, wdata, wstrb,
        output wready,
        output bvalid, bresp,
        input  bready,
        input  arvalid, araddr, arprot,
        output arready,
        output rvalid, rdata, rresp,
        input  rready
    );

endinterface
