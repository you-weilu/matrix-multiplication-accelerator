SIM           = verilator
TOPLEVEL_LANG = verilog
EXTRA_ARGS   += --timing --trace

VERILOG_SOURCES = ../../rtl/src/axi_lite_if.sv \
                  ../../rtl/src/csr_block.sv \
                  csr_block_wrap.sv

TOPLEVEL = csr_block_wrap
MODULE   = test_csr_block

include $(shell cocotb-config --makefiles)/Makefile.sim
