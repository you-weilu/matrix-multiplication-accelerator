# Control FSM Spec

The Control FSM is the global sequencer for the accelerator. It connects to all modules and drives their enables, address counters, and control signals. It sequences the accelerator through four phases: IDLE, LOAD (waiting for the Parser to fill both BRAMs), COMPUTE (running the Systolic Array and Accumulator Bank), and READBACK (streaming results from the Output BRAM through the TX FIFO to the host).
