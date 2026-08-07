// DMA Controller
//
// Translates tile fetch and writeback requests from the Tile Sequencer FSM into
// XDMA descriptor bypass pushes. Uses descriptor bypass mode: src_addr, dst_addr,
// len, and ctl are driven directly onto XDMA's fabric bypass bus rather than being
// written to host memory for XDMA to fetch over PCIe (which would waste a roundtrip).
//
// Initialization: at reset release, writes the Run bit to H2C ch0, H2C ch1, and
// C2H ch0 control registers via s_axil. XDMA ignores bypass descriptors until Run=1.
// s_axil is idle after this one-time setup.
//
// On fill_start: pushes one descriptor to H2C ch0 (weight tile, matrix B) and one
// to H2C ch1 (activation tile, matrix A) by asserting dsc_byp_load when XDMA's
// dsc_byp_ready is high. Both channels run concurrently; XDMA interleaves their
// PCIe reads round-robin. XDMA writes each tile to the inactive ping-pong buffer
// via AXI4; the ping-pong buffers assert fill_weight_done/fill_act_done when their
// AXI4 write handshake completes. h2c_sts_x[3] pulses one cycle on descriptor done.
//
// On writeback_start: pushes one descriptor to C2H ch0. XDMA reads the output
// buffer via AXI4 and writes the tile to host RAM. c2h_sts_0[3] pulses one cycle
// on completion; the DMA Controller registers this and asserts writeback_done.
//
// Address computation:
//   Weight tile (H2C ch0):     src = base_addr_b + (tile_j * k_tiles + k_tile) * 256
//   Activation tile (H2C ch1): src = base_addr_a + (tile_i * k_tiles + k_tile) * 256
//   Output tile (C2H ch0):     dst = base_addr_c + (tile_i * n_tiles + tile_j) * 1024
//
// Descriptor ctl field is always 16'h0003 (Stop=1, Completed=1) for single-descriptor
// transfers. Magic, Nxt_adj, and Nxt_adr fields are not used in bypass mode.

module dma_controller (
    input  logic        clk, rst_n,

    // FSM control
    input  logic        fill_start,
    input  logic        writeback_start,
    input  logic [7:0]  tile_i,
    input  logic [7:0]  tile_j,
    input  logic [7:0]  k_tile,

    // CSR base addresses and dimensions
    input  logic [63:0] base_addr_a,
    input  logic [63:0] base_addr_b,
    input  logic [63:0] base_addr_c,
    input  logic [7:0]  k_tiles,
    input  logic [7:0]  n_tiles,

    // Card-side AXI base addresses of ping-pong buffer slave ports (fixed in address map)
    input  logic [63:0] pp_weight_axi_base,
    input  logic [63:0] pp_act_axi_base,
    input  logic [63:0] output_buf_axi_base,

    // Completion signals to FSM
    output logic        writeback_done,
    output logic        init_done,

    // AXI4-Lite master: one-time init only (writes Run bit to H2C ch0/ch1, C2H ch0)
    axi_lite_if.master  s_axil,

    // H2C ch0 descriptor bypass: weight tile (matrix B)
    input  logic        h2c_dsc_byp_ready_0,
    output logic        h2c_dsc_byp_load_0,
    output logic [63:0] h2c_dsc_byp_src_addr_0,
    output logic [63:0] h2c_dsc_byp_dst_addr_0,
    output logic [27:0] h2c_dsc_byp_len_0,
    output logic [15:0] h2c_dsc_byp_ctl_0,

    // H2C ch1 descriptor bypass: activation tile (matrix A)
    input  logic        h2c_dsc_byp_ready_1,
    output logic        h2c_dsc_byp_load_1,
    output logic [63:0] h2c_dsc_byp_src_addr_1,
    output logic [63:0] h2c_dsc_byp_dst_addr_1,
    output logic [27:0] h2c_dsc_byp_len_1,
    output logic [15:0] h2c_dsc_byp_ctl_1,

    // C2H ch0 descriptor bypass: output tile writeback (matrix C)
    input  logic        c2h_dsc_byp_ready_0,
    output logic        c2h_dsc_byp_load_0,
    output logic [63:0] c2h_dsc_byp_src_addr_0,
    output logic [63:0] c2h_dsc_byp_dst_addr_0,
    output logic [27:0] c2h_dsc_byp_len_0,
    output logic [15:0] c2h_dsc_byp_ctl_0,

    // XDMA channel status: bit 3 pulses one cycle when descriptor completes
    input  logic [7:0]  h2c_sts_0,
    input  logic [7:0]  h2c_sts_1,
    input  logic [7:0]  c2h_sts_0
);
    // State declarations
    typedef enum logic [1:0] { IDLE, PUSH, WAIT_DONE } state_t;
    state_t w_state, a_state, c_state;

    // Address computations: change from comb to egistered to break the long path from
    // reg_k_tiles through the 64-bit multiply-add chain to XDMA's descriptor FIFO.
    // Addresses are stable at least one cycle before load is asserted (IDLE→PUSH
    // takes one cycle after fill_start, so the registered value is always ready).
    // Narrow offsets computed in 16-bit (max 255*255+255=65280 fits) to avoid
    // inferring a 64x64 multiplier from the original 64'() casts.
    logic [15:0] weight_offset, act_offset, out_offset;
    always_comb begin
        weight_offset = 16'(tile_j) * 16'(k_tiles) + 16'(k_tile);
        act_offset    = 16'(tile_i) * 16'(k_tiles) + 16'(k_tile);
        out_offset    = 16'(tile_i) * 16'(n_tiles) + 16'(tile_j);
    end

    always_ff @(posedge clk) begin
        // H2C ch0: weight tile (matrix B)
        h2c_dsc_byp_src_addr_0 <= base_addr_b + (64'(weight_offset) << 8);
        h2c_dsc_byp_dst_addr_0 <= pp_weight_axi_base;
        h2c_dsc_byp_len_0      <= 28'd256;
        h2c_dsc_byp_ctl_0      <= 16'h0003;
        // H2C ch1: activation tile (matrix A)
        h2c_dsc_byp_src_addr_1 <= base_addr_a + (64'(act_offset) << 8);
        h2c_dsc_byp_dst_addr_1 <= pp_act_axi_base;
        h2c_dsc_byp_len_1      <= 28'd256;
        h2c_dsc_byp_ctl_1      <= 16'h0003;
        // C2H ch0: output tile (matrix C)
        c2h_dsc_byp_src_addr_0 <= output_buf_axi_base;
        c2h_dsc_byp_dst_addr_0 <= base_addr_c + (64'(out_offset) << 10);
        c2h_dsc_byp_len_0      <= 28'd1024;
        c2h_dsc_byp_ctl_0      <= 16'h0003;
    end

    // H2C ch0 (WEIGHT) FSM
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            w_state            <= IDLE;
            h2c_dsc_byp_load_0 <= 0;
        end else begin
            h2c_dsc_byp_load_0 <= 0;  // default deasserted
            case (w_state)
                IDLE: begin
                    if (fill_start) w_state <= PUSH;
                end
                PUSH: begin
                    if (h2c_dsc_byp_ready_0) begin
                        h2c_dsc_byp_load_0 <= 1;
                        w_state <= WAIT_DONE;
                    end
                end
                WAIT_DONE: begin
                    if (h2c_sts_0[3]) w_state <= IDLE;
                end
                default: w_state <= IDLE;
            endcase
        end
    end

    // H2C ch1 (ACTIVATION) FSM
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            a_state            <= IDLE;
            h2c_dsc_byp_load_1 <= 0;
        end else begin
            h2c_dsc_byp_load_1 <= 0;  // default deasserted
            case (a_state)
                IDLE: begin
                    if (fill_start) a_state <= PUSH;
                end
                PUSH: begin
                    if (h2c_dsc_byp_ready_1) begin
                        h2c_dsc_byp_load_1 <= 1;
                        a_state <= WAIT_DONE;
                    end
                end
                WAIT_DONE: begin
                    if (h2c_sts_1[3]) a_state <= IDLE;
                end
                default: a_state <= IDLE;
            endcase
        end
    end

    // C2H ch0 (OUTPUT) FSM
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            c_state            <= IDLE;
            c2h_dsc_byp_load_0 <= 0;
            writeback_done     <= 0;
        end else begin
            c2h_dsc_byp_load_0 <= 0;  // default deasserted
            writeback_done     <= 0;   // default deasserted
            case (c_state)
                IDLE: begin
                    if (writeback_start) c_state <= PUSH;
                end
                PUSH: begin
                    if (c2h_dsc_byp_ready_0) begin
                        c2h_dsc_byp_load_0 <= 1;
                        c_state <= WAIT_DONE;
                    end
                end
                WAIT_DONE: begin
                    if (c2h_sts_0[3]) begin
                        writeback_done <= 1;
                        c_state <= IDLE;
                    end
                end
                default: c_state <= IDLE;
            endcase
        end
    end

    // Initialization FSM: writes Run bit to H2C ch0/ch1 and C2H ch0 via s_axil at startup.
    // XDMA ignores bypass descriptors until Run=1; this must complete before any fill_start.
    typedef enum logic [1:0] { I_AW, I_W, I_B, I_DONE } init_state_t;
    init_state_t init_state;
    logic [1:0] reg_idx;

    localparam logic [31:0] INIT_ADDRS [3] = '{ // '{}: array initializer not concatenation
        32'h0000_0004,  // H2C ch0 channel control INIT_ADDRS[0]
        32'h0000_1004,  // H2C ch1 channel control INIT_ADDRS[1]
        32'h0001_0004   // C2H ch0 channel control INIT_ADDRS[2]
    };

    assign init_done      = (init_state == I_DONE);
    assign s_axil.arvalid = 0;
    assign s_axil.rready  = 0;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            init_state     <= I_AW;
            reg_idx        <= 0;
            s_axil.awvalid <= 0;
            s_axil.wvalid  <= 0;
            s_axil.bready  <= 0;
        end else begin
            case (init_state)
                I_AW: begin
                    s_axil.awvalid <= 1;
                    s_axil.awaddr  <= INIT_ADDRS[reg_idx];
                    s_axil.awprot  <= 3'b000;
                    if (s_axil.awready) begin
                        s_axil.awvalid <= 0;
                        init_state     <= I_W;
                    end
                end
                I_W: begin
                    s_axil.wvalid <= 1;
                    s_axil.wdata  <= 32'h0000_0001;  // Run bit
                    s_axil.wstrb  <= 4'hF;
                    if (s_axil.wready) begin
                        s_axil.wvalid <= 0;
                        init_state    <= I_B;
                    end
                end
                I_B: begin
                    s_axil.bready <= 1;
                    if (s_axil.bvalid && s_axil.bready) begin
                        s_axil.bready <= 0;
                        if (reg_idx == 2) begin
                            init_state <= I_DONE;
                        end else begin
                            reg_idx    <= reg_idx + 1;
                            init_state <= I_AW;
                        end
                    end
                end
                I_DONE: ; // all three Run bits set; s_axil is idle
            endcase
        end
    end

endmodule
