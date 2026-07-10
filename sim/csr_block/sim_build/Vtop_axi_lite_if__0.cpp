// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_axi_lite_if___ico_sequent__TOP__csr_block_wrap__DOT__csr_axi__0(Vtop_axi_lite_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi_lite_if___ico_sequent__TOP__csr_block_wrap__DOT__csr_axi__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.awaddr = vlSymsp->TOP.csr_block_wrap__DOT__awaddr;
    vlSelfRef.awprot = vlSymsp->TOP.csr_block_wrap__DOT__awprot;
    vlSelfRef.awvalid = vlSymsp->TOP.csr_block_wrap__DOT__awvalid;
    vlSelfRef.wdata = vlSymsp->TOP.csr_block_wrap__DOT__wdata;
    vlSelfRef.wstrb = vlSymsp->TOP.csr_block_wrap__DOT__wstrb;
    vlSelfRef.wvalid = vlSymsp->TOP.csr_block_wrap__DOT__wvalid;
    vlSelfRef.araddr = vlSymsp->TOP.csr_block_wrap__DOT__araddr;
    vlSelfRef.arprot = vlSymsp->TOP.csr_block_wrap__DOT__arprot;
    vlSelfRef.arvalid = vlSymsp->TOP.csr_block_wrap__DOT__arvalid;
    vlSelfRef.rready = vlSymsp->TOP.csr_block_wrap__DOT__rready;
    vlSelfRef.aclk = vlSymsp->TOP.csr_block_wrap__DOT__clk;
    vlSelfRef.aresetn = vlSymsp->TOP.csr_block_wrap__DOT__rst_n;
    vlSelfRef.bready = vlSymsp->TOP.csr_block_wrap__DOT__bready;
}
