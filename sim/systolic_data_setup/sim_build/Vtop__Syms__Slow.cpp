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
    Verilated::stackCheck(284);
    // Setup sub module instances
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_systolic_data_setup = new VerilatedScope{this, "systolic_data_setup", "systolic_data_setup", "systolic_data_setup", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_systolic_data_setup__unnamedblk1 = new VerilatedScope{this, "systolic_data_setup.unnamedblk1", "unnamedblk1", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_systolic_data_setup__unnamedblk1__unnamedblk2 = new VerilatedScope{this, "systolic_data_setup.unnamedblk1.unnamedblk2", "unnamedblk2", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_systolic_data_setup__unnamedblk3 = new VerilatedScope{this, "systolic_data_setup.unnamedblk3", "unnamedblk3", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_systolic_data_setup__unnamedblk4 = new VerilatedScope{this, "systolic_data_setup.unnamedblk4", "unnamedblk4", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    __Vscopep_systolic_data_setup__unnamedblk5 = new VerilatedScope{this, "systolic_data_setup.unnamedblk5", "unnamedblk5", "<null>", -9, VerilatedScope::SCOPE_OTHER};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_systolic_data_setup);
    __Vhier.add(__Vscopep_systolic_data_setup, __Vscopep_systolic_data_setup__unnamedblk1);
    __Vhier.add(__Vscopep_systolic_data_setup, __Vscopep_systolic_data_setup__unnamedblk3);
    __Vhier.add(__Vscopep_systolic_data_setup, __Vscopep_systolic_data_setup__unnamedblk4);
    __Vhier.add(__Vscopep_systolic_data_setup, __Vscopep_systolic_data_setup__unnamedblk5);
    __Vhier.add(__Vscopep_systolic_data_setup__unnamedblk1, __Vscopep_systolic_data_setup__unnamedblk1__unnamedblk2);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("act_buf_addr", &(TOP.act_buf_addr), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_TOP->varInsert("act_buf_data", &(TOP.act_buf_data), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 1, 1 ,15,0 ,7,0);
    __Vscopep_TOP->varInsert("act_in", &(TOP.act_in), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 1, 1 ,15,0 ,7,0);
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("done", &(TOP.done), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("row_valid", &(TOP.row_valid), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rst_n", &(TOP.rst_n), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("start", &(TOP.start), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("weight_buf_addr", &(TOP.weight_buf_addr), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_TOP->varInsert("weight_buf_data", &(TOP.weight_buf_data), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 1, 1 ,15,0 ,7,0);
    __Vscopep_TOP->varInsert("weight_in", &(TOP.weight_in), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 1, 1 ,15,0 ,7,0);
    __Vscopep_TOP->varInsert("weight_load_en", &(TOP.weight_load_en), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_systolic_data_setup->varInsert("act_buf_addr", &(TOP.systolic_data_setup__DOT__act_buf_addr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_systolic_data_setup->varInsert("act_buf_data", &(TOP.systolic_data_setup__DOT__act_buf_data), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,15,0 ,7,0);
    __Vscopep_systolic_data_setup->varInsert("act_in", &(TOP.systolic_data_setup__DOT__act_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,15,0 ,7,0);
    __Vscopep_systolic_data_setup->varInsert("buf_work", &(TOP.systolic_data_setup__DOT__buf_work), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 2, 1 ,15,0 ,15,0 ,7,0);
    __Vscopep_systolic_data_setup->varInsert("clk", &(TOP.systolic_data_setup__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_systolic_data_setup->varInsert("cycle", &(TOP.systolic_data_setup__DOT__cycle), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_systolic_data_setup->varInsert("done", &(TOP.systolic_data_setup__DOT__done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_systolic_data_setup->varInsert("row_valid", &(TOP.systolic_data_setup__DOT__row_valid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_systolic_data_setup->varInsert("rst_n", &(TOP.systolic_data_setup__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_systolic_data_setup->varInsert("start", &(TOP.systolic_data_setup__DOT__start), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_systolic_data_setup->varInsert("state", &(TOP.systolic_data_setup__DOT__state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_systolic_data_setup->varInsert("weight_buf_addr", &(TOP.systolic_data_setup__DOT__weight_buf_addr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_systolic_data_setup->varInsert("weight_buf_data", &(TOP.systolic_data_setup__DOT__weight_buf_data), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,15,0 ,7,0);
    __Vscopep_systolic_data_setup->varInsert("weight_in", &(TOP.systolic_data_setup__DOT__weight_in), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,15,0 ,7,0);
    __Vscopep_systolic_data_setup->varInsert("weight_load_en", &(TOP.systolic_data_setup__DOT__weight_load_en), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_systolic_data_setup__unnamedblk1->varInsert("i", &(TOP.systolic_data_setup__DOT__unnamedblk1__DOT__i), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_systolic_data_setup__unnamedblk1__unnamedblk2->varInsert("j", &(TOP.systolic_data_setup__DOT__unnamedblk1__DOT__unnamedblk2__DOT__j), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_systolic_data_setup__unnamedblk3->varInsert("j", &(TOP.systolic_data_setup__DOT__unnamedblk3__DOT__j), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_systolic_data_setup__unnamedblk4->varInsert("i", &(TOP.systolic_data_setup__DOT__unnamedblk4__DOT__i), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_systolic_data_setup__unnamedblk5->varInsert("k", &(TOP.systolic_data_setup__DOT__unnamedblk5__DOT__k), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_DPI_CLAY|VLVF_SIGNED, 0, 1 ,31,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_systolic_data_setup);
    __Vhier.remove(__Vscopep_systolic_data_setup, __Vscopep_systolic_data_setup__unnamedblk1);
    __Vhier.remove(__Vscopep_systolic_data_setup, __Vscopep_systolic_data_setup__unnamedblk3);
    __Vhier.remove(__Vscopep_systolic_data_setup, __Vscopep_systolic_data_setup__unnamedblk4);
    __Vhier.remove(__Vscopep_systolic_data_setup, __Vscopep_systolic_data_setup__unnamedblk5);
    __Vhier.remove(__Vscopep_systolic_data_setup__unnamedblk1, __Vscopep_systolic_data_setup__unnamedblk1__unnamedblk2);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_systolic_data_setup, __Vscopep_systolic_data_setup = nullptr);
    VL_DO_CLEAR(delete __Vscopep_systolic_data_setup__unnamedblk1, __Vscopep_systolic_data_setup__unnamedblk1 = nullptr);
    VL_DO_CLEAR(delete __Vscopep_systolic_data_setup__unnamedblk1__unnamedblk2, __Vscopep_systolic_data_setup__unnamedblk1__unnamedblk2 = nullptr);
    VL_DO_CLEAR(delete __Vscopep_systolic_data_setup__unnamedblk3, __Vscopep_systolic_data_setup__unnamedblk3 = nullptr);
    VL_DO_CLEAR(delete __Vscopep_systolic_data_setup__unnamedblk4, __Vscopep_systolic_data_setup__unnamedblk4 = nullptr);
    VL_DO_CLEAR(delete __Vscopep_systolic_data_setup__unnamedblk5, __Vscopep_systolic_data_setup__unnamedblk5 = nullptr);
    // Tear down sub module instances
}
