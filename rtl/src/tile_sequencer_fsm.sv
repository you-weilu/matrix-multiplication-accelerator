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
//   go                          — software writes 1 to start; FSM clears it on completion
//   m_tiles, n_tiles, k_tiles   — matrix dimensions in tiles (each tile = 16 elements)
//
// Per-tile pass sequence:
//   IDLE           — wait for go from CSR block
//   FILL_WAIT      — wait for fill_weight_done and fill_act_done from ping-pong buffers;
//                    these are sticky level signals (not pulses) — they latch high on fill
//                    completion and clear only when swap fires, so they are safe to check
//                    even if fill completes while FSM is in WRITEBACK_WAIT
//   SWAP           — pulse swap to ping-pong buffers; clears sticky fill signals
//   COMPUTE_START  — pulse start to SDS for one cycle; latch final_pass if last K pass
//   COMPUTE        — wait for pass_done from SDS;
//                    if final_pass: go to ACCUM_WAIT
//                    else: increment k_tile, pulse fill_start, go to FILL_WAIT
//   ACCUM_WAIT     — wait for tile_done from accumulator bank; clear final_pass; go to ADVANCE
//   ADVANCE        — reset k_tile; pulse writeback_start; advance tile_j then tile_i;
//                    for intermediate tiles: pulse fill_start, set last_tile=0, go to WRITEBACK_WAIT
//                    for final tile: set last_tile=1, go to WRITEBACK_WAIT
//   WRITEBACK_WAIT — wait for writeback_done from DMA controller;
//                    if last_tile: pulse ts_done, go to IDLE
//                    else: pulse fill_start, go to FILL_WAIT (fill may already be in progress)
//
// Outputs:
//   swap            — pulse to ping-pong buffers
//   start           — pulse to SDS
//   final_pass      — high during the last K-tile pass of each output tile;
//                     signals accumulator bank to writeback on this pass
//   ts_done         — pulses when entire matrix multiply is complete (to CSR)
//   ts_busy         — held high while FSM is running (to CSR)
//   tile_i, tile_j  — current OUTPUT tile coordinates (for output buffer addressing)
//   k_tile          — current K-tile index (for AXI4 DMA fetching address generation)
//   fill_start      — pulse to trigger DMA fetch of next tile pair (uses tile_i/tile_j/k_tile)
//   writeback_start — pulse to trigger DMA C2H writeback of completed output tile to host RAM
//
// Inputs:
//   writeback_done  — pulsed by DMA controller when C2H writeback completes

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
    input  logic        pass_done,

    // Accumulator bank control
    output logic        final_pass,
    input  logic        tile_done,

    // CSR status
    output logic        ts_busy,
    output logic        ts_done,

    // Tile indices / counters
    output logic [7:0]  tile_i,
    output logic [7:0]  tile_j,
    output logic [7:0]  k_tile,

    // DMA triggers
    output logic        fill_start,
    output logic        writeback_start,
    input  logic        writeback_done
);

    typedef enum logic [3:0] { IDLE, FILL_WAIT, SWAP, COMPUTE_START, COMPUTE, ACCUM_WAIT, ADVANCE, WRITEBACK_WAIT } state_t;
    state_t state;

    logic last_tile;

    // Main FSM Logic
    always_ff @(posedge clk) begin

        if (!rst_n) begin
            state      <= IDLE;
            swap       <= 0;
            start      <= 0;
            final_pass <= 0;
            ts_busy    <= 0;
            ts_done    <= 0;
            fill_start      <= 0;
            writeback_start <= 0;
            tile_i          <= 0;
            tile_j          <= 0;
            k_tile          <= 0;
            last_tile       <= 0;

        end else begin
            // default: clear all pulse outputs each cycle
            swap            <= 0;
            start           <= 0;
            ts_done         <= 0;
            fill_start      <= 0;
            writeback_start <= 0;

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

                SWAP: begin
                    swap  <= 1;
                    state <= COMPUTE_START;
                end

                COMPUTE_START: begin
                    start      <= 1;
                    state      <= COMPUTE;
                    final_pass <= (k_tile == k_tiles - 1);
                end

                COMPUTE: begin
                    if (pass_done) begin
                        if (final_pass)
                            state <= ACCUM_WAIT;
                        else begin
                            // fill next K pass
                            k_tile     <= k_tile + 1;
                            fill_start <= 1;
                            state      <= FILL_WAIT;
                        end
                    end
                end

                ACCUM_WAIT: begin
                    if (tile_done) begin
                        final_pass <= 0;
                        state      <= ADVANCE;
                    end
                end

                ADVANCE: begin
                    k_tile          <= 0;
                    writeback_start <= 1;
                    if (tile_j == n_tiles - 1) begin
                        tile_j <= 0;
                        if (tile_i == m_tiles - 1) begin
                            // all output tiles done —-> wait for final writeback
                            last_tile <= 1;
                            state     <= WRITEBACK_WAIT;
                        end else begin
                            last_tile  <= 0;
                            tile_i     <= tile_i + 1;
                            fill_start <= 1;
                            state      <= WRITEBACK_WAIT;
                        end
                    end else begin
                        last_tile  <= 0;
                        tile_j     <= tile_j + 1;
                        fill_start <= 1;
                        state      <= WRITEBACK_WAIT;
                    end
                end

                WRITEBACK_WAIT: begin
                    if (writeback_done) begin
                        if (last_tile) begin
                            ts_done <= 1;
                            ts_busy <= 0;
                            state   <= IDLE;
                        end else
                            // do not wait for writeback_done for intermediate passes
                            state <= FILL_WAIT;
                    end
                end

                default: state <= IDLE;

            endcase

        end

    end

endmodule