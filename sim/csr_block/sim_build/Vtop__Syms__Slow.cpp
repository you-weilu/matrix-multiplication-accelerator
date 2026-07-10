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
    Verilated::stackCheck(250);
    // Setup sub module instances
    TOP__csr_block_wrap__DOT__csr_axi.ctor(this, "csr_block_wrap.csr_axi");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__csr_block_wrap__DOT__csr_axi = &TOP__csr_block_wrap__DOT__csr_axi;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__csr_block_wrap__DOT__csr_axi.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_csr_block_wrap = new VerilatedScope{this, "csr_block_wrap", "csr_block_wrap", "csr_block_wrap", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_csr_block_wrap__csr_axi = new VerilatedScope{this, "csr_block_wrap.csr_axi", "csr_axi", "axi_lite_if", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_csr_block_wrap__dut = new VerilatedScope{this, "csr_block_wrap.dut", "dut", "csr_block", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_csr_block_wrap);
    __Vhier.add(__Vscopep_csr_block_wrap, __Vscopep_csr_block_wrap__csr_axi);
    __Vhier.add(__Vscopep_csr_block_wrap, __Vscopep_csr_block_wrap__dut);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("araddr", &(TOP.araddr), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("arprot", &(TOP.arprot), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_TOP->varInsert("arready", &(TOP.arready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("arvalid", &(TOP.arvalid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("awaddr", &(TOP.awaddr), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("awprot", &(TOP.awprot), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_TOP->varInsert("awready", &(TOP.awready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("awvalid", &(TOP.awvalid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("bready", &(TOP.bready), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("bresp", &(TOP.bresp), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("bvalid", &(TOP.bvalid), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("go", &(TOP.go), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("k_tiles", &(TOP.k_tiles), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("m_tiles", &(TOP.m_tiles), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("n_tiles", &(TOP.n_tiles), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("rdata", &(TOP.rdata), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("rready", &(TOP.rready), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rresp", &(TOP.rresp), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("rst_n", &(TOP.rst_n), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("rvalid", &(TOP.rvalid), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("ts_busy", &(TOP.ts_busy), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("ts_done", &(TOP.ts_done), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("wdata", &(TOP.wdata), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("wready", &(TOP.wready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("wstrb", &(TOP.wstrb), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_TOP->varInsert("wvalid", &(TOP.wvalid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("araddr", &(TOP.csr_block_wrap__DOT__araddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_csr_block_wrap->varInsert("arprot", &(TOP.csr_block_wrap__DOT__arprot), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_csr_block_wrap->varInsert("arready", &(TOP.csr_block_wrap__DOT__arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("arvalid", &(TOP.csr_block_wrap__DOT__arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("awaddr", &(TOP.csr_block_wrap__DOT__awaddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_csr_block_wrap->varInsert("awprot", &(TOP.csr_block_wrap__DOT__awprot), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_csr_block_wrap->varInsert("awready", &(TOP.csr_block_wrap__DOT__awready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("awvalid", &(TOP.csr_block_wrap__DOT__awvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("bready", &(TOP.csr_block_wrap__DOT__bready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("bresp", &(TOP.csr_block_wrap__DOT__bresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_csr_block_wrap->varInsert("bvalid", &(TOP.csr_block_wrap__DOT__bvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("clk", &(TOP.csr_block_wrap__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("go", &(TOP.csr_block_wrap__DOT__go), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("k_tiles", &(TOP.csr_block_wrap__DOT__k_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_csr_block_wrap->varInsert("m_tiles", &(TOP.csr_block_wrap__DOT__m_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_csr_block_wrap->varInsert("n_tiles", &(TOP.csr_block_wrap__DOT__n_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_csr_block_wrap->varInsert("rdata", &(TOP.csr_block_wrap__DOT__rdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_csr_block_wrap->varInsert("rready", &(TOP.csr_block_wrap__DOT__rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("rresp", &(TOP.csr_block_wrap__DOT__rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_csr_block_wrap->varInsert("rst_n", &(TOP.csr_block_wrap__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("rvalid", &(TOP.csr_block_wrap__DOT__rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("ts_busy", &(TOP.csr_block_wrap__DOT__ts_busy), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("ts_done", &(TOP.csr_block_wrap__DOT__ts_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("wdata", &(TOP.csr_block_wrap__DOT__wdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_csr_block_wrap->varInsert("wready", &(TOP.csr_block_wrap__DOT__wready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csr_block_wrap->varInsert("wstrb", &(TOP.csr_block_wrap__DOT__wstrb), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_csr_block_wrap->varInsert("wvalid", &(TOP.csr_block_wrap__DOT__wvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__csr_block_wrap__DOT__csr_axi.ADDR_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__csr_block_wrap__DOT__csr_axi.DATA_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("aclk", &(TOP__csr_block_wrap__DOT__csr_axi.aclk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("araddr", &(TOP__csr_block_wrap__DOT__csr_axi.araddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("aresetn", &(TOP__csr_block_wrap__DOT__csr_axi.aresetn), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("arprot", &(TOP__csr_block_wrap__DOT__csr_axi.arprot), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,2,0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("arready", &(TOP__csr_block_wrap__DOT__csr_axi.arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("arvalid", &(TOP__csr_block_wrap__DOT__csr_axi.arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("awaddr", &(TOP__csr_block_wrap__DOT__csr_axi.awaddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("awprot", &(TOP__csr_block_wrap__DOT__csr_axi.awprot), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,2,0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("awready", &(TOP__csr_block_wrap__DOT__csr_axi.awready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("awvalid", &(TOP__csr_block_wrap__DOT__csr_axi.awvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("bready", &(TOP__csr_block_wrap__DOT__csr_axi.bready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("bresp", &(TOP__csr_block_wrap__DOT__csr_axi.bresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("bvalid", &(TOP__csr_block_wrap__DOT__csr_axi.bvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("rdata", &(TOP__csr_block_wrap__DOT__csr_axi.rdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("rready", &(TOP__csr_block_wrap__DOT__csr_axi.rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("rresp", &(TOP__csr_block_wrap__DOT__csr_axi.rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("rvalid", &(TOP__csr_block_wrap__DOT__csr_axi.rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("wdata", &(TOP__csr_block_wrap__DOT__csr_axi.wdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("wready", &(TOP__csr_block_wrap__DOT__csr_axi.wready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("wstrb", &(TOP__csr_block_wrap__DOT__csr_axi.wstrb), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,3,0);
    __Vscopep_csr_block_wrap__csr_axi->varInsert("wvalid", &(TOP__csr_block_wrap__DOT__csr_axi.wvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csr_block_wrap__dut->varInsert("clk", &(TOP.csr_block_wrap__DOT__dut__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csr_block_wrap__dut->varInsert("go", &(TOP.csr_block_wrap__DOT__dut__DOT__go), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csr_block_wrap__dut->varInsert("k_tiles", &(TOP.csr_block_wrap__DOT__dut__DOT__k_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,7,0);
    __Vscopep_csr_block_wrap__dut->varInsert("m_tiles", &(TOP.csr_block_wrap__DOT__dut__DOT__m_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,7,0);
    __Vscopep_csr_block_wrap__dut->varInsert("n_tiles", &(TOP.csr_block_wrap__DOT__dut__DOT__n_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,7,0);
    __Vscopep_csr_block_wrap__dut->varInsert("rd_state", &(TOP.csr_block_wrap__DOT__dut__DOT__rd_state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap__dut->varInsert("reg_done", &(TOP.csr_block_wrap__DOT__dut__DOT__reg_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap__dut->varInsert("reg_go", &(TOP.csr_block_wrap__DOT__dut__DOT__reg_go), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap__dut->varInsert("reg_k_tiles", &(TOP.csr_block_wrap__DOT__dut__DOT__reg_k_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_csr_block_wrap__dut->varInsert("reg_m_tiles", &(TOP.csr_block_wrap__DOT__dut__DOT__reg_m_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_csr_block_wrap__dut->varInsert("reg_n_tiles", &(TOP.csr_block_wrap__DOT__dut__DOT__reg_n_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_csr_block_wrap__dut->varInsert("rst_n", &(TOP.csr_block_wrap__DOT__dut__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csr_block_wrap__dut->varInsert("ts_busy", &(TOP.csr_block_wrap__DOT__dut__DOT__ts_busy), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap__dut->varInsert("ts_done", &(TOP.csr_block_wrap__DOT__dut__DOT__ts_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_csr_block_wrap__dut->varInsert("wr_addr_lat", &(TOP.csr_block_wrap__DOT__dut__DOT__wr_addr_lat), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,4,0);
    __Vscopep_csr_block_wrap__dut->varInsert("wr_commit", &(TOP.csr_block_wrap__DOT__dut__DOT__wr_commit), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_csr_block_wrap__dut->varInsert("wr_data_lat", &(TOP.csr_block_wrap__DOT__dut__DOT__wr_data_lat), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_csr_block_wrap__dut->varInsert("wr_state", &(TOP.csr_block_wrap__DOT__dut__DOT__wr_state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_csr_block_wrap);
    __Vhier.remove(__Vscopep_csr_block_wrap, __Vscopep_csr_block_wrap__csr_axi);
    __Vhier.remove(__Vscopep_csr_block_wrap, __Vscopep_csr_block_wrap__dut);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_csr_block_wrap, __Vscopep_csr_block_wrap = nullptr);
    VL_DO_CLEAR(delete __Vscopep_csr_block_wrap__csr_axi, __Vscopep_csr_block_wrap__csr_axi = nullptr);
    VL_DO_CLEAR(delete __Vscopep_csr_block_wrap__dut, __Vscopep_csr_block_wrap__dut = nullptr);
    // Tear down sub module instances
    TOP__csr_block_wrap__DOT__csr_axi.dtor();
}
