// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__systolic_data_setup__DOT__clk__0 
        = vlSelfRef.systolic_data_setup__DOT__clk;
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
            VL_FATAL_MT("../../rtl/src/systolic_data_setup.sv", 14, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
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

extern const VlUnpacked<CData/*3:0*/, 128> Vtop__ConstPool__TABLE_h0e90d959_0;
extern const VlUnpacked<CData/*3:0*/, 128> Vtop__ConstPool__TABLE_h423aee05_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_hebea6afc_0;

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
                    CData/*6:0*/ __Vinline_0__eval_stl___Vinline_0__ico_sequent__TOP__0___VdfgRegularize_hebeb780c_0_0;
                    __Vinline_0__eval_stl___Vinline_0__ico_sequent__TOP__0___VdfgRegularize_hebeb780c_0_0 = 0;
                    vlSelfRef.systolic_data_setup__DOT__clk 
                        = vlSelfRef.clk;
                    vlSelfRef.systolic_data_setup__DOT__rst_n 
                        = vlSelfRef.rst_n;
                    vlSelfRef.systolic_data_setup__DOT__start 
                        = vlSelfRef.start;
                    vlSelfRef.done = vlSelfRef.systolic_data_setup__DOT__done;
                    vlSelfRef.systolic_data_setup__DOT__weight_buf_data 
                        = vlSelfRef.weight_buf_data;
                    vlSelfRef.systolic_data_setup__DOT__act_buf_data 
                        = vlSelfRef.act_buf_data;
                    vlSelfRef.weight_in = vlSelfRef.systolic_data_setup__DOT__weight_in;
                    vlSelfRef.weight_load_en = vlSelfRef.systolic_data_setup__DOT__weight_load_en;
                    vlSelfRef.act_in = vlSelfRef.systolic_data_setup__DOT__act_in;
                    __Vinline_0__eval_stl___Vinline_0__ico_sequent__TOP__0___VdfgRegularize_hebeb780c_0_0 
                        = (((IData)(vlSelfRef.systolic_data_setup__DOT__cycle) 
                            << 2U) | (IData)(vlSelfRef.systolic_data_setup__DOT__state));
                    vlSelfRef.systolic_data_setup__DOT__weight_buf_addr 
                        = Vtop__ConstPool__TABLE_h0e90d959_0
                        [__Vinline_0__eval_stl___Vinline_0__ico_sequent__TOP__0___VdfgRegularize_hebeb780c_0_0];
                    vlSelfRef.systolic_data_setup__DOT__act_buf_addr 
                        = Vtop__ConstPool__TABLE_h423aee05_0
                        [__Vinline_0__eval_stl___Vinline_0__ico_sequent__TOP__0___VdfgRegularize_hebeb780c_0_0];
                    vlSelfRef.systolic_data_setup__DOT__row_valid 
                        = Vtop__ConstPool__TABLE_hebea6afc_0
                        [__Vinline_0__eval_stl___Vinline_0__ico_sequent__TOP__0___VdfgRegularize_hebeb780c_0_0];
                    vlSelfRef.weight_buf_addr = vlSelfRef.systolic_data_setup__DOT__weight_buf_addr;
                    vlSelfRef.act_buf_addr = vlSelfRef.systolic_data_setup__DOT__act_buf_addr;
                    vlSelfRef.row_valid = vlSelfRef.systolic_data_setup__DOT__row_valid;
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge systolic_data_setup.clk)\n");
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
    vlSelf->start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    vlSelf->done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10296494685231209730ull);
    vlSelf->weight_buf_addr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17907573903570466642ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->weight_buf_data[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5627088129221737615ull);
    }
    vlSelf->act_buf_addr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3500092107416786607ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->act_buf_data[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11111920656469564623ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->weight_in[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17664990524737627050ull);
    }
    vlSelf->weight_load_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 452863499328145582ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->act_in[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3492424077448558534ull);
    }
    vlSelf->row_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15516042521133067708ull);
    vlSelf->systolic_data_setup__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10557753968084902824ull);
    vlSelf->systolic_data_setup__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10702103558340015759ull);
    vlSelf->systolic_data_setup__DOT__start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2468149710586127753ull);
    vlSelf->systolic_data_setup__DOT__done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4003717566980664797ull);
    vlSelf->systolic_data_setup__DOT__weight_buf_addr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10237650437481678390ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->systolic_data_setup__DOT__weight_buf_data[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15877239332104507473ull);
    }
    vlSelf->systolic_data_setup__DOT__act_buf_addr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3844166789197907234ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->systolic_data_setup__DOT__act_buf_data[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1307558332277423044ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->systolic_data_setup__DOT__weight_in[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18365907496260022289ull);
    }
    vlSelf->systolic_data_setup__DOT__weight_load_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 797556491620480011ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->systolic_data_setup__DOT__act_in[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2084510419995119464ull);
    }
    vlSelf->systolic_data_setup__DOT__row_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10109221263481849301ull);
    vlSelf->systolic_data_setup__DOT__state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6931201527596949411ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 16; ++__Vi1) {
            vlSelf->systolic_data_setup__DOT__buf_work[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 291040785225510376ull);
        }
    }
    vlSelf->systolic_data_setup__DOT__cycle = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 8828330567128977247ull);
    vlSelf->systolic_data_setup__DOT__unnamedblk3__DOT__j = 0;
    vlSelf->systolic_data_setup__DOT__unnamedblk4__DOT__i = 0;
    vlSelf->systolic_data_setup__DOT__unnamedblk5__DOT__k = 0;
    vlSelf->systolic_data_setup__DOT__unnamedblk1__DOT__i = 0;
    vlSelf->systolic_data_setup__DOT__unnamedblk1__DOT__unnamedblk2__DOT__j = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__systolic_data_setup__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
