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
    Verilated::stackCheck(256);
    // Setup sub module instances
    TOP__dma_controller_wrap__DOT__axil.ctor(this, "dma_controller_wrap.axil");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-9);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.__PVT__dma_controller_wrap__DOT__axil = &TOP__dma_controller_wrap__DOT__axil;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__dma_controller_wrap__DOT__axil.__Vconfigure(true);
    // Setup scopes
    __Vscopep_TOP = new VerilatedScope{this, "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER};
    __Vscopep_dma_controller_wrap = new VerilatedScope{this, "dma_controller_wrap", "dma_controller_wrap", "dma_controller_wrap", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_dma_controller_wrap__axil = new VerilatedScope{this, "dma_controller_wrap.axil", "axil", "axi_lite_if", -9, VerilatedScope::SCOPE_MODULE};
    __Vscopep_dma_controller_wrap__dut = new VerilatedScope{this, "dma_controller_wrap.dut", "dut", "dma_controller", -9, VerilatedScope::SCOPE_MODULE};
    // Set up scope hierarchy
    __Vhier.add(0, __Vscopep_dma_controller_wrap);
    __Vhier.add(__Vscopep_dma_controller_wrap, __Vscopep_dma_controller_wrap__axil);
    __Vhier.add(__Vscopep_dma_controller_wrap, __Vscopep_dma_controller_wrap__dut);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varInsert("axil_araddr", &(TOP.axil_araddr), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("axil_arprot", &(TOP.axil_arprot), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,2,0);
    __Vscopep_TOP->varInsert("axil_arready", &(TOP.axil_arready), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("axil_arvalid", &(TOP.axil_arvalid), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("axil_awaddr", &(TOP.axil_awaddr), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("axil_awprot", &(TOP.axil_awprot), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,2,0);
    __Vscopep_TOP->varInsert("axil_awready", &(TOP.axil_awready), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("axil_awvalid", &(TOP.axil_awvalid), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("axil_bready", &(TOP.axil_bready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("axil_bresp", &(TOP.axil_bresp), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("axil_bvalid", &(TOP.axil_bvalid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("axil_rdata", &(TOP.axil_rdata), false, VLVT_UINT32, VLVD_IN|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("axil_rready", &(TOP.axil_rready), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("axil_rresp", &(TOP.axil_rresp), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_TOP->varInsert("axil_rvalid", &(TOP.axil_rvalid), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("axil_wdata", &(TOP.axil_wdata), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_TOP->varInsert("axil_wready", &(TOP.axil_wready), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("axil_wstrb", &(TOP.axil_wstrb), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,3,0);
    __Vscopep_TOP->varInsert("axil_wvalid", &(TOP.axil_wvalid), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_TOP->varInsert("base_addr_a", &(TOP.base_addr_a), false, VLVT_UINT64, VLVD_IN|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("base_addr_b", &(TOP.base_addr_b), false, VLVT_UINT64, VLVD_IN|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("base_addr_c", &(TOP.base_addr_c), false, VLVT_UINT64, VLVD_IN|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("c2h_dsc_byp_ctl_0", &(TOP.c2h_dsc_byp_ctl_0), false, VLVT_UINT16, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_TOP->varInsert("c2h_dsc_byp_dst_addr_0", &(TOP.c2h_dsc_byp_dst_addr_0), false, VLVT_UINT64, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("c2h_dsc_byp_len_0", &(TOP.c2h_dsc_byp_len_0), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,27,0);
    __Vscopep_TOP->varInsert("c2h_dsc_byp_load_0", &(TOP.c2h_dsc_byp_load_0), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("c2h_dsc_byp_ready_0", &(TOP.c2h_dsc_byp_ready_0), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("c2h_dsc_byp_src_addr_0", &(TOP.c2h_dsc_byp_src_addr_0), false, VLVT_UINT64, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("c2h_sts_0", &(TOP.c2h_sts_0), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("clk", &(TOP.clk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("fill_start", &(TOP.fill_start), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("h2c_dsc_byp_ctl_0", &(TOP.h2c_dsc_byp_ctl_0), false, VLVT_UINT16, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_TOP->varInsert("h2c_dsc_byp_ctl_1", &(TOP.h2c_dsc_byp_ctl_1), false, VLVT_UINT16, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_TOP->varInsert("h2c_dsc_byp_dst_addr_0", &(TOP.h2c_dsc_byp_dst_addr_0), false, VLVT_UINT64, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("h2c_dsc_byp_dst_addr_1", &(TOP.h2c_dsc_byp_dst_addr_1), false, VLVT_UINT64, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("h2c_dsc_byp_len_0", &(TOP.h2c_dsc_byp_len_0), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,27,0);
    __Vscopep_TOP->varInsert("h2c_dsc_byp_len_1", &(TOP.h2c_dsc_byp_len_1), false, VLVT_UINT32, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,27,0);
    __Vscopep_TOP->varInsert("h2c_dsc_byp_load_0", &(TOP.h2c_dsc_byp_load_0), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("h2c_dsc_byp_load_1", &(TOP.h2c_dsc_byp_load_1), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("h2c_dsc_byp_ready_0", &(TOP.h2c_dsc_byp_ready_0), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("h2c_dsc_byp_ready_1", &(TOP.h2c_dsc_byp_ready_1), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("h2c_dsc_byp_src_addr_0", &(TOP.h2c_dsc_byp_src_addr_0), false, VLVT_UINT64, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("h2c_dsc_byp_src_addr_1", &(TOP.h2c_dsc_byp_src_addr_1), false, VLVT_UINT64, VLVD_OUT|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("h2c_sts_0", &(TOP.h2c_sts_0), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("h2c_sts_1", &(TOP.h2c_sts_1), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("init_done", &(TOP.init_done), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("k_tile", &(TOP.k_tile), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("k_tiles", &(TOP.k_tiles), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("n_tiles", &(TOP.n_tiles), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("output_buf_axi_base", &(TOP.output_buf_axi_base), false, VLVT_UINT64, VLVD_IN|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("pp_act_axi_base", &(TOP.pp_act_axi_base), false, VLVT_UINT64, VLVD_IN|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("pp_weight_axi_base", &(TOP.pp_weight_axi_base), false, VLVT_UINT64, VLVD_IN|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_TOP->varInsert("rst_n", &(TOP.rst_n), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("tile_i", &(TOP.tile_i), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("tile_j", &(TOP.tile_j), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_TOP->varInsert("writeback_done", &(TOP.writeback_done), false, VLVT_UINT8, VLVD_OUT|VLVF_PUB_RW, 0, 0);
    __Vscopep_TOP->varInsert("writeback_start", &(TOP.writeback_start), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("axil_araddr", &(TOP.dma_controller_wrap__DOT__axil_araddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_dma_controller_wrap->varInsert("axil_arprot", &(TOP.dma_controller_wrap__DOT__axil_arprot), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,2,0);
    __Vscopep_dma_controller_wrap->varInsert("axil_arready", &(TOP.dma_controller_wrap__DOT__axil_arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("axil_arvalid", &(TOP.dma_controller_wrap__DOT__axil_arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("axil_awaddr", &(TOP.dma_controller_wrap__DOT__axil_awaddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_dma_controller_wrap->varInsert("axil_awprot", &(TOP.dma_controller_wrap__DOT__axil_awprot), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,2,0);
    __Vscopep_dma_controller_wrap->varInsert("axil_awready", &(TOP.dma_controller_wrap__DOT__axil_awready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("axil_awvalid", &(TOP.dma_controller_wrap__DOT__axil_awvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("axil_bready", &(TOP.dma_controller_wrap__DOT__axil_bready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("axil_bresp", &(TOP.dma_controller_wrap__DOT__axil_bresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_dma_controller_wrap->varInsert("axil_bvalid", &(TOP.dma_controller_wrap__DOT__axil_bvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("axil_rdata", &(TOP.dma_controller_wrap__DOT__axil_rdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_dma_controller_wrap->varInsert("axil_rready", &(TOP.dma_controller_wrap__DOT__axil_rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("axil_rresp", &(TOP.dma_controller_wrap__DOT__axil_rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_dma_controller_wrap->varInsert("axil_rvalid", &(TOP.dma_controller_wrap__DOT__axil_rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("axil_wdata", &(TOP.dma_controller_wrap__DOT__axil_wdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_dma_controller_wrap->varInsert("axil_wready", &(TOP.dma_controller_wrap__DOT__axil_wready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("axil_wstrb", &(TOP.dma_controller_wrap__DOT__axil_wstrb), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,3,0);
    __Vscopep_dma_controller_wrap->varInsert("axil_wvalid", &(TOP.dma_controller_wrap__DOT__axil_wvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("base_addr_a", &(TOP.dma_controller_wrap__DOT__base_addr_a), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap->varInsert("base_addr_b", &(TOP.dma_controller_wrap__DOT__base_addr_b), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap->varInsert("base_addr_c", &(TOP.dma_controller_wrap__DOT__base_addr_c), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap->varInsert("c2h_dsc_byp_ctl_0", &(TOP.dma_controller_wrap__DOT__c2h_dsc_byp_ctl_0), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_dma_controller_wrap->varInsert("c2h_dsc_byp_dst_addr_0", &(TOP.dma_controller_wrap__DOT__c2h_dsc_byp_dst_addr_0), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap->varInsert("c2h_dsc_byp_len_0", &(TOP.dma_controller_wrap__DOT__c2h_dsc_byp_len_0), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,27,0);
    __Vscopep_dma_controller_wrap->varInsert("c2h_dsc_byp_load_0", &(TOP.dma_controller_wrap__DOT__c2h_dsc_byp_load_0), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("c2h_dsc_byp_ready_0", &(TOP.dma_controller_wrap__DOT__c2h_dsc_byp_ready_0), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("c2h_dsc_byp_src_addr_0", &(TOP.dma_controller_wrap__DOT__c2h_dsc_byp_src_addr_0), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap->varInsert("c2h_sts_0", &(TOP.dma_controller_wrap__DOT__c2h_sts_0), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap->varInsert("clk", &(TOP.dma_controller_wrap__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("fill_start", &(TOP.dma_controller_wrap__DOT__fill_start), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("h2c_dsc_byp_ctl_0", &(TOP.dma_controller_wrap__DOT__h2c_dsc_byp_ctl_0), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_dma_controller_wrap->varInsert("h2c_dsc_byp_ctl_1", &(TOP.dma_controller_wrap__DOT__h2c_dsc_byp_ctl_1), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_dma_controller_wrap->varInsert("h2c_dsc_byp_dst_addr_0", &(TOP.dma_controller_wrap__DOT__h2c_dsc_byp_dst_addr_0), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap->varInsert("h2c_dsc_byp_dst_addr_1", &(TOP.dma_controller_wrap__DOT__h2c_dsc_byp_dst_addr_1), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap->varInsert("h2c_dsc_byp_len_0", &(TOP.dma_controller_wrap__DOT__h2c_dsc_byp_len_0), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,27,0);
    __Vscopep_dma_controller_wrap->varInsert("h2c_dsc_byp_len_1", &(TOP.dma_controller_wrap__DOT__h2c_dsc_byp_len_1), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,27,0);
    __Vscopep_dma_controller_wrap->varInsert("h2c_dsc_byp_load_0", &(TOP.dma_controller_wrap__DOT__h2c_dsc_byp_load_0), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("h2c_dsc_byp_load_1", &(TOP.dma_controller_wrap__DOT__h2c_dsc_byp_load_1), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("h2c_dsc_byp_ready_0", &(TOP.dma_controller_wrap__DOT__h2c_dsc_byp_ready_0), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("h2c_dsc_byp_ready_1", &(TOP.dma_controller_wrap__DOT__h2c_dsc_byp_ready_1), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("h2c_dsc_byp_src_addr_0", &(TOP.dma_controller_wrap__DOT__h2c_dsc_byp_src_addr_0), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap->varInsert("h2c_dsc_byp_src_addr_1", &(TOP.dma_controller_wrap__DOT__h2c_dsc_byp_src_addr_1), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap->varInsert("h2c_sts_0", &(TOP.dma_controller_wrap__DOT__h2c_sts_0), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap->varInsert("h2c_sts_1", &(TOP.dma_controller_wrap__DOT__h2c_sts_1), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap->varInsert("init_done", &(TOP.dma_controller_wrap__DOT__init_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("k_tile", &(TOP.dma_controller_wrap__DOT__k_tile), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap->varInsert("k_tiles", &(TOP.dma_controller_wrap__DOT__k_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap->varInsert("n_tiles", &(TOP.dma_controller_wrap__DOT__n_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap->varInsert("output_buf_axi_base", &(TOP.dma_controller_wrap__DOT__output_buf_axi_base), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap->varInsert("pp_act_axi_base", &(TOP.dma_controller_wrap__DOT__pp_act_axi_base), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap->varInsert("pp_weight_axi_base", &(TOP.dma_controller_wrap__DOT__pp_weight_axi_base), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap->varInsert("rst_n", &(TOP.dma_controller_wrap__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("tile_i", &(TOP.dma_controller_wrap__DOT__tile_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap->varInsert("tile_j", &(TOP.dma_controller_wrap__DOT__tile_j), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap->varInsert("writeback_done", &(TOP.dma_controller_wrap__DOT__writeback_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap->varInsert("writeback_start", &(TOP.dma_controller_wrap__DOT__writeback_start), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__axil->varInsert("ADDR_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__dma_controller_wrap__DOT__axil.ADDR_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_dma_controller_wrap__axil->varInsert("DATA_WIDTH", const_cast<void*>(static_cast<const void*>(&(TOP__dma_controller_wrap__DOT__axil.DATA_WIDTH))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_SIGNED, 0, 1 ,31,0);
    __Vscopep_dma_controller_wrap__axil->varInsert("aclk", &(TOP__dma_controller_wrap__DOT__axil.aclk), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__axil->varInsert("araddr", &(TOP__dma_controller_wrap__DOT__axil.araddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_dma_controller_wrap__axil->varInsert("aresetn", &(TOP__dma_controller_wrap__DOT__axil.aresetn), false, VLVT_UINT8, VLVD_IN|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__axil->varInsert("arprot", &(TOP__dma_controller_wrap__DOT__axil.arprot), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_dma_controller_wrap__axil->varInsert("arready", &(TOP__dma_controller_wrap__DOT__axil.arready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_dma_controller_wrap__axil->varInsert("arvalid", &(TOP__dma_controller_wrap__DOT__axil.arvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_dma_controller_wrap__axil->varInsert("awaddr", &(TOP__dma_controller_wrap__DOT__axil.awaddr), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_dma_controller_wrap__axil->varInsert("awprot", &(TOP__dma_controller_wrap__DOT__axil.awprot), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,2,0);
    __Vscopep_dma_controller_wrap__axil->varInsert("awready", &(TOP__dma_controller_wrap__DOT__axil.awready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_dma_controller_wrap__axil->varInsert("awvalid", &(TOP__dma_controller_wrap__DOT__axil.awvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__axil->varInsert("bready", &(TOP__dma_controller_wrap__DOT__axil.bready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__axil->varInsert("bresp", &(TOP__dma_controller_wrap__DOT__axil.bresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_dma_controller_wrap__axil->varInsert("bvalid", &(TOP__dma_controller_wrap__DOT__axil.bvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_dma_controller_wrap__axil->varInsert("rdata", &(TOP__dma_controller_wrap__DOT__axil.rdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,31,0);
    __Vscopep_dma_controller_wrap__axil->varInsert("rready", &(TOP__dma_controller_wrap__DOT__axil.rready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_dma_controller_wrap__axil->varInsert("rresp", &(TOP__dma_controller_wrap__DOT__axil.rresp), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 1 ,1,0);
    __Vscopep_dma_controller_wrap__axil->varInsert("rvalid", &(TOP__dma_controller_wrap__DOT__axil.rvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_dma_controller_wrap__axil->varInsert("wdata", &(TOP__dma_controller_wrap__DOT__axil.wdata), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,31,0);
    __Vscopep_dma_controller_wrap__axil->varInsert("wready", &(TOP__dma_controller_wrap__DOT__axil.wready), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_dma_controller_wrap__axil->varInsert("wstrb", &(TOP__dma_controller_wrap__DOT__axil.wstrb), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,3,0);
    __Vscopep_dma_controller_wrap__axil->varInsert("wvalid", &(TOP__dma_controller_wrap__DOT__axil.wvalid), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__dut->varInsert("INIT_ADDRS", const_cast<void*>(static_cast<const void*>(&(TOP.dma_controller_wrap__DOT__dut__DOT__INIT_ADDRS))), true, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 1, 1 ,0,2 ,31,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("a_state", &(TOP.dma_controller_wrap__DOT__dut__DOT__a_state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("base_addr_a", &(TOP.dma_controller_wrap__DOT__dut__DOT__base_addr_a), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("base_addr_b", &(TOP.dma_controller_wrap__DOT__dut__DOT__base_addr_b), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("base_addr_c", &(TOP.dma_controller_wrap__DOT__dut__DOT__base_addr_c), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("c2h_dsc_byp_ctl_0", &(TOP.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_ctl_0), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("c2h_dsc_byp_dst_addr_0", &(TOP.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_dst_addr_0), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("c2h_dsc_byp_len_0", &(TOP.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_len_0), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,27,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("c2h_dsc_byp_load_0", &(TOP.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_load_0), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__dut->varInsert("c2h_dsc_byp_ready_0", &(TOP.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_ready_0), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__dut->varInsert("c2h_dsc_byp_src_addr_0", &(TOP.dma_controller_wrap__DOT__dut__DOT__c2h_dsc_byp_src_addr_0), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("c2h_sts_0", &(TOP.dma_controller_wrap__DOT__dut__DOT__c2h_sts_0), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("c_state", &(TOP.dma_controller_wrap__DOT__dut__DOT__c_state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("clk", &(TOP.dma_controller_wrap__DOT__dut__DOT__clk), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__dut->varInsert("fill_start", &(TOP.dma_controller_wrap__DOT__dut__DOT__fill_start), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__dut->varInsert("h2c_dsc_byp_ctl_0", &(TOP.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ctl_0), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("h2c_dsc_byp_ctl_1", &(TOP.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ctl_1), false, VLVT_UINT16, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,15,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("h2c_dsc_byp_dst_addr_0", &(TOP.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_dst_addr_0), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("h2c_dsc_byp_dst_addr_1", &(TOP.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_dst_addr_1), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("h2c_dsc_byp_len_0", &(TOP.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_len_0), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,27,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("h2c_dsc_byp_len_1", &(TOP.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_len_1), false, VLVT_UINT32, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,27,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("h2c_dsc_byp_load_0", &(TOP.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_0), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__dut->varInsert("h2c_dsc_byp_load_1", &(TOP.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_load_1), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__dut->varInsert("h2c_dsc_byp_ready_0", &(TOP.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ready_0), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__dut->varInsert("h2c_dsc_byp_ready_1", &(TOP.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_ready_1), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__dut->varInsert("h2c_dsc_byp_src_addr_0", &(TOP.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_src_addr_0), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("h2c_dsc_byp_src_addr_1", &(TOP.dma_controller_wrap__DOT__dut__DOT__h2c_dsc_byp_src_addr_1), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("h2c_sts_0", &(TOP.dma_controller_wrap__DOT__dut__DOT__h2c_sts_0), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("h2c_sts_1", &(TOP.dma_controller_wrap__DOT__dut__DOT__h2c_sts_1), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("init_done", &(TOP.dma_controller_wrap__DOT__dut__DOT__init_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW|VLVF_CONTINUOUSLY, 0, 0);
    __Vscopep_dma_controller_wrap__dut->varInsert("init_state", &(TOP.dma_controller_wrap__DOT__dut__DOT__init_state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("k_tile", &(TOP.dma_controller_wrap__DOT__dut__DOT__k_tile), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("k_tiles", &(TOP.dma_controller_wrap__DOT__dut__DOT__k_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("n_tiles", &(TOP.dma_controller_wrap__DOT__dut__DOT__n_tiles), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("output_buf_axi_base", &(TOP.dma_controller_wrap__DOT__dut__DOT__output_buf_axi_base), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("pp_act_axi_base", &(TOP.dma_controller_wrap__DOT__dut__DOT__pp_act_axi_base), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("pp_weight_axi_base", &(TOP.dma_controller_wrap__DOT__dut__DOT__pp_weight_axi_base), false, VLVT_UINT64, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,63,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("reg_idx", &(TOP.dma_controller_wrap__DOT__dut__DOT__reg_idx), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("rst_n", &(TOP.dma_controller_wrap__DOT__dut__DOT__rst_n), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__dut->varInsert("tile_i", &(TOP.dma_controller_wrap__DOT__dut__DOT__tile_i), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("tile_j", &(TOP.dma_controller_wrap__DOT__dut__DOT__tile_j), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,7,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("w_state", &(TOP.dma_controller_wrap__DOT__dut__DOT__w_state), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 1 ,1,0);
    __Vscopep_dma_controller_wrap__dut->varInsert("writeback_done", &(TOP.dma_controller_wrap__DOT__dut__DOT__writeback_done), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
    __Vscopep_dma_controller_wrap__dut->varInsert("writeback_start", &(TOP.dma_controller_wrap__DOT__dut__DOT__writeback_start), false, VLVT_UINT8, VLVD_NODIR|VLVF_PUB_RW, 0, 0);
}

Vtop__Syms::~Vtop__Syms() {
    // Tear down scope hierarchy
    __Vhier.remove(0, __Vscopep_dma_controller_wrap);
    __Vhier.remove(__Vscopep_dma_controller_wrap, __Vscopep_dma_controller_wrap__axil);
    __Vhier.remove(__Vscopep_dma_controller_wrap, __Vscopep_dma_controller_wrap__dut);
    // Clear keys from hierarchy map after values have been removed
    __Vhier.clear();
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_dma_controller_wrap, __Vscopep_dma_controller_wrap = nullptr);
    VL_DO_CLEAR(delete __Vscopep_dma_controller_wrap__axil, __Vscopep_dma_controller_wrap__axil = nullptr);
    VL_DO_CLEAR(delete __Vscopep_dma_controller_wrap__dut, __Vscopep_dma_controller_wrap__dut = nullptr);
    // Tear down sub module instances
    TOP__dma_controller_wrap__DOT__axil.dtor();
}
