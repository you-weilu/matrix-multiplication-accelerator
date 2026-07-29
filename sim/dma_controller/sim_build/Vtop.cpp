// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop__pch.h"

//============================================================
// Constructors

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , fill_start{vlSymsp->TOP.fill_start}
    , writeback_start{vlSymsp->TOP.writeback_start}
    , tile_i{vlSymsp->TOP.tile_i}
    , tile_j{vlSymsp->TOP.tile_j}
    , k_tile{vlSymsp->TOP.k_tile}
    , k_tiles{vlSymsp->TOP.k_tiles}
    , n_tiles{vlSymsp->TOP.n_tiles}
    , writeback_done{vlSymsp->TOP.writeback_done}
    , init_done{vlSymsp->TOP.init_done}
    , axil_awvalid{vlSymsp->TOP.axil_awvalid}
    , axil_awready{vlSymsp->TOP.axil_awready}
    , axil_awprot{vlSymsp->TOP.axil_awprot}
    , axil_wvalid{vlSymsp->TOP.axil_wvalid}
    , axil_wready{vlSymsp->TOP.axil_wready}
    , axil_wstrb{vlSymsp->TOP.axil_wstrb}
    , axil_bvalid{vlSymsp->TOP.axil_bvalid}
    , axil_bready{vlSymsp->TOP.axil_bready}
    , axil_bresp{vlSymsp->TOP.axil_bresp}
    , axil_arvalid{vlSymsp->TOP.axil_arvalid}
    , axil_arready{vlSymsp->TOP.axil_arready}
    , axil_arprot{vlSymsp->TOP.axil_arprot}
    , axil_rvalid{vlSymsp->TOP.axil_rvalid}
    , axil_rready{vlSymsp->TOP.axil_rready}
    , axil_rresp{vlSymsp->TOP.axil_rresp}
    , h2c_dsc_byp_ready_0{vlSymsp->TOP.h2c_dsc_byp_ready_0}
    , h2c_dsc_byp_load_0{vlSymsp->TOP.h2c_dsc_byp_load_0}
    , h2c_dsc_byp_ready_1{vlSymsp->TOP.h2c_dsc_byp_ready_1}
    , h2c_dsc_byp_load_1{vlSymsp->TOP.h2c_dsc_byp_load_1}
    , c2h_dsc_byp_ready_0{vlSymsp->TOP.c2h_dsc_byp_ready_0}
    , c2h_dsc_byp_load_0{vlSymsp->TOP.c2h_dsc_byp_load_0}
    , h2c_sts_0{vlSymsp->TOP.h2c_sts_0}
    , h2c_sts_1{vlSymsp->TOP.h2c_sts_1}
    , c2h_sts_0{vlSymsp->TOP.c2h_sts_0}
    , h2c_dsc_byp_ctl_0{vlSymsp->TOP.h2c_dsc_byp_ctl_0}
    , h2c_dsc_byp_ctl_1{vlSymsp->TOP.h2c_dsc_byp_ctl_1}
    , c2h_dsc_byp_ctl_0{vlSymsp->TOP.c2h_dsc_byp_ctl_0}
    , axil_awaddr{vlSymsp->TOP.axil_awaddr}
    , axil_wdata{vlSymsp->TOP.axil_wdata}
    , axil_araddr{vlSymsp->TOP.axil_araddr}
    , axil_rdata{vlSymsp->TOP.axil_rdata}
    , h2c_dsc_byp_len_0{vlSymsp->TOP.h2c_dsc_byp_len_0}
    , h2c_dsc_byp_len_1{vlSymsp->TOP.h2c_dsc_byp_len_1}
    , c2h_dsc_byp_len_0{vlSymsp->TOP.c2h_dsc_byp_len_0}
    , base_addr_a{vlSymsp->TOP.base_addr_a}
    , base_addr_b{vlSymsp->TOP.base_addr_b}
    , base_addr_c{vlSymsp->TOP.base_addr_c}
    , pp_weight_axi_base{vlSymsp->TOP.pp_weight_axi_base}
    , pp_act_axi_base{vlSymsp->TOP.pp_act_axi_base}
    , output_buf_axi_base{vlSymsp->TOP.output_buf_axi_base}
    , h2c_dsc_byp_src_addr_0{vlSymsp->TOP.h2c_dsc_byp_src_addr_0}
    , h2c_dsc_byp_dst_addr_0{vlSymsp->TOP.h2c_dsc_byp_dst_addr_0}
    , h2c_dsc_byp_src_addr_1{vlSymsp->TOP.h2c_dsc_byp_src_addr_1}
    , h2c_dsc_byp_dst_addr_1{vlSymsp->TOP.h2c_dsc_byp_dst_addr_1}
    , c2h_dsc_byp_src_addr_0{vlSymsp->TOP.c2h_dsc_byp_src_addr_0}
    , c2h_dsc_byp_dst_addr_0{vlSymsp->TOP.c2h_dsc_byp_dst_addr_0}
    , __PVT__dma_controller_wrap__DOT__axil{vlSymsp->TOP.__PVT__dma_controller_wrap__DOT__axil}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtop::Vtop(const char* _vcname__)
    : Vtop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtop::~Vtop() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop___024root___eval_static(Vtop___024root* vlSelf);
void Vtop___024root___eval_initial(Vtop___024root* vlSelf);
void Vtop___024root___eval_settle(Vtop___024root* vlSelf);
void Vtop___024root___eval(Vtop___024root* vlSelf);

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtop___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtop___024root___eval_static(&(vlSymsp->TOP));
        Vtop___024root___eval_initial(&(vlSymsp->TOP));
        Vtop___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtop___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtop::eventsPending() { return false; }

uint64_t Vtop::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtop___024root___eval_final(Vtop___024root* vlSelf);

VL_ATTR_COLD void Vtop::final() {
    contextp()->executingFinal(true);
    Vtop___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtop::hierName() const { return vlSymsp->name(); }
const char* Vtop::modelName() const { return "Vtop"; }
unsigned Vtop::threads() const { return 1; }
void Vtop::prepareClone() const { contextp()->prepareClone(); }
void Vtop::atClone() const {
    contextp()->threadPoolpOnClone();
}
