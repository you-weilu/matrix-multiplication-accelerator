// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__output_buffer_wrap__DOT__dut__DOT__clk__0 
        = vlSelfRef.output_buffer_wrap__DOT__dut__DOT__clk;
}

VL_ATTR_COLD void Vtop_axi4_if___eval_initial__TOP__output_buffer_wrap__DOT__c2h_axi(Vtop_axi4_if* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop_axi4_if___eval_initial__TOP__output_buffer_wrap__DOT__c2h_axi((&vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi));
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
            VL_FATAL_MT("output_buffer_wrap.sv", 2, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
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

void Vtop_axi4_if___ico_sequent__TOP__output_buffer_wrap__DOT__c2h_axi__0(Vtop_axi4_if* vlSelf);

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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge output_buffer_wrap.dut.clk)\n");
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
    vlSelf->buf_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16609360438381948201ull);
    vlSelf->buf_row = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 11786551079248107244ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->buf_data[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 309058570608937582ull);
    }
    vlSelf->arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16774798297805906817ull);
    vlSelf->arid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2554568685633023ull);
    vlSelf->araddr = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 17685200476622543275ull);
    vlSelf->arlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2795619241893056918ull);
    vlSelf->arsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 548378465311237866ull);
    vlSelf->arburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17635634856046503333ull);
    vlSelf->arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2587622265565774708ull);
    vlSelf->rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14125721737830190460ull);
    vlSelf->rid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17711635114162165067ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->rdata, __VscopeHash, 10065165116613087284ull);
    vlSelf->rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 810448354640171968ull);
    vlSelf->rlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5670148758994432807ull);
    vlSelf->rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8930348232195030647ull);
    vlSelf->output_buffer_wrap__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10867839841086043464ull);
    vlSelf->output_buffer_wrap__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5704246570891690534ull);
    vlSelf->output_buffer_wrap__DOT__buf_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11472806631542691725ull);
    vlSelf->output_buffer_wrap__DOT__buf_row = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15820244676982819405ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->output_buffer_wrap__DOT__buf_data[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8821228677033344673ull);
    }
    vlSelf->output_buffer_wrap__DOT__arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2450224815789001282ull);
    vlSelf->output_buffer_wrap__DOT__arid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2474012653303115690ull);
    vlSelf->output_buffer_wrap__DOT__araddr = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 16058253137898071945ull);
    vlSelf->output_buffer_wrap__DOT__arlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18212541045340445261ull);
    vlSelf->output_buffer_wrap__DOT__arsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7859341094996514186ull);
    vlSelf->output_buffer_wrap__DOT__arburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2167072141851067217ull);
    vlSelf->output_buffer_wrap__DOT__arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3342009110249118226ull);
    vlSelf->output_buffer_wrap__DOT__rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14287146075337491178ull);
    vlSelf->output_buffer_wrap__DOT__rid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9327234546655699527ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->output_buffer_wrap__DOT__rdata, __VscopeHash, 6211491924935178461ull);
    vlSelf->output_buffer_wrap__DOT__rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11401471461132045043ull);
    vlSelf->output_buffer_wrap__DOT__rlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6471957125015816812ull);
    vlSelf->output_buffer_wrap__DOT__rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 544261706169945502ull);
    vlSelf->output_buffer_wrap__DOT__dut__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9511541776575231249ull);
    vlSelf->output_buffer_wrap__DOT__dut__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9006201712949730282ull);
    vlSelf->output_buffer_wrap__DOT__dut__DOT__buf_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14547737974912289977ull);
    vlSelf->output_buffer_wrap__DOT__dut__DOT__buf_row = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2197395773126227927ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->output_buffer_wrap__DOT__dut__DOT__buf_data[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1829142863519784009ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(128, vlSelf->output_buffer_wrap__DOT__dut__DOT__mem[__Vi0], __VscopeHash, 13082984643958568254ull);
    }
    vlSelf->output_buffer_wrap__DOT__dut__DOT__state = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2917836160895217302ull);
    vlSelf->output_buffer_wrap__DOT__dut__DOT__beat_addr = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 10227122714168654865ull);
    vlSelf->output_buffer_wrap__DOT__dut__DOT__beat_count = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2888023400053439937ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__output_buffer_wrap__DOT__dut__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
