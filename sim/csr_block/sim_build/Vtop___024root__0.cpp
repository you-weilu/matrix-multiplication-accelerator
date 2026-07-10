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
    vlSelfRef.csr_block_wrap__DOT__awaddr = vlSelfRef.awaddr;
    vlSelfRef.csr_block_wrap__DOT__awprot = vlSelfRef.awprot;
    vlSelfRef.csr_block_wrap__DOT__awvalid = vlSelfRef.awvalid;
    vlSelfRef.csr_block_wrap__DOT__awready = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awready;
    vlSelfRef.csr_block_wrap__DOT__wdata = vlSelfRef.wdata;
    vlSelfRef.csr_block_wrap__DOT__wstrb = vlSelfRef.wstrb;
    vlSelfRef.csr_block_wrap__DOT__wvalid = vlSelfRef.wvalid;
    vlSelfRef.csr_block_wrap__DOT__wready = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wready;
    vlSelfRef.csr_block_wrap__DOT__bresp = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bresp;
    vlSelfRef.csr_block_wrap__DOT__bvalid = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bvalid;
    vlSelfRef.csr_block_wrap__DOT__araddr = vlSelfRef.araddr;
    vlSelfRef.csr_block_wrap__DOT__arprot = vlSelfRef.arprot;
    vlSelfRef.csr_block_wrap__DOT__arvalid = vlSelfRef.arvalid;
    vlSelfRef.csr_block_wrap__DOT__arready = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.arready;
    vlSelfRef.csr_block_wrap__DOT__rdata = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rdata;
    vlSelfRef.csr_block_wrap__DOT__rresp = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rresp;
    vlSelfRef.csr_block_wrap__DOT__rvalid = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rvalid;
    vlSelfRef.csr_block_wrap__DOT__rready = vlSelfRef.rready;
    vlSelfRef.csr_block_wrap__DOT__ts_busy = vlSelfRef.ts_busy;
    vlSelfRef.csr_block_wrap__DOT__ts_done = vlSelfRef.ts_done;
    vlSelfRef.csr_block_wrap__DOT__clk = vlSelfRef.clk;
    vlSelfRef.csr_block_wrap__DOT__rst_n = vlSelfRef.rst_n;
    vlSelfRef.csr_block_wrap__DOT__dut__DOT__go = vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_go;
    vlSelfRef.csr_block_wrap__DOT__dut__DOT__m_tiles 
        = vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_m_tiles;
    vlSelfRef.csr_block_wrap__DOT__dut__DOT__n_tiles 
        = vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_n_tiles;
    vlSelfRef.csr_block_wrap__DOT__dut__DOT__k_tiles 
        = vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_k_tiles;
    vlSelfRef.csr_block_wrap__DOT__bready = vlSelfRef.bready;
    vlSelfRef.awready = vlSelfRef.csr_block_wrap__DOT__awready;
    vlSelfRef.wready = vlSelfRef.csr_block_wrap__DOT__wready;
    vlSelfRef.bresp = vlSelfRef.csr_block_wrap__DOT__bresp;
    vlSelfRef.bvalid = vlSelfRef.csr_block_wrap__DOT__bvalid;
    vlSelfRef.arready = vlSelfRef.csr_block_wrap__DOT__arready;
    vlSelfRef.rdata = vlSelfRef.csr_block_wrap__DOT__rdata;
    vlSelfRef.rresp = vlSelfRef.csr_block_wrap__DOT__rresp;
    vlSelfRef.rvalid = vlSelfRef.csr_block_wrap__DOT__rvalid;
    vlSelfRef.csr_block_wrap__DOT__dut__DOT__ts_busy 
        = vlSelfRef.csr_block_wrap__DOT__ts_busy;
    vlSelfRef.csr_block_wrap__DOT__dut__DOT__ts_done 
        = vlSelfRef.csr_block_wrap__DOT__ts_done;
    vlSelfRef.csr_block_wrap__DOT__go = vlSelfRef.csr_block_wrap__DOT__dut__DOT__go;
    vlSelfRef.csr_block_wrap__DOT__m_tiles = vlSelfRef.csr_block_wrap__DOT__dut__DOT__m_tiles;
    vlSelfRef.csr_block_wrap__DOT__n_tiles = vlSelfRef.csr_block_wrap__DOT__dut__DOT__n_tiles;
    vlSelfRef.csr_block_wrap__DOT__k_tiles = vlSelfRef.csr_block_wrap__DOT__dut__DOT__k_tiles;
    vlSelfRef.go = vlSelfRef.csr_block_wrap__DOT__go;
    vlSelfRef.m_tiles = vlSelfRef.csr_block_wrap__DOT__m_tiles;
    vlSelfRef.n_tiles = vlSelfRef.csr_block_wrap__DOT__n_tiles;
    vlSelfRef.k_tiles = vlSelfRef.csr_block_wrap__DOT__k_tiles;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
void Vtop_axi_lite_if___ico_sequent__TOP__csr_block_wrap__DOT__csr_axi__0(Vtop_axi_lite_if* vlSelf);

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

void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.csr_block_wrap__DOT__dut__DOT__rst_n) {
        if (vlSelfRef.csr_block_wrap__DOT__dut__DOT__rd_state) {
            if (vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rready) {
                vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rvalid = 0U;
                vlSelfRef.csr_block_wrap__DOT__dut__DOT__rd_state = 0U;
            }
        } else {
            vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.arready = 1U;
            if (vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.arvalid) {
                vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.arready = 0U;
                vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rvalid = 1U;
                vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rresp = 0U;
                vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rdata 
                    = ((0x00000010U & vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.araddr)
                        ? ((8U & vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.araddr)
                            ? 0U : ((4U & vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.araddr)
                                     ? 0U : (IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_done)))
                        : ((8U & vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.araddr)
                            ? ((4U & vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.araddr)
                                ? (IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_k_tiles)
                                : (IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_n_tiles))
                            : ((4U & vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.araddr)
                                ? (IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_m_tiles)
                                : (((IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__ts_busy) 
                                    << 1U) | (IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_go)))));
                vlSelfRef.csr_block_wrap__DOT__dut__DOT__rd_state = 1U;
            }
        }
        if (vlSelfRef.csr_block_wrap__DOT__dut__DOT__ts_done) {
            vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_done = 1U;
        }
        vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_go = 0U;
        if (vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_commit) {
            if ((1U & (~ ((IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_addr_lat) 
                          >> 4U)))) {
                if ((1U & (~ ((IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_addr_lat) 
                              >> 3U)))) {
                    if ((1U & (~ ((IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_addr_lat) 
                                  >> 2U)))) {
                        if ((1U & (vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_data_lat 
                                   & (~ (IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__ts_busy))))) {
                            vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_done = 0U;
                            vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_go = 1U;
                        }
                    }
                    if ((4U & (IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_addr_lat))) {
                        vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_m_tiles 
                            = (0x000000ffU & vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_data_lat);
                    }
                }
                if ((8U & (IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_addr_lat))) {
                    if ((4U & (IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_addr_lat))) {
                        vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_k_tiles 
                            = (0x000000ffU & vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_data_lat);
                    }
                    if ((1U & (~ ((IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_addr_lat) 
                                  >> 2U)))) {
                        vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_n_tiles 
                            = (0x000000ffU & vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_data_lat);
                    }
                }
            }
        }
        if ((2U & (IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_state))) {
            if ((1U & (IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_state))) {
                vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bvalid = 1U;
                vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bresp = 0U;
                if (vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bready) {
                    vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bvalid = 0U;
                    vlSelfRef.__Vdly__csr_block_wrap__DOT__dut__DOT__wr_state = 0U;
                }
            } else if (vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awvalid) {
                vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_addr_lat 
                    = (0x0000001fU & vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awaddr);
                vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awready = 0U;
                vlSelfRef.__Vdly__csr_block_wrap__DOT__dut__DOT__wr_state = 3U;
            }
        } else if ((1U & (IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_state))) {
            if (vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wvalid) {
                vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_data_lat 
                    = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wdata;
                vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wready = 0U;
                vlSelfRef.__Vdly__csr_block_wrap__DOT__dut__DOT__wr_state = 3U;
            }
        } else {
            vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awready = 1U;
            vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wready = 1U;
            if (((IData)(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awvalid) 
                 & (IData)(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wvalid))) {
                vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_addr_lat 
                    = (0x0000001fU & vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awaddr);
                vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_data_lat 
                    = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wdata;
                vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awready = 0U;
                vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wready = 0U;
                vlSelfRef.__Vdly__csr_block_wrap__DOT__dut__DOT__wr_state = 3U;
            } else if (vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awvalid) {
                vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_addr_lat 
                    = (0x0000001fU & vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awaddr);
                vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awready = 0U;
                vlSelfRef.__Vdly__csr_block_wrap__DOT__dut__DOT__wr_state = 1U;
            } else if (vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wvalid) {
                vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_data_lat 
                    = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wdata;
                vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wready = 0U;
                vlSelfRef.__Vdly__csr_block_wrap__DOT__dut__DOT__wr_state = 2U;
            }
        }
    } else {
        vlSelfRef.csr_block_wrap__DOT__dut__DOT__rd_state = 0U;
        vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.arready = 0U;
        vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rvalid = 0U;
        vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rdata = 0U;
        vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rresp = 0U;
        vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_done = 0U;
        vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_k_tiles = 1U;
        vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_n_tiles = 1U;
        vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_m_tiles = 1U;
        vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_go = 0U;
        vlSelfRef.__Vdly__csr_block_wrap__DOT__dut__DOT__wr_state = 0U;
        vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_addr_lat = 0U;
        vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_data_lat = 0U;
        vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awready = 0U;
        vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wready = 0U;
        vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bvalid = 0U;
        vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bresp = 0U;
    }
    vlSelfRef.csr_block_wrap__DOT__dut__DOT__k_tiles 
        = vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_k_tiles;
    vlSelfRef.csr_block_wrap__DOT__dut__DOT__n_tiles 
        = vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_n_tiles;
    vlSelfRef.csr_block_wrap__DOT__dut__DOT__m_tiles 
        = vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_m_tiles;
    vlSelfRef.csr_block_wrap__DOT__dut__DOT__go = vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_go;
    vlSelfRef.csr_block_wrap__DOT__k_tiles = vlSelfRef.csr_block_wrap__DOT__dut__DOT__k_tiles;
    vlSelfRef.csr_block_wrap__DOT__n_tiles = vlSelfRef.csr_block_wrap__DOT__dut__DOT__n_tiles;
    vlSelfRef.csr_block_wrap__DOT__m_tiles = vlSelfRef.csr_block_wrap__DOT__dut__DOT__m_tiles;
    vlSelfRef.csr_block_wrap__DOT__go = vlSelfRef.csr_block_wrap__DOT__dut__DOT__go;
    vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_state 
        = vlSelfRef.__Vdly__csr_block_wrap__DOT__dut__DOT__wr_state;
    vlSelfRef.k_tiles = vlSelfRef.csr_block_wrap__DOT__k_tiles;
    vlSelfRef.n_tiles = vlSelfRef.csr_block_wrap__DOT__n_tiles;
    vlSelfRef.m_tiles = vlSelfRef.csr_block_wrap__DOT__m_tiles;
    vlSelfRef.go = vlSelfRef.csr_block_wrap__DOT__go;
    vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_commit 
        = ((IData)(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bready) 
           & (3U == (IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_state)));
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
                                                        ((IData)(vlSelfRef.csr_block_wrap__DOT__dut__DOT__clk) 
                                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__csr_block_wrap__DOT__dut__DOT__clk__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__csr_block_wrap__DOT__dut__DOT__clk__0 
            = vlSelfRef.csr_block_wrap__DOT__dut__DOT__clk;
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
        {
            // Inlined CFunc: _eval_nba
            if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    vlSelfRef.__Vdly__csr_block_wrap__DOT__dut__DOT__wr_state 
                        = vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_state;
                }
                Vtop___024root___nba_sequent__TOP__1(vlSelf);
                {
                    // Inlined CFunc: _nba_sequent__TOP__2
                    vlSelfRef.csr_block_wrap__DOT__rvalid 
                        = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rvalid;
                    vlSelfRef.csr_block_wrap__DOT__arready 
                        = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.arready;
                    vlSelfRef.csr_block_wrap__DOT__rresp 
                        = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rresp;
                    vlSelfRef.csr_block_wrap__DOT__rdata 
                        = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rdata;
                    vlSelfRef.csr_block_wrap__DOT__bvalid 
                        = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bvalid;
                    vlSelfRef.csr_block_wrap__DOT__bresp 
                        = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bresp;
                    vlSelfRef.csr_block_wrap__DOT__awready 
                        = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awready;
                    vlSelfRef.csr_block_wrap__DOT__wready 
                        = vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wready;
                    vlSelfRef.rvalid = vlSelfRef.csr_block_wrap__DOT__rvalid;
                    vlSelfRef.arready = vlSelfRef.csr_block_wrap__DOT__arready;
                    vlSelfRef.rresp = vlSelfRef.csr_block_wrap__DOT__rresp;
                    vlSelfRef.rdata = vlSelfRef.csr_block_wrap__DOT__rdata;
                    vlSelfRef.bvalid = vlSelfRef.csr_block_wrap__DOT__bvalid;
                    vlSelfRef.bresp = vlSelfRef.csr_block_wrap__DOT__bresp;
                    vlSelfRef.awready = vlSelfRef.csr_block_wrap__DOT__awready;
                    vlSelfRef.wready = vlSelfRef.csr_block_wrap__DOT__wready;
                }
            }
        }
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
            VL_FATAL_MT("csr_block_wrap.sv", 2, "", "DIDNOTCONVERGE: Input combinational region did not converge after '--converge-limit' of 10000 tries");
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
            VL_FATAL_MT("csr_block_wrap.sv", 2, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 10000 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00002710U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("csr_block_wrap.sv", 2, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 10000 tries");
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
    if (VL_UNLIKELY(((vlSelfRef.awprot & 0xf8U)))) {
        Verilated::overWidthError("awprot");
    }
    if (VL_UNLIKELY(((vlSelfRef.awvalid & 0xfeU)))) {
        Verilated::overWidthError("awvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.wstrb & 0xf0U)))) {
        Verilated::overWidthError("wstrb");
    }
    if (VL_UNLIKELY(((vlSelfRef.wvalid & 0xfeU)))) {
        Verilated::overWidthError("wvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.bready & 0xfeU)))) {
        Verilated::overWidthError("bready");
    }
    if (VL_UNLIKELY(((vlSelfRef.arprot & 0xf8U)))) {
        Verilated::overWidthError("arprot");
    }
    if (VL_UNLIKELY(((vlSelfRef.arvalid & 0xfeU)))) {
        Verilated::overWidthError("arvalid");
    }
    if (VL_UNLIKELY(((vlSelfRef.rready & 0xfeU)))) {
        Verilated::overWidthError("rready");
    }
    if (VL_UNLIKELY(((vlSelfRef.ts_busy & 0xfeU)))) {
        Verilated::overWidthError("ts_busy");
    }
    if (VL_UNLIKELY(((vlSelfRef.ts_done & 0xfeU)))) {
        Verilated::overWidthError("ts_done");
    }
}
#endif  // VL_DEBUG
