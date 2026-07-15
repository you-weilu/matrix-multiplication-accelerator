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
    VL_IN8(go,0,0);
    VL_IN8(m_tiles,7,0);
    VL_IN8(n_tiles,7,0);
    VL_IN8(k_tiles,7,0);
    VL_OUT8(swap,0,0);
    VL_IN8(fill_weight_done,0,0);
    VL_IN8(fill_act_done,0,0);
    VL_OUT8(start,0,0);
    VL_IN8(pass_done,0,0);
    VL_OUT8(final_pass,0,0);
    VL_IN8(tile_done,0,0);
    VL_OUT8(ts_busy,0,0);
    VL_OUT8(ts_done,0,0);
    VL_OUT8(tile_i,7,0);
    VL_OUT8(tile_j,7,0);
    VL_OUT8(k_tile,7,0);
    VL_OUT8(fill_start,0,0);
    VL_OUT8(writeback_start,0,0);
    VL_IN8(writeback_done,0,0);
    CData/*0:0*/ tile_sequencer_fsm__DOT__clk;
    CData/*0:0*/ tile_sequencer_fsm__DOT__rst_n;
    CData/*0:0*/ tile_sequencer_fsm__DOT__go;
    CData/*7:0*/ tile_sequencer_fsm__DOT__m_tiles;
    CData/*7:0*/ tile_sequencer_fsm__DOT__n_tiles;
    CData/*7:0*/ tile_sequencer_fsm__DOT__k_tiles;
    CData/*0:0*/ tile_sequencer_fsm__DOT__swap;
    CData/*0:0*/ tile_sequencer_fsm__DOT__fill_weight_done;
    CData/*0:0*/ tile_sequencer_fsm__DOT__fill_act_done;
    CData/*0:0*/ tile_sequencer_fsm__DOT__start;
    CData/*0:0*/ tile_sequencer_fsm__DOT__pass_done;
    CData/*0:0*/ tile_sequencer_fsm__DOT__final_pass;
    CData/*0:0*/ tile_sequencer_fsm__DOT__tile_done;
    CData/*0:0*/ tile_sequencer_fsm__DOT__ts_busy;
    CData/*0:0*/ tile_sequencer_fsm__DOT__ts_done;
    CData/*7:0*/ tile_sequencer_fsm__DOT__tile_i;
    CData/*7:0*/ tile_sequencer_fsm__DOT__tile_j;
    CData/*7:0*/ tile_sequencer_fsm__DOT__k_tile;
    CData/*0:0*/ tile_sequencer_fsm__DOT__fill_start;
    CData/*0:0*/ tile_sequencer_fsm__DOT__writeback_start;
    CData/*0:0*/ tile_sequencer_fsm__DOT__writeback_done;
    CData/*3:0*/ tile_sequencer_fsm__DOT__state;
    CData/*0:0*/ tile_sequencer_fsm__DOT__last_tile;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VicoPhaseResult;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tile_sequencer_fsm__DOT__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ __VactIterCount;
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
