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
void Vtop_axi4_if___ico_sequent__TOP__output_buffer_wrap__DOT__c2h_axi__0(Vtop_axi4_if* vlSelf);

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
                    vlSelfRef.output_buffer_wrap__DOT__buf_wen 
                        = vlSelfRef.buf_wen;
                    vlSelfRef.output_buffer_wrap__DOT__buf_row 
                        = vlSelfRef.buf_row;
                    vlSelfRef.output_buffer_wrap__DOT__buf_data 
                        = vlSelfRef.buf_data;
                    vlSelfRef.output_buffer_wrap__DOT__arvalid 
                        = vlSelfRef.arvalid;
                    vlSelfRef.output_buffer_wrap__DOT__arid 
                        = vlSelfRef.arid;
                    vlSelfRef.output_buffer_wrap__DOT__araddr 
                        = vlSelfRef.araddr;
                    vlSelfRef.output_buffer_wrap__DOT__arlen 
                        = vlSelfRef.arlen;
                    vlSelfRef.output_buffer_wrap__DOT__arsize 
                        = vlSelfRef.arsize;
                    vlSelfRef.output_buffer_wrap__DOT__arburst 
                        = vlSelfRef.arburst;
                    vlSelfRef.output_buffer_wrap__DOT__arready 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arready;
                    vlSelfRef.output_buffer_wrap__DOT__rvalid 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rvalid;
                    vlSelfRef.output_buffer_wrap__DOT__rid 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rid;
                    vlSelfRef.output_buffer_wrap__DOT__rresp 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rresp;
                    vlSelfRef.output_buffer_wrap__DOT__rready 
                        = vlSelfRef.rready;
                    vlSelfRef.output_buffer_wrap__DOT__clk 
                        = vlSelfRef.clk;
                    vlSelfRef.output_buffer_wrap__DOT__rst_n 
                        = vlSelfRef.rst_n;
                    vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_wen 
                        = vlSelfRef.output_buffer_wrap__DOT__buf_wen;
                    vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_row 
                        = vlSelfRef.output_buffer_wrap__DOT__buf_row;
                    vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data 
                        = vlSelfRef.output_buffer_wrap__DOT__buf_data;
                    vlSelfRef.arready = vlSelfRef.output_buffer_wrap__DOT__arready;
                    vlSelfRef.rvalid = vlSelfRef.output_buffer_wrap__DOT__rvalid;
                    vlSelfRef.rid = vlSelfRef.output_buffer_wrap__DOT__rid;
                    vlSelfRef.rresp = vlSelfRef.output_buffer_wrap__DOT__rresp;
                    vlSelfRef.output_buffer_wrap__DOT__dut__DOT__clk 
                        = vlSelfRef.output_buffer_wrap__DOT__clk;
                    vlSelfRef.output_buffer_wrap__DOT__dut__DOT__rst_n 
                        = vlSelfRef.output_buffer_wrap__DOT__rst_n;
                }
                Vtop_axi4_if___ico_sequent__TOP__output_buffer_wrap__DOT__c2h_axi__0((&vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi));
                {
                    // Inlined CFunc: _ico_sequent__TOP__1
                    vlSelfRef.output_buffer_wrap__DOT__rdata[0U] 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rdata[0U];
                    vlSelfRef.output_buffer_wrap__DOT__rdata[1U] 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rdata[1U];
                    vlSelfRef.output_buffer_wrap__DOT__rdata[2U] 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rdata[2U];
                    vlSelfRef.output_buffer_wrap__DOT__rdata[3U] 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rdata[3U];
                    vlSelfRef.output_buffer_wrap__DOT__rlast 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rlast;
                    vlSelfRef.rdata[0U] = vlSelfRef.output_buffer_wrap__DOT__rdata[0U];
                    vlSelfRef.rdata[1U] = vlSelfRef.output_buffer_wrap__DOT__rdata[1U];
                    vlSelfRef.rdata[2U] = vlSelfRef.output_buffer_wrap__DOT__rdata[2U];
                    vlSelfRef.rdata[3U] = vlSelfRef.output_buffer_wrap__DOT__rdata[3U];
                    vlSelfRef.rlast = vlSelfRef.output_buffer_wrap__DOT__rlast;
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
    VlWide<4>/*127:0*/ __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v0;
    VL_ZERO_W(128, __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v0);
    CData/*5:0*/ __VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v0;
    __VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__output_buffer_wrap__DOT__dut__DOT__mem__v0;
    __VdlySet__output_buffer_wrap__DOT__dut__DOT__mem__v0 = 0;
    VlWide<4>/*127:0*/ __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v1;
    VL_ZERO_W(128, __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v1);
    CData/*5:0*/ __VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v1;
    __VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v1 = 0;
    VlWide<4>/*127:0*/ __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v2;
    VL_ZERO_W(128, __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v2);
    CData/*5:0*/ __VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v2;
    __VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v2 = 0;
    VlWide<4>/*127:0*/ __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v3;
    VL_ZERO_W(128, __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v3);
    CData/*5:0*/ __VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v3;
    __VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v3 = 0;
    // Body
    __VdlySet__output_buffer_wrap__DOT__dut__DOT__mem__v0 = 0U;
    if (vlSelfRef.output_buffer_wrap__DOT__dut__DOT__rst_n) {
        if (vlSelfRef.output_buffer_wrap__DOT__dut__DOT__state) {
            if (vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rready) {
                if ((0U == (IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__beat_count))) {
                    vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rvalid = 0U;
                    vlSelfRef.output_buffer_wrap__DOT__dut__DOT__state = 0U;
                } else {
                    vlSelfRef.output_buffer_wrap__DOT__dut__DOT__beat_addr 
                        = (0x0000003fU & ((IData)(1U) 
                                          + (IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__beat_addr)));
                    vlSelfRef.output_buffer_wrap__DOT__dut__DOT__beat_count 
                        = (0x000000ffU & ((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__beat_count) 
                                          - (IData)(1U)));
                }
            }
        } else {
            vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.__Vdly__arready = 1U;
            vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rvalid = 0U;
            if (((IData)(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arvalid) 
                 & (IData)(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arready))) {
                vlSelfRef.output_buffer_wrap__DOT__dut__DOT__beat_addr 
                    = (0x0000003fU & (IData)((vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.araddr 
                                              >> 4U)));
                vlSelfRef.output_buffer_wrap__DOT__dut__DOT__beat_count 
                    = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arlen;
                vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.__Vdly__arready = 0U;
                vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rvalid = 1U;
                vlSelfRef.output_buffer_wrap__DOT__dut__DOT__state = 1U;
            }
        }
    } else {
        vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.__Vdly__arready = 0U;
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__beat_addr = 0U;
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__beat_count = 0U;
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__state = 0U;
        vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rvalid = 0U;
    }
    if (vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_wen) {
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v0[0U] 
            = vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[0U];
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v0[1U] 
            = (IData)((((QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[2U])) 
                        << 0x00000020U) | (QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[1U]))));
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v0[2U] 
            = (IData)(((((QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[2U])) 
                         << 0x00000020U) | (QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[1U]))) 
                       >> 0x00000020U));
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v0[3U] 
            = vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[3U];
        __VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v0 
            = ((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_row) 
               << 2U);
        __VdlySet__output_buffer_wrap__DOT__dut__DOT__mem__v0 = 1U;
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v1[0U] 
            = vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[4U];
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v1[1U] 
            = (IData)((((QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[6U])) 
                        << 0x00000020U) | (QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[5U]))));
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v1[2U] 
            = (IData)(((((QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[6U])) 
                         << 0x00000020U) | (QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[5U]))) 
                       >> 0x00000020U));
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v1[3U] 
            = vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[7U];
        __VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v1 
            = (1U | ((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_row) 
                     << 2U));
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v2[0U] 
            = vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[8U];
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v2[1U] 
            = (IData)((((QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[10U])) 
                        << 0x00000020U) | (QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[9U]))));
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v2[2U] 
            = (IData)(((((QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[10U])) 
                         << 0x00000020U) | (QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[9U]))) 
                       >> 0x00000020U));
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v2[3U] 
            = vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[11U];
        __VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v2 
            = (2U | ((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_row) 
                     << 2U));
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v3[0U] 
            = vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[12U];
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v3[1U] 
            = (IData)((((QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[14U])) 
                        << 0x00000020U) | (QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[13U]))));
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v3[2U] 
            = (IData)(((((QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[14U])) 
                         << 0x00000020U) | (QData)((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[13U]))) 
                       >> 0x00000020U));
        __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v3[3U] 
            = vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[15U];
        __VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v3 
            = (3U | ((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_row) 
                     << 2U));
    }
    if (__VdlySet__output_buffer_wrap__DOT__dut__DOT__mem__v0) {
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v0][0U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v0[0U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v0][1U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v0[1U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v0][2U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v0[2U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v0][3U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v0[3U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v1][0U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v1[0U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v1][1U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v1[1U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v1][2U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v1[2U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v1][3U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v1[3U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v2][0U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v2[0U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v2][1U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v2[1U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v2][2U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v2[2U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v2][3U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v2[3U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v3][0U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v3[0U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v3][1U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v3[1U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v3][2U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v3[2U];
        vlSelfRef.output_buffer_wrap__DOT__dut__DOT__mem[__VdlyDim0__output_buffer_wrap__DOT__dut__DOT__mem__v3][3U] 
            = __VdlyVal__output_buffer_wrap__DOT__dut__DOT__mem__v3[3U];
    }
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
                                                        ((IData)(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__clk) 
                                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__output_buffer_wrap__DOT__dut__DOT__clk__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__output_buffer_wrap__DOT__dut__DOT__clk__0 
            = vlSelfRef.output_buffer_wrap__DOT__dut__DOT__clk;
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

void Vtop_axi4_if___nba_sequent__TOP__output_buffer_wrap__DOT__c2h_axi__0(Vtop_axi4_if* vlSelf);
void Vtop_axi4_if___nba_sequent__TOP__output_buffer_wrap__DOT__c2h_axi__1(Vtop_axi4_if* vlSelf);

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
                Vtop_axi4_if___nba_sequent__TOP__output_buffer_wrap__DOT__c2h_axi__0((&vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi));
                Vtop___024root___nba_sequent__TOP__0(vlSelf);
                Vtop_axi4_if___nba_sequent__TOP__output_buffer_wrap__DOT__c2h_axi__1((&vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi));
                {
                    // Inlined CFunc: _nba_sequent__TOP__1
                    vlSelfRef.output_buffer_wrap__DOT__rvalid 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rvalid;
                    vlSelfRef.output_buffer_wrap__DOT__arready 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arready;
                    vlSelfRef.output_buffer_wrap__DOT__rlast 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rlast;
                    vlSelfRef.output_buffer_wrap__DOT__rdata[0U] 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rdata[0U];
                    vlSelfRef.output_buffer_wrap__DOT__rdata[1U] 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rdata[1U];
                    vlSelfRef.output_buffer_wrap__DOT__rdata[2U] 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rdata[2U];
                    vlSelfRef.output_buffer_wrap__DOT__rdata[3U] 
                        = vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rdata[3U];
                    vlSelfRef.rvalid = vlSelfRef.output_buffer_wrap__DOT__rvalid;
                    vlSelfRef.arready = vlSelfRef.output_buffer_wrap__DOT__arready;
                    vlSelfRef.rlast = vlSelfRef.output_buffer_wrap__DOT__rlast;
                    vlSelfRef.rdata[0U] = vlSelfRef.output_buffer_wrap__DOT__rdata[0U];
                    vlSelfRef.rdata[1U] = vlSelfRef.output_buffer_wrap__DOT__rdata[1U];
                    vlSelfRef.rdata[2U] = vlSelfRef.output_buffer_wrap__DOT__rdata[2U];
                    vlSelfRef.rdata[3U] = vlSelfRef.output_buffer_wrap__DOT__rdata[3U];
                }
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
            VL_FATAL_MT("output_buffer_wrap.sv", 2, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
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
            VL_FATAL_MT("output_buffer_wrap.sv", 2, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("output_buffer_wrap.sv", 2, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.buf_wen & 0xfeU)))) {
        Verilated::overWidthError("buf_wen");
    }
    if (VL_UNLIKELY(((vlSelfRef.buf_row & 0xf0U)))) {
        Verilated::overWidthError("buf_row");
    }
    if (VL_UNLIKELY(((vlSelfRef.arvalid & 0xfeU)))) {
        Verilated::overWidthError("arvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.arid & 0xf0U)))) {
        Verilated::overWidthError("arid");
    }
    if (VL_UNLIKELY(((vlSelfRef.arsize & 0xf8U)))) {
        Verilated::overWidthError("arsize");
    }
    if (VL_UNLIKELY(((vlSelfRef.arburst & 0xfcU)))) {
        Verilated::overWidthError("arburst");
    }
    if (VL_UNLIKELY(((vlSelfRef.rready & 0xfeU)))) {
        Verilated::overWidthError("rready");
    }
}
#endif  // VL_DEBUG
