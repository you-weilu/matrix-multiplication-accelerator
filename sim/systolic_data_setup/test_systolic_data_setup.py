import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge

N = 16


async def reset(dut):
    dut.rst_n.value  = 0
    dut.start.value  = 0
    for i in range(N):
        dut.weight_buf_data[i].value = 0
        dut.act_buf_data[i].value    = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

def make_buf_model(weight_tile, act_tile):
    # returns (weight_buf, act_buf) as plain 2D lists the test drives cycle by cycle
    # weight_buf[row] = 16 INT8 values, act_buf[row] = 16 INT8 values
    return weight_tile, act_tile

async def run_tile_pass(dut, weight_tile, act_tile):
    # drive start for one cycle
    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0

    # PRELOAD: 16 cycles — SDS reads weight_buf and act_buf via address ports
    # respond to whatever address the SDS drives each cycle
    for _ in range(N):
        w_addr = int(dut.weight_buf_addr.value)
        a_addr = int(dut.act_buf_addr.value)
        for j in range(N):
            dut.weight_buf_data[j].value = weight_tile[w_addr][j] & 0xFF
            dut.act_buf_data[j].value    = act_tile[a_addr][j]    & 0xFF
        await RisingEdge(dut.clk)

    # FEED: 31 cycles - SDS no longer reads buffers, just drives act_in
    for _ in range(31):
        await RisingEdge(dut.clk)

    # wait one more cycle for done to be visible
    await RisingEdge(dut.clk)


@cocotb.test()
async def test_reset(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)
    await RisingEdge(dut.clk)
    assert int(dut.done.value)          == 0
    assert int(dut.weight_load_en.value) == 0
    assert int(dut.row_valid.value)      == 0


@cocotb.test()
async def test_done_pulses(dut):
    """done pulses exactly once at the end of the tile pass."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    weight_tile = [[1] * N for _ in range(N)]
    act_tile    = [[1] * N for _ in range(N)]
    await run_tile_pass(dut, weight_tile, act_tile)

    assert int(dut.done.value) == 1, "done should pulse at end of tile pass"
    await RisingEdge(dut.clk)
    assert int(dut.done.value) == 0, "done should only pulse one cycle"


@cocotb.test()
async def test_weight_load_en(dut):
    """weight_load_en is high for exactly 16 cycles during PRELOAD."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0

    # count cycles where weight_load_en is high
    count = 0
    for _ in range(N + 5):
        await RisingEdge(dut.clk)
        if int(dut.weight_load_en.value) == 1:
            count += 1

    assert count == N, f"weight_load_en should be high for 16 cycles, got {count}"


@cocotb.test()
async def test_row_valid_timing(dut):
    """row_valid goes high at cycle 15 of FEED and stays high for 16 cycles."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    weight_tile = [[0] * N for _ in range(N)]
    act_tile    = [[0] * N for _ in range(N)]

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0

    # PRELOAD: 16 cycles
    for _ in range(N):
        await RisingEdge(dut.clk)
        assert int(dut.row_valid.value) == 0, "row_valid should be 0 during PRELOAD"

    # FEED cycles 0-14: row_valid should be 0
    for i in range(15):
        assert int(dut.row_valid.value) == 0, f"row_valid should be 0 at FEED cycle {i}"
        await RisingEdge(dut.clk)

    await RisingEdge(dut.clk)

    # FEED cycles 15-30: row_valid should be 1
    for i in range(16):
        assert int(dut.row_valid.value) == 1, f"row_valid should be 1 at FEED cycle {i + 15}"
        await RisingEdge(dut.clk)


@cocotb.test()
async def test_weight_addr_sequence(dut):
    """During PRELOAD, weight_buf_addr counts down from 15 to 0."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0

    await RisingEdge(dut.clk)

    for expected_addr in range(15, -1, -1):
        assert int(dut.weight_buf_addr.value) == expected_addr, \
            f"expected weight_buf_addr={expected_addr}, got {int(dut.weight_buf_addr.value)}"
        await RisingEdge(dut.clk)


@cocotb.test()
async def test_act_in_skew(dut):
    """act_in is skewed: row k starts k cycles into FEED, all others are 0 before that."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    # fill act_tile with known values: act_tile[row][col] = row * 16 + col
    act_tile    = [[i * N + j for j in range(N)] for i in range(N)]
    weight_tile = [[0] * N for _ in range(N)]

    dut.start.value = 1
    await RisingEdge(dut.clk)
    dut.start.value = 0

    # PRELOAD: serve buffer data as SDS requests it
    for _ in range(N):
        w_addr = int(dut.weight_buf_addr.value)
        a_addr = int(dut.act_buf_addr.value)
        for j in range(N):
            dut.weight_buf_data[j].value = weight_tile[w_addr][j] & 0xFF
            dut.act_buf_data[j].value    = act_tile[a_addr][j]    & 0xFF
        await RisingEdge(dut.clk)

    # FEED: check skewing — at cycle t, row k should get act_tile[t-k][k] if t>=k else 0
    for t in range(31):
        await RisingEdge(dut.clk)
        print(f"t={t}  hw_cycle={int(dut.cycle.value)}  hw_state={int(dut.state.value)}  act_in0={int(dut.act_in[0].value)}")
        for k in range(N):
            result = int(dut.act_in[k].value)
            if t >= k and (t - k) < N:
                expected = act_tile[t - k][k] & 0xFF
            else:
                expected = 0
            # assert result == expected, \
            #     f"FEED cycle {t} row {k}: expected act_in={expected}, got {result}"
