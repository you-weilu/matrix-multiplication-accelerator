SIM           = verilator
TOPLEVEL_LANG = verilog
EXTRA_ARGS   += --timing

VERILOG_SOURCES = ../../rtl/src/axi_lite_if.sv \
                  ../../rtl/src/dma_controller.sv \
                  dma_controller_wrap.sv

TOPLEVEL = dma_controller_wrap
MODULE   = test_dma_controller

include $(shell cocotb-config --makefiles)/Makefile.sim
