// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 5> &out, const VlUnpacked<QData/*63:0*/, 5> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((4U >= n));
}

void Vtop___024root___eval_triggers_vec__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 5> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root___eval_triggers_vec__act(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vtop___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 5> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((5U > n));
}

bool Vtop___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 5> &in);
void Vtop___024root___eval_nba(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf);

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
            VL_FATAL_MT("compute_pipeline_wrap.sv", 14, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
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
            VL_FATAL_MT("compute_pipeline_wrap.sv", 14, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("compute_pipeline_wrap.sv", 14, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.csr_awprot & 0xf8U)))) {
        Verilated::overWidthError("csr_awprot");
    }
    if (VL_UNLIKELY(((vlSelfRef.csr_awvalid & 0xfeU)))) {
        Verilated::overWidthError("csr_awvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.csr_wstrb & 0xf0U)))) {
        Verilated::overWidthError("csr_wstrb");
    }
    if (VL_UNLIKELY(((vlSelfRef.csr_wvalid & 0xfeU)))) {
        Verilated::overWidthError("csr_wvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.csr_bready & 0xfeU)))) {
        Verilated::overWidthError("csr_bready");
    }
    if (VL_UNLIKELY(((vlSelfRef.csr_arprot & 0xf8U)))) {
        Verilated::overWidthError("csr_arprot");
    }
    if (VL_UNLIKELY(((vlSelfRef.csr_arvalid & 0xfeU)))) {
        Verilated::overWidthError("csr_arvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.csr_rready & 0xfeU)))) {
        Verilated::overWidthError("csr_rready");
    }
    if (VL_UNLIKELY(((vlSelfRef.fw_awvalid & 0xfeU)))) {
        Verilated::overWidthError("fw_awvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.fw_awid & 0xf0U)))) {
        Verilated::overWidthError("fw_awid");
    }
    if (VL_UNLIKELY(((vlSelfRef.fw_awsize & 0xf8U)))) {
        Verilated::overWidthError("fw_awsize");
    }
    if (VL_UNLIKELY(((vlSelfRef.fw_awburst & 0xfcU)))) {
        Verilated::overWidthError("fw_awburst");
    }
    if (VL_UNLIKELY(((vlSelfRef.fw_wvalid & 0xfeU)))) {
        Verilated::overWidthError("fw_wvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.fw_wlast & 0xfeU)))) {
        Verilated::overWidthError("fw_wlast");
    }
    if (VL_UNLIKELY(((vlSelfRef.fw_bready & 0xfeU)))) {
        Verilated::overWidthError("fw_bready");
    }
    if (VL_UNLIKELY(((vlSelfRef.fa_awvalid & 0xfeU)))) {
        Verilated::overWidthError("fa_awvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.fa_awid & 0xf0U)))) {
        Verilated::overWidthError("fa_awid");
    }
    if (VL_UNLIKELY(((vlSelfRef.fa_awsize & 0xf8U)))) {
        Verilated::overWidthError("fa_awsize");
    }
    if (VL_UNLIKELY(((vlSelfRef.fa_awburst & 0xfcU)))) {
        Verilated::overWidthError("fa_awburst");
    }
    if (VL_UNLIKELY(((vlSelfRef.fa_wvalid & 0xfeU)))) {
        Verilated::overWidthError("fa_wvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.fa_wlast & 0xfeU)))) {
        Verilated::overWidthError("fa_wlast");
    }
    if (VL_UNLIKELY(((vlSelfRef.fa_bready & 0xfeU)))) {
        Verilated::overWidthError("fa_bready");
    }
    if (VL_UNLIKELY(((vlSelfRef.ob_arvalid & 0xfeU)))) {
        Verilated::overWidthError("ob_arvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.ob_arid & 0xf0U)))) {
        Verilated::overWidthError("ob_arid");
    }
    if (VL_UNLIKELY(((vlSelfRef.ob_arsize & 0xf8U)))) {
        Verilated::overWidthError("ob_arsize");
    }
    if (VL_UNLIKELY(((vlSelfRef.ob_arburst & 0xfcU)))) {
        Verilated::overWidthError("ob_arburst");
    }
    if (VL_UNLIKELY(((vlSelfRef.ob_rready & 0xfeU)))) {
        Verilated::overWidthError("ob_rready");
    }
    if (VL_UNLIKELY(((vlSelfRef.init_done & 0xfeU)))) {
        Verilated::overWidthError("init_done");
    }
    if (VL_UNLIKELY(((vlSelfRef.writeback_done & 0xfeU)))) {
        Verilated::overWidthError("writeback_done");
    }
}
#endif  // VL_DEBUG
