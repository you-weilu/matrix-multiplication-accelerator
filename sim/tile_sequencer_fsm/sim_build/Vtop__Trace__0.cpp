// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+2,(vlSelfRef.go));
    bufp->chgCData(oldp+3,(vlSelfRef.m_tiles),8);
    bufp->chgCData(oldp+4,(vlSelfRef.n_tiles),8);
    bufp->chgCData(oldp+5,(vlSelfRef.k_tiles),8);
    bufp->chgBit(oldp+6,(vlSelfRef.swap));
    bufp->chgBit(oldp+7,(vlSelfRef.fill_weight_done));
    bufp->chgBit(oldp+8,(vlSelfRef.fill_act_done));
    bufp->chgBit(oldp+9,(vlSelfRef.start));
    bufp->chgBit(oldp+10,(vlSelfRef.pass_done));
    bufp->chgBit(oldp+11,(vlSelfRef.final_pass));
    bufp->chgBit(oldp+12,(vlSelfRef.tile_done));
    bufp->chgBit(oldp+13,(vlSelfRef.ts_busy));
    bufp->chgBit(oldp+14,(vlSelfRef.ts_done));
    bufp->chgCData(oldp+15,(vlSelfRef.tile_i),8);
    bufp->chgCData(oldp+16,(vlSelfRef.tile_j),8);
    bufp->chgCData(oldp+17,(vlSelfRef.k_tile),8);
    bufp->chgBit(oldp+18,(vlSelfRef.fill_start));
    bufp->chgBit(oldp+19,(vlSelfRef.writeback_start));
    bufp->chgBit(oldp+20,(vlSelfRef.writeback_done));
    bufp->chgBit(oldp+21,(vlSelfRef.tile_sequencer_fsm__DOT__clk));
    bufp->chgBit(oldp+22,(vlSelfRef.tile_sequencer_fsm__DOT__rst_n));
    bufp->chgBit(oldp+23,(vlSelfRef.tile_sequencer_fsm__DOT__go));
    bufp->chgCData(oldp+24,(vlSelfRef.tile_sequencer_fsm__DOT__m_tiles),8);
    bufp->chgCData(oldp+25,(vlSelfRef.tile_sequencer_fsm__DOT__n_tiles),8);
    bufp->chgCData(oldp+26,(vlSelfRef.tile_sequencer_fsm__DOT__k_tiles),8);
    bufp->chgBit(oldp+27,(vlSelfRef.tile_sequencer_fsm__DOT__swap));
    bufp->chgBit(oldp+28,(vlSelfRef.tile_sequencer_fsm__DOT__fill_weight_done));
    bufp->chgBit(oldp+29,(vlSelfRef.tile_sequencer_fsm__DOT__fill_act_done));
    bufp->chgBit(oldp+30,(vlSelfRef.tile_sequencer_fsm__DOT__start));
    bufp->chgBit(oldp+31,(vlSelfRef.tile_sequencer_fsm__DOT__pass_done));
    bufp->chgBit(oldp+32,(vlSelfRef.tile_sequencer_fsm__DOT__final_pass));
    bufp->chgBit(oldp+33,(vlSelfRef.tile_sequencer_fsm__DOT__tile_done));
    bufp->chgBit(oldp+34,(vlSelfRef.tile_sequencer_fsm__DOT__ts_busy));
    bufp->chgBit(oldp+35,(vlSelfRef.tile_sequencer_fsm__DOT__ts_done));
    bufp->chgCData(oldp+36,(vlSelfRef.tile_sequencer_fsm__DOT__tile_i),8);
    bufp->chgCData(oldp+37,(vlSelfRef.tile_sequencer_fsm__DOT__tile_j),8);
    bufp->chgCData(oldp+38,(vlSelfRef.tile_sequencer_fsm__DOT__k_tile),8);
    bufp->chgBit(oldp+39,(vlSelfRef.tile_sequencer_fsm__DOT__fill_start));
    bufp->chgBit(oldp+40,(vlSelfRef.tile_sequencer_fsm__DOT__writeback_start));
    bufp->chgBit(oldp+41,(vlSelfRef.tile_sequencer_fsm__DOT__writeback_done));
    bufp->chgCData(oldp+42,(vlSelfRef.tile_sequencer_fsm__DOT__state),4);
    bufp->chgBit(oldp+43,(vlSelfRef.tile_sequencer_fsm__DOT__last_tile));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
