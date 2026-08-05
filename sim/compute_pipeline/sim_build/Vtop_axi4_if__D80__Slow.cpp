// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

// Parameter definitions for Vtop_axi4_if__D80
constexpr IData/*31:0*/ Vtop_axi4_if__D80::ADDR_WIDTH;
constexpr IData/*31:0*/ Vtop_axi4_if__D80::DATA_WIDTH;
constexpr IData/*31:0*/ Vtop_axi4_if__D80::ID_WIDTH;
constexpr IData/*31:0*/ Vtop_axi4_if__D80::LEN_WIDTH;


void Vtop_axi4_if__D80___ctor_var_reset(Vtop_axi4_if__D80* vlSelf);

Vtop_axi4_if__D80::Vtop_axi4_if__D80() = default;
Vtop_axi4_if__D80::~Vtop_axi4_if__D80() = default;

void Vtop_axi4_if__D80::ctor(Vtop__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtop_axi4_if__D80___ctor_var_reset(this);
}

void Vtop_axi4_if__D80::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtop_axi4_if__D80::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
