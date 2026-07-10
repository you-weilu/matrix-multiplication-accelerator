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
    Vtop_axi_lite_if* __PVT__csr_block_wrap__DOT__csr_axi;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(awprot,2,0);
        VL_IN8(awvalid,0,0);
        VL_OUT8(awready,0,0);
        VL_IN8(wstrb,3,0);
        VL_IN8(wvalid,0,0);
        VL_OUT8(wready,0,0);
        VL_OUT8(bresp,1,0);
        VL_OUT8(bvalid,0,0);
        VL_IN8(bready,0,0);
        VL_IN8(arprot,2,0);
        VL_IN8(arvalid,0,0);
        VL_OUT8(arready,0,0);
        VL_OUT8(rresp,1,0);
        VL_OUT8(rvalid,0,0);
        VL_IN8(rready,0,0);
        VL_OUT8(go,0,0);
        VL_OUT8(m_tiles,7,0);
        VL_OUT8(n_tiles,7,0);
        VL_OUT8(k_tiles,7,0);
        VL_IN8(ts_busy,0,0);
        VL_IN8(ts_done,0,0);
        CData/*0:0*/ csr_block_wrap__DOT__clk;
        CData/*0:0*/ csr_block_wrap__DOT__rst_n;
        CData/*2:0*/ csr_block_wrap__DOT__awprot;
        CData/*0:0*/ csr_block_wrap__DOT__awvalid;
        CData/*0:0*/ csr_block_wrap__DOT__awready;
        CData/*3:0*/ csr_block_wrap__DOT__wstrb;
        CData/*0:0*/ csr_block_wrap__DOT__wvalid;
        CData/*0:0*/ csr_block_wrap__DOT__wready;
        CData/*1:0*/ csr_block_wrap__DOT__bresp;
        CData/*0:0*/ csr_block_wrap__DOT__bvalid;
        CData/*0:0*/ csr_block_wrap__DOT__bready;
        CData/*2:0*/ csr_block_wrap__DOT__arprot;
        CData/*0:0*/ csr_block_wrap__DOT__arvalid;
        CData/*0:0*/ csr_block_wrap__DOT__arready;
        CData/*1:0*/ csr_block_wrap__DOT__rresp;
        CData/*0:0*/ csr_block_wrap__DOT__rvalid;
        CData/*0:0*/ csr_block_wrap__DOT__rready;
        CData/*0:0*/ csr_block_wrap__DOT__go;
        CData/*7:0*/ csr_block_wrap__DOT__m_tiles;
        CData/*7:0*/ csr_block_wrap__DOT__n_tiles;
        CData/*7:0*/ csr_block_wrap__DOT__k_tiles;
        CData/*0:0*/ csr_block_wrap__DOT__ts_busy;
        CData/*0:0*/ csr_block_wrap__DOT__ts_done;
        CData/*0:0*/ csr_block_wrap__DOT__dut__DOT__go;
        CData/*7:0*/ csr_block_wrap__DOT__dut__DOT__m_tiles;
        CData/*7:0*/ csr_block_wrap__DOT__dut__DOT__n_tiles;
        CData/*7:0*/ csr_block_wrap__DOT__dut__DOT__k_tiles;
        CData/*0:0*/ csr_block_wrap__DOT__dut__DOT__ts_busy;
        CData/*0:0*/ csr_block_wrap__DOT__dut__DOT__ts_done;
        CData/*0:0*/ csr_block_wrap__DOT__dut__DOT__clk;
        CData/*0:0*/ csr_block_wrap__DOT__dut__DOT__rst_n;
        CData/*0:0*/ csr_block_wrap__DOT__dut__DOT__reg_go;
        CData/*7:0*/ csr_block_wrap__DOT__dut__DOT__reg_m_tiles;
        CData/*7:0*/ csr_block_wrap__DOT__dut__DOT__reg_n_tiles;
        CData/*7:0*/ csr_block_wrap__DOT__dut__DOT__reg_k_tiles;
        CData/*0:0*/ csr_block_wrap__DOT__dut__DOT__reg_done;
        CData/*4:0*/ csr_block_wrap__DOT__dut__DOT__wr_addr_lat;
        CData/*0:0*/ csr_block_wrap__DOT__dut__DOT__wr_commit;
        CData/*1:0*/ csr_block_wrap__DOT__dut__DOT__wr_state;
        CData/*0:0*/ csr_block_wrap__DOT__dut__DOT__rd_state;
        CData/*1:0*/ __Vdly__csr_block_wrap__DOT__dut__DOT__wr_state;
    };
    struct {
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __VicoPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__csr_block_wrap__DOT__dut__DOT__clk__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        VL_IN(awaddr,31,0);
        VL_IN(wdata,31,0);
        VL_IN(araddr,31,0);
        VL_OUT(rdata,31,0);
        IData/*31:0*/ csr_block_wrap__DOT__awaddr;
        IData/*31:0*/ csr_block_wrap__DOT__wdata;
        IData/*31:0*/ csr_block_wrap__DOT__araddr;
        IData/*31:0*/ csr_block_wrap__DOT__rdata;
        IData/*31:0*/ csr_block_wrap__DOT__dut__DOT__wr_data_lat;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
