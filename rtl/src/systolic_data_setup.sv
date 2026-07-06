// Systolic Data Setup (SDS)
//
// Timing controller between the active ping-pong buffers and the systolic array.
// Triggered by the Tile Sequencer FSM via start; pulses done when complete. It uses
// a simple memory-mapped register file interface (address in, data out) to talk
// to the ping-pong buffers
//
// IDLE:    waits for start pulse from Tile Sequencer FSM
// PRELOAD: loads weights into PE columns and copies activation tile into working buffer
// FEED:    drives skewed activations from working buffer into array rows, row k
//          starts k cycles late so each element meets the correct weight at each PE


module systolic_data_setup (
    input  logic        clk, rst_n,

    // FSM control
    input  logic        start, // pulse to begin a tile pass
    output logic        done,  // pulses one cycle when tile pass completes

    // Weight buffer read port (one row of 16 bytes per cycle)
    output logic [3:0]  weight_buf_addr,
    input  logic [7:0]  weight_buf_data [15:0],

    // Activation buffer read port (one row of 16 bytes per cycle)
    output logic [3:0]  act_buf_addr,
    input  logic [7:0]  act_buf_data  [15:0],

    // Systolic array inputs
    output logic [7:0]  weight_in      [15:0], // enters top of each column
    output logic        weight_load_en,
    output logic [7:0]  act_in         [15:0], // enters left of each row

    // Accumulator bank control
    output logic        row_valid // high when a valid row drains from array
);
    typedef enum logic [1:0] { IDLE, PRELOAD, FEED } state_t;
    state_t state;

    logic [7:0] buf_work [15:0][15:0];
    logic [4:0] cycle;

    always_comb begin
        weight_buf_addr = (state == PRELOAD) ? 4'(15 - cycle) : 4'b0;
        act_buf_addr    = (state == PRELOAD) ? cycle[3:0]     : 4'b0;
        row_valid       = (state == FEED) && (cycle >= 15);

    end

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            state          <= IDLE;
            cycle          <= 0;
            done           <= 0;
            weight_load_en <= 0;
            for (int i = 0; i < 16; i++) begin
                weight_in[i] <= 0;
                act_in[i]    <= 0;
                for (int j = 0; j < 16; j++)
                    buf_work[i][j] <= 0;
            end
        end else begin
            done           <= 0;
            weight_load_en <= 0;

            case (state)
                IDLE: begin
                    if (start) begin
                        state <= PRELOAD;
                        cycle <= 0;
                    end
                end

                PRELOAD: begin
                    weight_load_en <= 1;
                    for (int j = 0; j < 16; j++) begin
                        weight_in[j]       <= weight_buf_data[j];
                        buf_work[cycle][j] <= act_buf_data[j];
                    end
                    if (cycle == 15) begin
                        state <= FEED;
                        cycle <= 0;
                        for (int i = 0; i < 16; i++) begin
                            weight_in[i] <= 0;
                        end
                    end else
                        cycle <= cycle + 1;
                end

                FEED: begin // on cycle t, row k needs buf_work[t-k][k] if t >= k
                    for (int k = 0; k < 16; k++) begin
                        if (cycle >= k && (cycle - k) < 16)
                            act_in[k] <= buf_work[cycle - k][k]; // skew + transpose
                        else
                            act_in[k] <= 0;
                    end

                    if (cycle == 30) begin
                        state <= IDLE;
                        done <= 1;
                        cycle <= 0;
                    end else begin
                        cycle <= cycle + 1;
                    end
                end

                default: state <= IDLE;
            endcase
        end
    end



endmodule
