// Processing Element (PE)
//
// Weight-stationary MAC unit. One cell in the 16x16 systolic array.
//
// Each cycle:
//   - Receives INT8 activation from the left, passes it right
//   - Multiplies activation by its stored INT8 weight
//   - Adds product to INT32 partial sum received from above, passes result down
//
// Weights are loaded before compute begins and held stationary throughout a tile pass.
// Activations and partial sums are pipelined, outputs are registered

module pe (
    input  logic        clk, rst_n,
    input  logic        weight_load_en, // held high during weight loading
    input  logic [7:0]  in_act,
    input  logic [7:0]  weight_in,
    input  logic [31:0] in_partial,
    output  logic [7:0]  weight_out,
    output logic [7:0]  out_act,
    output logic [31:0] out_partial
);
    logic [7:0] weight;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            weight <= 0;
            out_partial <= 0;
            out_act <= 0;
            weight_out <= 0;
        end
        else if (weight_load_en) begin
            weight <= weight_in;
            weight_out <= weight_in;
        end
        else begin
            out_partial <= $signed(in_act) * $signed(weight) + $signed(in_partial);
            out_act <= in_act;
        end
    end

endmodule