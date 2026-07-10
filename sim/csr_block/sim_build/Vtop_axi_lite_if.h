// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_AXI_LITE_IF_H_
#define VERILATED_VTOP_AXI_LITE_IF_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_axi_lite_if final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ aclk;
    CData/*0:0*/ aresetn;
    CData/*0:0*/ awvalid;
    CData/*0:0*/ awready;
    CData/*2:0*/ awprot;
    CData/*0:0*/ wvalid;
    CData/*0:0*/ wready;
    CData/*3:0*/ wstrb;
    CData/*0:0*/ bvalid;
    CData/*0:0*/ bready;
    CData/*1:0*/ bresp;
    CData/*0:0*/ arvalid;
    CData/*0:0*/ arready;
    CData/*2:0*/ arprot;
    CData/*0:0*/ rvalid;
    CData/*0:0*/ rready;
    CData/*1:0*/ rresp;
    IData/*31:0*/ awaddr;
    IData/*31:0*/ wdata;
    IData/*31:0*/ araddr;
    IData/*31:0*/ rdata;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ ADDR_WIDTH = 0x00000020U;
    static constexpr IData/*31:0*/ DATA_WIDTH = 0x00000020U;

    // CONSTRUCTORS
    Vtop_axi_lite_if();
    ~Vtop_axi_lite_if();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_axi_lite_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
