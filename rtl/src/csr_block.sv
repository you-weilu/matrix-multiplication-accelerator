// CSR Block (Control and Status Registers)
//
// AXI4-Lite slave register file. Software (host CPU) writes matrix dimensions
// and asserts go before each matrix multiply; the tile sequencer FSM reads the
// config registers and writes status back through this block.
//
// Register map (each 32-bit, word-addressed):
//   0x00  CTRL     — bit[0]: go (W1S: write 1 to start; auto-clears when FSM done)
//                    bit[1]: busy (RO: 1 while FSM is running)
//   0x04  M_TILES  — number of output tile rows    (M / 16, max 255)
//   0x08  N_TILES  — number of output tile columns (N / 16, max 255)
//   0x0C  K_TILES  — number of K-tile passes       (K / 16, max 255)
//   0x10  STATUS   — bit[0]: done (RO: pulses when multiply completes; cleared on next go)
//
// AXI4-Lite interface:
//   Slave port (axi_lite_if.slave csr_axi) accepts reads and writes from the host.
//   Single-cycle register reads; writes take effect on the B-channel handshake.
//
// FSM interface (outputs to tile_sequencer_fsm):
//   go        — pulses one cycle when software sets CTRL[0]
//   m_tiles   — latched value of M_TILES register
//   n_tiles   — latched value of N_TILES register
//   k_tiles   — latched value of K_TILES register
//
// FSM interface (inputs from tile_sequencer_fsm):
//   fsm_busy  — held high while FSM is running; reflected in CTRL[1]
//   fsm_done  — pulsed by FSM on completion; sets STATUS[0] and clears busy
