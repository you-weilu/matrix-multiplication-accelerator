# SDC timing constraints — matrix multiplication accelerator
# Synplify reads this via the .prj add_file -constraint directive

# -------------------------------------------------------------------
# Clocks
# -------------------------------------------------------------------
# 200 MHz system clock (5 ns period) — update name to match top.sv port
create_clock -name clk -period 5.0 [get_ports clk]

# -------------------------------------------------------------------
# Input / output delays  (placeholders — tighten after floorplan)
# -------------------------------------------------------------------
set_input_delay  -clock clk -max 1.0 [all_inputs]
set_output_delay -clock clk -max 1.0 [all_outputs]

# -------------------------------------------------------------------
# False paths
# -------------------------------------------------------------------
# Async reset does not need timing closure
set_false_path -from [get_ports rst_n]

# -------------------------------------------------------------------
# Multicycle paths (add as needed)
# -------------------------------------------------------------------
# Example: accumulator writeback takes 2 cycles
# set_multicycle_path -setup 2 -from [get_cells accum_*] -to [get_cells output_*]
