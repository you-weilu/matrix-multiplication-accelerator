# Matrix Multiplication Accelerator

A fixed-function hardware accelerator for General Matrix Multiplication (GEMM — C = A × B), targeting the Digilent Arty A7-100T FPGA. Inspired by the Google TPU v1 architecture, it implements the core compute pipeline: a 16×16 systolic array, weight and activation buffers, and an accumulator bank, all backed by Block RAM. The host communicates with the accelerator over Gigabit Ethernet using a lightweight UDP protocol, eliminating the need for PCIe or a custom kernel driver.

## Block Diagram

![Block Diagram](docs/Block%20Diagram.png)

## Architecture

Data flows from the host through the accelerator and back as follows:

**Receive path:** The host sends matrix data over UDP. The on-chip Ethernet MAC receives frames and passes them via AXI-Stream into an RX FIFO. A Parser decodes the incoming packets, routing weight data into the Weight BRAM and activation data into the Activation BRAM.

**Compute path:** The Systolic Data Setup block reads from both BRAMs and skews the data correctly for systolic array ingestion. The 16×16 INT8 Systolic Array then performs the matrix multiply — each processing element computes a multiply-accumulate each cycle, with partial sums propagating through the array. Results flow into the Accumulator Bank.

**Transmit path:** Accumulated results are written to the Output BRAM. The Control FSM (which connects to all blocks) orchestrates readback — streaming results through the TX FIFO and Ethernet MAC back to the host over UDP.

### Key blocks

| Block | Description |
|---|---|
| Ethernet MAC | Gigabit Ethernet interface; AXI-Stream to/from the data path |
| RX FIFO / TX FIFO | Clock-domain crossing and flow control between MAC and logic |
| Parser | Decodes UDP payload, extracts opcode/address/data fields |
| Weight BRAM | Stores the weight matrix (stationary operand, TPU-style) |
| Activation BRAM | Stores the input activation matrix |
| Systolic Data Setup | Skews input data for correct systolic array feed timing |
| 16×16 INT8 Systolic Array | 256 PEs arranged in a 2-D mesh; each PE does one INT8 MAC/cycle |
| Accumulator Bank | Accumulates 32-bit partial sums from the systolic array columns |
| Output BRAM | Holds the completed result matrix pending readback |
| Control FSM | Global sequencer; drives all block enables and address counters |
