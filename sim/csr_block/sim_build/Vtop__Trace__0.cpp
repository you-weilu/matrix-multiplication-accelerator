// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_n));
    bufp->chgIData(oldp+2,(vlSelfRef.awaddr),32);
    bufp->chgCData(oldp+3,(vlSelfRef.awprot),3);
    bufp->chgBit(oldp+4,(vlSelfRef.awvalid));
    bufp->chgBit(oldp+5,(vlSelfRef.awready));
    bufp->chgIData(oldp+6,(vlSelfRef.wdata),32);
    bufp->chgCData(oldp+7,(vlSelfRef.wstrb),4);
    bufp->chgBit(oldp+8,(vlSelfRef.wvalid));
    bufp->chgBit(oldp+9,(vlSelfRef.wready));
    bufp->chgCData(oldp+10,(vlSelfRef.bresp),2);
    bufp->chgBit(oldp+11,(vlSelfRef.bvalid));
    bufp->chgBit(oldp+12,(vlSelfRef.bready));
    bufp->chgIData(oldp+13,(vlSelfRef.araddr),32);
    bufp->chgCData(oldp+14,(vlSelfRef.arprot),3);
    bufp->chgBit(oldp+15,(vlSelfRef.arvalid));
    bufp->chgBit(oldp+16,(vlSelfRef.arready));
    bufp->chgIData(oldp+17,(vlSelfRef.rdata),32);
    bufp->chgCData(oldp+18,(vlSelfRef.rresp),2);
    bufp->chgBit(oldp+19,(vlSelfRef.rvalid));
    bufp->chgBit(oldp+20,(vlSelfRef.rready));
    bufp->chgBit(oldp+21,(vlSelfRef.go));
    bufp->chgCData(oldp+22,(vlSelfRef.m_tiles),8);
    bufp->chgCData(oldp+23,(vlSelfRef.n_tiles),8);
    bufp->chgCData(oldp+24,(vlSelfRef.k_tiles),8);
    bufp->chgBit(oldp+25,(vlSelfRef.ts_busy));
    bufp->chgBit(oldp+26,(vlSelfRef.ts_done));
    bufp->chgBit(oldp+27,(vlSelfRef.csr_block_wrap__DOT__clk));
    bufp->chgBit(oldp+28,(vlSelfRef.csr_block_wrap__DOT__rst_n));
    bufp->chgIData(oldp+29,(vlSelfRef.csr_block_wrap__DOT__awaddr),32);
    bufp->chgCData(oldp+30,(vlSelfRef.csr_block_wrap__DOT__awprot),3);
    bufp->chgBit(oldp+31,(vlSelfRef.csr_block_wrap__DOT__awvalid));
    bufp->chgBit(oldp+32,(vlSelfRef.csr_block_wrap__DOT__awready));
    bufp->chgIData(oldp+33,(vlSelfRef.csr_block_wrap__DOT__wdata),32);
    bufp->chgCData(oldp+34,(vlSelfRef.csr_block_wrap__DOT__wstrb),4);
    bufp->chgBit(oldp+35,(vlSelfRef.csr_block_wrap__DOT__wvalid));
    bufp->chgBit(oldp+36,(vlSelfRef.csr_block_wrap__DOT__wready));
    bufp->chgCData(oldp+37,(vlSelfRef.csr_block_wrap__DOT__bresp),2);
    bufp->chgBit(oldp+38,(vlSelfRef.csr_block_wrap__DOT__bvalid));
    bufp->chgBit(oldp+39,(vlSelfRef.csr_block_wrap__DOT__bready));
    bufp->chgIData(oldp+40,(vlSelfRef.csr_block_wrap__DOT__araddr),32);
    bufp->chgCData(oldp+41,(vlSelfRef.csr_block_wrap__DOT__arprot),3);
    bufp->chgBit(oldp+42,(vlSelfRef.csr_block_wrap__DOT__arvalid));
    bufp->chgBit(oldp+43,(vlSelfRef.csr_block_wrap__DOT__arready));
    bufp->chgIData(oldp+44,(vlSelfRef.csr_block_wrap__DOT__rdata),32);
    bufp->chgCData(oldp+45,(vlSelfRef.csr_block_wrap__DOT__rresp),2);
    bufp->chgBit(oldp+46,(vlSelfRef.csr_block_wrap__DOT__rvalid));
    bufp->chgBit(oldp+47,(vlSelfRef.csr_block_wrap__DOT__rready));
    bufp->chgBit(oldp+48,(vlSelfRef.csr_block_wrap__DOT__go));
    bufp->chgCData(oldp+49,(vlSelfRef.csr_block_wrap__DOT__m_tiles),8);
    bufp->chgCData(oldp+50,(vlSelfRef.csr_block_wrap__DOT__n_tiles),8);
    bufp->chgCData(oldp+51,(vlSelfRef.csr_block_wrap__DOT__k_tiles),8);
    bufp->chgBit(oldp+52,(vlSelfRef.csr_block_wrap__DOT__ts_busy));
    bufp->chgBit(oldp+53,(vlSelfRef.csr_block_wrap__DOT__ts_done));
    bufp->chgBit(oldp+54,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__go));
    bufp->chgCData(oldp+55,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__m_tiles),8);
    bufp->chgCData(oldp+56,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__n_tiles),8);
    bufp->chgCData(oldp+57,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__k_tiles),8);
    bufp->chgBit(oldp+58,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__ts_busy));
    bufp->chgBit(oldp+59,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__ts_done));
    bufp->chgBit(oldp+60,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__clk));
    bufp->chgBit(oldp+61,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__rst_n));
    bufp->chgBit(oldp+62,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_go));
    bufp->chgCData(oldp+63,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_m_tiles),8);
    bufp->chgCData(oldp+64,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_n_tiles),8);
    bufp->chgCData(oldp+65,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_k_tiles),8);
    bufp->chgBit(oldp+66,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__reg_done));
    bufp->chgCData(oldp+67,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_addr_lat),5);
    bufp->chgIData(oldp+68,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_data_lat),32);
    bufp->chgBit(oldp+69,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_commit));
    bufp->chgCData(oldp+70,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__wr_state),2);
    bufp->chgBit(oldp+71,(vlSelfRef.csr_block_wrap__DOT__dut__DOT__rd_state));
    bufp->chgBit(oldp+72,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.aclk));
    bufp->chgBit(oldp+73,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.aresetn));
    bufp->chgBit(oldp+74,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awvalid));
    bufp->chgBit(oldp+75,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awready));
    bufp->chgIData(oldp+76,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awaddr),32);
    bufp->chgCData(oldp+77,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.awprot),3);
    bufp->chgBit(oldp+78,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wvalid));
    bufp->chgBit(oldp+79,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wready));
    bufp->chgIData(oldp+80,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wdata),32);
    bufp->chgCData(oldp+81,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.wstrb),4);
    bufp->chgBit(oldp+82,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bvalid));
    bufp->chgBit(oldp+83,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bready));
    bufp->chgCData(oldp+84,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.bresp),2);
    bufp->chgBit(oldp+85,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.arvalid));
    bufp->chgBit(oldp+86,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.arready));
    bufp->chgIData(oldp+87,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.araddr),32);
    bufp->chgCData(oldp+88,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.arprot),3);
    bufp->chgBit(oldp+89,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rvalid));
    bufp->chgBit(oldp+90,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rready));
    bufp->chgIData(oldp+91,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rdata),32);
    bufp->chgCData(oldp+92,(vlSymsp->TOP__csr_block_wrap__DOT__csr_axi.rresp),2);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Locals
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = 0;
    }
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __Vm_traceActivity[0U] = 0U;
}
