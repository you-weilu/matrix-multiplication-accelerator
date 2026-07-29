#!/bin/tcsh
# Synplify Pro synthesis script — matrix multiplication accelerator
# Run from syn/scripts/ on the lab server

# Source the Synplify environment
# Update this path to match the lab server (same pattern as /vol/ece303/genus_tutorial/cadence.env)
source /vol/ece303/synplify/synplify.env

# Run synthesis in batch mode
synplify_pro -batch matrix_mult_accel.prj

echo "Synthesis complete. Netlist: rev_1/top.vm"
echo "Log: check rev_1/ for .srr and .log files"
