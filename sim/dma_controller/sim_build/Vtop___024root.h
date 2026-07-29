// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop_axi_lite_if;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:
    // CELLS
    Vtop_axi_lite_if* __PVT__dma_controller_wrap__DOT__axil;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(fill_start,0,0);
        VL_IN8(writeback_start,0,0);
        VL_IN8(tile_i,7,0);
        VL_IN8(tile_j,7,0);
        VL_IN8(k_tile,7,0);
        VL_IN8(k_tiles,7,0);
        VL_IN8(n_tiles,7,0);
        VL_OUT8(writeback_done,0,0);
        VL_OUT8(init_done,0,0);
        VL_OUT8(axil_awvalid,0,0);
        VL_IN8(axil_awready,0,0);
        VL_OUT8(axil_awprot,2,0);
        VL_OUT8(axil_wvalid,0,0);
        VL_IN8(axil_wready,0,0);
        VL_OUT8(axil_wstrb,3,0);
        VL_IN8(axil_bvalid,0,0);
        VL_OUT8(axil_bready,0,0);
        VL_IN8(axil_bresp,1,0);
        VL_OUT8(axil_arvalid,0,0);
        VL_IN8(axil_arready,0,0);
        VL_OUT8(axil_arprot,2,0);
        VL_IN8(axil_rvalid,0,0);
        VL_OUT8(axil_rready,0,0);
        VL_IN8(axil_rresp,1,0);
        VL_IN8(h2c_dsc_byp_ready_0,0,0);
        VL_OUT8(h2c_dsc_byp_load_0,0,0);
        VL_IN8(h2c_dsc_byp_ready_1,0,0);
        VL_OUT8(h2c_dsc_byp_load_1,0,0);
        VL_IN8(c2h_dsc_byp_ready_0,0,0);
        VL_OUT8(c2h_dsc_byp_load_0,0,0);
        VL_IN8(h2c_sts_0,7,0);
        VL_IN8(h2c_sts_1,7,0);
        VL_IN8(c2h_sts_0,7,0);
        CData/*0:0*/ dma_controller_wrap__DOT__clk;
        CData/*0:0*/ dma_controller_wrap__DOT__rst_n;
        CData/*0:0*/ dma_controller_wrap__DOT__fill_start;
        CData/*0:0*/ dma_controller_wrap__DOT__writeback_start;
        CData/*7:0*/ dma_controller_wrap__DOT__tile_i;
        CData/*7:0*/ dma_controller_wrap__DOT__tile_j;
        CData/*7:0*/ dma_controller_wrap__DOT__k_tile;
        CData/*7:0*/ dma_controller_wrap__DOT__k_tiles;
        CData/*7:0*/ dma_controller_wrap__DOT__n_tiles;
        CData/*0:0*/ dma_controller_wrap__DOT__writeback_done;
        CData/*0:0*/ dma_controller_wrap__DOT__init_done;
        CData/*0:0*/ dma_controller_wrap__DOT__axil_awvalid;
        CData/*0:0*/ dma_controller_wrap__DOT__axil_awready;
        CData/*2:0*/ dma_controller_wrap__DOT__axil_awprot;
        CData/*0:0*/ dma_controller_wrap__DOT__axil_wvalid;
        CData/*0:0*/ dma_controller_wrap__DOT__axil_wready;
        CData/*3:0*/ dma_controller_wrap__DOT__axil_wstrb;
        CData/*0:0*/ dma_controller_wrap__DOT__axil_bvalid;
        CData/*0:0*/ dma_controller_wrap__DOT__axil_bready;
        CData/*1:0*/ dma_controller_wrap__DOT__axil_bresp;
        CData/*0:0*/ dma_controller_wrap__DOT__axil_arvalid;
        CData/*0:0*/ dma_controller_wrap__DOT__axil_arready;
        CData/*2:0*/ dma_controller_wrap__DOT__axil_arprot;
        CData/*0:0*/ dma_controller_wrap__DOT__axil_rvalid;
        CData/*0:0*/ dma_controller_wrap__DOT__axil_rready;
        CData/*1:0*/ dma_controller_wrap__DOT__axil_rresp;
        CData/*0:0*/ dma_controller_wrap__DOT__h2c_dsc_byp_ready_0;
        CData/*0:0*/ dma_controller_wrap__DOT__h2c_dsc_byp_load_0;
        CData/*0:0*/ dma_controller_wrap__DOT__h2c_dsc_byp_ready_1;
    };
    struct {
        CData/*0:0*/ dma_controller_wrap__DOT__h2c_dsc_byp_load_1;
        CData/*0:0*/ dma_controller_wrap__DOT__c2h_dsc_byp_ready_0;
        CData/*0:0*/ dma_controller_wrap__DOT__c2h_dsc_byp_load_0;
        CData/*7:0*/ dma_controller_wrap__DOT__h2c_sts_0;
        CData/*7:0*/ dma_controller_wrap__DOT__h2c_sts_1;
        CData/*7:0*/ dma_controller_wrap__DOT__c2h_sts_0;
        CData/*0:0*/ dma_controller_wrap__DOT__dut__DOT__clk;
        CData/*0:0*/ dma_controller_wrap__DOT__dut__DOT__rst_n;
        CData/*0:0*/ dma_controller_wrap__DOT__dut__DOT__fill_start;
        CData/*0:0*/ dma_controller_wrap__DOT__dut__DOT__writeback_start;
        CData/*7:0*/ dma_controller_wrap__DOT__dut__DOT__tile_i;
        CData/*7:0*/ dma_controller_wrap__DOT__dut__DOT__tile_j;
        CData/*7:0*/ dma_controller_wrap__DOT__dut__DOT__k_tile;
        CData/*7:0*/ dma_controller_wrap__DOT__dut__DOT__k_tiles;
        CData/*7:0*/ dma_controller_wrap__DOT__dut__DOT__n_tiles;
        CData/*0:0*/ dma_controller_wrap__DOT__dut__DOT__writeback_done;
        CData/*0:0*/ dma_controller_wrap__DOT__dut__DOT__init_done;
        CData/*0:0*/ dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ready_0;
        CData/*0:0*/ dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_0;
        CData/*0:0*/ dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ready_1;
        CData/*0:0*/ dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_1;
        CData/*0:0*/ dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_ready_0;
        CData/*0:0*/ dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_load_0;
        CData/*7:0*/ dma_controller_wrap__DOT__dut__DOT__h2c_sts_0;
        CData/*7:0*/ dma_controller_wrap__DOT__dut__DOT__h2c_sts_1;
        CData/*7:0*/ dma_controller_wrap__DOT__dut__DOT__c2h_sts_0;
        CData/*1:0*/ dma_controller_wrap__DOT__dut__DOT__w_state;
        CData/*1:0*/ dma_controller_wrap__DOT__dut__DOT__a_state;
        CData/*1:0*/ dma_controller_wrap__DOT__dut__DOT__c_state;
        CData/*1:0*/ dma_controller_wrap__DOT__dut__DOT__init_state;
        CData/*1:0*/ dma_controller_wrap__DOT__dut__DOT__reg_idx;
        CData/*1:0*/ __Vdly__dma_controller_wrap__DOT__dut__DOT__init_state;
        CData/*1:0*/ __Vdly__dma_controller_wrap__DOT__dut__DOT__reg_idx;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__dma_controller_wrap__DOT__dut__DOT__clk__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        VL_OUT16(h2c_dsc_byp_ctl_0,15,0);
        VL_OUT16(h2c_dsc_byp_ctl_1,15,0);
        VL_OUT16(c2h_dsc_byp_ctl_0,15,0);
        SData/*15:0*/ dma_controller_wrap__DOT__h2c_dsc_byp_ctl_0;
        SData/*15:0*/ dma_controller_wrap__DOT__h2c_dsc_byp_ctl_1;
        SData/*15:0*/ dma_controller_wrap__DOT__c2h_dsc_byp_ctl_0;
        SData/*15:0*/ dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ctl_0;
        SData/*15:0*/ dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ctl_1;
        SData/*15:0*/ dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_ctl_0;
        VL_OUT(axil_awaddr,31,0);
        VL_OUT(axil_wdata,31,0);
        VL_OUT(axil_araddr,31,0);
        VL_IN(axil_rdata,31,0);
        VL_OUT(h2c_dsc_byp_len_0,27,0);
        VL_OUT(h2c_dsc_byp_len_1,27,0);
        VL_OUT(c2h_dsc_byp_len_0,27,0);
        IData/*31:0*/ dma_controller_wrap__DOT__axil_awaddr;
        IData/*31:0*/ dma_controller_wrap__DOT__axil_wdata;
        IData/*31:0*/ dma_controller_wrap__DOT__axil_araddr;
        IData/*31:0*/ dma_controller_wrap__DOT__axil_rdata;
        IData/*27:0*/ dma_controller_wrap__DOT__h2c_dsc_byp_len_0;
        IData/*27:0*/ dma_controller_wrap__DOT__h2c_dsc_byp_len_1;
        IData/*27:0*/ dma_controller_wrap__DOT__c2h_dsc_byp_len_0;
        IData/*27:0*/ dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_len_0;
    };
    struct {
        IData/*27:0*/ dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_len_1;
        IData/*27:0*/ dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_len_0;
        IData/*31:0*/ __VactIterCount;
        VL_IN64(base_addr_a,63,0);
        VL_IN64(base_addr_b,63,0);
        VL_IN64(base_addr_c,63,0);
        VL_IN64(pp_weight_axi_base,63,0);
        VL_IN64(pp_act_axi_base,63,0);
        VL_IN64(output_buf_axi_base,63,0);
        VL_OUT64(h2c_dsc_byp_src_addr_0,63,0);
        VL_OUT64(h2c_dsc_byp_dst_addr_0,63,0);
        VL_OUT64(h2c_dsc_byp_src_addr_1,63,0);
        VL_OUT64(h2c_dsc_byp_dst_addr_1,63,0);
        VL_OUT64(c2h_dsc_byp_src_addr_0,63,0);
        VL_OUT64(c2h_dsc_byp_dst_addr_0,63,0);
        QData/*63:0*/ dma_controller_wrap__DOT__base_addr_a;
        QData/*63:0*/ dma_controller_wrap__DOT__base_addr_b;
        QData/*63:0*/ dma_controller_wrap__DOT__base_addr_c;
        QData/*63:0*/ dma_controller_wrap__DOT__pp_weight_axi_base;
        QData/*63:0*/ dma_controller_wrap__DOT__pp_act_axi_base;
        QData/*63:0*/ dma_controller_wrap__DOT__output_buf_axi_base;
        QData/*63:0*/ dma_controller_wrap__DOT__h2c_dsc_byp_src_addr_0;
        QData/*63:0*/ dma_controller_wrap__DOT__h2c_dsc_byp_dst_addr_0;
        QData/*63:0*/ dma_controller_wrap__DOT__h2c_dsc_byp_src_addr_1;
        QData/*63:0*/ dma_controller_wrap__DOT__h2c_dsc_byp_dst_addr_1;
        QData/*63:0*/ dma_controller_wrap__DOT__c2h_dsc_byp_src_addr_0;
        QData/*63:0*/ dma_controller_wrap__DOT__c2h_dsc_byp_dst_addr_0;
        QData/*63:0*/ dma_controller_wrap__DOT__dut__DOT__base_addr_a;
        QData/*63:0*/ dma_controller_wrap__DOT__dut__DOT__base_addr_b;
        QData/*63:0*/ dma_controller_wrap__DOT__dut__DOT__base_addr_c;
        QData/*63:0*/ dma_controller_wrap__DOT__dut__DOT__pp_weight_axi_base;
        QData/*63:0*/ dma_controller_wrap__DOT__dut__DOT__pp_act_axi_base;
        QData/*63:0*/ dma_controller_wrap__DOT__dut__DOT__output_buf_axi_base;
        QData/*63:0*/ dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_src_addr_0;
        QData/*63:0*/ dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_dst_addr_0;
        QData/*63:0*/ dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_src_addr_1;
        QData/*63:0*/ dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_dst_addr_1;
        QData/*63:0*/ dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_src_addr_0;
        QData/*63:0*/ dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_dst_addr_0;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr VlUnpacked<IData/*31:0*/, 3> dma_controller_wrap__DOT__dut__DOT__INIT_ADDRS = {{
        4U, 0x00001004U, 0x00010004U
    }};

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
