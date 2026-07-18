// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop_axi4_if___eval_initial__TOP__output_buffer_wrap__DOT__c2h_axi(Vtop_axi4_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi4_if___eval_initial__TOP__output_buffer_wrap__DOT__c2h_axi\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rresp = 0U;
    vlSelfRef.awvalid = 0U;
    vlSelfRef.awid = 0U;
    vlSelfRef.awaddr = 0ULL;
    vlSelfRef.awlen = 0U;
    vlSelfRef.awsize = 0U;
    vlSelfRef.awburst = 0U;
    vlSelfRef.wvalid = 0U;
    vlSelfRef.wdata[0U] = 0U;
    vlSelfRef.wdata[1U] = 0U;
    vlSelfRef.wdata[2U] = 0U;
    vlSelfRef.wdata[3U] = 0U;
    vlSelfRef.wstrb = 0U;
    vlSelfRef.wlast = 0U;
    vlSelfRef.bready = 0U;
    vlSelfRef.awready = 0U;
    vlSelfRef.wready = 0U;
    vlSelfRef.bvalid = 0U;
    vlSelfRef.bresp = 0U;
}

VL_ATTR_COLD void Vtop_axi4_if___ctor_var_reset(Vtop_axi4_if* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          Vtop_axi4_if___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->aclk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10553736683680568397ull);
    vlSelf->aresetn = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8123012239402083478ull);
    vlSelf->awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14077405313628979207ull);
    vlSelf->awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9399710217136046492ull);
    vlSelf->awid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3795331727834872933ull);
    vlSelf->awaddr = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10741232094138379896ull);
    vlSelf->awlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13823799410002427218ull);
    vlSelf->awsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14063175441069765856ull);
    vlSelf->awburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2194945690521623954ull);
    vlSelf->wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13135585445238253745ull);
    vlSelf->wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2694481459927628098ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->wdata, __VscopeHash, 12890271867161903902ull);
    vlSelf->wstrb = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 15125268524300477597ull);
    vlSelf->wlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8447900327780902047ull);
    vlSelf->bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14655036748745407948ull);
    vlSelf->bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16336171827316305440ull);
    vlSelf->bid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3323000146968766057ull);
    vlSelf->bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 3607396732575112162ull);
    vlSelf->arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16774798297805906817ull);
    vlSelf->arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2587622265565774708ull);
    vlSelf->arid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2554568685633023ull);
    vlSelf->araddr = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 17685200476622543275ull);
    vlSelf->arlen = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2795619241893056918ull);
    vlSelf->arsize = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 548378465311237866ull);
    vlSelf->arburst = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17635634856046503333ull);
    vlSelf->rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14125721737830190460ull);
    vlSelf->rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8930348232195030647ull);
    vlSelf->rid = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17711635114162165067ull);
    VL_SCOPED_RAND_RESET_W(128, vlSelf->rdata, __VscopeHash, 10065165116613087284ull);
    vlSelf->rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 810448354640171968ull);
    vlSelf->rlast = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5670148758994432807ull);
    vlSelf->__Vdly__arready = 0;
}
