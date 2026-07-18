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

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 16>& __VdtypeVar);

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+2,(vlSelfRef.buf_wen));
    bufp->chgCData(oldp+3,(vlSelfRef.buf_row),4);
    Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 4, vlSelfRef.buf_data);
    bufp->chgBit(oldp+20,(vlSelfRef.arvalid));
    bufp->chgCData(oldp+21,(vlSelfRef.arid),4);
    bufp->chgQData(oldp+22,(vlSelfRef.araddr),64);
    bufp->chgCData(oldp+24,(vlSelfRef.arlen),8);
    bufp->chgCData(oldp+25,(vlSelfRef.arsize),3);
    bufp->chgCData(oldp+26,(vlSelfRef.arburst),2);
    bufp->chgBit(oldp+27,(vlSelfRef.arready));
    bufp->chgBit(oldp+28,(vlSelfRef.rvalid));
    bufp->chgCData(oldp+29,(vlSelfRef.rid),4);
    bufp->chgWData(oldp+30,(vlSelfRef.rdata),128);
    bufp->chgCData(oldp+34,(vlSelfRef.rresp),2);
    bufp->chgBit(oldp+35,(vlSelfRef.rlast));
    bufp->chgBit(oldp+36,(vlSelfRef.rready));
    bufp->chgBit(oldp+37,(vlSelfRef.output_buffer_wrap__DOT__clk));
    bufp->chgBit(oldp+38,(vlSelfRef.output_buffer_wrap__DOT__rst_n));
    bufp->chgBit(oldp+39,(vlSelfRef.output_buffer_wrap__DOT__buf_wen));
    bufp->chgCData(oldp+40,(vlSelfRef.output_buffer_wrap__DOT__buf_row),4);
    bufp->chgIData(oldp+41,(vlSelfRef.output_buffer_wrap__DOT__buf_data[15]),32);
    bufp->chgIData(oldp+42,(vlSelfRef.output_buffer_wrap__DOT__buf_data[14]),32);
    bufp->chgIData(oldp+43,(vlSelfRef.output_buffer_wrap__DOT__buf_data[13]),32);
    bufp->chgIData(oldp+44,(vlSelfRef.output_buffer_wrap__DOT__buf_data[12]),32);
    bufp->chgIData(oldp+45,(vlSelfRef.output_buffer_wrap__DOT__buf_data[11]),32);
    bufp->chgIData(oldp+46,(vlSelfRef.output_buffer_wrap__DOT__buf_data[10]),32);
    bufp->chgIData(oldp+47,(vlSelfRef.output_buffer_wrap__DOT__buf_data[9]),32);
    bufp->chgIData(oldp+48,(vlSelfRef.output_buffer_wrap__DOT__buf_data[8]),32);
    bufp->chgIData(oldp+49,(vlSelfRef.output_buffer_wrap__DOT__buf_data[7]),32);
    bufp->chgIData(oldp+50,(vlSelfRef.output_buffer_wrap__DOT__buf_data[6]),32);
    bufp->chgIData(oldp+51,(vlSelfRef.output_buffer_wrap__DOT__buf_data[5]),32);
    bufp->chgIData(oldp+52,(vlSelfRef.output_buffer_wrap__DOT__buf_data[4]),32);
    bufp->chgIData(oldp+53,(vlSelfRef.output_buffer_wrap__DOT__buf_data[3]),32);
    bufp->chgIData(oldp+54,(vlSelfRef.output_buffer_wrap__DOT__buf_data[2]),32);
    bufp->chgIData(oldp+55,(vlSelfRef.output_buffer_wrap__DOT__buf_data[1]),32);
    bufp->chgIData(oldp+56,(vlSelfRef.output_buffer_wrap__DOT__buf_data[0]),32);
    bufp->chgBit(oldp+57,(vlSelfRef.output_buffer_wrap__DOT__arvalid));
    bufp->chgCData(oldp+58,(vlSelfRef.output_buffer_wrap__DOT__arid),4);
    bufp->chgQData(oldp+59,(vlSelfRef.output_buffer_wrap__DOT__araddr),64);
    bufp->chgCData(oldp+61,(vlSelfRef.output_buffer_wrap__DOT__arlen),8);
    bufp->chgCData(oldp+62,(vlSelfRef.output_buffer_wrap__DOT__arsize),3);
    bufp->chgCData(oldp+63,(vlSelfRef.output_buffer_wrap__DOT__arburst),2);
    bufp->chgBit(oldp+64,(vlSelfRef.output_buffer_wrap__DOT__arready));
    bufp->chgBit(oldp+65,(vlSelfRef.output_buffer_wrap__DOT__rvalid));
    bufp->chgCData(oldp+66,(vlSelfRef.output_buffer_wrap__DOT__rid),4);
    bufp->chgWData(oldp+67,(vlSelfRef.output_buffer_wrap__DOT__rdata),128);
    bufp->chgCData(oldp+71,(vlSelfRef.output_buffer_wrap__DOT__rresp),2);
    bufp->chgBit(oldp+72,(vlSelfRef.output_buffer_wrap__DOT__rlast));
    bufp->chgBit(oldp+73,(vlSelfRef.output_buffer_wrap__DOT__rready));
    bufp->chgBit(oldp+74,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__clk));
    bufp->chgBit(oldp+75,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__rst_n));
    bufp->chgBit(oldp+76,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_wen));
    bufp->chgCData(oldp+77,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_row),4);
    bufp->chgIData(oldp+78,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[15]),32);
    bufp->chgIData(oldp+79,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[14]),32);
    bufp->chgIData(oldp+80,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[13]),32);
    bufp->chgIData(oldp+81,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[12]),32);
    bufp->chgIData(oldp+82,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[11]),32);
    bufp->chgIData(oldp+83,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[10]),32);
    bufp->chgIData(oldp+84,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[9]),32);
    bufp->chgIData(oldp+85,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[8]),32);
    bufp->chgIData(oldp+86,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[7]),32);
    bufp->chgIData(oldp+87,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[6]),32);
    bufp->chgIData(oldp+88,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[5]),32);
    bufp->chgIData(oldp+89,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[4]),32);
    bufp->chgIData(oldp+90,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[3]),32);
    bufp->chgIData(oldp+91,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[2]),32);
    bufp->chgIData(oldp+92,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[1]),32);
    bufp->chgIData(oldp+93,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[0]),32);
    bufp->chgBit(oldp+94,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__state));
    bufp->chgCData(oldp+95,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__beat_addr),6);
    bufp->chgCData(oldp+96,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__beat_count),8);
    bufp->chgBit(oldp+97,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.aclk));
    bufp->chgBit(oldp+98,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.aresetn));
    bufp->chgBit(oldp+99,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.awvalid));
    bufp->chgBit(oldp+100,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.awready));
    bufp->chgCData(oldp+101,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.awid),4);
    bufp->chgQData(oldp+102,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.awaddr),64);
    bufp->chgCData(oldp+104,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.awlen),8);
    bufp->chgCData(oldp+105,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.awsize),3);
    bufp->chgCData(oldp+106,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.awburst),2);
    bufp->chgBit(oldp+107,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.wvalid));
    bufp->chgBit(oldp+108,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.wready));
    bufp->chgWData(oldp+109,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.wdata),128);
    bufp->chgSData(oldp+113,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.wstrb),16);
    bufp->chgBit(oldp+114,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.wlast));
    bufp->chgBit(oldp+115,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.bvalid));
    bufp->chgBit(oldp+116,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.bready));
    bufp->chgCData(oldp+117,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.bid),4);
    bufp->chgCData(oldp+118,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.bresp),2);
    bufp->chgBit(oldp+119,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arvalid));
    bufp->chgBit(oldp+120,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arready));
    bufp->chgCData(oldp+121,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arid),4);
    bufp->chgQData(oldp+122,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.araddr),64);
    bufp->chgCData(oldp+124,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arlen),8);
    bufp->chgCData(oldp+125,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arsize),3);
    bufp->chgCData(oldp+126,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arburst),2);
    bufp->chgBit(oldp+127,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rvalid));
    bufp->chgBit(oldp+128,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rready));
    bufp->chgCData(oldp+129,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rid),4);
    bufp->chgWData(oldp+130,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rdata),128);
    bufp->chgCData(oldp+134,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rresp),2);
    bufp->chgBit(oldp+135,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rlast));
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[0]),32);
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
