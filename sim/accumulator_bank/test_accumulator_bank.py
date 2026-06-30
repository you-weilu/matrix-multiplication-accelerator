import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
import random

N = 16

def to_signed32(v):
    v = int(v) & 0xFFFFFFFF
    return v if v < (1 << 31) else v - (1 << 32)

async def reset(dut):
    dut.rst_n.value      = 0
    dut.row_valid.value  = 0
    dut.final_pass.value = 0
    for i in range(N):
        dut.col_in[i].value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

async def feed_tile(dut, rows, final_pass):
    # rows: list of 16 rows, each a list of 16 INT32 partial sums
    dut.final_pass.value = 1 if final_pass else 0
    dut.row_valid.value  = 1
    for row in rows:
        for j in range(N):
            dut.col_in[j].value = row[j] & 0xFFFFFFFF
        await RisingEdge(dut.clk)
    dut.row_valid.value  = 0
    dut.final_pass.value = 0


@cocotb.test()
async def test_reset(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)
    await RisingEdge(dut.clk)
    assert int(dut.buf_wen.value)   == 0
    assert int(dut.tile_done.value) == 0


@cocotb.test()
async def test_no_write_intermediate_pass(dut):
    """On intermediate passes buf_wen should never go high."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    rows = [[100] * N for _ in range(N)]
    await feed_tile(dut, rows, final_pass=False)

    # run a few extra cycles and check buf_wen stays low
    for _ in range(4):
        await RisingEdge(dut.clk)
        assert int(dut.buf_wen.value) == 0, "buf_wen should not go high on intermediate pass"


@cocotb.test()
async def test_single_tile_writeback(dut):
    """Final pass: after 16 rows accumulated, writeback drives correct data."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    # build a known tile: row i, col j = i*16 + j
    rows = [[i * N + j for j in range(N)] for i in range(N)]
    await feed_tile(dut, rows, final_pass=True)

    # wait for writeback to start (registered outputs have one cycle delay)
    await RisingEdge(dut.clk)

    for i in range(N):
        await RisingEdge(dut.clk)
        assert int(dut.buf_wen.value) == 1, f"buf_wen should be high during writeback row {i}"
        assert int(dut.buf_row.value) == i, f"buf_row should be {i}"
        for j in range(N):
            result   = to_signed32(dut.buf_data[j].value)
            expected = rows[i][j]
            assert result == expected, f"row {i} col {j}: expected {expected}, got {result}"

    assert int(dut.tile_done.value) == 1
    await RisingEdge(dut.clk)
    assert int(dut.tile_done.value) == 0  # pulse only one cycle


@cocotb.test()
async def test_accumulation_across_passes(dut):
    """Two K-tile passes: second pass accumulates on top of first."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    rng = random.Random(42)
    pass1 = [[rng.randint(-1000, 1000) for _ in range(N)] for _ in range(N)]
    pass2 = [[rng.randint(-1000, 1000) for _ in range(N)] for _ in range(N)]
    expected = [[pass1[i][j] + pass2[i][j] for j in range(N)] for i in range(N)]

    await feed_tile(dut, pass1, final_pass=False)
    await feed_tile(dut, pass2, final_pass=True)

    # wait for writeback
    await RisingEdge(dut.clk)

    for i in range(N):
        await RisingEdge(dut.clk)
        for j in range(N):
            result = to_signed32(dut.buf_data[j].value)
            assert result == expected[i][j], \
                f"row {i} col {j}: expected {expected[i][j]}, got {result}"


@cocotb.test()
async def test_accumulators_clear_after_tile(dut):
    """After a final pass, accumulators clear so next tile starts from zero."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    rows = [[500] * N for _ in range(N)]

    # first tile
    await feed_tile(dut, rows, final_pass=True)
    # wait for writeback to complete (16 write cycles + 1 delay + 1 tile_done)
    for _ in range(N + 3):
        await RisingEdge(dut.clk)

    # second tile with same data — if accumulators cleared, result should equal rows not 2x
    await feed_tile(dut, rows, final_pass=True)
    await RisingEdge(dut.clk)

    for i in range(N):
        await RisingEdge(dut.clk)
        for j in range(N):
            result = to_signed32(dut.buf_data[j].value)
            assert result == 500, \
                f"row {i} col {j}: expected 500 (accumulators cleared), got {result}"
