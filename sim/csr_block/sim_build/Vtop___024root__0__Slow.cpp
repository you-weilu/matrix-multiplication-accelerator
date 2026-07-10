// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__csr_block_wrap__DOT__dut__DOT__clk__0 
        = vlSelfRef.csr_block_wrap__DOT__dut__DOT__clk;
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
            VL_FATAL_MT("csr_block_wrap.sv", 2, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop_axi_lite_if___ico_sequent__TOP__csr_block_wrap__DOT__csr_axi__0(Vtop_axi_lite_if* vlSelf);

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
                Vtop___024root___ico_sequent__TOP__0(vlSelf);
                Vtop_axi_lite_if___ico_sequent__TOP__csr_block_wrap__DOT__csr_axi__0((&vlSymsp->TOP__csr_block_wrap__DOT__csr_axi));
                {
                    // Inlined CFunc: _ico_sequent__TOP__1
                    vlSelfRef.csr_block_wrap__DOT__dut__DOT__clk 
                        = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.aclk;
                    vlSelfRef.csr_block_wrap__DOT__dut__DOT__rst_n 
                        = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.aresetn;
                    vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_commit 
                        = ((IData)(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bready) 
                           & (3U == (IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_state)));
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge csr_block_wrap.dut.clk)\n");
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
    vlSelf->awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10741232094138379896ull);
    vlSelf->awprot = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4465653203409244048ull);
    vlSelf->awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14077405313628979207ull);
    vlSelf->awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9399710217136046492ull);
    vlSelf->wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12890271867161903902ull);
    vlSelf->wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15125268524300477597ull);
    vlSelf->wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13135585445238253745ull);
    vlSelf->wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2694481459927628098ull);
    vlSelf->bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3607396732575112162ull);
    vlSelf->bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14655036748745407948ull);
    vlSelf->bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16336171827316305440ull);
    vlSelf->araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17685200476622543275ull);
    vlSelf->arprot = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 15011922206834421026ull);
    vlSelf->arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16774798297805906817ull);
    vlSelf->arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2587622265565774708ull);
    vlSelf->rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10065165116613087284ull);
    vlSelf->rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 810448354640171968ull);
    vlSelf->rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14125721737830190460ull);
    vlSelf->rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8930348232195030647ull);
    vlSelf->go = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9942418676787815235ull);
    vlSelf->m_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13513209641359451005ull);
    vlSelf->n_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11416870543161471892ull);
    vlSelf->k_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4310807444499800468ull);
    vlSelf->ts_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14002556710298275605ull);
    vlSelf->ts_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10622247347642098698ull);
    vlSelf->csr_block_wrap__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 997228093130166247ull);
    vlSelf->csr_block_wrap__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3458750665803273340ull);
    vlSelf->csr_block_wrap__DOT__awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14696662717686445973ull);
    vlSelf->csr_block_wrap__DOT__awprot = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7464917145310197597ull);
    vlSelf->csr_block_wrap__DOT__awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14472269311409904201ull);
    vlSelf->csr_block_wrap__DOT__awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6545826060037596248ull);
    vlSelf->csr_block_wrap__DOT__wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15659260732852415929ull);
    vlSelf->csr_block_wrap__DOT__wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9724864991609665913ull);
    vlSelf->csr_block_wrap__DOT__wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17580278719634668937ull);
    vlSelf->csr_block_wrap__DOT__wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1987299748771579075ull);
    vlSelf->csr_block_wrap__DOT__bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8819966530938347375ull);
    vlSelf->csr_block_wrap__DOT__bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3945416136022069904ull);
    vlSelf->csr_block_wrap__DOT__bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18441536571214376337ull);
    vlSelf->csr_block_wrap__DOT__araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9081610127692783799ull);
    vlSelf->csr_block_wrap__DOT__arprot = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 9870349372605368242ull);
    vlSelf->csr_block_wrap__DOT__arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11738568054671312171ull);
    vlSelf->csr_block_wrap__DOT__arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9848188656897785763ull);
    vlSelf->csr_block_wrap__DOT__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18424729583998783778ull);
    vlSelf->csr_block_wrap__DOT__rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2875115022932643529ull);
    vlSelf->csr_block_wrap__DOT__rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18408781666901691689ull);
    vlSelf->csr_block_wrap__DOT__rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18079058663008342250ull);
    vlSelf->csr_block_wrap__DOT__go = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11237644602719035497ull);
    vlSelf->csr_block_wrap__DOT__m_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5164772367376527517ull);
    vlSelf->csr_block_wrap__DOT__n_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1072646472043105076ull);
    vlSelf->csr_block_wrap__DOT__k_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3984180565691943214ull);
    vlSelf->csr_block_wrap__DOT__ts_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11648496118638076060ull);
    vlSelf->csr_block_wrap__DOT__ts_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9715734825189044192ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__go = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7407935481876537420ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__m_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15805875396076298533ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__n_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1773947429756340652ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__k_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11232590264419434309ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__ts_busy = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6012113353897961107ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__ts_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14002173693454510777ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3851775996596419395ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12393769642992955104ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__reg_go = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9348762095294752900ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__reg_m_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 223406705852094302ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__reg_n_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10638839221180633725ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__reg_k_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18012901135686842896ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__reg_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16933063787719326498ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__wr_addr_lat = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 7660819849893331587ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__wr_data_lat = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 8068561618634152532ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__wr_commit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5484265708031143945ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__wr_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6939929004242082284ull);
    vlSelf->csr_block_wrap__DOT__dut__DOT__rd_state = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8042745611485040586ull);
    vlSelf->__Vdly__csr_block_wrap__DOT__dut__DOT__wr_state = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__csr_block_wrap__DOT__dut__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
