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
    Verilated::stackCheck(388);
    // Setup sub module instances
    TOP__output_buffer_wrap__DOT__c2h_axi.ctor(this, "output_buffer_wrap.c2h_axi");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__output_buffer_wrap__DOT__c2h_axi = &TOP__output_buffer_wrap__DOT__c2h_axi;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__output_buffer_wrap__DOT__c2h_axi.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_output_buffer_wrap = new VerilatedScope{this, "output_buffer_wrap", "output_buffer_wrap", "output_buffer_wrap", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_output_buffer_wrap__c2h_axi = new VerilatedScope{this, "output_buffer_wrap.c2h_axi", "c2h_axi", "axi4_if", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_output_buffer_wrap__dut = new VerilatedScope{this, "output_buffer_wrap.dut", "dut", "output_buffer", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_output_buffer_wrap);
    __Vhier.add(__Vscopep_output_buffer_wrap, __Vscopep_output_buffer_wrap__c2h_axi);
    __Vhier.add(__Vscopep_output_buffer_wrap, __Vscopep_output_buffer_wrap__dut);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("araddr", &(TOP.araddr), false, VLVT_UINT64, VLVD_IN|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("arburst", &(TOP.arburst), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("arid", &(TOP.arid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_TOP->varInsert("arlen", &(TOP.arlen), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("arready", &(TOP.arready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("arsize", &(TOP.arsize), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_TOP->varInsert("arvalid", &(TOP.arvalid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("buf_data", &(TOP.buf_data), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 1, 1 ,15,0 ,31,0);
    __Vscopep_TOP->varInsert("buf_row", &(TOP.buf_row), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_TOP->varInsert("buf_wen", &(TOP.buf_wen), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rdata", &(TOP.rdata), false, VLVT_WDATA, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,127,0);
    __Vscopep_TOP->varInsert("rid", &(TOP.rid), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,3,0);
    __Vscopep_TOP->varInsert("rlast", &(TOP.rlast), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("rready", &(TOP.rready), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rresp", &(TOP.rresp), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("rst_n", &(TOP.rst_n), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rvalid", &(TOP.rvalid), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_output_buffer_wrap->varInsert("araddr", &(TOP.output_buffer_wrap__DOT__araddr), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_output_buffer_wrap->varInsert("arburst", &(TOP.output_buffer_wrap__DOT__arburst), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_output_buffer_wrap->varInsert("arid", &(TOP.output_buffer_wrap__DOT__arid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_output_buffer_wrap->varInsert("arlen", &(TOP.output_buffer_wrap__DOT__arlen), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_output_buffer_wrap->varInsert("arready", &(TOP.output_buffer_wrap__DOT__arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_output_buffer_wrap->varInsert("arsize", &(TOP.output_buffer_wrap__DOT__arsize), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_output_buffer_wrap->varInsert("arvalid", &(TOP.output_buffer_wrap__DOT__arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_output_buffer_wrap->varInsert("buf_data", &(TOP.output_buffer_wrap__DOT__buf_data), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,15,0 ,31,0);
    __Vscopep_output_buffer_wrap->varInsert("buf_row", &(TOP.output_buffer_wrap__DOT__buf_row), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_output_buffer_wrap->varInsert("buf_wen", &(TOP.output_buffer_wrap__DOT__buf_wen), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_output_buffer_wrap->varInsert("clk", &(TOP.output_buffer_wrap__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_output_buffer_wrap->varInsert("rdata", &(TOP.output_buffer_wrap__DOT__rdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,127,0);
    __Vscopep_output_buffer_wrap->varInsert("rid", &(TOP.output_buffer_wrap__DOT__rid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,3,0);
    __Vscopep_output_buffer_wrap->varInsert("rlast", &(TOP.output_buffer_wrap__DOT__rlast), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_output_buffer_wrap->varInsert("rready", &(TOP.output_buffer_wrap__DOT__rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_output_buffer_wrap->varInsert("rresp", &(TOP.output_buffer_wrap__DOT__rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_output_buffer_wrap->varInsert("rst_n", &(TOP.output_buffer_wrap__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_output_buffer_wrap->varInsert("rvalid", &(TOP.output_buffer_wrap__DOT__rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__output_buffer_wrap__DOT__c2h_axi.ADDR_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__output_buffer_wrap__DOT__c2h_axi.DATA_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("ID_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__output_buffer_wrap__DOT__c2h_axi.ID_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("LEN_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__output_buffer_wrap__DOT__c2h_axi.LEN_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("aclk", &(TOP__output_buffer_wrap__DOT__c2h_axi.aclk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("araddr", &(TOP__output_buffer_wrap__DOT__c2h_axi.araddr), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,63,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("arburst", &(TOP__output_buffer_wrap__DOT__c2h_axi.arburst), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("aresetn", &(TOP__output_buffer_wrap__DOT__c2h_axi.aresetn), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("arid", &(TOP__output_buffer_wrap__DOT__c2h_axi.arid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,3,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("arlen", &(TOP__output_buffer_wrap__DOT__c2h_axi.arlen), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,7,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("arready", &(TOP__output_buffer_wrap__DOT__c2h_axi.arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("arsize", &(TOP__output_buffer_wrap__DOT__c2h_axi.arsize), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,2,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("arvalid", &(TOP__output_buffer_wrap__DOT__c2h_axi.arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("awaddr", &(TOP__output_buffer_wrap__DOT__c2h_axi.awaddr), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,63,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("awburst", &(TOP__output_buffer_wrap__DOT__c2h_axi.awburst), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("awid", &(TOP__output_buffer_wrap__DOT__c2h_axi.awid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,3,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("awlen", &(TOP__output_buffer_wrap__DOT__c2h_axi.awlen), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,7,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("awready", &(TOP__output_buffer_wrap__DOT__c2h_axi.awready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("awsize", &(TOP__output_buffer_wrap__DOT__c2h_axi.awsize), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,2,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("awvalid", &(TOP__output_buffer_wrap__DOT__c2h_axi.awvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("bid", &(TOP__output_buffer_wrap__DOT__c2h_axi.bid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("bready", &(TOP__output_buffer_wrap__DOT__c2h_axi.bready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("bresp", &(TOP__output_buffer_wrap__DOT__c2h_axi.bresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("bvalid", &(TOP__output_buffer_wrap__DOT__c2h_axi.bvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("rdata", &(TOP__output_buffer_wrap__DOT__c2h_axi.rdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,127,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("rid", &(TOP__output_buffer_wrap__DOT__c2h_axi.rid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("rlast", &(TOP__output_buffer_wrap__DOT__c2h_axi.rlast), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("rready", &(TOP__output_buffer_wrap__DOT__c2h_axi.rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("rresp", &(TOP__output_buffer_wrap__DOT__c2h_axi.rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("rvalid", &(TOP__output_buffer_wrap__DOT__c2h_axi.rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("wdata", &(TOP__output_buffer_wrap__DOT__c2h_axi.wdata), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,127,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("wlast", &(TOP__output_buffer_wrap__DOT__c2h_axi.wlast), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("wready", &(TOP__output_buffer_wrap__DOT__c2h_axi.wready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("wstrb", &(TOP__output_buffer_wrap__DOT__c2h_axi.wstrb), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,15,0);
    __Vscopep_output_buffer_wrap__c2h_axi->varInsert("wvalid", &(TOP__output_buffer_wrap__DOT__c2h_axi.wvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_output_buffer_wrap__dut->varInsert("beat_addr", &(TOP.output_buffer_wrap__DOT__dut__DOT__beat_addr), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,5,0);
    __Vscopep_output_buffer_wrap__dut->varInsert("beat_count", &(TOP.output_buffer_wrap__DOT__dut__DOT__beat_count), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_output_buffer_wrap__dut->varInsert("buf_data", &(TOP.output_buffer_wrap__DOT__dut__DOT__buf_data), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,15,0 ,31,0);
    __Vscopep_output_buffer_wrap__dut->varInsert("buf_row", &(TOP.output_buffer_wrap__DOT__dut__DOT__buf_row), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_output_buffer_wrap__dut->varInsert("buf_wen", &(TOP.output_buffer_wrap__DOT__dut__DOT__buf_wen), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_output_buffer_wrap__dut->varInsert("clk", &(TOP.output_buffer_wrap__DOT__dut__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_output_buffer_wrap__dut->varInsert("mem", &(TOP.output_buffer_wrap__DOT__dut__DOT__mem), false, VLVT_WDATA, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,63,0 ,127,0);
    __Vscopep_output_buffer_wrap__dut->varInsert("rst_n", &(TOP.output_buffer_wrap__DOT__dut__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_output_buffer_wrap__dut->varInsert("state", &(TOP.output_buffer_wrap__DOT__dut__DOT__state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_output_buffer_wrap);
    __Vhier.remove(__Vscopep_output_buffer_wrap, __Vscopep_output_buffer_wrap__c2h_axi);
    __Vhier.remove(__Vscopep_output_buffer_wrap, __Vscopep_output_buffer_wrap__dut);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_output_buffer_wrap, __Vscopep_output_buffer_wrap = nullptr);
    VL_DO_CLEAR(delete __Vscopep_output_buffer_wrap__c2h_axi, __Vscopep_output_buffer_wrap__c2h_axi = nullptr);
    VL_DO_CLEAR(delete __Vscopep_output_buffer_wrap__dut, __Vscopep_output_buffer_wrap__dut = nullptr);
    // Tear down sub module instances
    TOP__output_buffer_wrap__DOT__c2h_axi.dtor();
}
