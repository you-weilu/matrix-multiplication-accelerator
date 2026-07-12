# CSR Block Spec

The CSR Block is a memory-mapped register file that the host accesses over PCIe via the XDMA AXI4-Lite slave port. It holds matrix dimensions, host RAM base addresses, the go control bit, and the done status flag. The Tile Sequencer FSM reads dimension config from the CSR Block at the start of each job and writes busy/done status back. The DMA Controller reads the base addresses to compute tile fetch and writeback addresses.

---

## Interface

| Signal | Width | Direction | Description |
|--------|-------|-----------|-------------|
| csr_axi | AXI4-Lite slave | Input | From XDMA; host reads and writes over PCIe |
| go | 1 | Output | One-cycle pulse to FSM when host writes CTRL[0] |
| m_tiles | 8 | Output | Number of output tile rows, to FSM |
| n_tiles | 8 | Output | Number of output tile columns, to FSM |
| k_tiles | 8 | Output | Number of K-tile passes, to FSM |
| base_addr_a | 64 | Output | Host RAM base address of matrix A, to DMA Controller |
| base_addr_b | 64 | Output | Host RAM base address of matrix B, to DMA Controller |
| base_addr_c | 64 | Output | Host RAM base address of matrix C, to DMA Controller |
| ts_busy | 1 | Input | Held high by FSM while running; reflected in CTRL[1] |
| ts_done | 1 | Input | One-cycle pulse from FSM on completion; sets STATUS[0] |

---

## Register Map

All registers are 32-bit, 4-byte aligned.

| Offset | Name | Access | Description |
|--------|------|--------|-------------|
| 0x00 | CTRL | R/W | bit[0]: go (W1S, self-clearing); bit[1]: busy (RO, reflects ts_busy) |
| 0x04 | M_TILES | R/W | Output tile row count (M / 16, max 255) |
| 0x08 | N_TILES | R/W | Output tile column count (N / 16, max 255) |
| 0x0C | K_TILES | R/W | K-tile pass count (K / 16, max 255) |
| 0x10 | STATUS | R | bit[0]: done (RO, set by ts_done, cleared on next go) |
| 0x14 | BASE_ADDR_A_LO | R/W | Lower 32 bits of matrix A base address in host RAM |
| 0x18 | BASE_ADDR_A_HI | R/W | Upper 32 bits of matrix A base address in host RAM |
| 0x1C | BASE_ADDR_B_LO | R/W | Lower 32 bits of matrix B base address in host RAM |
| 0x20 | BASE_ADDR_B_HI | R/W | Upper 32 bits of matrix B base address in host RAM |
| 0x24 | BASE_ADDR_C_LO | R/W | Lower 32 bits of matrix C base address in host RAM |
| 0x28 | BASE_ADDR_C_HI | R/W | Upper 32 bits of matrix C base address in host RAM |

---

## Behavior

### Write sequencing

The host must write all dimension and base address registers before writing CTRL[0]=1. There is no hardware enforcement of ordering; host software is responsible.

### go pulse

When the host writes 1 to CTRL[0], the CSR Block pulses `go` to the FSM for one cycle. The bit self-clears the next cycle. The write is ignored if `ts_busy` is high (the FSM is already running).

### busy

CTRL[1] directly reflects `ts_busy` from the FSM. It is read-only; writes to this bit are ignored.

### done

When the FSM asserts `ts_done`, the CSR Block sets STATUS[0]. It remains set until the next `go` write clears it.

---

## Reset Behavior

On reset: all registers cleared to 0, `go` deasserted.
