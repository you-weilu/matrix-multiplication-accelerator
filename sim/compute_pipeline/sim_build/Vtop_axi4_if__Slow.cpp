// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_axi4_if
constexpr IData/*31:0*/ Vtop_axi4_if::ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop_axi4_if::DATA_WIDTH;
constexpr IData/*31:0*/ Vtop_axi4_if::ID_WIDTH;
constexpr IData/*31:0*/ Vtop_axi4_if::LEN_WIDTH;


void Vtop_axi4_if___ctor_var_reset(Vtop_axi4_if* vlSelf);

Vtop_axi4_if::Vtop_axi4_if() = default;
Vtop_axi4_if::~Vtop_axi4_if() = default;

void Vtop_axi4_if::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_axi4_if___ctor_var_reset(this);
}

void Vtop_axi4_if::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_axi4_if::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
