// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_axi_lite_if___ico_sequent__TOP__dma_controller_wrap__DOT__axil__0(Vtop_axi_lite_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi_lite_if___ico_sequent__TOP__dma_controller_wrap__DOT__axil__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.awready = vlSymsp->TOP.dma_controller_wrap__DOT__axil_awready;
    vlSelfRef.wready = vlSymsp->TOP.dma_controller_wrap__DOT__axil_wready;
    vlSelfRef.bvalid = vlSymsp->TOP.dma_controller_wrap__DOT__axil_bvalid;
    vlSelfRef.bresp = vlSymsp->TOP.dma_controller_wrap__DOT__axil_bresp;
    vlSelfRef.arready = vlSymsp->TOP.dma_controller_wrap__DOT__axil_arready;
    vlSelfRef.rvalid = vlSymsp->TOP.dma_controller_wrap__DOT__axil_rvalid;
    vlSelfRef.rdata = vlSymsp->TOP.dma_controller_wrap__DOT__axil_rdata;
    vlSelfRef.rresp = vlSymsp->TOP.dma_controller_wrap__DOT__axil_rresp;
    vlSelfRef.aclk = vlSymsp->TOP.dma_controller_wrap__DOT__clk;
    vlSelfRef.aresetn = vlSymsp->TOP.dma_controller_wrap__DOT__rst_n;
}

void Vtop_axi_lite_if___nba_sequent__TOP__dma_controller_wrap__DOT__axil__0(Vtop_axi_lite_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi_lite_if___nba_sequent__TOP__dma_controller_wrap__DOT__axil__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__bready = vlSelfRef.bready;
}

void Vtop_axi_lite_if___nba_sequent__TOP__dma_controller_wrap__DOT__axil__1(Vtop_axi_lite_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi_lite_if___nba_sequent__TOP__dma_controller_wrap__DOT__axil__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.bready = vlSelfRef.__Vdly__bready;
}
