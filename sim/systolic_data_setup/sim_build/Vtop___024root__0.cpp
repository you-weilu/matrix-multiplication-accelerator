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
extern const VlUnpacked<CData/*3:0*/, 128> Vtop__ConstPool__TABLE_h0e90d959_0;
extern const VlUnpacked<CData/*3:0*/, 128> Vtop__ConstPool__TABLE_h423aee05_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vtop__ConstPool__TABLE_hebea6afc_0;

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
                    CData/*6:0*/ __Vinline_0__eval_ico___Vinline_1__ico_sequent__TOP__0___VdfgRegularize_hebeb780c_0_0;
                    __Vinline_0__eval_ico___Vinline_1__ico_sequent__TOP__0___VdfgRegularize_hebeb780c_0_0 = 0;
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
                    __Vinline_0__eval_ico___Vinline_1__ico_sequent__TOP__0___VdfgRegularize_hebeb780c_0_0 
                        = (((IData)(vlSelfRef.systolic_data_setup__DOT__cycle) 
                            << 2U) | (IData)(vlSelfRef.systolic_data_setup__DOT__state));
                    vlSelfRef.systolic_data_setup__DOT__weight_buf_addr 
                        = Vtop__ConstPool__TABLE_h0e90d959_0
                        [__Vinline_0__eval_ico___Vinline_1__ico_sequent__TOP__0___VdfgRegularize_hebeb780c_0_0];
                    vlSelfRef.systolic_data_setup__DOT__act_buf_addr 
                        = Vtop__ConstPool__TABLE_h423aee05_0
                        [__Vinline_0__eval_ico___Vinline_1__ico_sequent__TOP__0___VdfgRegularize_hebeb780c_0_0];
                    vlSelfRef.systolic_data_setup__DOT__row_valid 
                        = Vtop__ConstPool__TABLE_hebea6afc_0
                        [__Vinline_0__eval_ico___Vinline_1__ico_sequent__TOP__0___VdfgRegularize_hebeb780c_0_0];
                    vlSelfRef.weight_buf_addr = vlSelfRef.systolic_data_setup__DOT__weight_buf_addr;
                    vlSelfRef.act_buf_addr = vlSelfRef.systolic_data_setup__DOT__act_buf_addr;
                    vlSelfRef.row_valid = vlSelfRef.systolic_data_setup__DOT__row_valid;
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
    CData/*6:0*/ __VdfgRegularize_hebeb780c_0_0;
    __VdfgRegularize_hebeb780c_0_0 = 0;
    CData/*1:0*/ __Vdly__systolic_data_setup__DOT__state;
    __Vdly__systolic_data_setup__DOT__state = 0;
    CData/*4:0*/ __Vdly__systolic_data_setup__DOT__cycle;
    __Vdly__systolic_data_setup__DOT__cycle = 0;
    CData/*7:0*/ __VdlyVal__systolic_data_setup__DOT__weight_in__v0;
    __VdlyVal__systolic_data_setup__DOT__weight_in__v0 = 0;
    CData/*3:0*/ __VdlyDim0__systolic_data_setup__DOT__weight_in__v0;
    __VdlyDim0__systolic_data_setup__DOT__weight_in__v0 = 0;
    CData/*7:0*/ __VdlyVal__systolic_data_setup__DOT__buf_work__v0;
    __VdlyVal__systolic_data_setup__DOT__buf_work__v0 = 0;
    CData/*3:0*/ __VdlyDim0__systolic_data_setup__DOT__buf_work__v0;
    __VdlyDim0__systolic_data_setup__DOT__buf_work__v0 = 0;
    CData/*3:0*/ __VdlyDim1__systolic_data_setup__DOT__buf_work__v0;
    __VdlyDim1__systolic_data_setup__DOT__buf_work__v0 = 0;
    CData/*3:0*/ __VdlyDim0__systolic_data_setup__DOT__weight_in__v1;
    __VdlyDim0__systolic_data_setup__DOT__weight_in__v1 = 0;
    CData/*7:0*/ __VdlyVal__systolic_data_setup__DOT__act_in__v0;
    __VdlyVal__systolic_data_setup__DOT__act_in__v0 = 0;
    CData/*3:0*/ __VdlyDim0__systolic_data_setup__DOT__act_in__v0;
    __VdlyDim0__systolic_data_setup__DOT__act_in__v0 = 0;
    CData/*3:0*/ __VdlyDim0__systolic_data_setup__DOT__weight_in__v2;
    __VdlyDim0__systolic_data_setup__DOT__weight_in__v2 = 0;
    CData/*3:0*/ __VdlyDim0__systolic_data_setup__DOT__act_in__v1;
    __VdlyDim0__systolic_data_setup__DOT__act_in__v1 = 0;
    CData/*3:0*/ __VdlyDim0__systolic_data_setup__DOT__buf_work__v1;
    __VdlyDim0__systolic_data_setup__DOT__buf_work__v1 = 0;
    CData/*3:0*/ __VdlyDim1__systolic_data_setup__DOT__buf_work__v1;
    __VdlyDim1__systolic_data_setup__DOT__buf_work__v1 = 0;
    // Body
    __Vdly__systolic_data_setup__DOT__state = vlSelfRef.systolic_data_setup__DOT__state;
    __Vdly__systolic_data_setup__DOT__cycle = vlSelfRef.systolic_data_setup__DOT__cycle;
    if (vlSelfRef.systolic_data_setup__DOT__rst_n) {
        vlSelfRef.systolic_data_setup__DOT__done = 0U;
        vlSelfRef.systolic_data_setup__DOT__weight_load_en = 0U;
        if ((0U == (IData)(vlSelfRef.systolic_data_setup__DOT__state))) {
            if (vlSelfRef.systolic_data_setup__DOT__start) {
                __Vdly__systolic_data_setup__DOT__state = 1U;
                __Vdly__systolic_data_setup__DOT__cycle = 0U;
            }
        } else if ((1U == (IData)(vlSelfRef.systolic_data_setup__DOT__state))) {
            vlSelfRef.systolic_data_setup__DOT__unnamedblk3__DOT__j = 0U;
            vlSelfRef.systolic_data_setup__DOT__weight_load_en = 1U;
            while (VL_GTS_III(32, 0x00000010U, vlSelfRef.systolic_data_setup__DOT__unnamedblk3__DOT__j)) {
                __VdlyVal__systolic_data_setup__DOT__weight_in__v0 
                    = vlSelfRef.systolic_data_setup__DOT__weight_buf_data
                    [(0x0000000fU & vlSelfRef.systolic_data_setup__DOT__unnamedblk3__DOT__j)];
                __VdlyDim0__systolic_data_setup__DOT__weight_in__v0 
                    = (0x0000000fU & vlSelfRef.systolic_data_setup__DOT__unnamedblk3__DOT__j);
                vlSelfRef.__VdlyCommitQueuesystolic_data_setup__DOT__weight_in.enqueue(__VdlyVal__systolic_data_setup__DOT__weight_in__v0, (IData)(__VdlyDim0__systolic_data_setup__DOT__weight_in__v0));
                __VdlyVal__systolic_data_setup__DOT__buf_work__v0 
                    = vlSelfRef.systolic_data_setup__DOT__act_buf_data
                    [(0x0000000fU & vlSelfRef.systolic_data_setup__DOT__unnamedblk3__DOT__j)];
                __VdlyDim0__systolic_data_setup__DOT__buf_work__v0 
                    = (0x0000000fU & vlSelfRef.systolic_data_setup__DOT__unnamedblk3__DOT__j);
                __VdlyDim1__systolic_data_setup__DOT__buf_work__v0 
                    = (0x0000000fU & (IData)(vlSelfRef.systolic_data_setup__DOT__cycle));
                vlSelfRef.__VdlyCommitQueuesystolic_data_setup__DOT__buf_work.enqueue(__VdlyVal__systolic_data_setup__DOT__buf_work__v0, (IData)(__VdlyDim1__systolic_data_setup__DOT__buf_work__v0), __VdlyDim0__systolic_data_setup__DOT__buf_work__v0);
                vlSelfRef.systolic_data_setup__DOT__unnamedblk3__DOT__j 
                    = ((IData)(1U) + vlSelfRef.systolic_data_setup__DOT__unnamedblk3__DOT__j);
            }
            if ((0x0fU == (IData)(vlSelfRef.systolic_data_setup__DOT__cycle))) {
                vlSelfRef.systolic_data_setup__DOT__unnamedblk4__DOT__i = 0U;
                __Vdly__systolic_data_setup__DOT__state = 2U;
                __Vdly__systolic_data_setup__DOT__cycle = 0U;
                while (VL_GTS_III(32, 0x00000010U, vlSelfRef.systolic_data_setup__DOT__unnamedblk4__DOT__i)) {
                    __VdlyDim0__systolic_data_setup__DOT__weight_in__v1 
                        = (0x0000000fU & vlSelfRef.systolic_data_setup__DOT__unnamedblk4__DOT__i);
                    vlSelfRef.__VdlyCommitQueuesystolic_data_setup__DOT__weight_in.enqueue(0U, (IData)(__VdlyDim0__systolic_data_setup__DOT__weight_in__v1));
                    vlSelfRef.systolic_data_setup__DOT__unnamedblk4__DOT__i 
                        = ((IData)(1U) + vlSelfRef.systolic_data_setup__DOT__unnamedblk4__DOT__i);
                }
            } else {
                __Vdly__systolic_data_setup__DOT__cycle 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.systolic_data_setup__DOT__cycle)));
            }
        } else if ((2U == (IData)(vlSelfRef.systolic_data_setup__DOT__state))) {
            vlSelfRef.systolic_data_setup__DOT__unnamedblk5__DOT__k = 0U;
            while (VL_GTS_III(32, 0x00000010U, vlSelfRef.systolic_data_setup__DOT__unnamedblk5__DOT__k)) {
                __VdlyVal__systolic_data_setup__DOT__act_in__v0 
                    = ((((IData)(vlSelfRef.systolic_data_setup__DOT__cycle) 
                         >= (0x0000001fU & vlSelfRef.systolic_data_setup__DOT__unnamedblk5__DOT__k)) 
                        & (0x10U > (0x0000001fU & ((IData)(vlSelfRef.systolic_data_setup__DOT__cycle) 
                                                   - vlSelfRef.systolic_data_setup__DOT__unnamedblk5__DOT__k))))
                        ? vlSelfRef.systolic_data_setup__DOT__buf_work
                       [(0x0000000fU & ((IData)(vlSelfRef.systolic_data_setup__DOT__cycle) 
                                        - vlSelfRef.systolic_data_setup__DOT__unnamedblk5__DOT__k))]
                       [(0x0000000fU & vlSelfRef.systolic_data_setup__DOT__unnamedblk5__DOT__k)]
                        : 0U);
                __VdlyDim0__systolic_data_setup__DOT__act_in__v0 
                    = (0x0000000fU & vlSelfRef.systolic_data_setup__DOT__unnamedblk5__DOT__k);
                vlSelfRef.__VdlyCommitQueuesystolic_data_setup__DOT__act_in.enqueue(__VdlyVal__systolic_data_setup__DOT__act_in__v0, (IData)(__VdlyDim0__systolic_data_setup__DOT__act_in__v0));
                vlSelfRef.systolic_data_setup__DOT__unnamedblk5__DOT__k 
                    = ((IData)(1U) + vlSelfRef.systolic_data_setup__DOT__unnamedblk5__DOT__k);
            }
            if ((0x1eU == (IData)(vlSelfRef.systolic_data_setup__DOT__cycle))) {
                __Vdly__systolic_data_setup__DOT__state = 0U;
                vlSelfRef.systolic_data_setup__DOT__done = 1U;
                __Vdly__systolic_data_setup__DOT__cycle = 0U;
            } else {
                __Vdly__systolic_data_setup__DOT__cycle 
                    = (0x0000001fU & ((IData)(1U) + (IData)(vlSelfRef.systolic_data_setup__DOT__cycle)));
            }
        } else {
            __Vdly__systolic_data_setup__DOT__state = 0U;
        }
    } else {
        vlSelfRef.systolic_data_setup__DOT__unnamedblk1__DOT__i = 0U;
        __Vdly__systolic_data_setup__DOT__state = 0U;
        __Vdly__systolic_data_setup__DOT__cycle = 0U;
        vlSelfRef.systolic_data_setup__DOT__done = 0U;
        vlSelfRef.systolic_data_setup__DOT__weight_load_en = 0U;
        while (VL_GTS_III(32, 0x00000010U, vlSelfRef.systolic_data_setup__DOT__unnamedblk1__DOT__i)) {
            __VdlyDim0__systolic_data_setup__DOT__weight_in__v2 
                = (0x0000000fU & vlSelfRef.systolic_data_setup__DOT__unnamedblk1__DOT__i);
            vlSelfRef.__VdlyCommitQueuesystolic_data_setup__DOT__weight_in.enqueue(0U, (IData)(__VdlyDim0__systolic_data_setup__DOT__weight_in__v2));
            __VdlyDim0__systolic_data_setup__DOT__act_in__v1 
                = (0x0000000fU & vlSelfRef.systolic_data_setup__DOT__unnamedblk1__DOT__i);
            vlSelfRef.__VdlyCommitQueuesystolic_data_setup__DOT__act_in.enqueue(0U, (IData)(__VdlyDim0__systolic_data_setup__DOT__act_in__v1));
            vlSelfRef.systolic_data_setup__DOT__unnamedblk1__DOT__unnamedblk2__DOT__j = 0U;
            while (VL_GTS_III(32, 0x00000010U, vlSelfRef.systolic_data_setup__DOT__unnamedblk1__DOT__unnamedblk2__DOT__j)) {
                __VdlyDim0__systolic_data_setup__DOT__buf_work__v1 
                    = (0x0000000fU & vlSelfRef.systolic_data_setup__DOT__unnamedblk1__DOT__unnamedblk2__DOT__j);
                __VdlyDim1__systolic_data_setup__DOT__buf_work__v1 
                    = (0x0000000fU & vlSelfRef.systolic_data_setup__DOT__unnamedblk1__DOT__i);
                vlSelfRef.__VdlyCommitQueuesystolic_data_setup__DOT__buf_work.enqueue(0U, (IData)(__VdlyDim1__systolic_data_setup__DOT__buf_work__v1), __VdlyDim0__systolic_data_setup__DOT__buf_work__v1);
                vlSelfRef.systolic_data_setup__DOT__unnamedblk1__DOT__unnamedblk2__DOT__j 
                    = ((IData)(1U) + vlSelfRef.systolic_data_setup__DOT__unnamedblk1__DOT__unnamedblk2__DOT__j);
            }
            vlSelfRef.systolic_data_setup__DOT__unnamedblk1__DOT__i 
                = ((IData)(1U) + vlSelfRef.systolic_data_setup__DOT__unnamedblk1__DOT__i);
        }
    }
    vlSelfRef.__VdlyCommitQueuesystolic_data_setup__DOT__buf_work.commit(vlSelfRef.systolic_data_setup__DOT__buf_work);
    vlSelfRef.__VdlyCommitQueuesystolic_data_setup__DOT__weight_in.commit(vlSelfRef.systolic_data_setup__DOT__weight_in);
    vlSelfRef.__VdlyCommitQueuesystolic_data_setup__DOT__act_in.commit(vlSelfRef.systolic_data_setup__DOT__act_in);
    vlSelfRef.systolic_data_setup__DOT__state = __Vdly__systolic_data_setup__DOT__state;
    vlSelfRef.systolic_data_setup__DOT__cycle = __Vdly__systolic_data_setup__DOT__cycle;
    vlSelfRef.done = vlSelfRef.systolic_data_setup__DOT__done;
    vlSelfRef.weight_load_en = vlSelfRef.systolic_data_setup__DOT__weight_load_en;
    vlSelfRef.weight_in = vlSelfRef.systolic_data_setup__DOT__weight_in;
    vlSelfRef.act_in = vlSelfRef.systolic_data_setup__DOT__act_in;
    __VdfgRegularize_hebeb780c_0_0 = (((IData)(vlSelfRef.systolic_data_setup__DOT__cycle) 
                                       << 2U) | (IData)(vlSelfRef.systolic_data_setup__DOT__state));
    vlSelfRef.systolic_data_setup__DOT__weight_buf_addr 
        = Vtop__ConstPool__TABLE_h0e90d959_0[__VdfgRegularize_hebeb780c_0_0];
    vlSelfRef.systolic_data_setup__DOT__act_buf_addr 
        = Vtop__ConstPool__TABLE_h423aee05_0[__VdfgRegularize_hebeb780c_0_0];
    vlSelfRef.systolic_data_setup__DOT__row_valid = Vtop__ConstPool__TABLE_hebea6afc_0
        [__VdfgRegularize_hebeb780c_0_0];
    vlSelfRef.weight_buf_addr = vlSelfRef.systolic_data_setup__DOT__weight_buf_addr;
    vlSelfRef.act_buf_addr = vlSelfRef.systolic_data_setup__DOT__act_buf_addr;
    vlSelfRef.row_valid = vlSelfRef.systolic_data_setup__DOT__row_valid;
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
                                                        ((IData)(vlSelfRef.systolic_data_setup__DOT__clk) 
                                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__systolic_data_setup__DOT__clk__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__systolic_data_setup__DOT__clk__0 
            = vlSelfRef.systolic_data_setup__DOT__clk;
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
            VL_FATAL_MT("../../rtl/src/systolic_data_setup.sv", 14, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
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
            VL_FATAL_MT("../../rtl/src/systolic_data_setup.sv", 14, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("../../rtl/src/systolic_data_setup.sv", 14, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.start & 0xfeU)))) {
        Verilated::overWidthError("start");
    }
}
#endif  // VL_DEBUG
