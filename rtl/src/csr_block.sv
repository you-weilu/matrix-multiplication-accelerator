// CSR Block (Control and Status Registers)
//
// AXI4-Lite slave register file. Software (host CPU) writes matrix dimensions
// and asserts go before each matrix multiply; the tile sequencer FSM reads the
// config registers and writes status back through this block.
//
// Register map (each 32-bit, word-addressed):
//   0x00  CTRL          — bit[0]: go (W1S: write 1 to start; auto-clears when FSM done)
//                          bit[1]: busy (RO: 1 while FSM is running)
//   0x04  M_TILES        — number of output tile rows    (M / 16, max 255)
//   0x08  N_TILES        — number of output tile columns (N / 16, max 255)
//   0x0C  K_TILES        — number of K-tile passes       (K / 16, max 255)
//   0x10  STATUS         — bit[0]: done (RO: pulses when multiply completes; cleared on next go)
//   0x14  BASE_ADDR_A_LO — bits[31:0]  of matrix A base address in host RAM
//   0x18  BASE_ADDR_A_HI — bits[63:32] of matrix A base address in host RAM
//   0x1C  BASE_ADDR_B_LO — bits[31:0]  of matrix B base address in host RAM
//   0x20  BASE_ADDR_B_HI — bits[63:32] of matrix B base address in host RAM
//   0x24  BASE_ADDR_C_LO — bits[31:0]  of matrix C base address in host RAM
//   0x28  BASE_ADDR_C_HI — bits[63:32] of matrix C base address in host RAM
//
// AXI4-Lite interface:
//   Slave port (axi_lite_if.slave csr_axi) accepts reads and writes from the host.
//   Single-cycle register reads; writes take effect on the B-channel handshake.
//
// TS interface (outputs to tile_sequencer_fsm):
//   go        — pulses one cycle when software sets CTRL[0]
//   m_tiles   — latched value of M_TILES register
//   n_tiles   — latched value of N_TILES register
//   k_tiles   — latched value of K_TILES register
//
// TS interface (inputs from tile_sequencer_fsm):
//   ts_busy  — held high while tile sequencer is running; reflected in CTRL[1]
//   ts_done  — pulsed by tile sequencer on completion; sets STATUS[0] and clears busy

module csr_block (
    axi_lite_if.slave   csr_axi,

    // FSM outputs
    output logic        go,
    output logic [7:0]  m_tiles,
    output logic [7:0]  n_tiles,
    output logic [7:0]  k_tiles,

    // FSM inputs
    input  logic        ts_busy,
    input  logic        ts_done,

    // DMA controller outputs
    output logic [63:0] base_addr_a,
    output logic [63:0] base_addr_b,
    output logic [63:0] base_addr_c
);

    // Clock and reset from AXI interface
    logic clk, rst_n;
    assign clk   = csr_axi.aclk;
    assign rst_n = csr_axi.aresetn;

    // Register storage
    logic       reg_go;      // CTRL[0]: one-cycle pulse to FSM
    logic [7:0] reg_m_tiles;
    logic [7:0] reg_n_tiles;
    logic [7:0] reg_k_tiles;
    logic       reg_done;    // STATUS[0]: sticky, cleared on next go
    logic [31:0] reg_base_addr_a_lo;
    logic [31:0] reg_base_addr_a_hi;
    logic [31:0] reg_base_addr_b_lo;
    logic [31:0] reg_base_addr_b_hi;
    logic [31:0] reg_base_addr_c_lo;
    logic [31:0] reg_base_addr_c_hi;

    // Write path latches (hold whichever of addr/data arrives first)
    logic [5:0]  wr_addr_lat;
    logic [31:0] wr_data_lat;

    // Pulses one cycle when a write transaction is being committed
    logic wr_commit;
    assign wr_commit = (wr_state == WR_RESP) && csr_axi.bready;

    // State declarations
    typedef enum logic [1:0] { WR_IDLE, WR_HAVE_ADDR, WR_HAVE_DATA, WR_RESP } wr_state_t;
    wr_state_t wr_state;

    typedef enum logic { RD_IDLE, RD_RESP } rd_state_t;
    rd_state_t rd_state;

    // Write path FSM (AXI signals)
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            wr_state        <= WR_IDLE;
            wr_addr_lat     <= '0;
            wr_data_lat     <= '0;
            csr_axi.awready <= 0;
            csr_axi.wready  <= 0;
            csr_axi.bvalid  <= 0;
            csr_axi.bresp   <= 2'b00;
        end else begin
            case (wr_state)
                WR_IDLE: begin
                    csr_axi.awready <= 1;
                    csr_axi.wready  <= 1;
                    if (csr_axi.awvalid && csr_axi.wvalid) begin
                        wr_addr_lat     <= csr_axi.awaddr[5:0];
                        wr_data_lat     <= csr_axi.wdata;
                        csr_axi.awready <= 0;
                        csr_axi.wready  <= 0;
                        wr_state        <= WR_RESP;
                    end else if (csr_axi.awvalid) begin
                        wr_addr_lat     <= csr_axi.awaddr[5:0];
                        csr_axi.awready <= 0;
                        wr_state        <= WR_HAVE_ADDR;
                    end else if (csr_axi.wvalid) begin
                        wr_data_lat    <= csr_axi.wdata;
                        csr_axi.wready <= 0;
                        wr_state       <= WR_HAVE_DATA;
                    end
                end

                WR_HAVE_ADDR: begin
                    if (csr_axi.wvalid) begin
                        wr_data_lat    <= csr_axi.wdata;
                        csr_axi.wready <= 0;
                        wr_state       <= WR_RESP;
                    end
                end

                WR_HAVE_DATA: begin
                    if (csr_axi.awvalid) begin
                        wr_addr_lat     <= csr_axi.awaddr[5:0];
                        csr_axi.awready <= 0;
                        wr_state        <= WR_RESP;
                    end
                end

                WR_RESP: begin
                    csr_axi.bvalid <= 1;
                    csr_axi.bresp  <= 2'b00;
                    if (csr_axi.bready) begin
                        csr_axi.bvalid <= 0;
                        wr_state       <= WR_IDLE;
                    end
                end
                default: wr_state <= WR_IDLE;
            endcase
        end
    end

    // Register management (register write logic)
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            reg_go           <= 0;
            reg_m_tiles      <= 1;
            reg_n_tiles      <= 1;
            reg_k_tiles      <= 1;
            reg_done         <= 0;
            reg_base_addr_a_lo <= 0;
            reg_base_addr_a_hi <= 0;
            reg_base_addr_b_lo <= 0;
            reg_base_addr_b_hi <= 0;
            reg_base_addr_c_lo <= 0;
            reg_base_addr_c_hi <= 0;
        end else begin
            reg_go <= 0;  // auto-clear every cycle
            if (ts_done) reg_done <= 1;
            if (wr_commit) begin
                case (wr_addr_lat[5:2])
                    4'h0: if (wr_data_lat[0] && !ts_busy) begin // go gated by ts_busy
                              reg_go   <= 1;
                              reg_done <= 0;  // clear done on new go
                          end
                    4'h1: reg_m_tiles        <= wr_data_lat[7:0];
                    4'h2: reg_n_tiles        <= wr_data_lat[7:0];
                    4'h3: reg_k_tiles        <= wr_data_lat[7:0];
                    4'h5: reg_base_addr_a_lo <= wr_data_lat;
                    4'h6: reg_base_addr_a_hi <= wr_data_lat;
                    4'h7: reg_base_addr_b_lo <= wr_data_lat;
                    4'h8: reg_base_addr_b_hi <= wr_data_lat;
                    4'h9: reg_base_addr_c_lo <= wr_data_lat;
                    4'hA: reg_base_addr_c_hi <= wr_data_lat;
                    default: ;  // STATUS (0x10) and unmapped addresses are RO
                endcase
            end
        end
    end

    // Read path FSM
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            rd_state        <= RD_IDLE;
            csr_axi.arready <= 0;
            csr_axi.rvalid  <= 0;
            csr_axi.rdata   <= '0;
            csr_axi.rresp   <= 2'b00;
        end else begin
            case (rd_state)
                RD_IDLE: begin // wait for address
                    csr_axi.arready <= 1;
                    if (csr_axi.arvalid) begin
                        csr_axi.arready <= 0;
                        csr_axi.rvalid  <= 1;
                        csr_axi.rresp   <= 2'b00;
                        case (csr_axi.araddr[5:2])
                            4'h0: csr_axi.rdata <= {30'b0, ts_busy, reg_go};
                            4'h1: csr_axi.rdata <= {24'b0, reg_m_tiles};
                            4'h2: csr_axi.rdata <= {24'b0, reg_n_tiles};
                            4'h3: csr_axi.rdata <= {24'b0, reg_k_tiles};
                            4'h4: csr_axi.rdata <= {31'b0, reg_done};
                            4'h5: csr_axi.rdata <= reg_base_addr_a_lo;
                            4'h6: csr_axi.rdata <= reg_base_addr_a_hi;
                            4'h7: csr_axi.rdata <= reg_base_addr_b_lo;
                            4'h8: csr_axi.rdata <= reg_base_addr_b_hi;
                            4'h9: csr_axi.rdata <= reg_base_addr_c_lo;
                            4'hA: csr_axi.rdata <= reg_base_addr_c_hi;
                            default: csr_axi.rdata <= '0;
                        endcase
                        rd_state <= RD_RESP;
                    end
                end

                RD_RESP: begin
                    if (csr_axi.rready) begin
                        csr_axi.rvalid <= 0;
                        rd_state       <= RD_IDLE;
                    end
                end
                default: rd_state <= RD_IDLE;
            endcase
        end
    end

    // Output signals
    assign go          = reg_go;
    assign m_tiles     = reg_m_tiles;
    assign n_tiles     = reg_n_tiles;
    assign k_tiles     = reg_k_tiles;
    assign base_addr_a = {reg_base_addr_a_hi, reg_base_addr_a_lo};
    assign base_addr_b = {reg_base_addr_b_hi, reg_base_addr_b_lo};
    assign base_addr_c = {reg_base_addr_c_hi, reg_base_addr_c_lo};

endmodule