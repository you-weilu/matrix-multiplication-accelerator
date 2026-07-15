// Ping-Pong Buffers
//
// Double-buffered tile storage for weights and activations. While the active
// buffer pair is being read by the Systolic Data Setup, the inactive pair is
// being filled from the AXI4 memory interface, hiding DRAM latency.
//
// Each buffer holds one 16x16 INT8 tile (256 bytes). There are four SRAMs in
// total: ping_weight, pong_weight, ping_act, pong_act. A single bit (active)
// tracks which side the SDS reads from; the other side accepts AXI4 writes.
//
// On swap (pulsed by the Tile Sequencer FSM), the active bit flips. swap also
// serves as the acknowledgement for fill_weight_done and fill_act_done, clearing
// both sticky signals. The FSM must only assert swap after both are high.
//
// Fill side (AXI4 slave, write-only):
//   AXI4 bursts of 16 beats x 128-bit (one full tile per burst). The fill
//   controller accepts the burst and writes rows 0-15 into the inactive buffer.
//   fill_weight_done / fill_act_done latch high when each burst completes and
//   remain high until swap fires. This allows fill to complete while the FSM is
//   in another state without losing the completion signal.
//
// Read side (SDS, read-only):
//   Row-addressed read port: 4-bit addr selects a row, combinational 16-byte
//   data out. Separate ports for weight and activation tiles.

module pingpong_buffers (
    input  logic        clk, rst_n,

    // Tile Sequencer FSM control
    input  logic        swap,             // pulse swaps active/inactive buffer pair
    output logic        fill_weight_done, // pulses when weight burst completes
    output logic        fill_act_done,    // pulses when activation burst completes

    // AXI4 slave fill ports (write channels only; read channels tied off)
    axi4_if.slave       fill_weight_axi,
    axi4_if.slave       fill_act_axi,

    // SDS read ports (data should be fed combinationally to sds)
    input  logic [3:0]  weight_buf_addr,
    output logic [7:0]  weight_buf_data [15:0],
    input  logic [3:0]  act_buf_addr,
    output logic [7:0]  act_buf_data    [15:0]
);

    logic [7:0] ping_act    [15:0][15:0];
    logic [7:0] pong_act    [15:0][15:0];
    logic [7:0] ping_weight [15:0][15:0];
    logic [7:0] pong_weight [15:0][15:0];

    logic active; // 0 = ping active, 1 = pong active

    typedef enum logic [1:0] { IDLE, BURST, RESP } state_t;
    state_t weight_state, act_state;

    logic [3:0] weight_row, act_row;

    // swap logic
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            active <= 0;
        end else begin
            if (swap)
                active <= ~active;
        end
    end

    // SDS read logic
    always_comb begin
        if (!active) begin
            weight_buf_data = ping_weight[weight_buf_addr];
            act_buf_data    = ping_act[act_buf_addr];
        end else begin
            weight_buf_data = pong_weight[weight_buf_addr];
            act_buf_data    = pong_act[act_buf_addr];
        end
    end

    // AXI4 fill FSM
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            fill_weight_done        <= 0;
            fill_act_done           <= 0;
            weight_row              <= 0;
            act_row                 <= 0;
            weight_state            <= IDLE;
            act_state               <= IDLE;
            fill_weight_axi.awready <= 0;
            fill_weight_axi.wready  <= 0;
            fill_weight_axi.bvalid  <= 0;
            fill_act_axi.awready    <= 0;
            fill_act_axi.wready     <= 0;
            fill_act_axi.bvalid     <= 0;
        end else begin
            // clear fill_done signals when FSM acknowledges via swap
            if (swap) begin
                fill_weight_done <= 0;
                fill_act_done    <= 0;
            end

            // Weight FSM
            case (weight_state)
                IDLE: begin // waiting, ready to accept address from master
                    fill_weight_axi.awready <= 1;
                    if (fill_weight_axi.awvalid) begin // valid handshake
                        fill_weight_axi.awready <= 0;
                        weight_row <= 0;
                        weight_state <= BURST;
                    end
                end
                
                BURST: begin // accepts data one beat (16 bytes) per cycle into non_active buffer
                    fill_weight_axi.wready <= 1;
                    if (fill_weight_axi.wvalid) begin
                        if (!active) begin //active: ping --> fill pong
                            pong_weight[weight_row] <= fill_weight_axi.wdata;
                        end
                        else begin // active: pong --> fill ping
                            ping_weight[weight_row] <= fill_weight_axi.wdata;
                        end
                        weight_row <= weight_row + 1;
                        if (fill_weight_axi.wlast) begin
                            fill_weight_axi.wready <= 0;
                            weight_state <= RESP;
                        end
                    end
                end

                RESP: begin // send write response and wait for master to accept
                    fill_weight_axi.bvalid <= 1;
                    fill_weight_axi.bresp <= 2'b00; // AXI4 OKAY code
                    if (fill_weight_axi.bready) begin
                        fill_weight_axi.bvalid <= 0;
                        fill_weight_done <= 1;
                        weight_state <= IDLE;
                    end
                end

                default: weight_state <= IDLE;

            endcase

            // Activation FSM
            case (act_state)
                IDLE: begin // waiting, ready to accept address from master
                    fill_act_axi.awready <= 1;
                    if (fill_act_axi.awvalid) begin // valid handshake
                        fill_act_axi.awready <= 0;
                        act_row <= 0;
                        act_state <= BURST;
                    end
                    
                end
                BURST: begin // accepts data one beat (16 bytes) per cycle into non_active buffer
                    fill_act_axi.wready <= 1;
                    if (fill_act_axi.wvalid) begin
                        if (!active) begin //active: ping --> fill pong
                            pong_act[act_row] <= fill_act_axi.wdata;
                        end
                        else begin // active: pong --> fill ping
                            ping_act[act_row] <= fill_act_axi.wdata;
                        end
                        act_row <= act_row + 1;
                        if (fill_act_axi.wlast) begin
                            fill_act_axi.wready <= 0;
                            act_state <= RESP;
                        end
                    end
                end

                RESP: begin // send write response and wait for master to accept
                    fill_act_axi.bvalid <= 1;
                    fill_act_axi.bresp <= 2'b00; // AXI4 OKAY code
                    if (fill_act_axi.bready) begin
                        fill_act_axi.bvalid <= 0;
                        fill_act_done <= 1;
                        act_state <= IDLE;
                    end
                end

                default: act_state <= IDLE;

            endcase

        end
    end

    // Tie off read ports
    assign fill_weight_axi.arready = 0;
    assign fill_weight_axi.rvalid  = 0;
    assign fill_weight_axi.rdata   = 0;
    assign fill_weight_axi.rresp   = 0;
    assign fill_weight_axi.rlast   = 0;

    assign fill_act_axi.arready = 0;
    assign fill_act_axi.rvalid  = 0;
    assign fill_act_axi.rdata   = 0;
    assign fill_act_axi.rresp   = 0;
    assign fill_act_axi.rlast   = 0;


endmodule