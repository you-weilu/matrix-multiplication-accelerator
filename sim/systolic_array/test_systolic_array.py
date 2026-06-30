import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
import sys, os, random

sys.path.insert(0, os.path.join(os.path.dirname(__file__), '../../sw_model'))
from systolic_array import SystolicArray

N = 16

def to_signed8(v):
    v = int(v) & 0xFF
    return v if v < 128 else v - 256

def to_signed32(v):
    v = int(v) & 0xFFFFFFFF
    return v if v < (1 << 31) else v - (1 << 32)

async def reset(dut):
    dut.rst_n.value          = 0
    dut.weight_load_en.value = 0
    for i in range(N):
        dut.weight_in[i].value = 0
        dut.act_in[i].value    = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

async def load_weights(dut, ref, rows):
    # ref: reference sw model
    # rows: list of 16 rows, each a list of 16 INT8 values
    # feed in reverse order (row 15 first) so PE[i][j] ends up with rows[i][j]
    dut.weight_load_en.value = 1
    for row in reversed(rows):
        for j in range(N):
            dut.weight_in[j].value = row[j] & 0xFF
        ref.shift_weights(row)
        await RisingEdge(dut.clk)
    dut.weight_load_en.value = 0


@cocotb.test()
async def test_reset(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)
    await RisingEdge(dut.clk)
    for j in range(N):
        assert int(dut.col_out[j].value) == 0


@cocotb.test()
async def test_all_ones(dut):
    """All weights=1, all activations=1. After 16 compute cycles col_out[j]=16."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    ref = SystolicArray()
    await reset(dut)

    ones = [[1] * N for _ in range(N)]
    await load_weights(dut, ref, ones)

    for i in range(N):
        dut.act_in[i].value = 1

    # run 16 compute cycles so the partial sums ripple through all rows
    for _ in range(N):
        ref.step([1] * N)
        await RisingEdge(dut.clk)

    await RisingEdge(dut.clk)  # extra cycle to read registered outputs

    for j in range(N):
        result   = to_signed32(dut.col_out[j].value)
        expected = ref.col_out[j]
        assert result == expected, f"col_out[{j}]: expected {expected}, got {result}"


@cocotb.test()
async def test_sw_model(dut):
    """Random weights and activations compared against the Python sw model."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    ref = SystolicArray()
    await reset(dut)

    rng = random.Random(0)

    weights = [[rng.randint(-128, 127) for _ in range(N)] for _ in range(N)]
    await load_weights(dut, ref, weights)

    # feed 31 cycles of random activations in lock-step with sw model
    for acts in [[rng.randint(-128, 127) for _ in range(N)] for _ in range(31)]:
        for i in range(N):
            dut.act_in[i].value = acts[i] & 0xFF
        ref.step(acts)
        await RisingEdge(dut.clk)

    # one extra cycle so col_out reflects the last compute edge
    await RisingEdge(dut.clk)

    for j in range(N):
        result   = to_signed32(dut.col_out[j].value)
        expected = ref.col_out[j]
        assert result == expected, \
            f"col_out[{j}]: expected {expected}, got {result}"
