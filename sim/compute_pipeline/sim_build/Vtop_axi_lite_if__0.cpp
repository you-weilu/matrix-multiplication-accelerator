// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_axi_lite_if___ico_sequent__TOP__compute_pipeline_wrap__DOT__csr_axi__0(Vtop_axi_lite_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi_lite_if___ico_sequent__TOP__compute_pipeline_wrap__DOT__csr_axi__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.awaddr = vlSymsp->TOP.compute_pipeline_wrap__DOT__csr_awaddr;
    vlSelfRef.awprot = vlSymsp->TOP.compute_pipeline_wrap__DOT__csr_awprot;
    vlSelfRef.awvalid = vlSymsp->TOP.compute_pipeline_wrap__DOT__csr_awvalid;
    vlSelfRef.wdata = vlSymsp->TOP.compute_pipeline_wrap__DOT__csr_wdata;
    vlSelfRef.wstrb = vlSymsp->TOP.compute_pipeline_wrap__DOT__csr_wstrb;
    vlSelfRef.wvalid = vlSymsp->TOP.compute_pipeline_wrap__DOT__csr_wvalid;
    vlSelfRef.araddr = vlSymsp->TOP.compute_pipeline_wrap__DOT__csr_araddr;
    vlSelfRef.arprot = vlSymsp->TOP.compute_pipeline_wrap__DOT__csr_arprot;
    vlSelfRef.arvalid = vlSymsp->TOP.compute_pipeline_wrap__DOT__csr_arvalid;
    vlSelfRef.rready = vlSymsp->TOP.compute_pipeline_wrap__DOT__csr_rready;
    vlSelfRef.bready = vlSymsp->TOP.compute_pipeline_wrap__DOT__csr_bready;
    vlSelfRef.aclk = vlSymsp->TOP.compute_pipeline_wrap__DOT__clk;
    vlSelfRef.aresetn = vlSymsp->TOP.compute_pipeline_wrap__DOT__rst_n;
}
