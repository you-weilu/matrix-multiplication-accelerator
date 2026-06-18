# Matrix Multiplication Accelerator

A fixed-function hardware accelerator for General Matrix Multiplication (GEMM — C = A × B), targeting the ALINX AX7103 FPGA board (Xilinx XC7A100T). Inspired by the Google TPU v1 architecture, it implements a 16×16 INT8 weight-stationary systolic array backed by a tile-streaming memory subsystem. The host communicates with the accelerator over PCIe Gen2 x4 via the Xilinx XDMA IP core, using a C++ API backed by a Linux PCIe kernel driver.

The full matrices live in host RAM. The on-chip design holds only two ping-pong tile buffers per operand (4 × 256 bytes) and a 1 KB output buffer. A Tile Sequencer FSM autonomously sequences the entire tiling loop — fetching tiles from host RAM via XDMA, driving the compute pipeline, and writing results back — with no host CPU involvement between tiles.

## Block Diagram

![Block Diagram](docs/block%20diagram.png)

## Architecture

Data flows from the host through the accelerator and back as follows:

**Setup:** The host writes matrix dimensions (M, K, N) and the base addresses of A, B, and C in host RAM into the CSR Block over PCIe, then asserts the START bit. The XDMA IP core translates PCIe TLPs into AXI4 transactions on the internal interconnect.

**Tile fetch (double-buffered):** The Tile Sequencer FSM commands XDMA via AXI to DMA each 16×16 weight tile and activation tile from host RAM into the on-chip ping-pong buffers. While the systolic array processes one tile pair, XDMA loads the next pair into the shadow buffers.

**Compute path:** The Systolic Data Setup block reads from the active ping-pong buffers and skews the data correctly for systolic array ingestion. The 16×16 INT8 Systolic Array performs the matrix multiply — each PE computes one INT8 MAC per cycle, with partial sums propagating downward through each column into the Accumulator Bank.

**Result writeback:** After the final K-tile pass for each output tile, the Accumulator Bank writes the completed 16×16 INT32 tile into the Output Buffer. The Tile Sequencer FSM then commands XDMA to DMA the result back to the correct offset in host RAM. When all output tiles are done, the FSM asserts an interrupt to notify the host.

### Key blocks

| Block | Description |
|---|---|
| XDMA IP Core | Xilinx PCIe Gen2 x4 DMA engine; presents AXI4 master/slave interfaces on-chip |
| AXI Interconnect | Routes AXI4 transactions between XDMA, the ping-pong buffers, and the CSR Block |
| CSR Block | Memory-mapped control/status registers; holds matrix dimensions, host base addresses, START, and interrupt status |
| Weight Buffer ×2 | Ping-pong pair of 256-byte register buffers holding the current and next weight tile |
| Activation Buffer ×2 | Ping-pong pair of 256-byte register buffers holding the current and next activation tile |
| Systolic Data Setup | Reads the active ping-pong buffers and skews activation data for weight-stationary systolic feed |
| 16×16 INT8 Systolic Array | 256 PEs arranged in a 2-D mesh; each PE does one INT8 MAC/cycle |
| Accumulator Bank | Accumulates 32-bit partial sums across K-tile passes; writes completed tiles to the Output Buffer |
| Output Buffer | 1 KB register buffer holding one completed 16×16 INT32 output tile pending XDMA writeback |
| Tile Sequencer FSM | Autonomous tiling loop controller; drives XDMA fetches, compute pipeline, writeback, and the final interrupt |
