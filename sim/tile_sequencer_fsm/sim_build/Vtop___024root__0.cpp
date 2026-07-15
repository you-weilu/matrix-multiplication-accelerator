// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VicoTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_ico
            if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
                {
                    // Inlined CFunc: _ico_sequent__TOP__0
                    vlSelfRef.tile_sequencer_fsm__DOT__clk 
                        = vlSelfRef.clk;
                    vlSelfRef.tile_sequencer_fsm__DOT__rst_n 
                        = vlSelfRef.rst_n;
                    vlSelfRef.tile_sequencer_fsm__DOT__go 
                        = vlSelfRef.go;
                    vlSelfRef.tile_sequencer_fsm__DOT__m_tiles 
                        = vlSelfRef.m_tiles;
                    vlSelfRef.tile_sequencer_fsm__DOT__n_tiles 
                        = vlSelfRef.n_tiles;
                    vlSelfRef.tile_sequencer_fsm__DOT__k_tiles 
                        = vlSelfRef.k_tiles;
                    vlSelfRef.swap = vlSelfRef.tile_sequencer_fsm__DOT__swap;
                    vlSelfRef.tile_sequencer_fsm__DOT__fill_weight_done 
                        = vlSelfRef.fill_weight_done;
                    vlSelfRef.tile_sequencer_fsm__DOT__fill_act_done 
                        = vlSelfRef.fill_act_done;
                    vlSelfRef.start = vlSelfRef.tile_sequencer_fsm__DOT__start;
                    vlSelfRef.tile_sequencer_fsm__DOT__pass_done 
                        = vlSelfRef.pass_done;
                    vlSelfRef.final_pass = vlSelfRef.tile_sequencer_fsm__DOT__final_pass;
                    vlSelfRef.tile_sequencer_fsm__DOT__tile_done 
                        = vlSelfRef.tile_done;
                    vlSelfRef.ts_busy = vlSelfRef.tile_sequencer_fsm__DOT__ts_busy;
                    vlSelfRef.ts_done = vlSelfRef.tile_sequencer_fsm__DOT__ts_done;
                    vlSelfRef.tile_i = vlSelfRef.tile_sequencer_fsm__DOT__tile_i;
                    vlSelfRef.tile_j = vlSelfRef.tile_sequencer_fsm__DOT__tile_j;
                    vlSelfRef.k_tile = vlSelfRef.tile_sequencer_fsm__DOT__k_tile;
                    vlSelfRef.fill_start = vlSelfRef.tile_sequencer_fsm__DOT__fill_start;
                    vlSelfRef.writeback_start = vlSelfRef.tile_sequencer_fsm__DOT__writeback_start;
                    vlSelfRef.tile_sequencer_fsm__DOT__writeback_done 
                        = vlSelfRef.writeback_done;
                }
            }
        }
    }
    return (__VicoExecute);
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ __Vdly__tile_sequencer_fsm__DOT__state;
    __Vdly__tile_sequencer_fsm__DOT__state = 0;
    CData/*7:0*/ __Vdly__tile_sequencer_fsm__DOT__k_tile;
    __Vdly__tile_sequencer_fsm__DOT__k_tile = 0;
    CData/*7:0*/ __Vdly__tile_sequencer_fsm__DOT__tile_j;
    __Vdly__tile_sequencer_fsm__DOT__tile_j = 0;
    CData/*0:0*/ __Vdly__tile_sequencer_fsm__DOT__final_pass;
    __Vdly__tile_sequencer_fsm__DOT__final_pass = 0;
    // Body
    __Vdly__tile_sequencer_fsm__DOT__state = vlSelfRef.tile_sequencer_fsm__DOT__state;
    __Vdly__tile_sequencer_fsm__DOT__k_tile = vlSelfRef.tile_sequencer_fsm__DOT__k_tile;
    __Vdly__tile_sequencer_fsm__DOT__tile_j = vlSelfRef.tile_sequencer_fsm__DOT__tile_j;
    __Vdly__tile_sequencer_fsm__DOT__final_pass = vlSelfRef.tile_sequencer_fsm__DOT__final_pass;
    if (vlSelfRef.tile_sequencer_fsm__DOT__rst_n) {
        vlSelfRef.tile_sequencer_fsm__DOT__swap = 0U;
        vlSelfRef.tile_sequencer_fsm__DOT__start = 0U;
        vlSelfRef.tile_sequencer_fsm__DOT__ts_done = 0U;
        vlSelfRef.tile_sequencer_fsm__DOT__fill_start = 0U;
        vlSelfRef.tile_sequencer_fsm__DOT__writeback_start = 0U;
        if ((8U & (IData)(vlSelfRef.tile_sequencer_fsm__DOT__state))) {
            __Vdly__tile_sequencer_fsm__DOT__state = 0U;
        } else if ((4U & (IData)(vlSelfRef.tile_sequencer_fsm__DOT__state))) {
            if ((2U & (IData)(vlSelfRef.tile_sequencer_fsm__DOT__state))) {
                if ((1U & (IData)(vlSelfRef.tile_sequencer_fsm__DOT__state))) {
                    if (vlSelfRef.tile_sequencer_fsm__DOT__writeback_done) {
                        if (vlSelfRef.tile_sequencer_fsm__DOT__last_tile) {
                            vlSelfRef.tile_sequencer_fsm__DOT__ts_done = 1U;
                            vlSelfRef.tile_sequencer_fsm__DOT__ts_busy = 0U;
                            __Vdly__tile_sequencer_fsm__DOT__state = 0U;
                        } else {
                            __Vdly__tile_sequencer_fsm__DOT__state = 1U;
                        }
                    }
                } else {
                    __Vdly__tile_sequencer_fsm__DOT__k_tile = 0U;
                    vlSelfRef.tile_sequencer_fsm__DOT__writeback_start = 1U;
                    if (((IData)(vlSelfRef.tile_sequencer_fsm__DOT__tile_j) 
                         == ((IData)(vlSelfRef.tile_sequencer_fsm__DOT__n_tiles) 
                             - (IData)(1U)))) {
                        __Vdly__tile_sequencer_fsm__DOT__tile_j = 0U;
                        if (((IData)(vlSelfRef.tile_sequencer_fsm__DOT__tile_i) 
                             == ((IData)(vlSelfRef.tile_sequencer_fsm__DOT__m_tiles) 
                                 - (IData)(1U)))) {
                            vlSelfRef.tile_sequencer_fsm__DOT__last_tile = 1U;
                        } else {
                            vlSelfRef.tile_sequencer_fsm__DOT__tile_i 
                                = (0x000000ffU & ((IData)(1U) 
                                                  + (IData)(vlSelfRef.tile_sequencer_fsm__DOT__tile_i)));
                            vlSelfRef.tile_sequencer_fsm__DOT__last_tile = 0U;
                            vlSelfRef.tile_sequencer_fsm__DOT__fill_start = 1U;
                        }
                    } else {
                        __Vdly__tile_sequencer_fsm__DOT__tile_j 
                            = (0x000000ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.tile_sequencer_fsm__DOT__tile_j)));
                        vlSelfRef.tile_sequencer_fsm__DOT__last_tile = 0U;
                        vlSelfRef.tile_sequencer_fsm__DOT__fill_start = 1U;
                    }
                    __Vdly__tile_sequencer_fsm__DOT__state = 7U;
                }
            } else if ((1U & (IData)(vlSelfRef.tile_sequencer_fsm__DOT__state))) {
                if (vlSelfRef.tile_sequencer_fsm__DOT__tile_done) {
                    __Vdly__tile_sequencer_fsm__DOT__final_pass = 0U;
                    __Vdly__tile_sequencer_fsm__DOT__state = 6U;
                }
            } else if (vlSelfRef.tile_sequencer_fsm__DOT__pass_done) {
                if (vlSelfRef.tile_sequencer_fsm__DOT__final_pass) {
                    __Vdly__tile_sequencer_fsm__DOT__state = 5U;
                } else {
                    __Vdly__tile_sequencer_fsm__DOT__k_tile 
                        = (0x000000ffU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.tile_sequencer_fsm__DOT__k_tile)));
                    vlSelfRef.tile_sequencer_fsm__DOT__fill_start = 1U;
                    __Vdly__tile_sequencer_fsm__DOT__state = 1U;
                }
            }
        } else if ((2U & (IData)(vlSelfRef.tile_sequencer_fsm__DOT__state))) {
            if ((1U & (IData)(vlSelfRef.tile_sequencer_fsm__DOT__state))) {
                vlSelfRef.tile_sequencer_fsm__DOT__start = 1U;
                __Vdly__tile_sequencer_fsm__DOT__state = 4U;
                __Vdly__tile_sequencer_fsm__DOT__final_pass 
                    = ((IData)(vlSelfRef.tile_sequencer_fsm__DOT__k_tile) 
                       == ((IData)(vlSelfRef.tile_sequencer_fsm__DOT__k_tiles) 
                           - (IData)(1U)));
            } else {
                vlSelfRef.tile_sequencer_fsm__DOT__swap = 1U;
                __Vdly__tile_sequencer_fsm__DOT__state = 3U;
            }
        } else if ((1U & (IData)(vlSelfRef.tile_sequencer_fsm__DOT__state))) {
            if (((IData)(vlSelfRef.tile_sequencer_fsm__DOT__fill_weight_done) 
                 & (IData)(vlSelfRef.tile_sequencer_fsm__DOT__fill_act_done))) {
                __Vdly__tile_sequencer_fsm__DOT__state = 2U;
            }
        } else {
            vlSelfRef.tile_sequencer_fsm__DOT__ts_busy = 0U;
            if (vlSelfRef.tile_sequencer_fsm__DOT__go) {
                vlSelfRef.tile_sequencer_fsm__DOT__tile_i = 0U;
                __Vdly__tile_sequencer_fsm__DOT__tile_j = 0U;
                __Vdly__tile_sequencer_fsm__DOT__state = 1U;
                vlSelfRef.tile_sequencer_fsm__DOT__ts_busy = 1U;
                __Vdly__tile_sequencer_fsm__DOT__k_tile = 0U;
                vlSelfRef.tile_sequencer_fsm__DOT__fill_start = 1U;
            }
        }
    } else {
        vlSelfRef.tile_sequencer_fsm__DOT__tile_i = 0U;
        __Vdly__tile_sequencer_fsm__DOT__tile_j = 0U;
        __Vdly__tile_sequencer_fsm__DOT__state = 0U;
        vlSelfRef.tile_sequencer_fsm__DOT__swap = 0U;
        vlSelfRef.tile_sequencer_fsm__DOT__start = 0U;
        __Vdly__tile_sequencer_fsm__DOT__final_pass = 0U;
        vlSelfRef.tile_sequencer_fsm__DOT__ts_busy = 0U;
        vlSelfRef.tile_sequencer_fsm__DOT__ts_done = 0U;
        vlSelfRef.tile_sequencer_fsm__DOT__fill_start = 0U;
        vlSelfRef.tile_sequencer_fsm__DOT__writeback_start = 0U;
        __Vdly__tile_sequencer_fsm__DOT__k_tile = 0U;
        vlSelfRef.tile_sequencer_fsm__DOT__last_tile = 0U;
    }
    vlSelfRef.tile_sequencer_fsm__DOT__state = __Vdly__tile_sequencer_fsm__DOT__state;
    vlSelfRef.tile_sequencer_fsm__DOT__k_tile = __Vdly__tile_sequencer_fsm__DOT__k_tile;
    vlSelfRef.tile_sequencer_fsm__DOT__tile_j = __Vdly__tile_sequencer_fsm__DOT__tile_j;
    vlSelfRef.tile_sequencer_fsm__DOT__final_pass = __Vdly__tile_sequencer_fsm__DOT__final_pass;
    vlSelfRef.swap = vlSelfRef.tile_sequencer_fsm__DOT__swap;
    vlSelfRef.start = vlSelfRef.tile_sequencer_fsm__DOT__start;
    vlSelfRef.ts_done = vlSelfRef.tile_sequencer_fsm__DOT__ts_done;
    vlSelfRef.fill_start = vlSelfRef.tile_sequencer_fsm__DOT__fill_start;
    vlSelfRef.writeback_start = vlSelfRef.tile_sequencer_fsm__DOT__writeback_start;
    vlSelfRef.ts_busy = vlSelfRef.tile_sequencer_fsm__DOT__ts_busy;
    vlSelfRef.k_tile = vlSelfRef.tile_sequencer_fsm__DOT__k_tile;
    vlSelfRef.tile_j = vlSelfRef.tile_sequencer_fsm__DOT__tile_j;
    vlSelfRef.tile_i = vlSelfRef.tile_sequencer_fsm__DOT__tile_i;
    vlSelfRef.final_pass = vlSelfRef.tile_sequencer_fsm__DOT__final_pass;
}

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        ((IData)(vlSelfRef.tile_sequencer_fsm__DOT__clk) 
                                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__tile_sequencer_fsm__DOT__clk__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__tile_sequencer_fsm__DOT__clk__0 
            = vlSelfRef.tile_sequencer_fsm__DOT__clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                Vtop___024root___nba_sequent__TOP__0(vlSelf);
            }
        }
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("../../rtl/src/tile_sequencer_fsm.sv", 50, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        vlSelfRef.__VicoPhaseResult = Vtop___024root___eval_phase__ico(vlSelf);
        vlSelfRef.__VicoFirstIteration = 0U;
    } while (vlSelfRef.__VicoPhaseResult);
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("../../rtl/src/tile_sequencer_fsm.sv", 50, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../../rtl/src/tile_sequencer_fsm.sv", 50, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactPhaseResult = Vtop___024root___eval_phase__act(vlSelf);
        } while (vlSelfRef.__VactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtop___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst_n & 0xfeU)))) {
        Verilated::overWidthError("rst_n");
    }
    if (VL_UNLIKELY(((vlSelfRef.go & 0xfeU)))) {
        Verilated::overWidthError("go");
    }
    if (VL_UNLIKELY(((vlSelfRef.fill_weight_done & 0xfeU)))) {
        Verilated::overWidthError("fill_weight_done");
    }
    if (VL_UNLIKELY(((vlSelfRef.fill_act_done & 0xfeU)))) {
        Verilated::overWidthError("fill_act_done");
    }
    if (VL_UNLIKELY(((vlSelfRef.pass_done & 0xfeU)))) {
        Verilated::overWidthError("pass_done");
    }
    if (VL_UNLIKELY(((vlSelfRef.tile_done & 0xfeU)))) {
        Verilated::overWidthError("tile_done");
    }
    if (VL_UNLIKELY(((vlSelfRef.writeback_done & 0xfeU)))) {
        Verilated::overWidthError("writeback_done");
    }
}
#endif  // VL_DEBUG
