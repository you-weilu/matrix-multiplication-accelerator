// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_axi4_if___ico_sequent__TOP__compute_pipeline_wrap__DOT__fill_weight_axi__0(Vtop_axi4_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi4_if___ico_sequent__TOP__compute_pipeline_wrap__DOT__fill_weight_axi__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.awvalid = vlSymsp->TOP.compute_pipeline_wrap__DOT__fw_awvalid;
    vlSelfRef.awid = vlSymsp->TOP.compute_pipeline_wrap__DOT__fw_awid;
    vlSelfRef.awaddr = vlSymsp->TOP.compute_pipeline_wrap__DOT__fw_awaddr;
    vlSelfRef.awlen = vlSymsp->TOP.compute_pipeline_wrap__DOT__fw_awlen;
    vlSelfRef.awsize = vlSymsp->TOP.compute_pipeline_wrap__DOT__fw_awsize;
    vlSelfRef.awburst = vlSymsp->TOP.compute_pipeline_wrap__DOT__fw_awburst;
    vlSelfRef.wvalid = vlSymsp->TOP.compute_pipeline_wrap__DOT__fw_wvalid;
    vlSelfRef.wdata[0U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__fw_wdata[0U];
    vlSelfRef.wdata[1U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__fw_wdata[1U];
    vlSelfRef.wdata[2U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__fw_wdata[2U];
    vlSelfRef.wdata[3U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__fw_wdata[3U];
    vlSelfRef.wstrb = vlSymsp->TOP.compute_pipeline_wrap__DOT__fw_wstrb;
    vlSelfRef.wlast = vlSymsp->TOP.compute_pipeline_wrap__DOT__fw_wlast;
    vlSelfRef.bready = vlSymsp->TOP.compute_pipeline_wrap__DOT__fw_bready;
    vlSelfRef.aclk = vlSymsp->TOP.compute_pipeline_wrap__DOT__clk;
    vlSelfRef.aresetn = vlSymsp->TOP.compute_pipeline_wrap__DOT__rst_n;
}

void Vtop_axi4_if___ico_sequent__TOP__compute_pipeline_wrap__DOT__fill_act_axi__0(Vtop_axi4_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi4_if___ico_sequent__TOP__compute_pipeline_wrap__DOT__fill_act_axi__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.awvalid = vlSymsp->TOP.compute_pipeline_wrap__DOT__fa_awvalid;
    vlSelfRef.awid = vlSymsp->TOP.compute_pipeline_wrap__DOT__fa_awid;
    vlSelfRef.awaddr = vlSymsp->TOP.compute_pipeline_wrap__DOT__fa_awaddr;
    vlSelfRef.awlen = vlSymsp->TOP.compute_pipeline_wrap__DOT__fa_awlen;
    vlSelfRef.awsize = vlSymsp->TOP.compute_pipeline_wrap__DOT__fa_awsize;
    vlSelfRef.awburst = vlSymsp->TOP.compute_pipeline_wrap__DOT__fa_awburst;
    vlSelfRef.wvalid = vlSymsp->TOP.compute_pipeline_wrap__DOT__fa_wvalid;
    vlSelfRef.wdata[0U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__fa_wdata[0U];
    vlSelfRef.wdata[1U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__fa_wdata[1U];
    vlSelfRef.wdata[2U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__fa_wdata[2U];
    vlSelfRef.wdata[3U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__fa_wdata[3U];
    vlSelfRef.wstrb = vlSymsp->TOP.compute_pipeline_wrap__DOT__fa_wstrb;
    vlSelfRef.wlast = vlSymsp->TOP.compute_pipeline_wrap__DOT__fa_wlast;
    vlSelfRef.bready = vlSymsp->TOP.compute_pipeline_wrap__DOT__fa_bready;
    vlSelfRef.aclk = vlSymsp->TOP.compute_pipeline_wrap__DOT__clk;
    vlSelfRef.aresetn = vlSymsp->TOP.compute_pipeline_wrap__DOT__rst_n;
}

void Vtop_axi4_if___ico_sequent__TOP__compute_pipeline_wrap__DOT__c2h_axi__0(Vtop_axi4_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi4_if___ico_sequent__TOP__compute_pipeline_wrap__DOT__c2h_axi__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rdata[0U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__mem
        [vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__beat_addr][0U];
    vlSelfRef.rdata[1U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__mem
        [vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__beat_addr][1U];
    vlSelfRef.rdata[2U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__mem
        [vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__beat_addr][2U];
    vlSelfRef.rdata[3U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__mem
        [vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__beat_addr][3U];
    vlSelfRef.rlast = ((IData)(vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__state) 
                       & (0U == (IData)(vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__beat_count)));
    vlSelfRef.arvalid = vlSymsp->TOP.compute_pipeline_wrap__DOT__ob_arvalid;
    vlSelfRef.arid = vlSymsp->TOP.compute_pipeline_wrap__DOT__ob_arid;
    vlSelfRef.araddr = vlSymsp->TOP.compute_pipeline_wrap__DOT__ob_araddr;
    vlSelfRef.arlen = vlSymsp->TOP.compute_pipeline_wrap__DOT__ob_arlen;
    vlSelfRef.arsize = vlSymsp->TOP.compute_pipeline_wrap__DOT__ob_arsize;
    vlSelfRef.arburst = vlSymsp->TOP.compute_pipeline_wrap__DOT__ob_arburst;
    vlSelfRef.rready = vlSymsp->TOP.compute_pipeline_wrap__DOT__ob_rready;
    vlSelfRef.aclk = vlSymsp->TOP.compute_pipeline_wrap__DOT__clk;
    vlSelfRef.aresetn = vlSymsp->TOP.compute_pipeline_wrap__DOT__rst_n;
}

void Vtop_axi4_if___nba_sequent__TOP__compute_pipeline_wrap__DOT__c2h_axi__0(Vtop_axi4_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi4_if___nba_sequent__TOP__compute_pipeline_wrap__DOT__c2h_axi__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__arready = vlSelfRef.arready;
}

void Vtop_axi4_if___nba_sequent__TOP__compute_pipeline_wrap__DOT__c2h_axi__1(Vtop_axi4_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi4_if___nba_sequent__TOP__compute_pipeline_wrap__DOT__c2h_axi__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.arready = vlSelfRef.__Vdly__arready;
    vlSelfRef.rlast = ((IData)(vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__state) 
                       & (0U == (IData)(vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__beat_count)));
    vlSelfRef.rdata[0U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__mem
        [vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__beat_addr][0U];
    vlSelfRef.rdata[1U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__mem
        [vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__beat_addr][1U];
    vlSelfRef.rdata[2U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__mem
        [vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__beat_addr][2U];
    vlSelfRef.rdata[3U] = vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__mem
        [vlSymsp->TOP.compute_pipeline_wrap__DOT__u_outbuf__DOT__beat_addr][3U];
}
