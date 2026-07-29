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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.dma_controller_wrap__DOT__fill_start 
        = vlSelfRef.fill_start;
    vlSelfRef.dma_controller_wrap__DOT__writeback_start 
        = vlSelfRef.writeback_start;
    vlSelfRef.dma_controller_wrap__DOT__writeback_done 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__writeback_done;
    vlSelfRef.dma_controller_wrap__DOT__axil_awvalid 
        = vlSymsp->TOP__dma_controller_wrap__DOT__axil.awvalid;
    vlSelfRef.dma_controller_wrap__DOT__axil_awready 
        = vlSelfRef.axil_awready;
    vlSelfRef.dma_controller_wrap__DOT__axil_awaddr 
        = vlSymsp->TOP__dma_controller_wrap__DOT__axil.awaddr;
    vlSelfRef.dma_controller_wrap__DOT__axil_awprot 
        = vlSymsp->TOP__dma_controller_wrap__DOT__axil.awprot;
    vlSelfRef.dma_controller_wrap__DOT__axil_wvalid 
        = vlSymsp->TOP__dma_controller_wrap__DOT__axil.wvalid;
    vlSelfRef.dma_controller_wrap__DOT__axil_wready 
        = vlSelfRef.axil_wready;
    vlSelfRef.dma_controller_wrap__DOT__axil_wdata 
        = vlSymsp->TOP__dma_controller_wrap__DOT__axil.wdata;
    vlSelfRef.dma_controller_wrap__DOT__axil_wstrb 
        = vlSymsp->TOP__dma_controller_wrap__DOT__axil.wstrb;
    vlSelfRef.dma_controller_wrap__DOT__axil_bvalid 
        = vlSelfRef.axil_bvalid;
    vlSelfRef.dma_controller_wrap__DOT__axil_bready 
        = vlSymsp->TOP__dma_controller_wrap__DOT__axil.bready;
    vlSelfRef.dma_controller_wrap__DOT__axil_bresp 
        = vlSelfRef.axil_bresp;
    vlSelfRef.dma_controller_wrap__DOT__axil_arvalid 
        = vlSymsp->TOP__dma_controller_wrap__DOT__axil.arvalid;
    vlSelfRef.dma_controller_wrap__DOT__axil_arready 
        = vlSelfRef.axil_arready;
    vlSelfRef.dma_controller_wrap__DOT__axil_araddr 
        = vlSymsp->TOP__dma_controller_wrap__DOT__axil.araddr;
    vlSelfRef.dma_controller_wrap__DOT__axil_arprot 
        = vlSymsp->TOP__dma_controller_wrap__DOT__axil.arprot;
    vlSelfRef.dma_controller_wrap__DOT__axil_rvalid 
        = vlSelfRef.axil_rvalid;
    vlSelfRef.dma_controller_wrap__DOT__axil_rready 
        = vlSymsp->TOP__dma_controller_wrap__DOT__axil.rready;
    vlSelfRef.dma_controller_wrap__DOT__axil_rdata 
        = vlSelfRef.axil_rdata;
    vlSelfRef.dma_controller_wrap__DOT__axil_rresp 
        = vlSelfRef.axil_rresp;
    vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_ready_0 
        = vlSelfRef.h2c_dsc_byp_ready_0;
    vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_load_0 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_0;
    vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_len_0 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_len_0;
    vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_ctl_0 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ctl_0;
    vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_ready_1 
        = vlSelfRef.h2c_dsc_byp_ready_1;
    vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_load_1 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_1;
    vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_len_1 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_len_1;
    vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_ctl_1 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ctl_1;
    vlSelfRef.dma_controller_wrap__DOT__c2h_dsc_byp_ready_0 
        = vlSelfRef.c2h_dsc_byp_ready_0;
    vlSelfRef.dma_controller_wrap__DOT__c2h_dsc_byp_load_0 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_load_0;
    vlSelfRef.dma_controller_wrap__DOT__c2h_dsc_byp_len_0 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_len_0;
    vlSelfRef.dma_controller_wrap__DOT__c2h_dsc_byp_ctl_0 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_ctl_0;
    vlSelfRef.dma_controller_wrap__DOT__h2c_sts_0 = vlSelfRef.h2c_sts_0;
    vlSelfRef.dma_controller_wrap__DOT__h2c_sts_1 = vlSelfRef.h2c_sts_1;
    vlSelfRef.dma_controller_wrap__DOT__c2h_sts_0 = vlSelfRef.c2h_sts_0;
    vlSelfRef.dma_controller_wrap__DOT__clk = vlSelfRef.clk;
    vlSelfRef.dma_controller_wrap__DOT__rst_n = vlSelfRef.rst_n;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__init_done 
        = (3U == (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__init_state));
    vlSelfRef.dma_controller_wrap__DOT__pp_weight_axi_base 
        = vlSelfRef.pp_weight_axi_base;
    vlSelfRef.dma_controller_wrap__DOT__pp_act_axi_base 
        = vlSelfRef.pp_act_axi_base;
    vlSelfRef.dma_controller_wrap__DOT__output_buf_axi_base 
        = vlSelfRef.output_buf_axi_base;
    vlSelfRef.dma_controller_wrap__DOT__base_addr_a 
        = vlSelfRef.base_addr_a;
    vlSelfRef.dma_controller_wrap__DOT__base_addr_b 
        = vlSelfRef.base_addr_b;
    vlSelfRef.dma_controller_wrap__DOT__base_addr_c 
        = vlSelfRef.base_addr_c;
    vlSelfRef.dma_controller_wrap__DOT__n_tiles = vlSelfRef.n_tiles;
    vlSelfRef.dma_controller_wrap__DOT__tile_i = vlSelfRef.tile_i;
    vlSelfRef.dma_controller_wrap__DOT__tile_j = vlSelfRef.tile_j;
    vlSelfRef.dma_controller_wrap__DOT__k_tile = vlSelfRef.k_tile;
    vlSelfRef.dma_controller_wrap__DOT__k_tiles = vlSelfRef.k_tiles;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__fill_start 
        = vlSelfRef.dma_controller_wrap__DOT__fill_start;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__writeback_start 
        = vlSelfRef.dma_controller_wrap__DOT__writeback_start;
    vlSelfRef.writeback_done = vlSelfRef.dma_controller_wrap__DOT__writeback_done;
    vlSelfRef.axil_awvalid = vlSelfRef.dma_controller_wrap__DOT__axil_awvalid;
    vlSelfRef.axil_awaddr = vlSelfRef.dma_controller_wrap__DOT__axil_awaddr;
    vlSelfRef.axil_awprot = vlSelfRef.dma_controller_wrap__DOT__axil_awprot;
    vlSelfRef.axil_wvalid = vlSelfRef.dma_controller_wrap__DOT__axil_wvalid;
    vlSelfRef.axil_wdata = vlSelfRef.dma_controller_wrap__DOT__axil_wdata;
    vlSelfRef.axil_wstrb = vlSelfRef.dma_controller_wrap__DOT__axil_wstrb;
    vlSelfRef.axil_bready = vlSelfRef.dma_controller_wrap__DOT__axil_bready;
    vlSelfRef.axil_arvalid = vlSelfRef.dma_controller_wrap__DOT__axil_arvalid;
    vlSelfRef.axil_araddr = vlSelfRef.dma_controller_wrap__DOT__axil_araddr;
    vlSelfRef.axil_arprot = vlSelfRef.dma_controller_wrap__DOT__axil_arprot;
    vlSelfRef.axil_rready = vlSelfRef.dma_controller_wrap__DOT__axil_rready;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ready_0 
        = vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_ready_0;
    vlSelfRef.h2c_dsc_byp_load_0 = vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_load_0;
    vlSelfRef.h2c_dsc_byp_len_0 = vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_len_0;
    vlSelfRef.h2c_dsc_byp_ctl_0 = vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_ctl_0;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ready_1 
        = vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_ready_1;
    vlSelfRef.h2c_dsc_byp_load_1 = vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_load_1;
    vlSelfRef.h2c_dsc_byp_len_1 = vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_len_1;
    vlSelfRef.h2c_dsc_byp_ctl_1 = vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_ctl_1;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_ready_0 
        = vlSelfRef.dma_controller_wrap__DOT__c2h_dsc_byp_ready_0;
    vlSelfRef.c2h_dsc_byp_load_0 = vlSelfRef.dma_controller_wrap__DOT__c2h_dsc_byp_load_0;
    vlSelfRef.c2h_dsc_byp_len_0 = vlSelfRef.dma_controller_wrap__DOT__c2h_dsc_byp_len_0;
    vlSelfRef.c2h_dsc_byp_ctl_0 = vlSelfRef.dma_controller_wrap__DOT__c2h_dsc_byp_ctl_0;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_sts_0 
        = vlSelfRef.dma_controller_wrap__DOT__h2c_sts_0;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_sts_1 
        = vlSelfRef.dma_controller_wrap__DOT__h2c_sts_1;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_sts_0 
        = vlSelfRef.dma_controller_wrap__DOT__c2h_sts_0;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__clk 
        = vlSelfRef.dma_controller_wrap__DOT__clk;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__rst_n 
        = vlSelfRef.dma_controller_wrap__DOT__rst_n;
    vlSelfRef.dma_controller_wrap__DOT__init_done = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__init_done;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__pp_weight_axi_base 
        = vlSelfRef.dma_controller_wrap__DOT__pp_weight_axi_base;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__pp_act_axi_base 
        = vlSelfRef.dma_controller_wrap__DOT__pp_act_axi_base;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__output_buf_axi_base 
        = vlSelfRef.dma_controller_wrap__DOT__output_buf_axi_base;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__base_addr_a 
        = vlSelfRef.dma_controller_wrap__DOT__base_addr_a;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__base_addr_b 
        = vlSelfRef.dma_controller_wrap__DOT__base_addr_b;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__base_addr_c 
        = vlSelfRef.dma_controller_wrap__DOT__base_addr_c;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__n_tiles 
        = vlSelfRef.dma_controller_wrap__DOT__n_tiles;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__tile_i 
        = vlSelfRef.dma_controller_wrap__DOT__tile_i;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__tile_j 
        = vlSelfRef.dma_controller_wrap__DOT__tile_j;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__k_tile 
        = vlSelfRef.dma_controller_wrap__DOT__k_tile;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__k_tiles 
        = vlSelfRef.dma_controller_wrap__DOT__k_tiles;
    vlSelfRef.init_done = vlSelfRef.dma_controller_wrap__DOT__init_done;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_dst_addr_0 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__pp_weight_axi_base;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_dst_addr_1 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__pp_act_axi_base;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_src_addr_0 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__output_buf_axi_base;
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_dst_addr_0 
        = (vlSelfRef.dma_controller_wrap__DOT__dut__DOT__base_addr_c 
           + ((((QData)((IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__n_tiles)) 
                * (QData)((IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__tile_i))) 
               + (QData)((IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__tile_j))) 
              << 0x0000000aU));
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_src_addr_0 
        = (vlSelfRef.dma_controller_wrap__DOT__dut__DOT__base_addr_b 
           + (((QData)((IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__k_tile)) 
               + ((QData)((IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__k_tiles)) 
                  * (QData)((IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__tile_j)))) 
              << 8U));
    vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_src_addr_1 
        = (vlSelfRef.dma_controller_wrap__DOT__dut__DOT__base_addr_a 
           + (((QData)((IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__k_tile)) 
               + ((QData)((IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__tile_i)) 
                  * (QData)((IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__k_tiles)))) 
              << 8U));
    vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_dst_addr_0 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_dst_addr_0;
    vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_dst_addr_1 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_dst_addr_1;
    vlSelfRef.dma_controller_wrap__DOT__c2h_dsc_byp_src_addr_0 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_src_addr_0;
    vlSelfRef.dma_controller_wrap__DOT__c2h_dsc_byp_dst_addr_0 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_dst_addr_0;
    vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_src_addr_0 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_src_addr_0;
    vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_src_addr_1 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_src_addr_1;
    vlSelfRef.h2c_dsc_byp_dst_addr_0 = vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_dst_addr_0;
    vlSelfRef.h2c_dsc_byp_dst_addr_1 = vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_dst_addr_1;
    vlSelfRef.c2h_dsc_byp_src_addr_0 = vlSelfRef.dma_controller_wrap__DOT__c2h_dsc_byp_src_addr_0;
    vlSelfRef.c2h_dsc_byp_dst_addr_0 = vlSelfRef.dma_controller_wrap__DOT__c2h_dsc_byp_dst_addr_0;
    vlSelfRef.h2c_dsc_byp_src_addr_0 = vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_src_addr_0;
    vlSelfRef.h2c_dsc_byp_src_addr_1 = vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_src_addr_1;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
void Vtop_axi_lite_if___ico_sequent__TOP__dma_controller_wrap__DOT__axil__0(Vtop_axi_lite_if* vlSelf);

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
                Vtop___024root___ico_sequent__TOP__0(vlSelf);
                Vtop_axi_lite_if___ico_sequent__TOP__dma_controller_wrap__DOT__axil__0((&vlSymsp->TOP__dma_controller_wrap__DOT__axil));
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

void Vtop_axi_lite_if___nba_sequent__TOP__dma_controller_wrap__DOT__axil__0(Vtop_axi_lite_if* vlSelf);
void Vtop_axi_lite_if___nba_sequent__TOP__dma_controller_wrap__DOT__axil__1(Vtop_axi_lite_if* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_sequent__TOP__0
            CData/*1:0*/ __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__w_state;
            __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__w_state = 0;
            CData/*1:0*/ __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__a_state;
            __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__a_state = 0;
            CData/*1:0*/ __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__c_state;
            __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__c_state = 0;
            __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__w_state 
                = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__w_state;
            __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__a_state 
                = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__a_state;
            __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__c_state 
                = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c_state;
            vlSelfRef.__Vdly__dma_controller_wrap__DOT__dut__DOT__reg_idx 
                = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__reg_idx;
            vlSelfRef.__Vdly__dma_controller_wrap__DOT__dut__DOT__init_state 
                = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__init_state;
            if (vlSelfRef.dma_controller_wrap__DOT__dut__DOT__rst_n) {
                vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_0 = 0U;
                if ((0U == (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__w_state))) {
                    if (vlSelfRef.dma_controller_wrap__DOT__dut__DOT__fill_start) {
                        __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__w_state = 1U;
                    }
                } else if ((1U == (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__w_state))) {
                    if (vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ready_0) {
                        vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_0 = 1U;
                        __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__w_state = 2U;
                    }
                } else if ((2U == (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__w_state))) {
                    if ((8U & (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_sts_0))) {
                        __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__w_state = 0U;
                    }
                } else {
                    __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__w_state = 0U;
                }
                vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_1 = 0U;
                if ((0U == (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__a_state))) {
                    if (vlSelfRef.dma_controller_wrap__DOT__dut__DOT__fill_start) {
                        __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__a_state = 1U;
                    }
                } else if ((1U == (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__a_state))) {
                    if (vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ready_1) {
                        vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_1 = 1U;
                        __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__a_state = 2U;
                    }
                } else if ((2U == (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__a_state))) {
                    if ((8U & (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_sts_1))) {
                        __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__a_state = 0U;
                    }
                } else {
                    __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__a_state = 0U;
                }
                vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_load_0 = 0U;
                vlSelfRef.dma_controller_wrap__DOT__dut__DOT__writeback_done = 0U;
                if ((0U == (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c_state))) {
                    if (vlSelfRef.dma_controller_wrap__DOT__dut__DOT__writeback_start) {
                        __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__c_state = 1U;
                    }
                } else if ((1U == (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c_state))) {
                    if (vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_ready_0) {
                        vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_load_0 = 1U;
                        __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__c_state = 2U;
                    }
                } else if ((2U == (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c_state))) {
                    if ((8U & (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_sts_0))) {
                        vlSelfRef.dma_controller_wrap__DOT__dut__DOT__writeback_done = 1U;
                        __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__c_state = 0U;
                    }
                } else {
                    __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__c_state = 0U;
                }
            } else {
                __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__w_state = 0U;
                vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_0 = 0U;
                __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__a_state = 0U;
                vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_1 = 0U;
                __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__c_state = 0U;
                vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_load_0 = 0U;
                vlSelfRef.dma_controller_wrap__DOT__dut__DOT__writeback_done = 0U;
            }
            vlSelfRef.dma_controller_wrap__DOT__dut__DOT__w_state 
                = __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__w_state;
            vlSelfRef.dma_controller_wrap__DOT__dut__DOT__a_state 
                = __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__a_state;
            vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c_state 
                = __Vinline_0__nba_sequent__TOP__0___Vdly__dma_controller_wrap__DOT__dut__DOT__c_state;
            vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_load_0 
                = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_0;
            vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_load_1 
                = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_1;
            vlSelfRef.dma_controller_wrap__DOT__c2h_dsc_byp_load_0 
                = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_load_0;
            vlSelfRef.dma_controller_wrap__DOT__writeback_done 
                = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__writeback_done;
            vlSelfRef.h2c_dsc_byp_load_0 = vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_load_0;
            vlSelfRef.h2c_dsc_byp_load_1 = vlSelfRef.dma_controller_wrap__DOT__h2c_dsc_byp_load_1;
            vlSelfRef.c2h_dsc_byp_load_0 = vlSelfRef.dma_controller_wrap__DOT__c2h_dsc_byp_load_0;
            vlSelfRef.writeback_done = vlSelfRef.dma_controller_wrap__DOT__writeback_done;
        }
        Vtop_axi_lite_if___nba_sequent__TOP__dma_controller_wrap__DOT__axil__0((&vlSymsp->TOP__dma_controller_wrap__DOT__axil));
        {
            // Inlined CFunc: _nba_sequent__TOP__1
            if (vlSelfRef.dma_controller_wrap__DOT__dut__DOT__rst_n) {
                if ((2U & (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__init_state))) {
                    if ((1U & (~ (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__init_state)))) {
                        vlSymsp->TOP__dma_controller_wrap__DOT__axil.__Vdly__bready = 1U;
                        if (((IData)(vlSymsp->TOP__dma_controller_wrap__DOT__axil.bvalid) 
                             & (IData)(vlSymsp->TOP__dma_controller_wrap__DOT__axil.bready))) {
                            vlSymsp->TOP__dma_controller_wrap__DOT__axil.__Vdly__bready = 0U;
                            if ((2U == (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__reg_idx))) {
                                vlSelfRef.__Vdly__dma_controller_wrap__DOT__dut__DOT__init_state = 3U;
                            } else {
                                vlSelfRef.__Vdly__dma_controller_wrap__DOT__dut__DOT__reg_idx 
                                    = (3U & ((IData)(1U) 
                                             + (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__reg_idx)));
                                vlSelfRef.__Vdly__dma_controller_wrap__DOT__dut__DOT__init_state = 0U;
                            }
                        }
                    }
                } else if ((1U & (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__init_state))) {
                    vlSymsp->TOP__dma_controller_wrap__DOT__axil.wvalid = 1U;
                    vlSymsp->TOP__dma_controller_wrap__DOT__axil.wdata = 1U;
                    vlSymsp->TOP__dma_controller_wrap__DOT__axil.wstrb = 0x0fU;
                    if (vlSymsp->TOP__dma_controller_wrap__DOT__axil.wready) {
                        vlSymsp->TOP__dma_controller_wrap__DOT__axil.wvalid = 0U;
                        vlSelfRef.__Vdly__dma_controller_wrap__DOT__dut__DOT__init_state = 2U;
                    }
                } else {
                    vlSymsp->TOP__dma_controller_wrap__DOT__axil.awvalid = 1U;
                    vlSymsp->TOP__dma_controller_wrap__DOT__axil.awaddr 
                        = ((2U >= (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__reg_idx))
                            ? vlSelfRef.dma_controller_wrap__DOT__dut__DOT__INIT_ADDRS
                           [vlSelfRef.dma_controller_wrap__DOT__dut__DOT__reg_idx]
                            : 0U);
                    vlSymsp->TOP__dma_controller_wrap__DOT__axil.awprot = 0U;
                    if (vlSymsp->TOP__dma_controller_wrap__DOT__axil.awready) {
                        vlSymsp->TOP__dma_controller_wrap__DOT__axil.awvalid = 0U;
                        vlSelfRef.__Vdly__dma_controller_wrap__DOT__dut__DOT__init_state = 1U;
                    }
                }
            } else {
                vlSelfRef.__Vdly__dma_controller_wrap__DOT__dut__DOT__reg_idx = 0U;
                vlSymsp->TOP__dma_controller_wrap__DOT__axil.__Vdly__bready = 0U;
                vlSelfRef.__Vdly__dma_controller_wrap__DOT__dut__DOT__init_state = 0U;
                vlSymsp->TOP__dma_controller_wrap__DOT__axil.awvalid = 0U;
                vlSymsp->TOP__dma_controller_wrap__DOT__axil.wvalid = 0U;
            }
            vlSelfRef.dma_controller_wrap__DOT__dut__DOT__reg_idx 
                = vlSelfRef.__Vdly__dma_controller_wrap__DOT__dut__DOT__reg_idx;
            vlSelfRef.dma_controller_wrap__DOT__dut__DOT__init_state 
                = vlSelfRef.__Vdly__dma_controller_wrap__DOT__dut__DOT__init_state;
            vlSelfRef.dma_controller_wrap__DOT__dut__DOT__init_done 
                = (3U == (IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__init_state));
            vlSelfRef.dma_controller_wrap__DOT__init_done 
                = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__init_done;
            vlSelfRef.init_done = vlSelfRef.dma_controller_wrap__DOT__init_done;
        }
        Vtop_axi_lite_if___nba_sequent__TOP__dma_controller_wrap__DOT__axil__1((&vlSymsp->TOP__dma_controller_wrap__DOT__axil));
        {
            // Inlined CFunc: _nba_sequent__TOP__2
            vlSelfRef.dma_controller_wrap__DOT__axil_bready 
                = vlSymsp->TOP__dma_controller_wrap__DOT__axil.bready;
            vlSelfRef.dma_controller_wrap__DOT__axil_wvalid 
                = vlSymsp->TOP__dma_controller_wrap__DOT__axil.wvalid;
            vlSelfRef.dma_controller_wrap__DOT__axil_wdata 
                = vlSymsp->TOP__dma_controller_wrap__DOT__axil.wdata;
            vlSelfRef.dma_controller_wrap__DOT__axil_wstrb 
                = vlSymsp->TOP__dma_controller_wrap__DOT__axil.wstrb;
            vlSelfRef.dma_controller_wrap__DOT__axil_awvalid 
                = vlSymsp->TOP__dma_controller_wrap__DOT__axil.awvalid;
            vlSelfRef.dma_controller_wrap__DOT__axil_awaddr 
                = vlSymsp->TOP__dma_controller_wrap__DOT__axil.awaddr;
            vlSelfRef.dma_controller_wrap__DOT__axil_awprot 
                = vlSymsp->TOP__dma_controller_wrap__DOT__axil.awprot;
            vlSelfRef.axil_bready = vlSelfRef.dma_controller_wrap__DOT__axil_bready;
            vlSelfRef.axil_wvalid = vlSelfRef.dma_controller_wrap__DOT__axil_wvalid;
            vlSelfRef.axil_wdata = vlSelfRef.dma_controller_wrap__DOT__axil_wdata;
            vlSelfRef.axil_wstrb = vlSelfRef.dma_controller_wrap__DOT__axil_wstrb;
            vlSelfRef.axil_awvalid = vlSelfRef.dma_controller_wrap__DOT__axil_awvalid;
            vlSelfRef.axil_awaddr = vlSelfRef.dma_controller_wrap__DOT__axil_awaddr;
            vlSelfRef.axil_awprot = vlSelfRef.dma_controller_wrap__DOT__axil_awprot;
        }
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
                                                        ((IData)(vlSelfRef.dma_controller_wrap__DOT__dut__DOT__clk) 
                                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__dma_controller_wrap__DOT__dut__DOT__clk__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__dma_controller_wrap__DOT__dut__DOT__clk__0 
            = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__clk;
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
            VL_FATAL_MT("dma_controller_wrap.sv", 2, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
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
            VL_FATAL_MT("dma_controller_wrap.sv", 2, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("dma_controller_wrap.sv", 2, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.fill_start & 0xfeU)))) {
        Verilated::overWidthError("fill_start");
    }
    if (VL_UNLIKELY(((vlSelfRef.writeback_start & 0xfeU)))) {
        Verilated::overWidthError("writeback_start");
    }
    if (VL_UNLIKELY(((vlSelfRef.axil_awready & 0xfeU)))) {
        Verilated::overWidthError("axil_awready");
    }
    if (VL_UNLIKELY(((vlSelfRef.axil_wready & 0xfeU)))) {
        Verilated::overWidthError("axil_wready");
    }
    if (VL_UNLIKELY(((vlSelfRef.axil_bvalid & 0xfeU)))) {
        Verilated::overWidthError("axil_bvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.axil_bresp & 0xfcU)))) {
        Verilated::overWidthError("axil_bresp");
    }
    if (VL_UNLIKELY(((vlSelfRef.axil_arready & 0xfeU)))) {
        Verilated::overWidthError("axil_arready");
    }
    if (VL_UNLIKELY(((vlSelfRef.axil_rvalid & 0xfeU)))) {
        Verilated::overWidthError("axil_rvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.axil_rresp & 0xfcU)))) {
        Verilated::overWidthError("axil_rresp");
    }
    if (VL_UNLIKELY(((vlSelfRef.h2c_dsc_byp_ready_0 
                      & 0xfeU)))) {
        Verilated::overWidthError("h2c_dsc_byp_ready_0");
    }
    if (VL_UNLIKELY(((vlSelfRef.h2c_dsc_byp_ready_1 
                      & 0xfeU)))) {
        Verilated::overWidthError("h2c_dsc_byp_ready_1");
    }
    if (VL_UNLIKELY(((vlSelfRef.c2h_dsc_byp_ready_0 
                      & 0xfeU)))) {
        Verilated::overWidthError("c2h_dsc_byp_ready_0");
    }
}
#endif  // VL_DEBUG
