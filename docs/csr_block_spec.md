# CSR Block Spec

The CSR Block is a memory-mapped register file that the host accesses over PCIe via the XDMA AXI-Lite slave port. It holds matrix dimensions, host RAM base addresses, the START control bit, and the interrupt status flag. The Tile Sequencer FSM reads configuration from the CSR Block at the start of each job and writes the DONE interrupt flag on completion.

---

## Interface

| Signal | Width | Direction | Description |
|--------|-------|-----------|-------------|
| s_axi_* | AXI-Lite | Input | AXI-Lite slave port from XDMA (host reads/writes) |
| m_tiles | 16 bits | Output | Number of M-dimension tile blocks, to FSM |
| k_tiles | 16 bits | Output | Number of K-dimension tile blocks, to FSM |
| n_tiles | 16 bits | Output | Number of N-dimension tile blocks, to FSM |
| a_base_addr | 64 bits | Output | Host RAM base address for matrix A, to FSM |
| b_base_addr | 64 bits | Output | Host RAM base address for matrix B, to FSM |
| c_base_addr | 64 bits | Output | Host RAM base address for matrix C (output), to FSM |
| start | 1 bit | Output | Pulsed to FSM when host writes CONTROL=1 |
| done | 1 bit | Input | Driven by FSM; sets STATUS DONE bit and asserts interrupt |
| interrupt | 1 bit | Output | Level interrupt to PCIe interrupt controller |
| rst | 1 bit | Input | Global reset (active high) |

---

## Register map

All registers are 32-bit wide and 4-byte aligned on the AXI-Lite address space.

| Offset | Name | Access | Description |
|--------|------|--------|-------------|
| 0x00 | M_TILES | R/W | Number of 16-row tile blocks in M (1–N) |
| 0x04 | K_TILES | R/W | Number of 16-deep tile blocks in K (1–N) |
| 0x08 | N_TILES | R/W | Number of 16-column tile blocks in N (1–N) |
| 0x10 | A_BASE_LO | R/W | Lower 32 bits of matrix A base address |
| 0x14 | A_BASE_HI | R/W | Upper 32 bits of matrix A base address |
| 0x18 | B_BASE_LO | R/W | Lower 32 bits of matrix B base address |
| 0x1C | B_BASE_HI | R/W | Upper 32 bits of matrix B base address |
| 0x20 | C_BASE_LO | R/W | Lower 32 bits of matrix C base address |
| 0x24 | C_BASE_HI | R/W | Upper 32 bits of matrix C base address |
| 0x28 | CONTROL | W | Write 1 to start computation; self-clearing |
| 0x2C | STATUS | R/W1C | Bit 0 = DONE; write 1 to clear and de-assert interrupt |

---

## Behavior

### Write sequencing

The host must write all dimension and address registers before writing CONTROL=1. There is no hardware enforcement of ordering; the host software is responsible.

### START pulse

When the host writes 1 to CONTROL, the CSR Block pulses `start` to the Tile Sequencer FSM for one clock cycle. The CONTROL register self-clears; reading it always returns 0.

### DONE / interrupt

When the Tile Sequencer FSM asserts `done`, the CSR Block sets bit 0 of STATUS and asserts the `interrupt` output. The interrupt remains asserted until the host writes 1 to STATUS bit 0 (write-1-to-clear). The host reads STATUS to confirm completion before reading results from host RAM.

---

## Reset behavior

On global reset: all registers cleared to 0, interrupt deasserted.
