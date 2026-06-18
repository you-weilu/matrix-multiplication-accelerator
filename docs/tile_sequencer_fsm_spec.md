# Tile Sequencer FSM Spec

The Tile Sequencer FSM is the autonomous tiling loop controller. It replaces the original hardwired Control FSM. After the host writes matrix dimensions and base addresses to the CSR Block and asserts START, the FSM sequences the entire computation: fetching tiles from host RAM via XDMA, driving the compute pipeline, and writing results back to host RAM, with no host CPU involvement between tiles. It asserts an interrupt when the full matrix multiply is complete.

The FSM connects to all blocks (XDMA command interface, Weight/Activation Buffers, Systolic Data Setup, Accumulator Bank, Output Buffer, CSR Block).

---

## States

### IDLE
Resting state. The FSM waits for the START bit in the CSR CONTROL register to be asserted. On START, it latches M_TILES, K_TILES, N_TILES, A_BASE_ADDR, B_BASE_ADDR, and C_BASE_ADDR from the CSR Block, initializes tile counters (ti=0, tj=0, tk=0), and transitions to FETCH.

### FETCH
Issues two AXI commands to the XDMA engine: one to DMA weight tile B[tk][tj] into the shadow Weight Buffer, one to DMA activation tile A[ti][tk] into the shadow Activation Buffer. Transitions to FETCH_WAIT.

### FETCH_WAIT
Waits for both DMA transfers to complete (XDMA done signals). On completion, swaps active/shadow buffer roles (toggles ping-pong select), then transitions to COMPUTE.

### COMPUTE
Triggers the Systolic Data Setup to run one tile pass (47 cycles: 16 pre-load + 31 activation feeding). Simultaneously, if the next tile's fetch has not yet been issued (pipeline overlap), issues the next DMA fetch into the newly-freed shadow buffers. Transitions to COMPUTE_WAIT.

### COMPUTE_WAIT
Waits for the tile pass to complete. Signals the Accumulator Bank:
- If tk < K_TILES-1: **intermediate**: bank accumulates, holds result; transitions to FETCH_WAIT (or FETCH if next DMA was already issued)
- If tk == K_TILES-1: **final**: bank accumulates and writes completed tile to Output Buffer, clears accumulators; transitions to WRITEBACK

### WRITEBACK
Issues one AXI command to the XDMA engine to DMA the Output Buffer to the correct offset in host RAM for C[ti][tj]. Transitions to WRITEBACK_WAIT.

### WRITEBACK_WAIT
Waits for the writeback DMA to complete. Advances tile counters:
- tj++ → if tj < N_TILES, transition to FETCH with tk=0
- tj wraps → ti++, tj=0 → if ti < M_TILES, transition to FETCH with tk=0
- All tiles done → transition to DONE

### DONE
Asserts the interrupt (sets STATUS DONE bit in CSR Block). Returns to IDLE. The interrupt remains asserted until the host writes STATUS=1 to clear it.

---

## Tile counter management

The FSM maintains three counters: `ti` (0..M_TILES-1), `tj` (0..N_TILES-1), `tk` (0..K_TILES-1). `tk` iterates innermost (K loop), then `tj`, then `ti`. These are used to compute DMA source/destination addresses per the addressing scheme in the Data Flow Spec.

---

## Double-buffering

To keep the systolic array active continuously, the FSM issues the next tile's DMA fetch as soon as the buffers swap (end of FETCH_WAIT), overlapping DMA with compute. The COMPUTE state may find the next fetch already in progress. The FSM tracks whether a pending fetch is in-flight to avoid issuing duplicate DMA commands.

---

## Reset behavior

On global reset: FSM returns to IDLE, all counters cleared, all output signals deasserted, STATUS DONE bit cleared.
