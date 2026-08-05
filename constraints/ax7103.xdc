###############################################################################
# GEMM Accelerator — AX7103 (xc7a100t-fgg484-2)
# PCIe x4 Gen2, XDMA descriptor bypass
###############################################################################

###############################################################################
# Bitstream / configuration
###############################################################################
set_property BITSTREAM.CONFIG.SPI_BUSWIDTH 4 [current_design]
set_property CONFIG_MODE SPIx4 [current_design]
set_property BITSTREAM.CONFIG.CONFIGRATE 50 [current_design]

###############################################################################
# PCIe reset (PERST#, active low) — from PCIe slot via board supervisor
###############################################################################
set_property PACKAGE_PIN J20      [get_ports reset_rtl_0]
set_property IOSTANDARD  LVCMOS33 [get_ports reset_rtl_0]
set_property PULLUP true          [get_ports reset_rtl_0]

set_false_path -from [get_ports reset_rtl_0]

###############################################################################
# PCIe reference clock (100 MHz differential)
# Pin location is set by XDMA IP through its own generated XDC.
# The IBUFDS_GTE2 LOC is embedded in the IP output products — do not
# duplicate it here or Vivado will flag a conflict.
###############################################################################

###############################################################################
# PCIe MGT lanes (RXP/RXN, TXP/TXN)
# Physical routing to the PCIe edge connector is handled by XDMA IP XDC.
###############################################################################

###############################################################################
# Optional: link-up LED — connect user_lnk_up_0 to a board LED if desired.
# Uncomment and set the correct pin for your board layout.
# set_property PACKAGE_PIN <LED_PIN> [get_ports user_lnk_up_0]
# set_property IOSTANDARD LVCMOS33   [get_ports user_lnk_up_0]
###############################################################################
