// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"
class Vtop_axi4_if;


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:
    // CELLS
    Vtop_axi4_if* __PVT__output_buffer_wrap__DOT__c2h_axi;

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(buf_wen,0,0);
    VL_IN8(buf_row,3,0);
    VL_IN8(arvalid,0,0);
    VL_IN8(arid,3,0);
    VL_IN8(arlen,7,0);
    VL_IN8(arsize,2,0);
    VL_IN8(arburst,1,0);
    VL_OUT8(arready,0,0);
    VL_OUT8(rvalid,0,0);
    VL_OUT8(rid,3,0);
    VL_OUT8(rresp,1,0);
    VL_OUT8(rlast,0,0);
    VL_IN8(rready,0,0);
    CData/*0:0*/ output_buffer_wrap__DOT__clk;
    CData/*0:0*/ output_buffer_wrap__DOT__rst_n;
    CData/*0:0*/ output_buffer_wrap__DOT__buf_wen;
    CData/*3:0*/ output_buffer_wrap__DOT__buf_row;
    CData/*0:0*/ output_buffer_wrap__DOT__arvalid;
    CData/*3:0*/ output_buffer_wrap__DOT__arid;
    CData/*7:0*/ output_buffer_wrap__DOT__arlen;
    CData/*2:0*/ output_buffer_wrap__DOT__arsize;
    CData/*1:0*/ output_buffer_wrap__DOT__arburst;
    CData/*0:0*/ output_buffer_wrap__DOT__arready;
    CData/*0:0*/ output_buffer_wrap__DOT__rvalid;
    CData/*3:0*/ output_buffer_wrap__DOT__rid;
    CData/*1:0*/ output_buffer_wrap__DOT__rresp;
    CData/*0:0*/ output_buffer_wrap__DOT__rlast;
    CData/*0:0*/ output_buffer_wrap__DOT__rready;
    CData/*0:0*/ output_buffer_wrap__DOT__dut__DOT__clk;
    CData/*0:0*/ output_buffer_wrap__DOT__dut__DOT__rst_n;
    CData/*0:0*/ output_buffer_wrap__DOT__dut__DOT__buf_wen;
    CData/*3:0*/ output_buffer_wrap__DOT__dut__DOT__buf_row;
    CData/*0:0*/ output_buffer_wrap__DOT__dut__DOT__state;
    CData/*5:0*/ output_buffer_wrap__DOT__dut__DOT__beat_addr;
    CData/*7:0*/ output_buffer_wrap__DOT__dut__DOT__beat_count;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__output_buffer_wrap__DOT__dut__DOT__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    VL_OUTW(rdata,127,0,4);
    VlWide<4>/*127:0*/ output_buffer_wrap__DOT__rdata;
    IData/*31:0*/ __VactIterCount;
    VL_IN64(araddr,63,0);
    QData/*63:0*/ output_buffer_wrap__DOT__araddr;
    VlUnpacked<IData/*31:0*/, 16> buf_data;
    VlUnpacked<IData/*31:0*/, 16> output_buffer_wrap__DOT__buf_data;
    VlUnpacked<IData/*31:0*/, 16> output_buffer_wrap__DOT__dut__DOT__buf_data;
    VlUnpacked<VlWide<4>/*127:0*/, 64> output_buffer_wrap__DOT__dut__DOT__mem;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

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
