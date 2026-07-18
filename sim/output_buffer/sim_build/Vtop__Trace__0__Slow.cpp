// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_dtype____0(Vtop___024root* vlSelf, VerilatedVcd* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);
VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__output_buffer_wrap__DOT__c2h_axi__0(Vtop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "$rootio", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"buf_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"buf_row",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);

    Vtop___024root__trace_init_dtype____0(vlSelf, tracep, "buf_data", 0, c+4, VerilatedTraceSigDirection::INPUT);
    VL_TRACE_DECL_BIT(tracep,c+20,0,"arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+21,0,"arid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_QUAD(tracep,c+22,0,"araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+24,0,"arlen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+25,0,"arsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+26,0,"arburst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+27,0,"arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+28,0,"rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+29,0,"rid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_WIDE(tracep,c+30,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BUS(tracep,c+34,0,"rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+35,0,"rlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+36,0,"rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "output_buffer_wrap", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+37,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+38,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+39,0,"buf_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+40,0,"buf_row",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "buf_data", VerilatedTracePrefixType::ARRAY_UNPACKED, 15, 0);
    for (int i = 0; i < 16; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+41+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, (15 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+57,0,"arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+58,0,"arid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_QUAD(tracep,c+59,0,"araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+61,0,"arlen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+62,0,"arsize",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+63,0,"arburst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+64,0,"arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+65,0,"rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+66,0,"rid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_WIDE(tracep,c+67,0,"rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BUS(tracep,c+71,0,"rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+72,0,"rlast",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+73,0,"rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_PUSH_PREFIX(tracep, "c2h_axi", VerilatedTracePrefixType::SCOPE_INTERFACE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__output_buffer_wrap__DOT__c2h_axi__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "dut", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+74,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+75,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+76,0,"buf_wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+77,0,"buf_row",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_PUSH_PREFIX(tracep, "buf_data", VerilatedTracePrefixType::ARRAY_UNPACKED, 15, 0);
    for (int i = 0; i < 16; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+78+i*1,0,"",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, (15 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_DECL_BIT(tracep,c+94,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+95,0,"beat_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 5,0);
    VL_TRACE_DECL_BUS(tracep,c+96,0,"beat_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_PUSH_PREFIX(tracep, "c2h_axi", VerilatedTracePrefixType::SCOPE_INTERFACE, 0, 0);
    Vtop___024root__trace_init_sub__TOP__output_buffer_wrap__DOT__c2h_axi__0(vlSelf, tracep);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
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
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, (15 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__output_buffer_wrap__DOT__c2h_axi__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__output_buffer_wrap__DOT__c2h_axi__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_DECL_BUS(tracep,c+136,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+137,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+138,0,"ID_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+139,0,"LEN_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+97,0,"aclk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+98,0,"aresetn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+99,0,"awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+100,0,"awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+101,0,"awid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_QUAD(tracep,c+102,0,"awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+104,0,"awlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+105,0,"awsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+106,0,"awburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+107,0,"wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+108,0,"wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_WIDE(tracep,c+109,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BUS(tracep,c+113,0,"wstrb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 15,0);
    VL_TRACE_DECL_BIT(tracep,c+114,0,"wlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+115,0,"bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+116,0,"bready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+117,0,"bid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+118,0,"bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+119,0,"arvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+120,0,"arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+121,0,"arid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_QUAD(tracep,c+122,0,"araddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 63,0);
    VL_TRACE_DECL_BUS(tracep,c+124,0,"arlen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+125,0,"arsize",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+126,0,"arburst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+127,0,"rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+128,0,"rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+129,0,"rid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_WIDE(tracep,c+130,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 127,0);
    VL_TRACE_DECL_BUS(tracep,c+134,0,"rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BIT(tracep,c+135,0,"rlast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC);
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

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+136,(0x00000040U),32);
    bufp->fullIData(oldp+137,(0x00000080U),32);
    bufp->fullIData(oldp+138,(4U),32);
    bufp->fullIData(oldp+139,(8U),32);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 16>& __VdtypeVar);

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+0,(vlSelfRef.clk));
    bufp->fullBit(oldp+1,(vlSelfRef.rst_n));
    bufp->fullBit(oldp+2,(vlSelfRef.buf_wen));
    bufp->fullCData(oldp+3,(vlSelfRef.buf_row),4);
    Vtop___024root__trace_full_dtype____0(vlSelf, bufp, 4, vlSelfRef.buf_data);
    bufp->fullBit(oldp+20,(vlSelfRef.arvalid));
    bufp->fullCData(oldp+21,(vlSelfRef.arid),4);
    bufp->fullQData(oldp+22,(vlSelfRef.araddr),64);
    bufp->fullCData(oldp+24,(vlSelfRef.arlen),8);
    bufp->fullCData(oldp+25,(vlSelfRef.arsize),3);
    bufp->fullCData(oldp+26,(vlSelfRef.arburst),2);
    bufp->fullBit(oldp+27,(vlSelfRef.arready));
    bufp->fullBit(oldp+28,(vlSelfRef.rvalid));
    bufp->fullCData(oldp+29,(vlSelfRef.rid),4);
    bufp->fullWData(oldp+30,(vlSelfRef.rdata),128);
    bufp->fullCData(oldp+34,(vlSelfRef.rresp),2);
    bufp->fullBit(oldp+35,(vlSelfRef.rlast));
    bufp->fullBit(oldp+36,(vlSelfRef.rready));
    bufp->fullBit(oldp+37,(vlSelfRef.output_buffer_wrap__DOT__clk));
    bufp->fullBit(oldp+38,(vlSelfRef.output_buffer_wrap__DOT__rst_n));
    bufp->fullBit(oldp+39,(vlSelfRef.output_buffer_wrap__DOT__buf_wen));
    bufp->fullCData(oldp+40,(vlSelfRef.output_buffer_wrap__DOT__buf_row),4);
    bufp->fullIData(oldp+41,(vlSelfRef.output_buffer_wrap__DOT__buf_data[15]),32);
    bufp->fullIData(oldp+42,(vlSelfRef.output_buffer_wrap__DOT__buf_data[14]),32);
    bufp->fullIData(oldp+43,(vlSelfRef.output_buffer_wrap__DOT__buf_data[13]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.output_buffer_wrap__DOT__buf_data[12]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.output_buffer_wrap__DOT__buf_data[11]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.output_buffer_wrap__DOT__buf_data[10]),32);
    bufp->fullIData(oldp+47,(vlSelfRef.output_buffer_wrap__DOT__buf_data[9]),32);
    bufp->fullIData(oldp+48,(vlSelfRef.output_buffer_wrap__DOT__buf_data[8]),32);
    bufp->fullIData(oldp+49,(vlSelfRef.output_buffer_wrap__DOT__buf_data[7]),32);
    bufp->fullIData(oldp+50,(vlSelfRef.output_buffer_wrap__DOT__buf_data[6]),32);
    bufp->fullIData(oldp+51,(vlSelfRef.output_buffer_wrap__DOT__buf_data[5]),32);
    bufp->fullIData(oldp+52,(vlSelfRef.output_buffer_wrap__DOT__buf_data[4]),32);
    bufp->fullIData(oldp+53,(vlSelfRef.output_buffer_wrap__DOT__buf_data[3]),32);
    bufp->fullIData(oldp+54,(vlSelfRef.output_buffer_wrap__DOT__buf_data[2]),32);
    bufp->fullIData(oldp+55,(vlSelfRef.output_buffer_wrap__DOT__buf_data[1]),32);
    bufp->fullIData(oldp+56,(vlSelfRef.output_buffer_wrap__DOT__buf_data[0]),32);
    bufp->fullBit(oldp+57,(vlSelfRef.output_buffer_wrap__DOT__arvalid));
    bufp->fullCData(oldp+58,(vlSelfRef.output_buffer_wrap__DOT__arid),4);
    bufp->fullQData(oldp+59,(vlSelfRef.output_buffer_wrap__DOT__araddr),64);
    bufp->fullCData(oldp+61,(vlSelfRef.output_buffer_wrap__DOT__arlen),8);
    bufp->fullCData(oldp+62,(vlSelfRef.output_buffer_wrap__DOT__arsize),3);
    bufp->fullCData(oldp+63,(vlSelfRef.output_buffer_wrap__DOT__arburst),2);
    bufp->fullBit(oldp+64,(vlSelfRef.output_buffer_wrap__DOT__arready));
    bufp->fullBit(oldp+65,(vlSelfRef.output_buffer_wrap__DOT__rvalid));
    bufp->fullCData(oldp+66,(vlSelfRef.output_buffer_wrap__DOT__rid),4);
    bufp->fullWData(oldp+67,(vlSelfRef.output_buffer_wrap__DOT__rdata),128);
    bufp->fullCData(oldp+71,(vlSelfRef.output_buffer_wrap__DOT__rresp),2);
    bufp->fullBit(oldp+72,(vlSelfRef.output_buffer_wrap__DOT__rlast));
    bufp->fullBit(oldp+73,(vlSelfRef.output_buffer_wrap__DOT__rready));
    bufp->fullBit(oldp+74,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__clk));
    bufp->fullBit(oldp+75,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__rst_n));
    bufp->fullBit(oldp+76,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_wen));
    bufp->fullCData(oldp+77,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_row),4);
    bufp->fullIData(oldp+78,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[15]),32);
    bufp->fullIData(oldp+79,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[14]),32);
    bufp->fullIData(oldp+80,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[13]),32);
    bufp->fullIData(oldp+81,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[12]),32);
    bufp->fullIData(oldp+82,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[11]),32);
    bufp->fullIData(oldp+83,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[10]),32);
    bufp->fullIData(oldp+84,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[9]),32);
    bufp->fullIData(oldp+85,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[8]),32);
    bufp->fullIData(oldp+86,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[7]),32);
    bufp->fullIData(oldp+87,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[6]),32);
    bufp->fullIData(oldp+88,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[5]),32);
    bufp->fullIData(oldp+89,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[4]),32);
    bufp->fullIData(oldp+90,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[3]),32);
    bufp->fullIData(oldp+91,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[2]),32);
    bufp->fullIData(oldp+92,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[1]),32);
    bufp->fullIData(oldp+93,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__buf_data[0]),32);
    bufp->fullBit(oldp+94,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__state));
    bufp->fullCData(oldp+95,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__beat_addr),6);
    bufp->fullCData(oldp+96,(vlSelfRef.output_buffer_wrap__DOT__dut__DOT__beat_count),8);
    bufp->fullBit(oldp+97,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.aclk));
    bufp->fullBit(oldp+98,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.aresetn));
    bufp->fullBit(oldp+99,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.awvalid));
    bufp->fullBit(oldp+100,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.awready));
    bufp->fullCData(oldp+101,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.awid),4);
    bufp->fullQData(oldp+102,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.awaddr),64);
    bufp->fullCData(oldp+104,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.awlen),8);
    bufp->fullCData(oldp+105,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.awsize),3);
    bufp->fullCData(oldp+106,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.awburst),2);
    bufp->fullBit(oldp+107,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.wvalid));
    bufp->fullBit(oldp+108,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.wready));
    bufp->fullWData(oldp+109,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.wdata),128);
    bufp->fullSData(oldp+113,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.wstrb),16);
    bufp->fullBit(oldp+114,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.wlast));
    bufp->fullBit(oldp+115,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.bvalid));
    bufp->fullBit(oldp+116,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.bready));
    bufp->fullCData(oldp+117,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.bid),4);
    bufp->fullCData(oldp+118,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.bresp),2);
    bufp->fullBit(oldp+119,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arvalid));
    bufp->fullBit(oldp+120,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arready));
    bufp->fullCData(oldp+121,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arid),4);
    bufp->fullQData(oldp+122,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.araddr),64);
    bufp->fullCData(oldp+124,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arlen),8);
    bufp->fullCData(oldp+125,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arsize),3);
    bufp->fullCData(oldp+126,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.arburst),2);
    bufp->fullBit(oldp+127,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rvalid));
    bufp->fullBit(oldp+128,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rready));
    bufp->fullCData(oldp+129,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rid),4);
    bufp->fullWData(oldp+130,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rdata),128);
    bufp->fullCData(oldp+134,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rresp),2);
    bufp->fullBit(oldp+135,(vlSymsp->TOP__output_buffer_wrap__DOT__c2h_axi.rlast));
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp, uint32_t offset, const VlUnpacked<IData/*31:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[15]),32);
    bufp->fullIData(oldp+1,(__VdtypeVar[14]),32);
    bufp->fullIData(oldp+2,(__VdtypeVar[13]),32);
    bufp->fullIData(oldp+3,(__VdtypeVar[12]),32);
    bufp->fullIData(oldp+4,(__VdtypeVar[11]),32);
    bufp->fullIData(oldp+5,(__VdtypeVar[10]),32);
    bufp->fullIData(oldp+6,(__VdtypeVar[9]),32);
    bufp->fullIData(oldp+7,(__VdtypeVar[8]),32);
    bufp->fullIData(oldp+8,(__VdtypeVar[7]),32);
    bufp->fullIData(oldp+9,(__VdtypeVar[6]),32);
    bufp->fullIData(oldp+10,(__VdtypeVar[5]),32);
    bufp->fullIData(oldp+11,(__VdtypeVar[4]),32);
    bufp->fullIData(oldp+12,(__VdtypeVar[3]),32);
    bufp->fullIData(oldp+13,(__VdtypeVar[2]),32);
    bufp->fullIData(oldp+14,(__VdtypeVar[1]),32);
    bufp->fullIData(oldp+15,(__VdtypeVar[0]),32);
}
