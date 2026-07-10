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

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____1(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____2(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar);
void Vtop___024root__trace_chg_dtype____3(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar);

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgBit(oldp+0,(vlSelfRef.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.rst_n));
    bufp->chgBit(oldp+2,(vlSelfRef.start));
    bufp->chgBit(oldp+3,(vlSelfRef.done));
    bufp->chgCData(oldp+4,(vlSelfRef.weight_buf_addr),4);
    Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 5, vlSelfRef.weight_buf_data);
    bufp->chgCData(oldp+21,(vlSelfRef.act_buf_addr),4);
    Vtop___024root__trace_chg_dtype____1(vlSelf, bufp, 22, vlSelfRef.act_buf_data);
    bufp->chgCData(oldp+38,(vlSelfRef.weight_in[15]),8);
    bufp->chgCData(oldp+39,(vlSelfRef.weight_in[14]),8);
    bufp->chgCData(oldp+40,(vlSelfRef.weight_in[13]),8);
    bufp->chgCData(oldp+41,(vlSelfRef.weight_in[12]),8);
    bufp->chgCData(oldp+42,(vlSelfRef.weight_in[11]),8);
    bufp->chgCData(oldp+43,(vlSelfRef.weight_in[10]),8);
    bufp->chgCData(oldp+44,(vlSelfRef.weight_in[9]),8);
    bufp->chgCData(oldp+45,(vlSelfRef.weight_in[8]),8);
    bufp->chgCData(oldp+46,(vlSelfRef.weight_in[7]),8);
    bufp->chgCData(oldp+47,(vlSelfRef.weight_in[6]),8);
    bufp->chgCData(oldp+48,(vlSelfRef.weight_in[5]),8);
    bufp->chgCData(oldp+49,(vlSelfRef.weight_in[4]),8);
    bufp->chgCData(oldp+50,(vlSelfRef.weight_in[3]),8);
    bufp->chgCData(oldp+51,(vlSelfRef.weight_in[2]),8);
    bufp->chgCData(oldp+52,(vlSelfRef.weight_in[1]),8);
    bufp->chgCData(oldp+53,(vlSelfRef.weight_in[0]),8);
    bufp->chgBit(oldp+54,(vlSelfRef.weight_load_en));
    bufp->chgCData(oldp+55,(vlSelfRef.act_in[15]),8);
    bufp->chgCData(oldp+56,(vlSelfRef.act_in[14]),8);
    bufp->chgCData(oldp+57,(vlSelfRef.act_in[13]),8);
    bufp->chgCData(oldp+58,(vlSelfRef.act_in[12]),8);
    bufp->chgCData(oldp+59,(vlSelfRef.act_in[11]),8);
    bufp->chgCData(oldp+60,(vlSelfRef.act_in[10]),8);
    bufp->chgCData(oldp+61,(vlSelfRef.act_in[9]),8);
    bufp->chgCData(oldp+62,(vlSelfRef.act_in[8]),8);
    bufp->chgCData(oldp+63,(vlSelfRef.act_in[7]),8);
    bufp->chgCData(oldp+64,(vlSelfRef.act_in[6]),8);
    bufp->chgCData(oldp+65,(vlSelfRef.act_in[5]),8);
    bufp->chgCData(oldp+66,(vlSelfRef.act_in[4]),8);
    bufp->chgCData(oldp+67,(vlSelfRef.act_in[3]),8);
    bufp->chgCData(oldp+68,(vlSelfRef.act_in[2]),8);
    bufp->chgCData(oldp+69,(vlSelfRef.act_in[1]),8);
    bufp->chgCData(oldp+70,(vlSelfRef.act_in[0]),8);
    bufp->chgBit(oldp+71,(vlSelfRef.row_valid));
    bufp->chgBit(oldp+72,(vlSelfRef.systolic_data_setup__DOT__clk));
    bufp->chgBit(oldp+73,(vlSelfRef.systolic_data_setup__DOT__rst_n));
    bufp->chgBit(oldp+74,(vlSelfRef.systolic_data_setup__DOT__start));
    bufp->chgBit(oldp+75,(vlSelfRef.systolic_data_setup__DOT__done));
    bufp->chgCData(oldp+76,(vlSelfRef.systolic_data_setup__DOT__weight_buf_addr),4);
    bufp->chgCData(oldp+77,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[15]),8);
    bufp->chgCData(oldp+78,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[14]),8);
    bufp->chgCData(oldp+79,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[13]),8);
    bufp->chgCData(oldp+80,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[12]),8);
    bufp->chgCData(oldp+81,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[11]),8);
    bufp->chgCData(oldp+82,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[10]),8);
    bufp->chgCData(oldp+83,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[9]),8);
    bufp->chgCData(oldp+84,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[8]),8);
    bufp->chgCData(oldp+85,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[7]),8);
    bufp->chgCData(oldp+86,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[6]),8);
    bufp->chgCData(oldp+87,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[5]),8);
    bufp->chgCData(oldp+88,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[4]),8);
    bufp->chgCData(oldp+89,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[3]),8);
    bufp->chgCData(oldp+90,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[2]),8);
    bufp->chgCData(oldp+91,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[1]),8);
    bufp->chgCData(oldp+92,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[0]),8);
    bufp->chgCData(oldp+93,(vlSelfRef.systolic_data_setup__DOT__act_buf_addr),4);
    bufp->chgCData(oldp+94,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[15]),8);
    bufp->chgCData(oldp+95,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[14]),8);
    bufp->chgCData(oldp+96,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[13]),8);
    bufp->chgCData(oldp+97,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[12]),8);
    bufp->chgCData(oldp+98,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[11]),8);
    bufp->chgCData(oldp+99,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[10]),8);
    bufp->chgCData(oldp+100,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[9]),8);
    bufp->chgCData(oldp+101,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[8]),8);
    bufp->chgCData(oldp+102,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[7]),8);
    bufp->chgCData(oldp+103,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[6]),8);
    bufp->chgCData(oldp+104,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[5]),8);
    bufp->chgCData(oldp+105,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[4]),8);
    bufp->chgCData(oldp+106,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[3]),8);
    bufp->chgCData(oldp+107,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[2]),8);
    bufp->chgCData(oldp+108,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[1]),8);
    bufp->chgCData(oldp+109,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[0]),8);
    Vtop___024root__trace_chg_dtype____2(vlSelf, bufp, 110, vlSelfRef.systolic_data_setup__DOT__weight_in);
    bufp->chgBit(oldp+126,(vlSelfRef.systolic_data_setup__DOT__weight_load_en));
    Vtop___024root__trace_chg_dtype____3(vlSelf, bufp, 127, vlSelfRef.systolic_data_setup__DOT__act_in);
    bufp->chgBit(oldp+143,(vlSelfRef.systolic_data_setup__DOT__row_valid));
    bufp->chgCData(oldp+144,(vlSelfRef.systolic_data_setup__DOT__state),2);
    bufp->chgCData(oldp+145,(vlSelfRef.systolic_data_setup__DOT__cycle),5);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,(__VdtypeVar[15]),8);
    bufp->chgCData(oldp+1,(__VdtypeVar[14]),8);
    bufp->chgCData(oldp+2,(__VdtypeVar[13]),8);
    bufp->chgCData(oldp+3,(__VdtypeVar[12]),8);
    bufp->chgCData(oldp+4,(__VdtypeVar[11]),8);
    bufp->chgCData(oldp+5,(__VdtypeVar[10]),8);
    bufp->chgCData(oldp+6,(__VdtypeVar[9]),8);
    bufp->chgCData(oldp+7,(__VdtypeVar[8]),8);
    bufp->chgCData(oldp+8,(__VdtypeVar[7]),8);
    bufp->chgCData(oldp+9,(__VdtypeVar[6]),8);
    bufp->chgCData(oldp+10,(__VdtypeVar[5]),8);
    bufp->chgCData(oldp+11,(__VdtypeVar[4]),8);
    bufp->chgCData(oldp+12,(__VdtypeVar[3]),8);
    bufp->chgCData(oldp+13,(__VdtypeVar[2]),8);
    bufp->chgCData(oldp+14,(__VdtypeVar[1]),8);
    bufp->chgCData(oldp+15,(__VdtypeVar[0]),8);
}

void Vtop___024root__trace_chg_dtype____1(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,(__VdtypeVar[15]),8);
    bufp->chgCData(oldp+1,(__VdtypeVar[14]),8);
    bufp->chgCData(oldp+2,(__VdtypeVar[13]),8);
    bufp->chgCData(oldp+3,(__VdtypeVar[12]),8);
    bufp->chgCData(oldp+4,(__VdtypeVar[11]),8);
    bufp->chgCData(oldp+5,(__VdtypeVar[10]),8);
    bufp->chgCData(oldp+6,(__VdtypeVar[9]),8);
    bufp->chgCData(oldp+7,(__VdtypeVar[8]),8);
    bufp->chgCData(oldp+8,(__VdtypeVar[7]),8);
    bufp->chgCData(oldp+9,(__VdtypeVar[6]),8);
    bufp->chgCData(oldp+10,(__VdtypeVar[5]),8);
    bufp->chgCData(oldp+11,(__VdtypeVar[4]),8);
    bufp->chgCData(oldp+12,(__VdtypeVar[3]),8);
    bufp->chgCData(oldp+13,(__VdtypeVar[2]),8);
    bufp->chgCData(oldp+14,(__VdtypeVar[1]),8);
    bufp->chgCData(oldp+15,(__VdtypeVar[0]),8);
}

void Vtop___024root__trace_chg_dtype____2(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,(__VdtypeVar[15]),8);
    bufp->chgCData(oldp+1,(__VdtypeVar[14]),8);
    bufp->chgCData(oldp+2,(__VdtypeVar[13]),8);
    bufp->chgCData(oldp+3,(__VdtypeVar[12]),8);
    bufp->chgCData(oldp+4,(__VdtypeVar[11]),8);
    bufp->chgCData(oldp+5,(__VdtypeVar[10]),8);
    bufp->chgCData(oldp+6,(__VdtypeVar[9]),8);
    bufp->chgCData(oldp+7,(__VdtypeVar[8]),8);
    bufp->chgCData(oldp+8,(__VdtypeVar[7]),8);
    bufp->chgCData(oldp+9,(__VdtypeVar[6]),8);
    bufp->chgCData(oldp+10,(__VdtypeVar[5]),8);
    bufp->chgCData(oldp+11,(__VdtypeVar[4]),8);
    bufp->chgCData(oldp+12,(__VdtypeVar[3]),8);
    bufp->chgCData(oldp+13,(__VdtypeVar[2]),8);
    bufp->chgCData(oldp+14,(__VdtypeVar[1]),8);
    bufp->chgCData(oldp+15,(__VdtypeVar[0]),8);
}

void Vtop___024root__trace_chg_dtype____3(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgCData(oldp+0,(__VdtypeVar[15]),8);
    bufp->chgCData(oldp+1,(__VdtypeVar[14]),8);
    bufp->chgCData(oldp+2,(__VdtypeVar[13]),8);
    bufp->chgCData(oldp+3,(__VdtypeVar[12]),8);
    bufp->chgCData(oldp+4,(__VdtypeVar[11]),8);
    bufp->chgCData(oldp+5,(__VdtypeVar[10]),8);
    bufp->chgCData(oldp+6,(__VdtypeVar[9]),8);
    bufp->chgCData(oldp+7,(__VdtypeVar[8]),8);
    bufp->chgCData(oldp+8,(__VdtypeVar[7]),8);
    bufp->chgCData(oldp+9,(__VdtypeVar[6]),8);
    bufp->chgCData(oldp+10,(__VdtypeVar[5]),8);
    bufp->chgCData(oldp+11,(__VdtypeVar[4]),8);
    bufp->chgCData(oldp+12,(__VdtypeVar[3]),8);
    bufp->chgCData(oldp+13,(__VdtypeVar[2]),8);
    bufp->chgCData(oldp+14,(__VdtypeVar[1]),8);
    bufp->chgCData(oldp+15,(__VdtypeVar[0]),8);
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
