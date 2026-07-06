// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(start,0,0);
    VL_OUT8(done,0,0);
    VL_OUT8(weight_buf_addr,3,0);
    VL_OUT8(act_buf_addr,3,0);
    VL_OUT8(weight_load_en,0,0);
    VL_OUT8(row_valid,0,0);
    CData/*0:0*/ systolic_data_setup__DOT__clk;
    CData/*0:0*/ systolic_data_setup__DOT__rst_n;
    CData/*0:0*/ systolic_data_setup__DOT__start;
    CData/*0:0*/ systolic_data_setup__DOT__done;
    CData/*3:0*/ systolic_data_setup__DOT__weight_buf_addr;
    CData/*3:0*/ systolic_data_setup__DOT__act_buf_addr;
    CData/*0:0*/ systolic_data_setup__DOT__weight_load_en;
    CData/*0:0*/ systolic_data_setup__DOT__row_valid;
    CData/*1:0*/ systolic_data_setup__DOT__state;
    CData/*4:0*/ systolic_data_setup__DOT__cycle;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__systolic_data_setup__DOT__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ systolic_data_setup__DOT__unnamedblk3__DOT__j;
    IData/*31:0*/ systolic_data_setup__DOT__unnamedblk4__DOT__i;
    IData/*31:0*/ systolic_data_setup__DOT__unnamedblk5__DOT__k;
    IData/*31:0*/ systolic_data_setup__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ systolic_data_setup__DOT__unnamedblk1__DOT__unnamedblk2__DOT__j;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 16> weight_buf_data;
    VlUnpacked<CData/*7:0*/, 16> act_buf_data;
    VlUnpacked<CData/*7:0*/, 16> weight_in;
    VlUnpacked<CData/*7:0*/, 16> act_in;
    VlUnpacked<CData/*7:0*/, 16> systolic_data_setup__DOT__weight_buf_data;
    VlUnpacked<CData/*7:0*/, 16> systolic_data_setup__DOT__act_buf_data;
    VlUnpacked<CData/*7:0*/, 16> systolic_data_setup__DOT__weight_in;
    VlUnpacked<CData/*7:0*/, 16> systolic_data_setup__DOT__act_in;
    VlUnpacked<VlUnpacked<CData/*7:0*/, 16>, 16> systolic_data_setup__DOT__buf_work;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlNBACommitQueue<VlUnpacked<CData/*7:0*/, 16>, false, CData/*7:0*/, 1> __VdlyCommitQueuesystolic_data_setup__DOT__weight_in;
    VlNBACommitQueue<VlUnpacked<VlUnpacked<CData/*7:0*/, 16>, 16>, false, CData/*7:0*/, 2> __VdlyCommitQueuesystolic_data_setup__DOT__buf_work;
    VlNBACommitQueue<VlUnpacked<CData/*7:0*/, 16>, false, CData/*7:0*/, 1> __VdlyCommitQueuesystolic_data_setup__DOT__act_in;

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
