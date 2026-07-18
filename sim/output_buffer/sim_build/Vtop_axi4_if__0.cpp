// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop_axi4_if___ico_sequent__TOP__output_buffer_wrap__DOT__c2h_axi__0(Vtop_axi4_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi4_if___ico_sequent__TOP__output_buffer_wrap__DOT__c2h_axi__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rdata[0U] = vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__mem
        [vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__beat_addr][0U];
    vlSelfRef.rdata[1U] = vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__mem
        [vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__beat_addr][1U];
    vlSelfRef.rdata[2U] = vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__mem
        [vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__beat_addr][2U];
    vlSelfRef.rdata[3U] = vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__mem
        [vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__beat_addr][3U];
    vlSelfRef.rlast = ((IData)(vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__state) 
                       & (0U == (IData)(vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__beat_count)));
    vlSelfRef.arvalid = vlSymsp->TOP.output_buffer_wrap__DOT__arvalid;
    vlSelfRef.arid = vlSymsp->TOP.output_buffer_wrap__DOT__arid;
    vlSelfRef.araddr = vlSymsp->TOP.output_buffer_wrap__DOT__araddr;
    vlSelfRef.arlen = vlSymsp->TOP.output_buffer_wrap__DOT__arlen;
    vlSelfRef.arsize = vlSymsp->TOP.output_buffer_wrap__DOT__arsize;
    vlSelfRef.arburst = vlSymsp->TOP.output_buffer_wrap__DOT__arburst;
    vlSelfRef.rready = vlSymsp->TOP.output_buffer_wrap__DOT__rready;
    vlSelfRef.aclk = vlSymsp->TOP.output_buffer_wrap__DOT__clk;
    vlSelfRef.aresetn = vlSymsp->TOP.output_buffer_wrap__DOT__rst_n;
}

void Vtop_axi4_if___nba_sequent__TOP__output_buffer_wrap__DOT__c2h_axi__0(Vtop_axi4_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi4_if___nba_sequent__TOP__output_buffer_wrap__DOT__c2h_axi__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vdly__arready = vlSelfRef.arready;
}

void Vtop_axi4_if___nba_sequent__TOP__output_buffer_wrap__DOT__c2h_axi__1(Vtop_axi4_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi4_if___nba_sequent__TOP__output_buffer_wrap__DOT__c2h_axi__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.arready = vlSelfRef.__Vdly__arready;
    vlSelfRef.rlast = ((IData)(vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__state) 
                       & (0U == (IData)(vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__beat_count)));
    vlSelfRef.rdata[0U] = vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__mem
        [vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__beat_addr][0U];
    vlSelfRef.rdata[1U] = vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__mem
        [vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__beat_addr][1U];
    vlSelfRef.rdata[2U] = vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__mem
        [vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__beat_addr][2U];
    vlSelfRef.rdata[3U] = vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__mem
        [vlSymsp->TOP.output_buffer_wrap__DOT__dut__DOT__beat_addr][3U];
}
