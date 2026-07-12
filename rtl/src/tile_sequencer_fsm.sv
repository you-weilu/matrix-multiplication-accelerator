// Tile Sequencer
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
//   ts_done         — pulses when entire matrix multiply is complete (to CSR)
//   ts_busy         — held high while FSM is running (to CSR)
//   tile_i, tile_j  — current output tile coordinates (for output buffer addressing)
//   k_tile          — current K-tile index (for AXI4 DMA address generation)
//   fill_start      — pulse to trigger DMA fetch of next tile pair (uses tile_i/tile_j/k_tile)

module tile_sequencer_fsm (
    input  logic        clk, rst_n,

    // CSR inputs
    input  logic        go,
    input  logic [7:0]  m_tiles,
    input  logic [7:0]  n_tiles,
    input  logic [7:0]  k_tiles,

    // Ping-pong buffer handshake
    output logic        swap,
    input  logic        fill_weight_done,
    input  logic        fill_act_done,

    // SDS control
    output logic        start,
    input  logic        sds_done,

    // Accumulator bank control
    output logic        final_pass,
    input  logic        tile_done,

    // CSR status
    output logic        ts_busy,
    output logic        ts_done,

    // Tile indices
    output logic [7:0]  tile_i,
    output logic [7:0]  tile_j,
    output logic [7:0]  k_tile,

    // DMA fill trigger
    output logic        fill_start
);

    typedef enum logic [2:0] { IDLE, FILL_WAIT, SWAP, COMPUTE, ACCUM_WAIT, ADVANCE } state_t;
    state_t state;

    // Main FSM Logic
    always_ff @(posedge clk) begin

        if (!rst_n) begin
            state      <= IDLE;
            swap       <= 0;
            start      <= 0;
            final_pass <= 0;
            ts_busy    <= 0;
            ts_done    <= 0;
            fill_start <= 0;
            tile_i     <= 0;
            tile_j     <= 0;
            k_tile     <= 0;

        end else begin
            // default: clear all pulse outputs each cycle
            swap       <= 0;
            start      <= 0;
            final_pass <= 0;
            ts_done    <= 0;
            fill_start <= 0;

            case (state)
                IDLE: begin
                    ts_busy <= 0;
                    if (go) begin
                        state      <= FILL_WAIT;
                        ts_busy    <= 1;
                        tile_i     <= 0;
                        tile_j     <= 0;
                        k_tile     <= 0;
                        fill_start <= 1;
                    end
                end

                FILL_WAIT: begin
                    if (fill_weight_done && fill_act_done) begin
                        state <= SWAP;
                    end
                end

                default: state <= IDLE;

            endcase

        end

    end

endmodule