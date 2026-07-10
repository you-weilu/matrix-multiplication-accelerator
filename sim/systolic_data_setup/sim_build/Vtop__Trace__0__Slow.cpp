// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_dtype____0(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtop___024root__trace_init_dtype____1(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtop___024root__trace_init_dtype____2(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtop___024root__trace_init_dtype____3(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "$rootio", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+3,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"weight_buf_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);

    Vtop___024root__trace_init_dtype____0(vlSelf, tracep, "weight_buf_data", 0, c+5, VerilatedTraceSigDirection::INPUT);
    VL_TRACE_DECL_BUS(tracep,c+21,0,"act_buf_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);

    Vtop___024root__trace_init_dtype____1(vlSelf, tracep, "act_buf_data", 0, c+22, VerilatedTraceSigDirection::INPUT);
    VL_TRACE_PUSH_PREFIX(tracep, "weight_in", VerilatedTracePrefixType::ARRAY_UNPACKED, 15, 0);
    for (int i = 0; i < 16; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+38+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, (15 - i), 7,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+54,0,"weight_load_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "act_in", VerilatedTracePrefixType::ARRAY_UNPACKED, 15, 0);
    for (int i = 0; i < 16; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+55+i*1,0,"",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, (15 - i), 7,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+71,0,"row_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "systolic_data_setup", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+72,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+73,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+74,0,"start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+76,0,"weight_buf_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "weight_buf_data", VerilatedTracePrefixType::ARRAY_UNPACKED, 15, 0);
    for (int i = 0; i < 16; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+77+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, (15 - i), 7,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BUS(tracep,c+93,0,"act_buf_addr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "act_buf_data", VerilatedTracePrefixType::ARRAY_UNPACKED, 15, 0);
    for (int i = 0; i < 16; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+94+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, (15 - i), 7,0);
    }
    VL_TRACE_POP_PREFIX(tracep);

    Vtop___024root__trace_init_dtype____2(vlSelf, tracep, "weight_in", 0, c+110, VerilatedTraceSigDirection::OUTPUT);
    VL_TRACE_DECL_BIT(tracep,c+126,0,"weight_load_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);

    Vtop___024root__trace_init_dtype____3(vlSelf, tracep, "act_in", 0, c+127, VerilatedTraceSigDirection::OUTPUT);
    VL_TRACE_DECL_BIT(tracep,c+143,0,"row_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+144,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+145,0,"cycle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____0(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____0(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____0(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____0(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 15, 0);
    for (int i = 0; i < 16; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, (15 - i), 7,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____1(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____1(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____1(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____1(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 15, 0);
    for (int i = 0; i < 16; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, (15 - i), 7,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____2(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____2(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____2(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____2(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 15, 0);
    for (int i = 0; i < 16; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, (15 - i), 7,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____3(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____3(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____3(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____3(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 15, 0);
    for (int i = 0; i < 16; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, (15 - i), 7,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar);
VL_ATTR_COLD void Vtop___024root__trace_full_dtype____1(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar);
VL_ATTR_COLD void Vtop___024root__trace_full_dtype____2(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar);
VL_ATTR_COLD void Vtop___024root__trace_full_dtype____3(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar);

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+0,(vlSelfRef.clk));
    bufp->fullBit(oldp+1,(vlSelfRef.rst_n));
    bufp->fullBit(oldp+2,(vlSelfRef.start));
    bufp->fullBit(oldp+3,(vlSelfRef.done));
    bufp->fullCData(oldp+4,(vlSelfRef.weight_buf_addr),4);
    Vtop___024root__trace_full_dtype____0(vlSelf, bufp, 5, vlSelfRef.weight_buf_data);
    bufp->fullCData(oldp+21,(vlSelfRef.act_buf_addr),4);
    Vtop___024root__trace_full_dtype____1(vlSelf, bufp, 22, vlSelfRef.act_buf_data);
    bufp->fullCData(oldp+38,(vlSelfRef.weight_in[15]),8);
    bufp->fullCData(oldp+39,(vlSelfRef.weight_in[14]),8);
    bufp->fullCData(oldp+40,(vlSelfRef.weight_in[13]),8);
    bufp->fullCData(oldp+41,(vlSelfRef.weight_in[12]),8);
    bufp->fullCData(oldp+42,(vlSelfRef.weight_in[11]),8);
    bufp->fullCData(oldp+43,(vlSelfRef.weight_in[10]),8);
    bufp->fullCData(oldp+44,(vlSelfRef.weight_in[9]),8);
    bufp->fullCData(oldp+45,(vlSelfRef.weight_in[8]),8);
    bufp->fullCData(oldp+46,(vlSelfRef.weight_in[7]),8);
    bufp->fullCData(oldp+47,(vlSelfRef.weight_in[6]),8);
    bufp->fullCData(oldp+48,(vlSelfRef.weight_in[5]),8);
    bufp->fullCData(oldp+49,(vlSelfRef.weight_in[4]),8);
    bufp->fullCData(oldp+50,(vlSelfRef.weight_in[3]),8);
    bufp->fullCData(oldp+51,(vlSelfRef.weight_in[2]),8);
    bufp->fullCData(oldp+52,(vlSelfRef.weight_in[1]),8);
    bufp->fullCData(oldp+53,(vlSelfRef.weight_in[0]),8);
    bufp->fullBit(oldp+54,(vlSelfRef.weight_load_en));
    bufp->fullCData(oldp+55,(vlSelfRef.act_in[15]),8);
    bufp->fullCData(oldp+56,(vlSelfRef.act_in[14]),8);
    bufp->fullCData(oldp+57,(vlSelfRef.act_in[13]),8);
    bufp->fullCData(oldp+58,(vlSelfRef.act_in[12]),8);
    bufp->fullCData(oldp+59,(vlSelfRef.act_in[11]),8);
    bufp->fullCData(oldp+60,(vlSelfRef.act_in[10]),8);
    bufp->fullCData(oldp+61,(vlSelfRef.act_in[9]),8);
    bufp->fullCData(oldp+62,(vlSelfRef.act_in[8]),8);
    bufp->fullCData(oldp+63,(vlSelfRef.act_in[7]),8);
    bufp->fullCData(oldp+64,(vlSelfRef.act_in[6]),8);
    bufp->fullCData(oldp+65,(vlSelfRef.act_in[5]),8);
    bufp->fullCData(oldp+66,(vlSelfRef.act_in[4]),8);
    bufp->fullCData(oldp+67,(vlSelfRef.act_in[3]),8);
    bufp->fullCData(oldp+68,(vlSelfRef.act_in[2]),8);
    bufp->fullCData(oldp+69,(vlSelfRef.act_in[1]),8);
    bufp->fullCData(oldp+70,(vlSelfRef.act_in[0]),8);
    bufp->fullBit(oldp+71,(vlSelfRef.row_valid));
    bufp->fullBit(oldp+72,(vlSelfRef.systolic_data_setup__DOT__clk));
    bufp->fullBit(oldp+73,(vlSelfRef.systolic_data_setup__DOT__rst_n));
    bufp->fullBit(oldp+74,(vlSelfRef.systolic_data_setup__DOT__start));
    bufp->fullBit(oldp+75,(vlSelfRef.systolic_data_setup__DOT__done));
    bufp->fullCData(oldp+76,(vlSelfRef.systolic_data_setup__DOT__weight_buf_addr),4);
    bufp->fullCData(oldp+77,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[15]),8);
    bufp->fullCData(oldp+78,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[14]),8);
    bufp->fullCData(oldp+79,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[13]),8);
    bufp->fullCData(oldp+80,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[12]),8);
    bufp->fullCData(oldp+81,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[11]),8);
    bufp->fullCData(oldp+82,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[10]),8);
    bufp->fullCData(oldp+83,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[9]),8);
    bufp->fullCData(oldp+84,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[8]),8);
    bufp->fullCData(oldp+85,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[7]),8);
    bufp->fullCData(oldp+86,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[6]),8);
    bufp->fullCData(oldp+87,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[5]),8);
    bufp->fullCData(oldp+88,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[4]),8);
    bufp->fullCData(oldp+89,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[3]),8);
    bufp->fullCData(oldp+90,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[2]),8);
    bufp->fullCData(oldp+91,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[1]),8);
    bufp->fullCData(oldp+92,(vlSelfRef.systolic_data_setup__DOT__weight_buf_data[0]),8);
    bufp->fullCData(oldp+93,(vlSelfRef.systolic_data_setup__DOT__act_buf_addr),4);
    bufp->fullCData(oldp+94,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[15]),8);
    bufp->fullCData(oldp+95,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[14]),8);
    bufp->fullCData(oldp+96,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[13]),8);
    bufp->fullCData(oldp+97,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[12]),8);
    bufp->fullCData(oldp+98,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[11]),8);
    bufp->fullCData(oldp+99,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[10]),8);
    bufp->fullCData(oldp+100,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[9]),8);
    bufp->fullCData(oldp+101,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[8]),8);
    bufp->fullCData(oldp+102,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[7]),8);
    bufp->fullCData(oldp+103,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[6]),8);
    bufp->fullCData(oldp+104,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[5]),8);
    bufp->fullCData(oldp+105,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[4]),8);
    bufp->fullCData(oldp+106,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[3]),8);
    bufp->fullCData(oldp+107,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[2]),8);
    bufp->fullCData(oldp+108,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[1]),8);
    bufp->fullCData(oldp+109,(vlSelfRef.systolic_data_setup__DOT__act_buf_data[0]),8);
    Vtop___024root__trace_full_dtype____2(vlSelf, bufp, 110, vlSelfRef.systolic_data_setup__DOT__weight_in);
    bufp->fullBit(oldp+126,(vlSelfRef.systolic_data_setup__DOT__weight_load_en));
    Vtop___024root__trace_full_dtype____3(vlSelf, bufp, 127, vlSelfRef.systolic_data_setup__DOT__act_in);
    bufp->fullBit(oldp+143,(vlSelfRef.systolic_data_setup__DOT__row_valid));
    bufp->fullCData(oldp+144,(vlSelfRef.systolic_data_setup__DOT__state),2);
    bufp->fullCData(oldp+145,(vlSelfRef.systolic_data_setup__DOT__cycle),5);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,(__VdtypeVar[15]),8);
    bufp->fullCData(oldp+1,(__VdtypeVar[14]),8);
    bufp->fullCData(oldp+2,(__VdtypeVar[13]),8);
    bufp->fullCData(oldp+3,(__VdtypeVar[12]),8);
    bufp->fullCData(oldp+4,(__VdtypeVar[11]),8);
    bufp->fullCData(oldp+5,(__VdtypeVar[10]),8);
    bufp->fullCData(oldp+6,(__VdtypeVar[9]),8);
    bufp->fullCData(oldp+7,(__VdtypeVar[8]),8);
    bufp->fullCData(oldp+8,(__VdtypeVar[7]),8);
    bufp->fullCData(oldp+9,(__VdtypeVar[6]),8);
    bufp->fullCData(oldp+10,(__VdtypeVar[5]),8);
    bufp->fullCData(oldp+11,(__VdtypeVar[4]),8);
    bufp->fullCData(oldp+12,(__VdtypeVar[3]),8);
    bufp->fullCData(oldp+13,(__VdtypeVar[2]),8);
    bufp->fullCData(oldp+14,(__VdtypeVar[1]),8);
    bufp->fullCData(oldp+15,(__VdtypeVar[0]),8);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____1(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,(__VdtypeVar[15]),8);
    bufp->fullCData(oldp+1,(__VdtypeVar[14]),8);
    bufp->fullCData(oldp+2,(__VdtypeVar[13]),8);
    bufp->fullCData(oldp+3,(__VdtypeVar[12]),8);
    bufp->fullCData(oldp+4,(__VdtypeVar[11]),8);
    bufp->fullCData(oldp+5,(__VdtypeVar[10]),8);
    bufp->fullCData(oldp+6,(__VdtypeVar[9]),8);
    bufp->fullCData(oldp+7,(__VdtypeVar[8]),8);
    bufp->fullCData(oldp+8,(__VdtypeVar[7]),8);
    bufp->fullCData(oldp+9,(__VdtypeVar[6]),8);
    bufp->fullCData(oldp+10,(__VdtypeVar[5]),8);
    bufp->fullCData(oldp+11,(__VdtypeVar[4]),8);
    bufp->fullCData(oldp+12,(__VdtypeVar[3]),8);
    bufp->fullCData(oldp+13,(__VdtypeVar[2]),8);
    bufp->fullCData(oldp+14,(__VdtypeVar[1]),8);
    bufp->fullCData(oldp+15,(__VdtypeVar[0]),8);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____2(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,(__VdtypeVar[15]),8);
    bufp->fullCData(oldp+1,(__VdtypeVar[14]),8);
    bufp->fullCData(oldp+2,(__VdtypeVar[13]),8);
    bufp->fullCData(oldp+3,(__VdtypeVar[12]),8);
    bufp->fullCData(oldp+4,(__VdtypeVar[11]),8);
    bufp->fullCData(oldp+5,(__VdtypeVar[10]),8);
    bufp->fullCData(oldp+6,(__VdtypeVar[9]),8);
    bufp->fullCData(oldp+7,(__VdtypeVar[8]),8);
    bufp->fullCData(oldp+8,(__VdtypeVar[7]),8);
    bufp->fullCData(oldp+9,(__VdtypeVar[6]),8);
    bufp->fullCData(oldp+10,(__VdtypeVar[5]),8);
    bufp->fullCData(oldp+11,(__VdtypeVar[4]),8);
    bufp->fullCData(oldp+12,(__VdtypeVar[3]),8);
    bufp->fullCData(oldp+13,(__VdtypeVar[2]),8);
    bufp->fullCData(oldp+14,(__VdtypeVar[1]),8);
    bufp->fullCData(oldp+15,(__VdtypeVar[0]),8);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____3(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<CData/*7:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____3\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullCData(oldp+0,(__VdtypeVar[15]),8);
    bufp->fullCData(oldp+1,(__VdtypeVar[14]),8);
    bufp->fullCData(oldp+2,(__VdtypeVar[13]),8);
    bufp->fullCData(oldp+3,(__VdtypeVar[12]),8);
    bufp->fullCData(oldp+4,(__VdtypeVar[11]),8);
    bufp->fullCData(oldp+5,(__VdtypeVar[10]),8);
    bufp->fullCData(oldp+6,(__VdtypeVar[9]),8);
    bufp->fullCData(oldp+7,(__VdtypeVar[8]),8);
    bufp->fullCData(oldp+8,(__VdtypeVar[7]),8);
    bufp->fullCData(oldp+9,(__VdtypeVar[6]),8);
    bufp->fullCData(oldp+10,(__VdtypeVar[5]),8);
    bufp->fullCData(oldp+11,(__VdtypeVar[4]),8);
    bufp->fullCData(oldp+12,(__VdtypeVar[3]),8);
    bufp->fullCData(oldp+13,(__VdtypeVar[2]),8);
    bufp->fullCData(oldp+14,(__VdtypeVar[1]),8);
    bufp->fullCData(oldp+15,(__VdtypeVar[0]),8);
}
