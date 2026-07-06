module cocotb_iverilog_dump();
initial begin
    $dumpfile("sim_build/systolic_data_setup.fst");
    $dumpvars(0, systolic_data_setup);
end
endmodule
