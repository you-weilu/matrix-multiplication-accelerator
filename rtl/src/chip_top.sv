module chip_top (
    // PCIe reference clock — differential pair from PCIe slot
    input  logic        diff_clock_rtl_0_clk_p,
    input  logic        diff_clock_rtl_0_clk_n,

    // PCIe reset (active low, from PCIe slot or board supervisor)
    input  logic        reset_rtl_0,

    // PCIe MGT — physical high-speed serial transceiver lanes
    input  logic [3:0]  pcie_7x_mgt_rtl_0_rxp,
    input  logic [3:0]  pcie_7x_mgt_rtl_0_rxn,
    output logic [3:0]  pcie_7x_mgt_rtl_0_txp,
    output logic [3:0]  pcie_7x_mgt_rtl_0_txn,

    // PCIe link status — goes high when host enumerates the device
    output logic        user_lnk_up_0
);

    // AXI clock and reset driven by XDMA; all user logic runs on these
    logic axi_aclk, axi_aresetn;

    // -------------------------------------------------------------------------
    // AXI interface instances — all share the same clock and reset from XDMA
    // -------------------------------------------------------------------------

    // XDMA M_AXI_LITE master → csr_block slave (host CSR access path)
    axi_lite_if csr_if (.aclk(axi_aclk), .aresetn(axi_aresetn));

    // DMA controller master → XDMA S_AXI_LITE slave (one-time Run bit init)
    axi_lite_if dma_axil_if (.aclk(axi_aclk), .aresetn(axi_aresetn));

    // SmartConnect M00 → weight ping-pong buffer
    axi4_if weight_if (.aclk(axi_aclk), .aresetn(axi_aresetn));

    // SmartConnect M01 → activation ping-pong buffer
    axi4_if act_if (.aclk(axi_aclk), .aresetn(axi_aresetn));

    // SmartConnect M02 → output buffer
    axi4_if c2h_if (.aclk(axi_aclk), .aresetn(axi_aresetn));

    // -------------------------------------------------------------------------
    // Descriptor bypass signals
    // -------------------------------------------------------------------------

    logic        h2c_byp_rdy_0, h2c_byp_ld_0;
    logic [63:0] h2c_byp_src_0, h2c_byp_dst_0;
    logic [27:0] h2c_byp_len_0;
    logic [15:0] h2c_byp_ctl_0;

    logic        h2c_byp_rdy_1, h2c_byp_ld_1;
    logic [63:0] h2c_byp_src_1, h2c_byp_dst_1;
    logic [27:0] h2c_byp_len_1;
    logic [15:0] h2c_byp_ctl_1;

    logic        c2h_byp_rdy_0, c2h_byp_ld_0;
    logic [63:0] c2h_byp_src_0, c2h_byp_dst_0;
    logic [27:0] c2h_byp_len_0;
    logic [15:0] c2h_byp_ctl_0;

    // DMA channel completion status
    logic [7:0] h2c_sts_0, h2c_sts_1, c2h_sts_0_sig;

    // -------------------------------------------------------------------------
    // Block design (XDMA + SmartConnect infrastructure)
    // Instantiated directly to use flat signals, bypassing the SV wrapper
    // -------------------------------------------------------------------------

    gemm_bd u_bd (
        // PCIe physical interface
        .diff_clock_rtl_0_clk_p            (diff_clock_rtl_0_clk_p),
        .diff_clock_rtl_0_clk_n            (diff_clock_rtl_0_clk_n),
        .pcie_7x_mgt_rtl_0_rxp             (pcie_7x_mgt_rtl_0_rxp),
        .pcie_7x_mgt_rtl_0_rxn             (pcie_7x_mgt_rtl_0_rxn),
        .pcie_7x_mgt_rtl_0_txp             (pcie_7x_mgt_rtl_0_txp),
        .pcie_7x_mgt_rtl_0_txn             (pcie_7x_mgt_rtl_0_txn),
        .reset_rtl_0                        (reset_rtl_0),

        // Clock and reset outputs to user logic
        .axi_aclk_0                         (axi_aclk),
        .axi_aresetn_0                      (axi_aresetn),
        .user_lnk_up_0                      (user_lnk_up_0),

        // S_AXI_LITE: DMA controller → XDMA internal registers (Run bit init)
        .S_AXI_LITE_0_awvalid              (dma_axil_if.awvalid),
        .S_AXI_LITE_0_awready              (dma_axil_if.awready),
        .S_AXI_LITE_0_awaddr               (dma_axil_if.awaddr),
        .S_AXI_LITE_0_awprot               (dma_axil_if.awprot),
        .S_AXI_LITE_0_wvalid               (dma_axil_if.wvalid),
        .S_AXI_LITE_0_wready               (dma_axil_if.wready),
        .S_AXI_LITE_0_wdata                (dma_axil_if.wdata),
        .S_AXI_LITE_0_wstrb                (dma_axil_if.wstrb),
        .S_AXI_LITE_0_bvalid               (dma_axil_if.bvalid),
        .S_AXI_LITE_0_bready               (dma_axil_if.bready),
        .S_AXI_LITE_0_bresp                (dma_axil_if.bresp),
        .S_AXI_LITE_0_arvalid              (dma_axil_if.arvalid),
        .S_AXI_LITE_0_arready              (dma_axil_if.arready),
        .S_AXI_LITE_0_araddr               (dma_axil_if.araddr),
        .S_AXI_LITE_0_arprot               (dma_axil_if.arprot),
        .S_AXI_LITE_0_rvalid               (dma_axil_if.rvalid),
        .S_AXI_LITE_0_rready               (dma_axil_if.rready),
        .S_AXI_LITE_0_rdata                (dma_axil_if.rdata),
        .S_AXI_LITE_0_rresp                (dma_axil_if.rresp),

        // M_AXI_LITE: XDMA → csr_block (host CSR register access)
        .M_AXI_LITE_0_awvalid              (csr_if.awvalid),
        .M_AXI_LITE_0_awready              (csr_if.awready),
        .M_AXI_LITE_0_awaddr               (csr_if.awaddr),
        .M_AXI_LITE_0_awprot               (csr_if.awprot),
        .M_AXI_LITE_0_wvalid               (csr_if.wvalid),
        .M_AXI_LITE_0_wready               (csr_if.wready),
        .M_AXI_LITE_0_wdata                (csr_if.wdata),
        .M_AXI_LITE_0_wstrb                (csr_if.wstrb),
        .M_AXI_LITE_0_bvalid               (csr_if.bvalid),
        .M_AXI_LITE_0_bready               (csr_if.bready),
        .M_AXI_LITE_0_bresp                (csr_if.bresp),
        .M_AXI_LITE_0_arvalid              (csr_if.arvalid),
        .M_AXI_LITE_0_arready              (csr_if.arready),
        .M_AXI_LITE_0_araddr               (csr_if.araddr),
        .M_AXI_LITE_0_arprot               (csr_if.arprot),
        .M_AXI_LITE_0_rvalid               (csr_if.rvalid),
        .M_AXI_LITE_0_rready               (csr_if.rready),
        .M_AXI_LITE_0_rdata                (csr_if.rdata),
        .M_AXI_LITE_0_rresp                (csr_if.rresp),

        // M00_AXI: SmartConnect → weight ping-pong buffer
        .M00_AXI_0_awvalid                 (weight_if.awvalid),
        .M00_AXI_0_awready                 (weight_if.awready),
        .M00_AXI_0_awaddr                  (weight_if.awaddr),
        .M00_AXI_0_awlen                   (weight_if.awlen),
        .M00_AXI_0_awsize                  (weight_if.awsize),
        .M00_AXI_0_awburst                 (weight_if.awburst),
        .M00_AXI_0_awlock                  (),
        .M00_AXI_0_awcache                 (),
        .M00_AXI_0_awprot                  (),
        .M00_AXI_0_awqos                   (),
        .M00_AXI_0_wvalid                  (weight_if.wvalid),
        .M00_AXI_0_wready                  (weight_if.wready),
        .M00_AXI_0_wdata                   (weight_if.wdata),
        .M00_AXI_0_wstrb                   (weight_if.wstrb),
        .M00_AXI_0_wlast                   (weight_if.wlast),
        .M00_AXI_0_bvalid                  (weight_if.bvalid),
        .M00_AXI_0_bready                  (weight_if.bready),
        .M00_AXI_0_bresp                   (weight_if.bresp),
        .M00_AXI_0_arvalid                 (weight_if.arvalid),
        .M00_AXI_0_arready                 (weight_if.arready),
        .M00_AXI_0_araddr                  (weight_if.araddr),
        .M00_AXI_0_arlen                   (weight_if.arlen),
        .M00_AXI_0_arsize                  (weight_if.arsize),
        .M00_AXI_0_arburst                 (weight_if.arburst),
        .M00_AXI_0_arlock                  (),
        .M00_AXI_0_arcache                 (),
        .M00_AXI_0_arprot                  (),
        .M00_AXI_0_arqos                   (),
        .M00_AXI_0_rvalid                  (weight_if.rvalid),
        .M00_AXI_0_rready                  (weight_if.rready),
        .M00_AXI_0_rdata                   (weight_if.rdata),
        .M00_AXI_0_rresp                   (weight_if.rresp),
        .M00_AXI_0_rlast                   (weight_if.rlast),

        // M01_AXI: SmartConnect → activation ping-pong buffer
        .M01_AXI_0_awvalid                 (act_if.awvalid),
        .M01_AXI_0_awready                 (act_if.awready),
        .M01_AXI_0_awaddr                  (act_if.awaddr),
        .M01_AXI_0_awlen                   (act_if.awlen),
        .M01_AXI_0_awsize                  (act_if.awsize),
        .M01_AXI_0_awburst                 (act_if.awburst),
        .M01_AXI_0_awlock                  (),
        .M01_AXI_0_awcache                 (),
        .M01_AXI_0_awprot                  (),
        .M01_AXI_0_awqos                   (),
        .M01_AXI_0_wvalid                  (act_if.wvalid),
        .M01_AXI_0_wready                  (act_if.wready),
        .M01_AXI_0_wdata                   (act_if.wdata),
        .M01_AXI_0_wstrb                   (act_if.wstrb),
        .M01_AXI_0_wlast                   (act_if.wlast),
        .M01_AXI_0_bvalid                  (act_if.bvalid),
        .M01_AXI_0_bready                  (act_if.bready),
        .M01_AXI_0_bresp                   (act_if.bresp),
        .M01_AXI_0_arvalid                 (act_if.arvalid),
        .M01_AXI_0_arready                 (act_if.arready),
        .M01_AXI_0_araddr                  (act_if.araddr),
        .M01_AXI_0_arlen                   (act_if.arlen),
        .M01_AXI_0_arsize                  (act_if.arsize),
        .M01_AXI_0_arburst                 (act_if.arburst),
        .M01_AXI_0_arlock                  (),
        .M01_AXI_0_arcache                 (),
        .M01_AXI_0_arprot                  (),
        .M01_AXI_0_arqos                   (),
        .M01_AXI_0_rvalid                  (act_if.rvalid),
        .M01_AXI_0_rready                  (act_if.rready),
        .M01_AXI_0_rdata                   (act_if.rdata),
        .M01_AXI_0_rresp                   (act_if.rresp),
        .M01_AXI_0_rlast                   (act_if.rlast),

        // M02_AXI: SmartConnect → output buffer (C2H readback)
        .M02_AXI_0_awvalid                 (c2h_if.awvalid),
        .M02_AXI_0_awready                 (c2h_if.awready),
        .M02_AXI_0_awaddr                  (c2h_if.awaddr),
        .M02_AXI_0_awlen                   (c2h_if.awlen),
        .M02_AXI_0_awsize                  (c2h_if.awsize),
        .M02_AXI_0_awburst                 (c2h_if.awburst),
        .M02_AXI_0_awlock                  (),
        .M02_AXI_0_awcache                 (),
        .M02_AXI_0_awprot                  (),
        .M02_AXI_0_awqos                   (),
        .M02_AXI_0_wvalid                  (c2h_if.wvalid),
        .M02_AXI_0_wready                  (c2h_if.wready),
        .M02_AXI_0_wdata                   (c2h_if.wdata),
        .M02_AXI_0_wstrb                   (c2h_if.wstrb),
        .M02_AXI_0_wlast                   (c2h_if.wlast),
        .M02_AXI_0_bvalid                  (c2h_if.bvalid),
        .M02_AXI_0_bready                  (c2h_if.bready),
        .M02_AXI_0_bresp                   (c2h_if.bresp),
        .M02_AXI_0_arvalid                 (c2h_if.arvalid),
        .M02_AXI_0_arready                 (c2h_if.arready),
        .M02_AXI_0_araddr                  (c2h_if.araddr),
        .M02_AXI_0_arlen                   (c2h_if.arlen),
        .M02_AXI_0_arsize                  (c2h_if.arsize),
        .M02_AXI_0_arburst                 (c2h_if.arburst),
        .M02_AXI_0_arlock                  (),
        .M02_AXI_0_arcache                 (),
        .M02_AXI_0_arprot                  (),
        .M02_AXI_0_arqos                   (),
        .M02_AXI_0_rvalid                  (c2h_if.rvalid),
        .M02_AXI_0_rready                  (c2h_if.rready),
        .M02_AXI_0_rdata                   (c2h_if.rdata),
        .M02_AXI_0_rresp                   (c2h_if.rresp),
        .M02_AXI_0_rlast                   (c2h_if.rlast),

        // Descriptor bypass — H2C ch0 (weight tile)
        .dsc_bypass_h2c_0_0_dsc_byp_ready  (h2c_byp_rdy_0),
        .dsc_bypass_h2c_0_0_dsc_byp_load   (h2c_byp_ld_0),
        .dsc_bypass_h2c_0_0_dsc_byp_src_addr(h2c_byp_src_0),
        .dsc_bypass_h2c_0_0_dsc_byp_dst_addr(h2c_byp_dst_0),
        .dsc_bypass_h2c_0_0_dsc_byp_len    (h2c_byp_len_0),
        .dsc_bypass_h2c_0_0_dsc_byp_ctl    (h2c_byp_ctl_0),

        // Descriptor bypass — H2C ch1 (activation tile)
        .dsc_bypass_h2c_1_0_dsc_byp_ready  (h2c_byp_rdy_1),
        .dsc_bypass_h2c_1_0_dsc_byp_load   (h2c_byp_ld_1),
        .dsc_bypass_h2c_1_0_dsc_byp_src_addr(h2c_byp_src_1),
        .dsc_bypass_h2c_1_0_dsc_byp_dst_addr(h2c_byp_dst_1),
        .dsc_bypass_h2c_1_0_dsc_byp_len    (h2c_byp_len_1),
        .dsc_bypass_h2c_1_0_dsc_byp_ctl    (h2c_byp_ctl_1),

        // Descriptor bypass — C2H ch0 (output tile writeback)
        .dsc_bypass_c2h_0_0_dsc_byp_ready  (c2h_byp_rdy_0),
        .dsc_bypass_c2h_0_0_dsc_byp_load   (c2h_byp_ld_0),
        .dsc_bypass_c2h_0_0_dsc_byp_src_addr(c2h_byp_src_0),
        .dsc_bypass_c2h_0_0_dsc_byp_dst_addr(c2h_byp_dst_0),
        .dsc_bypass_c2h_0_0_dsc_byp_len    (c2h_byp_len_0),
        .dsc_bypass_c2h_0_0_dsc_byp_ctl    (c2h_byp_ctl_0),

        // DMA channel completion status
        .dma_status_ports_0_h2c_sts0       (h2c_sts_0),
        .dma_status_ports_0_h2c_sts1       (h2c_sts_1),
        .dma_status_ports_0_c2h_sts0       (c2h_sts_0_sig)
    );

    // -------------------------------------------------------------------------
    // User logic
    // -------------------------------------------------------------------------

    top u_top (
        .csr_axi                (csr_if.slave),
        .s_axil                 (dma_axil_if.master),
        .fill_weight_axi        (weight_if.slave),
        .fill_act_axi           (act_if.slave),
        .c2h_axi                (c2h_if.slave),

        // Descriptor bypass — H2C ch0
        .h2c_dsc_byp_ready_0   (h2c_byp_rdy_0),
        .h2c_dsc_byp_load_0    (h2c_byp_ld_0),
        .h2c_dsc_byp_src_addr_0(h2c_byp_src_0),
        .h2c_dsc_byp_dst_addr_0(h2c_byp_dst_0),
        .h2c_dsc_byp_len_0     (h2c_byp_len_0),
        .h2c_dsc_byp_ctl_0     (h2c_byp_ctl_0),

        // Descriptor bypass — H2C ch1
        .h2c_dsc_byp_ready_1   (h2c_byp_rdy_1),
        .h2c_dsc_byp_load_1    (h2c_byp_ld_1),
        .h2c_dsc_byp_src_addr_1(h2c_byp_src_1),
        .h2c_dsc_byp_dst_addr_1(h2c_byp_dst_1),
        .h2c_dsc_byp_len_1     (h2c_byp_len_1),
        .h2c_dsc_byp_ctl_1     (h2c_byp_ctl_1),

        // Descriptor bypass — C2H ch0
        .c2h_dsc_byp_ready_0   (c2h_byp_rdy_0),
        .c2h_dsc_byp_load_0    (c2h_byp_ld_0),
        .c2h_dsc_byp_src_addr_0(c2h_byp_src_0),
        .c2h_dsc_byp_dst_addr_0(c2h_byp_dst_0),
        .c2h_dsc_byp_len_0     (c2h_byp_len_0),
        .c2h_dsc_byp_ctl_0     (c2h_byp_ctl_0),

        // DMA channel completion status
        .h2c_sts_0             (h2c_sts_0),
        .h2c_sts_1             (h2c_sts_1),
        .c2h_sts_0             (c2h_sts_0_sig)
    );

endmodule
