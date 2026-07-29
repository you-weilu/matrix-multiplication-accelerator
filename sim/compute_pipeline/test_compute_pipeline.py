"""
Compute pipeline integration test.

The testbench acts as DMA proxy:
  - Drives init_done=1 (bypasses DMA init FSM)
  - Monitors fill_start: writes the correct weight/act tile to the ping-pong
    buffer AXI slaves
  - Monitors writeback_start: reads the output buffer, verifies vs numpy
    reference, then drives writeback_done for one cycle

Matrix layout:
  Weight tile (B): B[k*16:(k+1)*16,  j*16:(j+1)*16]  — stored row by row
  Act tile    (A): A[i*16:(i+1)*16,  k*16:(k+1)*16]  — stored row by row

When fill_start fires, tile_i/tile_j/k_tile already hold the coordinates
of the tile being fetched (they are updated by the FSM in the same registered
step that asserts fill_start, so the values are stable for the entire
FILL_WAIT state).

For writeback, the FSM increments tile_i/tile_j in the same registered step
that asserts writeback_start (ADVANCE state), so the DUT's tile_i/tile_j
reflect the NEXT tile by the time writeback_start is visible. The testbench
therefore maintains its own wb_i/wb_j counter.
"""

import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
import numpy as np

N = 16  # tile side length


# CSR register byte offsets
CSR_CTRL    = 0x00
CSR_M_TILES = 0x04
CSR_N_TILES = 0x08
CSR_K_TILES = 0x0C


# ---------------------------------------------------------------------------
# Data helpers
# ---------------------------------------------------------------------------

def pack_tile_int8(tile_np):
    """Pack a 16x16 INT8 numpy array into a list of 16 128-bit beat values.
    Row r → beat r; within beat: col c at bits [c*8+7 : c*8]."""
    beats = []
    for row in range(N):
        val = 0
        for col in range(N):
            b = int(tile_np[row, col]) & 0xFF
            val |= b << (col * 8)
        beats.append(val)
    return beats


def beats_to_tile_int32(beats):
    """Decode 64 128-bit beats into a 16x16 numpy INT32 array.
    Beat b → row b//4; within beat: word w at bits [w*32+31 : w*32] → col (b%4)*4+w."""
    tile = np.zeros((N, N), dtype=np.int32)
    for b, val in enumerate(beats):
        row = b // 4
        col_base = (b % 4) * 4
        for w in range(4):
            raw = (val >> (32 * w)) & 0xFFFFFFFF
            tile[row, col_base + w] = np.int32(raw if raw < (1 << 31) else raw - (1 << 32))
    return tile


# ---------------------------------------------------------------------------
# Bus helpers
# ---------------------------------------------------------------------------

async def reset(dut):
    dut.rst_n.value       = 0
    dut.init_done.value   = 0
    dut.writeback_done.value = 0

    # CSR AXI4-Lite
    dut.csr_awvalid.value = 0;  dut.csr_awaddr.value = 0; dut.csr_awprot.value = 0
    dut.csr_wvalid.value  = 0;  dut.csr_wdata.value  = 0; dut.csr_wstrb.value  = 0
    dut.csr_bready.value  = 0
    dut.csr_arvalid.value = 0;  dut.csr_araddr.value = 0; dut.csr_arprot.value = 0
    dut.csr_rready.value  = 0

    # fill_weight AXI4
    dut.fw_awvalid.value  = 0;  dut.fw_awid.value   = 0;    dut.fw_awaddr.value  = 0
    dut.fw_awlen.value    = 0;  dut.fw_awsize.value  = 0;   dut.fw_awburst.value = 0
    dut.fw_wvalid.value   = 0;  dut.fw_wdata.value   = 0;   dut.fw_wstrb.value   = 0
    dut.fw_wlast.value    = 0;  dut.fw_bready.value  = 0

    # fill_act AXI4
    dut.fa_awvalid.value  = 0;  dut.fa_awid.value   = 0;    dut.fa_awaddr.value  = 0
    dut.fa_awlen.value    = 0;  dut.fa_awsize.value  = 0;   dut.fa_awburst.value = 0
    dut.fa_wvalid.value   = 0;  dut.fa_wdata.value   = 0;   dut.fa_wstrb.value   = 0
    dut.fa_wlast.value    = 0;  dut.fa_bready.value  = 0

    # output buffer AXI4 read
    dut.ob_arvalid.value  = 0;  dut.ob_arid.value   = 0;    dut.ob_araddr.value  = 0
    dut.ob_arlen.value    = 0;  dut.ob_arsize.value  = 0;   dut.ob_arburst.value = 0
    dut.ob_rready.value   = 0

    for _ in range(5):
        await RisingEdge(dut.clk)
    dut.rst_n.value     = 1
    dut.init_done.value = 1     # bypass DMA init: tell tile sequencer we're ready
    await RisingEdge(dut.clk)


async def csr_write(dut, addr, data):
    """AXI4-Lite write (AW then W then B, sequential)."""
    # Wait until the slave has awready registered high, then present awvalid for the handshake.
    # Reading ready before presenting valid avoids the NBA-cancellation where the slave
    # simultaneously asserts and deasserts ready on the first clock valid is seen.
    while not dut.csr_awready.value:
        await RisingEdge(dut.clk)
    dut.csr_awvalid.value = 1
    dut.csr_awaddr.value  = addr
    dut.csr_awprot.value  = 0
    await RisingEdge(dut.clk)  # handshake: awvalid=1, awready already registered high
    dut.csr_awvalid.value = 0

    while not dut.csr_wready.value:
        await RisingEdge(dut.clk)
    dut.csr_wvalid.value = 1
    dut.csr_wdata.value  = int(data) & 0xFFFF_FFFF
    dut.csr_wstrb.value  = 0xF
    await RisingEdge(dut.clk)  # handshake: wvalid=1, wready already registered high
    dut.csr_wvalid.value = 0

    while True:
        await RisingEdge(dut.clk)
        if dut.csr_bvalid.value:
            break
    dut.csr_bready.value = 1
    await RisingEdge(dut.clk)  # handshake edge: bvalid=1 and bready=1 simultaneously
    dut.csr_bready.value = 0


async def _axi4_write_beats(dut, aw_valid, aw_id, aw_addr, aw_len, aw_size, aw_burst,
                             aw_ready, w_valid, w_data, w_strb, w_last, w_ready,
                             b_valid, b_ready, beats_128):
    """Generic 16-beat AXI4 write (used for both fw and fa ports)."""
    while not aw_ready.value:
        await RisingEdge(dut.clk)
    aw_valid.value  = 1
    aw_id.value     = 0
    aw_addr.value   = 0
    aw_len.value    = N - 1       # 16 beats
    aw_size.value   = 4           # 2^4 = 16 bytes per beat
    aw_burst.value  = 1           # INCR
    await RisingEdge(dut.clk)  # handshake: awvalid=1, awready already registered high
    aw_valid.value = 0

    for i, beat in enumerate(beats_128):
        # Wait for wready registered high before presenting wvalid. This avoids presenting
        # wvalid while wready is still transitioning — the ping-pong BURST state writes
        # data on wvalid regardless of wready, so presenting them simultaneously corrupts
        # the first beat.
        while not w_ready.value:
            await RisingEdge(dut.clk)
        w_valid.value = 1
        w_data.value  = beat
        w_strb.value  = 0xFFFF
        w_last.value  = 1 if i == N - 1 else 0
        await RisingEdge(dut.clk)  # handshake: wvalid=1, wready already registered high
    w_valid.value = 0
    w_last.value  = 0

    while True:
        await RisingEdge(dut.clk)
        if b_valid.value:
            break
    b_ready.value = 1
    await RisingEdge(dut.clk)  # handshake edge: bvalid=1 and bready=1 simultaneously
    b_ready.value = 0


async def axi4_write_fw(dut, beats_128):
    """Write 16 128-bit beats to the fill_weight ping-pong port."""
    await _axi4_write_beats(
        dut,
        dut.fw_awvalid, dut.fw_awid, dut.fw_awaddr, dut.fw_awlen, dut.fw_awsize, dut.fw_awburst,
        dut.fw_awready,
        dut.fw_wvalid, dut.fw_wdata, dut.fw_wstrb, dut.fw_wlast, dut.fw_wready,
        dut.fw_bvalid, dut.fw_bready,
        beats_128,
    )


async def axi4_write_fa(dut, beats_128):
    """Write 16 128-bit beats to the fill_act ping-pong port."""
    await _axi4_write_beats(
        dut,
        dut.fa_awvalid, dut.fa_awid, dut.fa_awaddr, dut.fa_awlen, dut.fa_awsize, dut.fa_awburst,
        dut.fa_awready,
        dut.fa_wvalid, dut.fa_wdata, dut.fa_wstrb, dut.fa_wlast, dut.fa_wready,
        dut.fa_bvalid, dut.fa_bready,
        beats_128,
    )


async def axi4_read_output(dut):
    """Issue a 64-beat AXI4 burst read on ob_*. Returns list of 64 int values."""
    dut.ob_rready.value  = 1
    # Wait for arready registered high before presenting arvalid. The output buffer
    # checks (arvalid && arready_reg) to trigger the burst — if arvalid arrives while
    # arready_reg=0, the first IDLE clock asserts arready but the condition isn't met
    # until the NEXT clock, by which time arvalid must still be 1. Waiting first
    # guarantees arvalid and arready_reg are both 1 on the same (handshake) clock.
    while not dut.ob_arready.value:
        await RisingEdge(dut.clk)
    dut.ob_arvalid.value = 1
    dut.ob_arid.value    = 0
    dut.ob_araddr.value  = 0
    dut.ob_arlen.value   = 63     # 64 beats
    dut.ob_arsize.value  = 4      # 16 bytes per beat
    dut.ob_arburst.value = 1      # INCR
    await RisingEdge(dut.clk)  # handshake: arvalid=1, arready already registered high
    dut.ob_arvalid.value = 0
    dut._log.info(f"[read_output] AR handshake done: rvalid={int(dut.ob_rvalid.value)} rdata=0x{int(dut.ob_rdata.value):032x}")

    # The output buffer drives rvalid=1 and rdata=mem[beat_addr] starting immediately
    # after the AR handshake clock. rdata is combinational from the registered beat_addr,
    # so it is valid BEFORE the next rising edge (beat_addr advances on each beat's edge).
    # Sampling rvalid/rdata before each await captures the correct data for every beat.
    beats = []
    while True:
        if dut.ob_rvalid.value:
            val = int(dut.ob_rdata.value)
            if len(beats) < 4:
                dut._log.info(f"[read_output] beat[{len(beats)}] rdata=0x{val:032x}")
            beats.append(val)
            if dut.ob_rlast.value:
                await RisingEdge(dut.clk)  # consume last beat's handshake edge
                break
            await RisingEdge(dut.clk)
        else:
            await RisingEdge(dut.clk)
    dut.ob_rready.value = 0
    return beats


# ---------------------------------------------------------------------------
# DMA proxy coroutines
# ---------------------------------------------------------------------------

async def fill_monitor(dut, A, B, total_fills):
    """Watch fill_start; write the correct weight and act tile to ping-pong buffers.

    When fill_start fires, tile_i/tile_j/k_tile are already the coordinates
    of the tile being fetched (they are stable through the FILL_WAIT state).
    Launches fw and fa writes concurrently since they use independent buses.
    """
    for _ in range(total_fills):
        while True:
            await RisingEdge(dut.clk)
            if dut.fill_start.value:
                break

        ti = int(dut.tile_i.value)
        tj = int(dut.tile_j.value)
        tk = int(dut.k_tile.value)

        # Slice the correct 16x16 subtiles
        weight_np = B[tk * N:(tk + 1) * N, tj * N:(tj + 1) * N]  # rows=k, cols=j
        act_np    = A[ti * N:(ti + 1) * N, tk * N:(tk + 1) * N]  # rows=i, cols=k

        weight_beats = pack_tile_int8(weight_np)
        act_beats    = pack_tile_int8(act_np)

        # Launch both writes concurrently — they use independent AXI buses.
        # The FSM will hold in FILL_WAIT until both fill_done signals arrive
        # from inside the ping-pong buffers.
        cocotb.start_soon(axi4_write_fw(dut, weight_beats))
        cocotb.start_soon(axi4_write_fa(dut, act_beats))


async def writeback_monitor(dut, C_ref, m_tiles, n_tiles, errors):
    """Watch writeback_start; read output buffer, verify, drive writeback_done.

    tile_i/tile_j reflect the NEXT tile by the time writeback_start is
    visible (they are updated in the same ADVANCE registered step), so
    wb_i/wb_j are tracked independently in row-major order.
    """
    wb_i = 0
    wb_j = 0
    total = m_tiles * n_tiles

    for _ in range(total):
        while True:
            await RisingEdge(dut.clk)
            if dut.writeback_start.value:
                break

        # Read output buffer (64 beats)
        cocotb.log.info(f"[wb_mon] writeback_start detected for tile({wb_i},{wb_j}): ob_arready={int(dut.ob_arready.value)}")
        beats = await axi4_read_output(dut)
        assert len(beats) == 64, f"[tile {wb_i},{wb_j}] expected 64 beats, got {len(beats)}"

        got      = beats_to_tile_int32(beats)
        cocotb.log.info(f"tile({wb_i},{wb_j}) got[0][0:4]={got[0,0:4].tolist()} expected[0][0:4]={C_ref[wb_i*N, wb_j*N:wb_j*N+4].tolist()}")
        expected = C_ref[wb_i * N:(wb_i + 1) * N, wb_j * N:(wb_j + 1) * N]

        for r in range(N):
            for c in range(N):
                if got[r, c] != expected[r, c]:
                    errors.append(
                        f"tile({wb_i},{wb_j}) row{r} col{c}: "
                        f"expected {expected[r,c]}, got {got[r,c]}"
                    )

        # Acknowledge writeback to FSM (one-cycle pulse)
        dut.writeback_done.value = 1
        await RisingEdge(dut.clk)
        dut.writeback_done.value = 0

        # Advance row-major counter
        if wb_j == n_tiles - 1:
            wb_j  = 0
            wb_i += 1
        else:
            wb_j += 1


# ---------------------------------------------------------------------------
# Test
# ---------------------------------------------------------------------------

@cocotb.test()
async def test_matmul_2x2tiles_k1(dut):
    """2×2 output tiles, k_tiles=1 (32×32 = 32×16 @ 16×32, INT8→INT32)."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    m_tiles = 2
    n_tiles = 2
    k_tiles = 1
    M, N_dim, K = m_tiles * N, n_tiles * N, k_tiles * N  # 32×32, K=16

    rng = np.random.default_rng(0)
    A = rng.integers(-128, 128, size=(M, K), dtype=np.int8)
    B = rng.integers(-128, 128, size=(K, N_dim), dtype=np.int8)
    C_ref = A.astype(np.int32) @ B.astype(np.int32)

    # Configure CSR
    await csr_write(dut, CSR_M_TILES, m_tiles)
    await csr_write(dut, CSR_N_TILES, n_tiles)
    await csr_write(dut, CSR_K_TILES, k_tiles)
    # Base addresses don't matter here (DMA controller is not present),
    # but write something so the CSR block sees clean register values.
    await csr_write(dut, 0x14, 0)  # BASE_ADDR_A_LO
    await csr_write(dut, 0x18, 0)  # BASE_ADDR_A_HI
    await csr_write(dut, 0x1C, 0)  # BASE_ADDR_B_LO
    await csr_write(dut, 0x20, 0)  # BASE_ADDR_B_HI
    await csr_write(dut, 0x24, 0)  # BASE_ADDR_C_LO
    await csr_write(dut, 0x28, 0)  # BASE_ADDR_C_HI

    errors = []
    total_fills = m_tiles * n_tiles * k_tiles

    # Start proxy coroutines before asserting go so they're ready for fill_start
    cocotb.start_soon(fill_monitor(dut, A, B, total_fills))
    wb_task = cocotb.start_soon(writeback_monitor(dut, C_ref, m_tiles, n_tiles, errors))

    # Start the FSM
    await csr_write(dut, CSR_CTRL, 1)

    # Wait for writeback_monitor to finish all tiles (timeout ~4000 cycles)
    for _ in range(4000):
        await RisingEdge(dut.clk)
        if wb_task.done():
            break
    else:
        assert False, "Timed out waiting for all writeback tiles"

    assert not errors, "Verification errors:\n" + "\n".join(errors[:10])


@cocotb.test()
async def test_matmul_1x1tile_k1(dut):
    """1×1 output tile, k_tiles=1: single 16×16 matmul (simplest smoke test)."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    m_tiles = 1
    n_tiles = 1
    k_tiles = 1

    rng = np.random.default_rng(1)
    A = rng.integers(-128, 128, size=(N, N), dtype=np.int8)
    B = rng.integers(-128, 128, size=(N, N), dtype=np.int8)
    C_ref = A.astype(np.int32) @ B.astype(np.int32)

    await csr_write(dut, CSR_M_TILES, m_tiles)
    await csr_write(dut, CSR_N_TILES, n_tiles)
    await csr_write(dut, CSR_K_TILES, k_tiles)
    await csr_write(dut, 0x14, 0); await csr_write(dut, 0x18, 0)
    await csr_write(dut, 0x1C, 0); await csr_write(dut, 0x20, 0)
    await csr_write(dut, 0x24, 0); await csr_write(dut, 0x28, 0)

    errors = []
    cocotb.start_soon(fill_monitor(dut, A, B, m_tiles * n_tiles * k_tiles))
    wb_task = cocotb.start_soon(writeback_monitor(dut, C_ref, m_tiles, n_tiles, errors))

    await csr_write(dut, CSR_CTRL, 1)

    for _ in range(1500):
        await RisingEdge(dut.clk)
        if wb_task.done():
            break
    else:
        assert False, "Timed out waiting for writeback"

    assert not errors, "Verification errors:\n" + "\n".join(errors[:10])


@cocotb.test()
async def test_matmul_1x1tile_k2(dut):
    """1×1 output tile, k_tiles=2: two K passes, verifies accumulation."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    m_tiles = 1
    n_tiles = 1
    k_tiles = 2
    K = k_tiles * N  # 32

    rng = np.random.default_rng(2)
    A = rng.integers(-128, 128, size=(N, K), dtype=np.int8)
    B = rng.integers(-128, 128, size=(K, N), dtype=np.int8)
    C_ref = A.astype(np.int32) @ B.astype(np.int32)

    await csr_write(dut, CSR_M_TILES, m_tiles)
    await csr_write(dut, CSR_N_TILES, n_tiles)
    await csr_write(dut, CSR_K_TILES, k_tiles)
    await csr_write(dut, 0x14, 0); await csr_write(dut, 0x18, 0)
    await csr_write(dut, 0x1C, 0); await csr_write(dut, 0x20, 0)
    await csr_write(dut, 0x24, 0); await csr_write(dut, 0x28, 0)

    errors = []
    cocotb.start_soon(fill_monitor(dut, A, B, m_tiles * n_tiles * k_tiles))
    wb_task = cocotb.start_soon(writeback_monitor(dut, C_ref, m_tiles, n_tiles, errors))

    await csr_write(dut, CSR_CTRL, 1)

    for _ in range(3000):
        await RisingEdge(dut.clk)
        if wb_task.done():
            break
    else:
        assert False, "Timed out waiting for writeback"

    assert not errors, "Verification errors:\n" + "\n".join(errors[:10])
