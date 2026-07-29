// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , csr_awprot{vlSymsp->TOP.csr_awprot}
    , csr_awvalid{vlSymsp->TOP.csr_awvalid}
    , csr_awready{vlSymsp->TOP.csr_awready}
    , csr_wstrb{vlSymsp->TOP.csr_wstrb}
    , csr_wvalid{vlSymsp->TOP.csr_wvalid}
    , csr_wready{vlSymsp->TOP.csr_wready}
    , csr_bresp{vlSymsp->TOP.csr_bresp}
    , csr_bvalid{vlSymsp->TOP.csr_bvalid}
    , csr_bready{vlSymsp->TOP.csr_bready}
    , csr_arprot{vlSymsp->TOP.csr_arprot}
    , csr_arvalid{vlSymsp->TOP.csr_arvalid}
    , csr_arready{vlSymsp->TOP.csr_arready}
    , csr_rresp{vlSymsp->TOP.csr_rresp}
    , csr_rvalid{vlSymsp->TOP.csr_rvalid}
    , csr_rready{vlSymsp->TOP.csr_rready}
    , fw_awvalid{vlSymsp->TOP.fw_awvalid}
    , fw_awid{vlSymsp->TOP.fw_awid}
    , fw_awlen{vlSymsp->TOP.fw_awlen}
    , fw_awsize{vlSymsp->TOP.fw_awsize}
    , fw_awburst{vlSymsp->TOP.fw_awburst}
    , fw_awready{vlSymsp->TOP.fw_awready}
    , fw_wvalid{vlSymsp->TOP.fw_wvalid}
    , fw_wlast{vlSymsp->TOP.fw_wlast}
    , fw_wready{vlSymsp->TOP.fw_wready}
    , fw_bvalid{vlSymsp->TOP.fw_bvalid}
    , fw_bid{vlSymsp->TOP.fw_bid}
    , fw_bresp{vlSymsp->TOP.fw_bresp}
    , fw_bready{vlSymsp->TOP.fw_bready}
    , fa_awvalid{vlSymsp->TOP.fa_awvalid}
    , fa_awid{vlSymsp->TOP.fa_awid}
    , fa_awlen{vlSymsp->TOP.fa_awlen}
    , fa_awsize{vlSymsp->TOP.fa_awsize}
    , fa_awburst{vlSymsp->TOP.fa_awburst}
    , fa_awready{vlSymsp->TOP.fa_awready}
    , fa_wvalid{vlSymsp->TOP.fa_wvalid}
    , fa_wlast{vlSymsp->TOP.fa_wlast}
    , fa_wready{vlSymsp->TOP.fa_wready}
    , fa_bvalid{vlSymsp->TOP.fa_bvalid}
    , fa_bid{vlSymsp->TOP.fa_bid}
    , fa_bresp{vlSymsp->TOP.fa_bresp}
    , fa_bready{vlSymsp->TOP.fa_bready}
    , ob_arvalid{vlSymsp->TOP.ob_arvalid}
    , ob_arid{vlSymsp->TOP.ob_arid}
    , ob_arlen{vlSymsp->TOP.ob_arlen}
    , ob_arsize{vlSymsp->TOP.ob_arsize}
    , ob_arburst{vlSymsp->TOP.ob_arburst}
    , ob_arready{vlSymsp->TOP.ob_arready}
    , ob_rvalid{vlSymsp->TOP.ob_rvalid}
    , ob_rid{vlSymsp->TOP.ob_rid}
    , ob_rresp{vlSymsp->TOP.ob_rresp}
    , ob_rlast{vlSymsp->TOP.ob_rlast}
    , ob_rready{vlSymsp->TOP.ob_rready}
    , init_done{vlSymsp->TOP.init_done}
    , writeback_done{vlSymsp->TOP.writeback_done}
    , fill_start{vlSymsp->TOP.fill_start}
    , writeback_start{vlSymsp->TOP.writeback_start}
    , tile_i{vlSymsp->TOP.tile_i}
    , tile_j{vlSymsp->TOP.tile_j}
    , k_tile{vlSymsp->TOP.k_tile}
    , ts_done{vlSymsp->TOP.ts_done}
    , ts_busy{vlSymsp->TOP.ts_busy}
    , fw_wstrb{vlSymsp->TOP.fw_wstrb}
    , fa_wstrb{vlSymsp->TOP.fa_wstrb}
    , csr_awaddr{vlSymsp->TOP.csr_awaddr}
    , csr_wdata{vlSymsp->TOP.csr_wdata}
    , csr_araddr{vlSymsp->TOP.csr_araddr}
    , csr_rdata{vlSymsp->TOP.csr_rdata}
    , fw_wdata{vlSymsp->TOP.fw_wdata}
    , fa_wdata{vlSymsp->TOP.fa_wdata}
    , ob_rdata{vlSymsp->TOP.ob_rdata}
    , fw_awaddr{vlSymsp->TOP.fw_awaddr}
    , fa_awaddr{vlSymsp->TOP.fa_awaddr}
    , ob_araddr{vlSymsp->TOP.ob_araddr}
    , __PVT__compute_pipeline_wrap__DOT__csr_axi{vlSymsp->TOP.__PVT__compute_pipeline_wrap__DOT__csr_axi}
    , __PVT__compute_pipeline_wrap__DOT__fill_weight_axi{vlSymsp->TOP.__PVT__compute_pipeline_wrap__DOT__fill_weight_axi}
    , __PVT__compute_pipeline_wrap__DOT__fill_act_axi{vlSymsp->TOP.__PVT__compute_pipeline_wrap__DOT__fill_act_axi}
    , __PVT__compute_pipeline_wrap__DOT__c2h_axi{vlSymsp->TOP.__PVT__compute_pipeline_wrap__DOT__c2h_axi}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
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
    vlSymsp->__Vm_activity = true;
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
std::unique_ptr<VerilatedTraceConfig> Vtop::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vtop___024root__trace_decl_types(VerilatedVcd* tracep);

void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vtop___024root__trace_decl_types(tracep);
    Vtop___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vtop::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 3391);
    Vtop___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
