import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge


@cocotb.test()
async def test_reset(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

    await RisingEdge(dut.clk)
    assert int(dut.out_partial.value) == 0
    assert int(dut.out_act.value)     == 0
    assert int(dut.weight_out.value)  == 0

def to_signed32(v):
    v = int(v) & 0xFFFFFFFF
    return v if v < (1 << 31) else v - (1 << 32)


@cocotb.test()
async def test_weight_load(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

    dut.weight_load_en.value = 1
    dut.weight_in.value      = 42
    await RisingEdge(dut.clk)
    dut.weight_load_en.value = 0

    await RisingEdge(dut.clk)
    assert int(dut.weight_out.value) == 42


@cocotb.test()
async def test_weight_shift_chain(dut):
    # Simulates two PEs in a column: PE0 captures first value and passes it
    # to PE1 (weight_out), then captures the second value on the next cycle.
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

    dut.weight_load_en.value = 1
    dut.weight_in.value      = 10
    await RisingEdge(dut.clk)   # PE captures 10, weight_out becomes 10
    dut.weight_in.value      = 20
    await RisingEdge(dut.clk)   # PE captures 20, weight_out becomes 20
    dut.weight_load_en.value = 0
    await RisingEdge(dut.clk)   # extra cycle to see value from previous edge

    assert int(dut.weight_out.value) == 20


@cocotb.test()
async def test_mac_basic(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

    dut.weight_load_en.value = 1
    dut.weight_in.value      = 3
    await RisingEdge(dut.clk)
    dut.weight_load_en.value = 0

    dut.in_act.value     = 5
    dut.in_partial.value = 100
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)

    assert to_signed32(dut.out_partial.value) == 115  # 100 + 5*3


@cocotb.test()
async def test_mac_signed(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

    dut.weight_load_en.value = 1
    dut.weight_in.value      = (-4) & 0xFF
    await RisingEdge(dut.clk)
    dut.weight_load_en.value = 0

    dut.in_act.value     = (-7) & 0xFF
    dut.in_partial.value = 10 & 0xFFFFFFFF
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)

    assert to_signed32(dut.out_partial.value) == 38  # 10 + (-7)*(-4)


@cocotb.test()
async def test_act_passthrough(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

    dut.weight_load_en.value = 0
    dut.in_act.value         = 0xAB
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)

    assert int(dut.out_act.value) == 0xAB


@cocotb.test()
async def test_no_compute_during_weight_load(dut):
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

    dut.in_act.value         = 10
    dut.in_partial.value     = 50
    dut.weight_load_en.value = 1
    dut.weight_in.value      = 5
    for _ in range(4):
        await RisingEdge(dut.clk)
        assert int(dut.out_partial.value) == 0, \
            "out_partial should not update while weight_load_en is high"
    dut.weight_load_en.value = 0


@cocotb.test()
async def test_mac_random(dut):
    import random
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())

    dut.rst_n.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1

    rng = random.Random(42)
    for _ in range(200):
        weight = rng.randint(-128, 127)
        act    = rng.randint(-128, 127)
        psum   = rng.randint(-(1 << 30), (1 << 30))

        dut.weight_load_en.value = 1
        dut.weight_in.value      = weight & 0xFF
        await RisingEdge(dut.clk)
        dut.weight_load_en.value = 0

        dut.in_act.value     = act  & 0xFF
        dut.in_partial.value = psum & 0xFFFFFFFF
        await RisingEdge(dut.clk)
        await RisingEdge(dut.clk)

        result   = to_signed32(dut.out_partial.value)
        expected = psum + act * weight
        assert result == expected, \
            f"weight={weight} act={act} psum={psum}: expected {expected}, got {result}"