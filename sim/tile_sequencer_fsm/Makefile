SIM           = verilator
TOPLEVEL_LANG = verilog
EXTRA_ARGS   += --timing --trace

VERILOG_SOURCES = ../../rtl/src/tile_sequencer_fsm.sv

TOPLEVEL = tile_sequencer_fsm
MODULE   = test_tile_sequencer_fsm

include $(shell cocotb-config --makefiles)/Makefile.sim
