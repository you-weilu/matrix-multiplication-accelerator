import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge


async def reset(dut):
    dut.rst_n.value          = 0
    dut.go.value             = 0
    dut.m_tiles.value        = 1
    dut.n_tiles.value        = 1
    dut.k_tiles.value        = 1
    dut.fill_weight_done.value = 0
    dut.fill_act_done.value    = 0
    dut.pass_done.value        = 0
    dut.tile_done.value        = 0
    dut.writeback_done.value   = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)


async def wait_for(dut, signal, timeout=100):
    """Wait for a signal to go high, fail if timeout cycles exceeded."""
    for _ in range(timeout):
        await RisingEdge(dut.clk)
        if int(signal.value) == 1:
            return
    assert False, f"Timeout waiting for {signal._name}"


async def do_fill(dut):
    """Assert sticky fill signals and wait for swap to clear them."""
    dut.fill_weight_done.value = 1
    dut.fill_act_done.value    = 1
    await wait_for(dut, dut.swap)
    # swap clears the sticky signals in ping-pong buffers — mirror that here
    dut.fill_weight_done.value = 0
    dut.fill_act_done.value    = 0


async def do_k_pass(dut, is_final):
    """Drive one K-tile pass through COMPUTE_START → COMPUTE → (ACCUM_WAIT if final)."""
    await wait_for(dut, dut.start)
    if is_final:
        assert int(dut.final_pass.value) == 1, "final_pass should be high on last K pass"
    else:
        assert int(dut.final_pass.value) == 0, "final_pass should be low on non-final K pass"
    await RisingEdge(dut.clk)
    dut.pass_done.value = 1
    await RisingEdge(dut.clk)
    dut.pass_done.value = 0


async def do_tile_done(dut):
    """Pulse tile_done to complete the accumulator writeback."""
    dut.tile_done.value = 1
    await RisingEdge(dut.clk)
    dut.tile_done.value = 0


async def do_writeback_done(dut):
    """Pulse writeback_done to complete the DMA C2H transfer."""
    await wait_for(dut, dut.writeback_start)
    await RisingEdge(dut.clk)
    dut.writeback_done.value = 1
    await RisingEdge(dut.clk)
    dut.writeback_done.value = 0


@cocotb.test()
async def test_reset(dut):
    """All outputs deasserted after reset."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)
    assert int(dut.swap.value)            == 0
    assert int(dut.start.value)           == 0
    assert int(dut.final_pass.value)      == 0
    assert int(dut.ts_busy.value)         == 0
    assert int(dut.ts_done.value)         == 0
    assert int(dut.fill_start.value)      == 0
    assert int(dut.writeback_start.value) == 0


@cocotb.test()
async def test_single_tile(dut):
    """1x1x1: full multiply completes correctly with one tile and one K pass."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    dut.m_tiles.value = 1
    dut.n_tiles.value = 1
    dut.k_tiles.value = 1

    # assert go
    dut.go.value = 1
    await RisingEdge(dut.clk)
    await FallingEdge(dut.clk)
    dut.go.value = 0

    assert int(dut.ts_busy.value) == 1, "ts_busy should go high after go"

    # wait for fill_start then complete the fill
    await wait_for(dut, dut.fill_start)
    assert int(dut.k_tile.value)  == 0
    assert int(dut.tile_i.value)  == 0
    assert int(dut.tile_j.value)  == 0
    await do_fill(dut)

    # one K pass (final)
    await do_k_pass(dut, is_final=True)
    await do_tile_done(dut)

    # writeback then ts_done
    await do_writeback_done(dut)

    await wait_for(dut, dut.ts_done)
    assert int(dut.ts_busy.value) == 0, "ts_busy should clear after ts_done"


@cocotb.test()
async def test_k_tile_increments(dut):
    """k_tile increments correctly across K passes and resets for next output tile."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    K = 3
    dut.m_tiles.value = 1
    dut.n_tiles.value = 1
    dut.k_tiles.value = K

    dut.go.value = 1
    await RisingEdge(dut.clk)
    dut.go.value = 0

    for k in range(K):
        await wait_for(dut, dut.fill_start)
        assert int(dut.k_tile.value) == k, f"expected k_tile={k}, got {int(dut.k_tile.value)}"
        await do_fill(dut)
        is_final = (k == K - 1)
        await do_k_pass(dut, is_final=is_final)
        if is_final:
            await do_tile_done(dut)

    await do_writeback_done(dut)
    await wait_for(dut, dut.ts_done)


@cocotb.test()
async def test_tile_j_advances(dut):
    """tile_j increments across output tile columns and resets after n_tiles."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    dut.m_tiles.value = 1
    dut.n_tiles.value = 3
    dut.k_tiles.value = 1

    dut.go.value = 1
    await RisingEdge(dut.clk)
    dut.go.value = 0

    for j in range(3):
        await wait_for(dut, dut.fill_start)
        assert int(dut.tile_j.value) == j, f"expected tile_j={j}, got {int(dut.tile_j.value)}"
        await do_fill(dut)
        await do_k_pass(dut, is_final=True)
        await do_tile_done(dut)
        # ADVANCE pulses writeback_start and fill_start simultaneously for non-last tiles;
        # run writeback in background so the next iteration can catch fill_start.
        if j == 2:
            await do_writeback_done(dut)
        else:
            cocotb.start_soon(do_writeback_done(dut)) # equivalent to spawning a thread/coroutine

    await wait_for(dut, dut.ts_done)


@cocotb.test()
async def test_tile_i_advances(dut):
    """tile_i increments after tile_j wraps, ts_done only fires after all tiles."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    M, N = 2, 2
    dut.m_tiles.value = M
    dut.n_tiles.value = N
    dut.k_tiles.value = 1

    dut.go.value = 1
    await RisingEdge(dut.clk)
    dut.go.value = 0

    for i in range(M):
        for j in range(N):
            await wait_for(dut, dut.fill_start)
            assert int(dut.tile_i.value) == i, f"expected tile_i={i}"
            assert int(dut.tile_j.value) == j, f"expected tile_j={j}"
            await do_fill(dut)
            await do_k_pass(dut, is_final=True)
            await do_tile_done(dut)
            is_last = (i == M - 1 and j == N - 1)
            # same parallel writeback/fill issue as previous test
            # --> run writeback in background for non-last tiles
            if is_last:
                await do_writeback_done(dut)
            else:
                cocotb.start_soon(do_writeback_done(dut))

    await wait_for(dut, dut.ts_done)


@cocotb.test()
async def test_final_pass_only_on_last_k(dut):
    """final_pass is high only on the last K pass, low on all others."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    K = 4
    dut.m_tiles.value = 1
    dut.n_tiles.value = 1
    dut.k_tiles.value = K

    dut.go.value = 1
    await RisingEdge(dut.clk)
    dut.go.value = 0

    for k in range(K):
        await wait_for(dut, dut.fill_start)
        await do_fill(dut)
        await wait_for(dut, dut.start)
        expected_final = 1 if k == K - 1 else 0
        assert int(dut.final_pass.value) == expected_final, \
            f"K pass {k}: expected final_pass={expected_final}, got {int(dut.final_pass.value)}"
        await RisingEdge(dut.clk)
        dut.pass_done.value = 1
        await RisingEdge(dut.clk)
        dut.pass_done.value = 0
        if k == K - 1:
            await do_tile_done(dut)

    await do_writeback_done(dut)
    await wait_for(dut, dut.ts_done)
