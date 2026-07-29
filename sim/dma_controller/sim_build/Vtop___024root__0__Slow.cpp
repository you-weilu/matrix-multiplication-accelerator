// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__dma_controller_wrap__DOT__dut__DOT__clk__0 
        = vlSelfRef.dma_controller_wrap__DOT__dut__DOT__clk;
}

VL_ATTR_COLD void Vtop_axi_lite_if___eval_initial__TOP__dma_controller_wrap__DOT__axil(Vtop_axi_lite_if* vlSelf);

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_len_0 = 0x00000100U;
        vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ctl_0 = 3U;
        vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_len_1 = 0x00000100U;
        vlSelfRef.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ctl_1 = 3U;
        vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_len_0 = 0x00000400U;
        vlSelfRef.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_ctl_0 = 3U;
    }
    Vtop_axi_lite_if___eval_initial__TOP__dma_controller_wrap__DOT__axil((&vlSymsp->TOP__dma_controller_wrap__DOT__axil));
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
            VL_FATAL_MT("dma_controller_wrap.sv", 2, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 10000 tries");
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
void Vtop_axi_lite_if___ico_sequent__TOP__dma_controller_wrap__DOT__axil__0(Vtop_axi_lite_if* vlSelf);

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
                Vtop_axi_lite_if___ico_sequent__TOP__dma_controller_wrap__DOT__axil__0((&vlSymsp->TOP__dma_controller_wrap__DOT__axil));
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge dma_controller_wrap.dut.clk)\n");
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
    vlSelf->fill_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12514334226953459133ull);
    vlSelf->writeback_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12070831044157274392ull);
    vlSelf->tile_i = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17738761636903319141ull);
    vlSelf->tile_j = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 678514002863363964ull);
    vlSelf->k_tile = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5641551249870019250ull);
    vlSelf->base_addr_a = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4968268523320223095ull);
    vlSelf->base_addr_b = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8103509870780299253ull);
    vlSelf->base_addr_c = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1922401070092935823ull);
    vlSelf->k_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4310807444499800468ull);
    vlSelf->n_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11416870543161471892ull);
    vlSelf->pp_weight_axi_base = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2792521278938100975ull);
    vlSelf->pp_act_axi_base = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14549567959671694631ull);
    vlSelf->output_buf_axi_base = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8497775383935423146ull);
    vlSelf->writeback_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14023772087719021166ull);
    vlSelf->init_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13642578072536774985ull);
    vlSelf->axil_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 53887506674697437ull);
    vlSelf->axil_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11280912013677280673ull);
    vlSelf->axil_awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1920525979676961978ull);
    vlSelf->axil_awprot = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14631318902665053440ull);
    vlSelf->axil_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9631877390738867953ull);
    vlSelf->axil_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11634533003368264159ull);
    vlSelf->axil_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9275542371487604846ull);
    vlSelf->axil_wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9523256507973966445ull);
    vlSelf->axil_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14603309044227579681ull);
    vlSelf->axil_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 659735141704856389ull);
    vlSelf->axil_bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13594267840613266084ull);
    vlSelf->axil_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12348380811571764281ull);
    vlSelf->axil_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18407107678386603798ull);
    vlSelf->axil_araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6155571341973983676ull);
    vlSelf->axil_arprot = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6056944832381051923ull);
    vlSelf->axil_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10668020559640439403ull);
    vlSelf->axil_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4954236880298128893ull);
    vlSelf->axil_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12101726123492654325ull);
    vlSelf->axil_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14086912507644079708ull);
    vlSelf->h2c_dsc_byp_ready_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7501496745938927015ull);
    vlSelf->h2c_dsc_byp_load_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8011004696705953ull);
    vlSelf->h2c_dsc_byp_src_addr_0 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1207457825352866137ull);
    vlSelf->h2c_dsc_byp_dst_addr_0 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11974052232255880706ull);
    vlSelf->h2c_dsc_byp_len_0 = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 14015956918061242809ull);
    vlSelf->h2c_dsc_byp_ctl_0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 1746197073812151994ull);
    vlSelf->h2c_dsc_byp_ready_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18022018129360821615ull);
    vlSelf->h2c_dsc_byp_load_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17478086975459963497ull);
    vlSelf->h2c_dsc_byp_src_addr_1 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9605173677491049721ull);
    vlSelf->h2c_dsc_byp_dst_addr_1 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 18389502722026066240ull);
    vlSelf->h2c_dsc_byp_len_1 = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 1806820237359849510ull);
    vlSelf->h2c_dsc_byp_ctl_1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 3698987057298616192ull);
    vlSelf->c2h_dsc_byp_ready_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12687785324596301328ull);
    vlSelf->c2h_dsc_byp_load_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15076890565509279526ull);
    vlSelf->c2h_dsc_byp_src_addr_0 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11280908715993344812ull);
    vlSelf->c2h_dsc_byp_dst_addr_0 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5988028895608365247ull);
    vlSelf->c2h_dsc_byp_len_0 = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 9211040973596411921ull);
    vlSelf->c2h_dsc_byp_ctl_0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 6725552647098515212ull);
    vlSelf->h2c_sts_0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8859974381990866621ull);
    vlSelf->h2c_sts_1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12777289257135270515ull);
    vlSelf->c2h_sts_0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1809044285604395772ull);
    vlSelf->dma_controller_wrap__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11118632116262363594ull);
    vlSelf->dma_controller_wrap__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5168825684982834418ull);
    vlSelf->dma_controller_wrap__DOT__fill_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6029763265264569436ull);
    vlSelf->dma_controller_wrap__DOT__writeback_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15372234877650471044ull);
    vlSelf->dma_controller_wrap__DOT__tile_i = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2816406458791121366ull);
    vlSelf->dma_controller_wrap__DOT__tile_j = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4196673475295139289ull);
    vlSelf->dma_controller_wrap__DOT__k_tile = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4713343557589161531ull);
    vlSelf->dma_controller_wrap__DOT__base_addr_a = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14649089338335172598ull);
    vlSelf->dma_controller_wrap__DOT__base_addr_b = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 12591617086134766520ull);
    vlSelf->dma_controller_wrap__DOT__base_addr_c = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 377614627342285097ull);
    vlSelf->dma_controller_wrap__DOT__k_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4924669688712826860ull);
    vlSelf->dma_controller_wrap__DOT__n_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1684327472622621746ull);
    vlSelf->dma_controller_wrap__DOT__pp_weight_axi_base = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7592838505780481950ull);
    vlSelf->dma_controller_wrap__DOT__pp_act_axi_base = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 17932079149550566444ull);
    vlSelf->dma_controller_wrap__DOT__output_buf_axi_base = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5196715682027169118ull);
    vlSelf->dma_controller_wrap__DOT__writeback_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13774490032292635923ull);
    vlSelf->dma_controller_wrap__DOT__init_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7936838705966577088ull);
    vlSelf->dma_controller_wrap__DOT__axil_awvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8490355997909958918ull);
    vlSelf->dma_controller_wrap__DOT__axil_awready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16511466884334103212ull);
    vlSelf->dma_controller_wrap__DOT__axil_awaddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2836633611638727219ull);
    vlSelf->dma_controller_wrap__DOT__axil_awprot = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6310923092119650762ull);
    vlSelf->dma_controller_wrap__DOT__axil_wvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17227564194949059469ull);
    vlSelf->dma_controller_wrap__DOT__axil_wready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9991808331788104520ull);
    vlSelf->dma_controller_wrap__DOT__axil_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12692347828296949657ull);
    vlSelf->dma_controller_wrap__DOT__axil_wstrb = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8013169940690982509ull);
    vlSelf->dma_controller_wrap__DOT__axil_bvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2153896902390201639ull);
    vlSelf->dma_controller_wrap__DOT__axil_bready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5759851811574544908ull);
    vlSelf->dma_controller_wrap__DOT__axil_bresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1893607704884192013ull);
    vlSelf->dma_controller_wrap__DOT__axil_arvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 153031784979656772ull);
    vlSelf->dma_controller_wrap__DOT__axil_arready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17689207307828774250ull);
    vlSelf->dma_controller_wrap__DOT__axil_araddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18422712975536144609ull);
    vlSelf->dma_controller_wrap__DOT__axil_arprot = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8955451609908676143ull);
    vlSelf->dma_controller_wrap__DOT__axil_rvalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3072966493557713247ull);
    vlSelf->dma_controller_wrap__DOT__axil_rready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12716469394259966475ull);
    vlSelf->dma_controller_wrap__DOT__axil_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11295534509974815438ull);
    vlSelf->dma_controller_wrap__DOT__axil_rresp = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6881353464117641300ull);
    vlSelf->dma_controller_wrap__DOT__h2c_dsc_byp_ready_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9941906610846002256ull);
    vlSelf->dma_controller_wrap__DOT__h2c_dsc_byp_load_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2834623080383025112ull);
    vlSelf->dma_controller_wrap__DOT__h2c_dsc_byp_src_addr_0 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11115034304829701465ull);
    vlSelf->dma_controller_wrap__DOT__h2c_dsc_byp_dst_addr_0 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1396366849375174281ull);
    vlSelf->dma_controller_wrap__DOT__h2c_dsc_byp_len_0 = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 6928779703969481531ull);
    vlSelf->dma_controller_wrap__DOT__h2c_dsc_byp_ctl_0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12338684733252082398ull);
    vlSelf->dma_controller_wrap__DOT__h2c_dsc_byp_ready_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 396180504752812652ull);
    vlSelf->dma_controller_wrap__DOT__h2c_dsc_byp_load_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8473805198549341692ull);
    vlSelf->dma_controller_wrap__DOT__h2c_dsc_byp_src_addr_1 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4917564280610976622ull);
    vlSelf->dma_controller_wrap__DOT__h2c_dsc_byp_dst_addr_1 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5902875461329881998ull);
    vlSelf->dma_controller_wrap__DOT__h2c_dsc_byp_len_1 = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 3113838042127235733ull);
    vlSelf->dma_controller_wrap__DOT__h2c_dsc_byp_ctl_1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14838918483395974225ull);
    vlSelf->dma_controller_wrap__DOT__c2h_dsc_byp_ready_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6698887692376383522ull);
    vlSelf->dma_controller_wrap__DOT__c2h_dsc_byp_load_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10134945923944530603ull);
    vlSelf->dma_controller_wrap__DOT__c2h_dsc_byp_src_addr_0 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 281115367783224564ull);
    vlSelf->dma_controller_wrap__DOT__c2h_dsc_byp_dst_addr_0 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5904830674917027584ull);
    vlSelf->dma_controller_wrap__DOT__c2h_dsc_byp_len_0 = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 10690344981310383051ull);
    vlSelf->dma_controller_wrap__DOT__c2h_dsc_byp_ctl_0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 14435945029390688483ull);
    vlSelf->dma_controller_wrap__DOT__h2c_sts_0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4413186582284844356ull);
    vlSelf->dma_controller_wrap__DOT__h2c_sts_1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 5230452036094394626ull);
    vlSelf->dma_controller_wrap__DOT__c2h_sts_0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10735338101405087291ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9043502305306784154ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17490808742488837982ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__fill_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12333213878034101032ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__writeback_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18321620579742890755ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__tile_i = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3926294854000302421ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__tile_j = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16722509041248759077ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__k_tile = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18191759389758929942ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__base_addr_a = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 18079811017871001176ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__base_addr_b = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4191573023353438275ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__base_addr_c = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11275406914132963203ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__k_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2573282375727096843ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__n_tiles = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 796222473530378646ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__pp_weight_axi_base = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8752404416468412578ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__pp_act_axi_base = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15318054130950893509ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__output_buf_axi_base = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7610063600021004355ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__writeback_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12721946659425142272ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__init_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15762820161369177097ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ready_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7653428452163445833ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17242061441669935609ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_src_addr_0 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14230814581859837204ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_dst_addr_0 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11132120513128425368ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_len_0 = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 15734873207010575651ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ctl_0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 7035293354499846662ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ready_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2665794327410868010ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5012132142439823759ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_src_addr_1 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1754101458914752504ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_dst_addr_1 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 7853688303793954709ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_len_1 = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 816819625880081372ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ctl_1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9088942354103757693ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_ready_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5896871915006956418ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_load_0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16081872164679865874ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_src_addr_0 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 9420388435158378343ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_dst_addr_0 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15152480996183839213ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_len_0 = VL_SCOPED_RAND_RESET_I(28, __VscopeHash, 5545693268740617883ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_ctl_0 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5235608762912686141ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__h2c_sts_0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11160293546201576484ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__h2c_sts_1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15532922971138851761ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__c2h_sts_0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4749422991280643849ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__w_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2152954694964407747ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__a_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15788225693951982743ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__c_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8464358396711824522ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__init_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15372581996587068773ull);
    vlSelf->dma_controller_wrap__DOT__dut__DOT__reg_idx = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13010108925351658986ull);
    vlSelf->__Vdly__dma_controller_wrap__DOT__dut__DOT__init_state = 0;
    vlSelf->__Vdly__dma_controller_wrap__DOT__dut__DOT__reg_idx = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__dma_controller_wrap__DOT__dut__DOT__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
