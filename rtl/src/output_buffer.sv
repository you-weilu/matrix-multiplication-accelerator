// Output Buffer
//
// Holds one completed 16×16 INT32 output tile (1024 bytes) between the
// accumulator bank and XDMA's C2H DMA channel.
//
// Write side: the accumulator bank writes one row (16 × 32-bit = 64 bytes) per
// cycle during its WRITEBACK state over 16 consecutive cycles via buf_wen,
// buf_row, and buf_data. Each row is packed into four consecutive 128-bit words.
//
// Read side: AXI4 slave. XDMA C2H issues a single 64-beat burst read
// (arlen=63, arsize=4 --> 16 bytes/beat) to move the full tile to host RAM.
// araddr[9:4] selects the 128-bit word within the buffer; the buffer must
// be aligned to a 1 KB boundary in the AXI address map.
//
// No double-buffering needed: the Tile Sequencer FSM ensures writeback_done
// is received before the next tile_done, so XDMA always finishes reading
// before the accumulator bank overwrites the buffer.

module output_buffer (
    input  logic        clk, rst_n,

    // Write port from accumulator bank (one row per cycle, 16 cycles per tile)
    input  logic        buf_wen,
    input  logic [3:0]  buf_row,
    input  logic [31:0] buf_data [15:0],

    // AXI4 slave read port for XDMA C2H (write channels tied off)
    axi4_if.slave       c2h_axi
);

    // 64 x 128-bit words = 1024 bytes
    (* ram_style = "registers" *) logic [127:0] mem [63:0];

    // Write: one accumulator row (16 x 32-bit) maps to 4 consecutive 128-bit words (AXI data bus is 128-bit)
    // buf_data[0] lands in bits [31:0] of the first word (little-endian column order).
    always_ff @(posedge clk) begin
        if (buf_wen) begin
            mem[{buf_row, 2'b00}] <= {buf_data[3],  buf_data[2],  buf_data[1],  buf_data[0]};
            mem[{buf_row, 2'b01}] <= {buf_data[7],  buf_data[6],  buf_data[5],  buf_data[4]};
            mem[{buf_row, 2'b10}] <= {buf_data[11], buf_data[10], buf_data[9],  buf_data[8]};
            mem[{buf_row, 2'b11}] <= {buf_data[15], buf_data[14], buf_data[13], buf_data[12]};
        end
    end

    // AXI4 read FSM
    typedef enum logic { IDLE, BURST } read_state_t;
    read_state_t state;

    logic [5:0] beat_addr;  // 16-byte word index into mem[63:0]
    logic [7:0] beat_count;   // beats remaining in burst (laoded from arlen)

    // Combinational read outputs: driven directly from beat_addr so data is
    // valid on the same cycle rvalid is asserted, with no extra pipeline stage.
    assign c2h_axi.rdata = mem[beat_addr];
    assign c2h_axi.rlast = (state == BURST) && (beat_count == 0);
    assign c2h_axi.rresp = 2'b00;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            state             <= IDLE;
            c2h_axi.arready   <= 0;
            c2h_axi.rvalid    <= 0;
            beat_addr         <= 0;
            beat_count        <= 0;
        end else begin
            case (state)
                IDLE: begin
                    c2h_axi.arready <= 1;
                    c2h_axi.rvalid  <= 0;
                    if (c2h_axi.arvalid && c2h_axi.arready) begin
                        c2h_axi.arready   <= 0;
                        c2h_axi.rvalid    <= 1;
                        beat_addr         <= c2h_axi.araddr[9:4];
                        beat_count        <= c2h_axi.arlen;
                        state             <= BURST;
                    end
                end
                BURST: begin
                    if (c2h_axi.rready) begin
                        if (beat_count == 0) begin
                            c2h_axi.rvalid <= 0;
                            state          <= IDLE;
                        end else begin
                            beat_addr   <= beat_addr + 1;
                            beat_count  <= beat_count  - 1;
                        end
                    end
                end
            endcase
        end
    end

    // Tie off write channels — XDMA never writes to the C2H source buffer
    assign c2h_axi.awready = 0;
    assign c2h_axi.wready  = 0;
    assign c2h_axi.bvalid  = 0;
    assign c2h_axi.bresp   = 2'b00;

endmodule
