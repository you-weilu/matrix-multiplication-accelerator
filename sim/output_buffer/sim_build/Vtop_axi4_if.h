// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP_AXI4_IF_H_
#define VERILATED_VTOP_AXI4_IF_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_axi4_if final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ aclk;
    CData/*0:0*/ aresetn;
    CData/*0:0*/ awvalid;
    CData/*0:0*/ awready;
    CData/*3:0*/ awid;
    CData/*7:0*/ awlen;
    CData/*2:0*/ awsize;
    CData/*1:0*/ awburst;
    CData/*0:0*/ wvalid;
    CData/*0:0*/ wready;
    CData/*0:0*/ wlast;
    CData/*0:0*/ bvalid;
    CData/*0:0*/ bready;
    CData/*3:0*/ bid;
    CData/*1:0*/ bresp;
    CData/*0:0*/ arvalid;
    CData/*0:0*/ arready;
    CData/*3:0*/ arid;
    CData/*7:0*/ arlen;
    CData/*2:0*/ arsize;
    CData/*1:0*/ arburst;
    CData/*0:0*/ rvalid;
    CData/*0:0*/ rready;
    CData/*3:0*/ rid;
    CData/*1:0*/ rresp;
    CData/*0:0*/ rlast;
    CData/*0:0*/ __Vdly__arready;
    SData/*15:0*/ wstrb;
    VlWide<4>/*127:0*/ wdata;
    VlWide<4>/*127:0*/ rdata;
    QData/*63:0*/ awaddr;
    QData/*63:0*/ araddr;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // PARAMETERS
    static constexpr IData/*31:0*/ ADDR_WIDTH = 0x00000040U;
    static constexpr IData/*31:0*/ DATA_WIDTH = 0x00000080U;
    static constexpr IData/*31:0*/ ID_WIDTH = 4U;
    static constexpr IData/*31:0*/ LEN_WIDTH = 8U;

    // CONSTRUCTORS
    Vtop_axi4_if();
    ~Vtop_axi4_if();
    void ctor(Vtop__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtop_axi4_if);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
