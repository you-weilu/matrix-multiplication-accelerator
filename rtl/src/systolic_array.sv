// Systolic Array
//
// 16x16 mesh of weight-stationary PEs.
//
// Weight loading (weight_load_en high for 16 cycles, driven by SDS):
//   Weight values enter the top of each column and shift down one PE per cycle.
//   After 16 cycles PE[i][j] holds weight B[i][j].
//
// Compute (weight_load_en low):
//   Activations flow left to right across each row.
//   Partial sums flow top to bottom down each column.
//   col_out[j] carries the partial sum exiting the bottom of column j each cycle.
//
// All PE outputs are registered. weight_load_en is broadcast to every PE.

module systolic_array (
    input  logic        clk, rst_n,
    input  logic        weight_load_en,
    input  logic [7:0]  weight_in [15:0],  // one value per column, enters top of each column
    input  logic [7:0]  act_in    [15:0],  // one value per row, enters left of each row
    output logic [31:0] col_out   [15:0]   // partial sum exiting bottom of each column
);
    
    logic [7:0]  act_wire    [15:0][15:0];
    logic [7:0]  weight_wire [15:0][15:0];
    logic [31:0] psum_wire   [15:0][15:0];

    genvar i, j; // only exists at elaboration time (building the netlist)
    generate
        for (i = 0; i < 16; i++) begin : row
            for (j = 0; j < 16; j++) begin : col
                pe pe_inst (
                    .clk           (clk),
                    .rst_n         (rst_n),
                    .weight_load_en(weight_load_en),
                    .in_act        (j == 0 ? act_in[i] : act_wire[i][j-1]),
                    .weight_in     (i == 0 ? weight_in[j] : weight_wire[i-1][j]),
                    .weight_out    (weight_wire[i][j]),
                    .in_partial    (i == 0 ? 32'd0 : psum_wire[i-1][j]),
                    .out_act       (act_wire[i][j]),
                    .out_partial   (psum_wire[i][j])
                );
            end
        end
    endgenerate

    // partial sums exiting the bottom row
    genvar k;
    generate
        for (k = 0; k < 16; k++) begin : col_out_assign
            assign col_out[k] = psum_wire[15][k];
        end
    endgenerate

endmodule
