SIM           = verilator
TOPLEVEL_LANG = verilog
EXTRA_ARGS   += --timing --trace

VERILOG_SOURCES = ../../rtl/src/axi4_if.sv \
                  ../../rtl/src/axi_lite_if.sv \
                  ../../rtl/src/csr_block.sv \
                  ../../rtl/src/tile_sequencer_fsm.sv \
                  ../../rtl/src/pingpong_buffers.sv \
                  ../../rtl/src/systolic_data_setup.sv \
                  ../../rtl/src/pe.sv \
                  ../../rtl/src/systolic_array.sv \
                  ../../rtl/src/accumulator_bank.sv \
                  ../../rtl/src/output_buffer.sv \
                  compute_pipeline_wrap.sv

TOPLEVEL = compute_pipeline_wrap
MODULE   = test_compute_pipeline

include $(shell cocotb-config --makefiles)/Makefile.sim
