// Tile Sequencer FSM
//
// Top-level control FSM for the matrix multiplication accelerator. Iterates
// over all output tiles of C = A x B, orchestrating the ping-pong buffers,
// SDS, systolic array, and accumulator bank for each tile.
//
// A full matrix multiply is decomposed into output tiles (each 16x16 INT32).
// Each output tile C[ti][tj] is the sum of K/16 partial products, one per
// K-tile pass. The FSM drives this double loop: outer over output tiles,
// inner over K-tile passes.
//
// CSR inputs (from csr_block):
//   go        — software writes 1 to start; FSM clears it on completion
//   M, N, K   — matrix dimensions in tiles (each tile = 16 elements)
//
// Per-tile pass sequence:
//   IDLE       — wait for go from CSR block
//   FILL_WAIT  — wait for fill_weight_done and fill_act_done from ping-pong buffers
//                (first pass: buffers already filled before go; subsequent passes:
//                 new tile loaded during previous compute)
//   SWAP       — pulse swap to ping-pong buffers; buffers exchange active/inactive
//   COMPUTE    — pulse start to SDS; wait for done
//   ACCUM_WAIT — wait for tile_done from accumulator bank (writeback to output buffer)
//   ADVANCE    — increment K tile index; if more K passes remain, trigger next fill
//                and loop back to FILL_WAIT; else advance output tile indices,
//                check if all output tiles done, go back to IDLE or next tile
//
// Outputs:
//   swap            — pulse to ping-pong buffers
//   start           — pulse to SDS
//   final_pass      — high during the last K-tile pass of each output tile;
//                     signals accumulator bank to writeback on this pass
//   done            — pulses when entire matrix multiply is complete
//   tile_i, tile_j  — current output tile coordinates (for output buffer addressing)
//   k_tile          — current K-tile index (for AXI4 DMA address generation)
