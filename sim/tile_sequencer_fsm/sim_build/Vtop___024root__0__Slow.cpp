// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tile_sequencer_fsm__DOT__clk__0 
        = vlSelfRef.tile_sequencer_fsm__DOT__clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00002710U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("../../rtl/src/tile_sequencer_fsm.sv", 50, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtop___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD bool Vtop___024root___eval_phase__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__stl
        vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VstlTriggered[0U]) 
                                         | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
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
    return (__VstlExecute);
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tile_sequencer_fsm.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->go = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9942418676787815235ull);
    vlSelf->m_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13513209641359451005ull);
    vlSelf->n_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11416870543161471892ull);
    vlSelf->k_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4310807444499800468ull);
    vlSelf->swap = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17263893192133048920ull);
    vlSelf->fill_weight_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12633430062072914190ull);
    vlSelf->fill_act_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12025392712872053086ull);
    vlSelf->start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    vlSelf->pass_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16196788924807663559ull);
    vlSelf->final_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 917856162158580468ull);
    vlSelf->tile_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3324423728752466192ull);
    vlSelf->ts_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14002556710298275605ull);
    vlSelf->ts_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10622247347642098698ull);
    vlSelf->tile_i = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17738761636903319141ull);
    vlSelf->tile_j = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 678514002863363964ull);
    vlSelf->k_tile = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5641551249870019250ull);
    vlSelf->fill_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12514334226953459133ull);
    vlSelf->writeback_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12070831044157274392ull);
    vlSelf->writeback_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14023772087719021166ull);
    vlSelf->tile_sequencer_fsm__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15830410430650925668ull);
    vlSelf->tile_sequencer_fsm__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10743160279904794605ull);
    vlSelf->tile_sequencer_fsm__DOT__go = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14924180483321558705ull);
    vlSelf->tile_sequencer_fsm__DOT__m_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10960553687369173690ull);
    vlSelf->tile_sequencer_fsm__DOT__n_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2216445678108308813ull);
    vlSelf->tile_sequencer_fsm__DOT__k_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1735238380986878899ull);
    vlSelf->tile_sequencer_fsm__DOT__swap = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17844591422237512132ull);
    vlSelf->tile_sequencer_fsm__DOT__fill_weight_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5017246482737003315ull);
    vlSelf->tile_sequencer_fsm__DOT__fill_act_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12385804945899948779ull);
    vlSelf->tile_sequencer_fsm__DOT__start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15425224640876530852ull);
    vlSelf->tile_sequencer_fsm__DOT__pass_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13421225037230907264ull);
    vlSelf->tile_sequencer_fsm__DOT__final_pass = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8156092950957118907ull);
    vlSelf->tile_sequencer_fsm__DOT__tile_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15596697259287727527ull);
    vlSelf->tile_sequencer_fsm__DOT__ts_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7099257334756819826ull);
    vlSelf->tile_sequencer_fsm__DOT__ts_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15419181845117383798ull);
    vlSelf->tile_sequencer_fsm__DOT__tile_i = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2592852784023605202ull);
    vlSelf->tile_sequencer_fsm__DOT__tile_j = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15969294303038406432ull);
    vlSelf->tile_sequencer_fsm__DOT__k_tile = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2803412692845176868ull);
    vlSelf->tile_sequencer_fsm__DOT__fill_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11933314019871116349ull);
    vlSelf->tile_sequencer_fsm__DOT__writeback_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 719917602546070537ull);
    vlSelf->tile_sequencer_fsm__DOT__writeback_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12603507778198937705ull);
    vlSelf->tile_sequencer_fsm__DOT__state = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14672369296493934567ull);
    vlSelf->tile_sequencer_fsm__DOT__last_tile = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1129317256036520629ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tile_sequencer_fsm__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
