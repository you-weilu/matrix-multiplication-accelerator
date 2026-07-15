// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__pch.h"

Vtop__Syms::Vtop__Syms(VerilatedContext* contextp, const char* namep, Vtop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(258);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_tile_sequencer_fsm = new VerilatedScope{this, "tile_sequencer_fsm", "tile_sequencer_fsm", "tile_sequencer_fsm", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_tile_sequencer_fsm);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("fill_act_done", &(TOP.fill_act_done), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("fill_start", &(TOP.fill_start), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("fill_weight_done", &(TOP.fill_weight_done), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("final_pass", &(TOP.final_pass), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("go", &(TOP.go), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("k_tile", &(TOP.k_tile), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("k_tiles", &(TOP.k_tiles), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("m_tiles", &(TOP.m_tiles), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("n_tiles", &(TOP.n_tiles), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("pass_done", &(TOP.pass_done), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rst_n", &(TOP.rst_n), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("start", &(TOP.start), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("swap", &(TOP.swap), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("tile_done", &(TOP.tile_done), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("tile_i", &(TOP.tile_i), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("tile_j", &(TOP.tile_j), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("ts_busy", &(TOP.ts_busy), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("ts_done", &(TOP.ts_done), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("writeback_done", &(TOP.writeback_done), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("writeback_start", &(TOP.writeback_start), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("clk", &(TOP.tile_sequencer_fsm__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("fill_act_done", &(TOP.tile_sequencer_fsm__DOT__fill_act_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("fill_start", &(TOP.tile_sequencer_fsm__DOT__fill_start), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("fill_weight_done", &(TOP.tile_sequencer_fsm__DOT__fill_weight_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("final_pass", &(TOP.tile_sequencer_fsm__DOT__final_pass), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("go", &(TOP.tile_sequencer_fsm__DOT__go), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("k_tile", &(TOP.tile_sequencer_fsm__DOT__k_tile), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_tile_sequencer_fsm->varInsert("k_tiles", &(TOP.tile_sequencer_fsm__DOT__k_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_tile_sequencer_fsm->varInsert("last_tile", &(TOP.tile_sequencer_fsm__DOT__last_tile), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("m_tiles", &(TOP.tile_sequencer_fsm__DOT__m_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_tile_sequencer_fsm->varInsert("n_tiles", &(TOP.tile_sequencer_fsm__DOT__n_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_tile_sequencer_fsm->varInsert("pass_done", &(TOP.tile_sequencer_fsm__DOT__pass_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("rst_n", &(TOP.tile_sequencer_fsm__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("start", &(TOP.tile_sequencer_fsm__DOT__start), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("state", &(TOP.tile_sequencer_fsm__DOT__state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_tile_sequencer_fsm->varInsert("swap", &(TOP.tile_sequencer_fsm__DOT__swap), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("tile_done", &(TOP.tile_sequencer_fsm__DOT__tile_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("tile_i", &(TOP.tile_sequencer_fsm__DOT__tile_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_tile_sequencer_fsm->varInsert("tile_j", &(TOP.tile_sequencer_fsm__DOT__tile_j), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_tile_sequencer_fsm->varInsert("ts_busy", &(TOP.tile_sequencer_fsm__DOT__ts_busy), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("ts_done", &(TOP.tile_sequencer_fsm__DOT__ts_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("writeback_done", &(TOP.tile_sequencer_fsm__DOT__writeback_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_tile_sequencer_fsm->varInsert("writeback_start", &(TOP.tile_sequencer_fsm__DOT__writeback_start), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_tile_sequencer_fsm);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_tile_sequencer_fsm, __Vscopep_tile_sequencer_fsm = nullptr);
    // Tear down sub module instances
}
