// Accumulator Bank
//
// Accumulates partial sums from the systolic array bottom across K-tile passes.
// One 32-bit accumulator per column (16 total), each holding a running sum.
//
// Each cycle row_valid is high, the 16 col_in values form one complete output
// row and are added to the corresponding accumulator row. An internal counter
// tracks which row (0-15) is currently being written.
//
// On the final K-tile pass (final_pass high), after row 15 is accumulated the
// completed 16x16 INT32 tile is written to the Output Buffer row by row and
// accumulators are cleared for the next output tile.

module accumulator_bank (
    input  logic        clk, rst_n,
    input  logic [31:0] col_in     [15:0],   // partial sums from bottom of systolic array
    input  logic        row_valid,           // high when col_in holds a valid output row
    input  logic        final_pass,          // high on last K-tile pass for current tile
    output logic [31:0] buf_data   [15:0],   // row of data being written to output buffer
    output logic [3:0]  buf_row,             // which row is being written
    output logic        buf_wen,             // output buffer write enable
    output logic        tile_done            // pulsed when full tile has been written
);

    typedef enum logic { ACCUMULATE, WRITEBACK } state_t;
    state_t state;

    logic [3:0]  row;
    logic [3:0]  wb_row;
    logic [31:0] buf_acc [15:0][15:0];

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            state     <= ACCUMULATE;
            row       <= 0;
            wb_row    <= 0;
            buf_wen   <= 0;
            tile_done <= 0;
            for (int i = 0; i < 16; i++)
                for (int j = 0; j < 16; j++)
                    buf_acc[i][j] <= 0;
        end
        else begin
            tile_done <= 0;
            buf_wen   <= 0;

            case (state)
                ACCUMULATE: begin
                    if (row_valid) begin
                        for (int j = 0; j < 16; j++)
                            buf_acc[row][j] <= buf_acc[row][j] + col_in[j];
                        row <= row + 1;
                        if (final_pass && row == 15) begin
                            state  <= WRITEBACK;
                            wb_row <= 0;
                        end
                    end
                end

                WRITEBACK: begin
                    buf_wen <= 1;
                    buf_row <= wb_row;
                    for (int j = 0; j < 16; j++)
                        buf_data[j] <= buf_acc[wb_row][j];
                    wb_row <= wb_row + 1;

                    if (wb_row == 15) begin
                        tile_done <= 1;
                        state     <= ACCUMULATE;
                        row       <= 0;
                        for (int i = 0; i < 16; i++)
                            for (int j = 0; j < 16; j++)
                                buf_acc[i][j] <= 0;
                    end
                end
            endcase
        end
    end

endmodule
