// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VTOP_H_
#define VERILATED_VTOP_H_  // guard

#include "verilated.h"
#include "svdpi.h"

class Vtop__Syms;
class Vtop___024root;
class Vtop_axi_lite_if;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) Vtop VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    Vtop__Syms* const vlSymsp;

  public:

    // CONSTEXPR CAPABILITIES
    // Verilated with --trace?
    static constexpr bool traceCapable = false;

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&clk,0,0);
    VL_IN8(&rst_n,0,0);
    VL_IN8(&fill_start,0,0);
    VL_IN8(&writeback_start,0,0);
    VL_IN8(&tile_i,7,0);
    VL_IN8(&tile_j,7,0);
    VL_IN8(&k_tile,7,0);
    VL_IN8(&k_tiles,7,0);
    VL_IN8(&n_tiles,7,0);
    VL_OUT8(&writeback_done,0,0);
    VL_OUT8(&init_done,0,0);
    VL_OUT8(&axil_awvalid,0,0);
    VL_IN8(&axil_awready,0,0);
    VL_OUT8(&axil_awprot,2,0);
    VL_OUT8(&axil_wvalid,0,0);
    VL_IN8(&axil_wready,0,0);
    VL_OUT8(&axil_wstrb,3,0);
    VL_IN8(&axil_bvalid,0,0);
    VL_OUT8(&axil_bready,0,0);
    VL_IN8(&axil_bresp,1,0);
    VL_OUT8(&axil_arvalid,0,0);
    VL_IN8(&axil_arready,0,0);
    VL_OUT8(&axil_arprot,2,0);
    VL_IN8(&axil_rvalid,0,0);
    VL_OUT8(&axil_rready,0,0);
    VL_IN8(&axil_rresp,1,0);
    VL_IN8(&h2c_dsc_byp_ready_0,0,0);
    VL_OUT8(&h2c_dsc_byp_load_0,0,0);
    VL_IN8(&h2c_dsc_byp_ready_1,0,0);
    VL_OUT8(&h2c_dsc_byp_load_1,0,0);
    VL_IN8(&c2h_dsc_byp_ready_0,0,0);
    VL_OUT8(&c2h_dsc_byp_load_0,0,0);
    VL_IN8(&h2c_sts_0,7,0);
    VL_IN8(&h2c_sts_1,7,0);
    VL_IN8(&c2h_sts_0,7,0);
    VL_OUT16(&h2c_dsc_byp_ctl_0,15,0);
    VL_OUT16(&h2c_dsc_byp_ctl_1,15,0);
    VL_OUT16(&c2h_dsc_byp_ctl_0,15,0);
    VL_OUT(&axil_awaddr,31,0);
    VL_OUT(&axil_wdata,31,0);
    VL_OUT(&axil_araddr,31,0);
    VL_IN(&axil_rdata,31,0);
    VL_OUT(&h2c_dsc_byp_len_0,27,0);
    VL_OUT(&h2c_dsc_byp_len_1,27,0);
    VL_OUT(&c2h_dsc_byp_len_0,27,0);
    VL_IN64(&base_addr_a,63,0);
    VL_IN64(&base_addr_b,63,0);
    VL_IN64(&base_addr_c,63,0);
    VL_IN64(&pp_weight_axi_base,63,0);
    VL_IN64(&pp_act_axi_base,63,0);
    VL_IN64(&output_buf_axi_base,63,0);
    VL_OUT64(&h2c_dsc_byp_src_addr_0,63,0);
    VL_OUT64(&h2c_dsc_byp_dst_addr_0,63,0);
    VL_OUT64(&h2c_dsc_byp_src_addr_1,63,0);
    VL_OUT64(&h2c_dsc_byp_dst_addr_1,63,0);
    VL_OUT64(&c2h_dsc_byp_src_addr_0,63,0);
    VL_OUT64(&c2h_dsc_byp_dst_addr_0,63,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    Vtop_axi_lite_if* const __PVT__dma_controller_wrap__DOT__axil;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    Vtop___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit Vtop(VerilatedContext* contextp, const char* name = "TOP");
    explicit Vtop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~Vtop();
  private:
    VL_UNCOPYABLE(Vtop);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedTraceBaseC* tfp, int levels, int options = 0) { contextp()->trace(tfp, levels, options); }
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
  private:
    // Internal functions - trace registration
    void traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options);
};

#endif  // guard
