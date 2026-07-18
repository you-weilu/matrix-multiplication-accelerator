SIM           = verilator
TOPLEVEL_LANG = verilog
EXTRA_ARGS   += --timing --trace

VERILOG_SOURCES = ../../rtl/src/axi4_if.sv \
                  ../../rtl/src/output_buffer.sv \
                  output_buffer_wrap.sv

TOPLEVEL = output_buffer_wrap
MODULE   = test_output_buffer

include $(shell cocotb-config --makefiles)/Makefile.sim
