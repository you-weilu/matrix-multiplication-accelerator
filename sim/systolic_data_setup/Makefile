SIM           = verilator
TOPLEVEL_LANG = verilog
EXTRA_ARGS   += --timing --trace

VERILOG_SOURCES = ../../rtl/src/systolic_data_setup.sv
TOPLEVEL        = systolic_data_setup
MODULE          = test_systolic_data_setup

include $(shell cocotb-config --makefiles)/Makefile.sim
