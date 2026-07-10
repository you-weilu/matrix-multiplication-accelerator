import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge

# Register byte addresses
CTRL    = 0x00
M_TILES = 0x04
N_TILES = 0x08
K_TILES = 0x0C
STATUS  = 0x10

# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

async def reset(dut):
    dut.rst_n.value   = 0
    dut.awaddr.value  = 0
    dut.awprot.value  = 0
    dut.awvalid.value = 0
    dut.wdata.value   = 0
    dut.wstrb.value   = 0
    dut.wvalid.value  = 0
    dut.bready.value  = 0
    dut.araddr.value  = 0
    dut.arprot.value  = 0
    dut.arvalid.value = 0
    dut.rready.value  = 0
    dut.ts_busy.value = 0
    dut.ts_done.value = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    # Two extra cycles so awready/arready are high before any transaction
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)


async def axi_write(dut, addr, data):
    """AXI4-Lite write: present AW and W simultaneously."""
    dut.awaddr.value  = addr
    dut.awvalid.value = 1
    dut.wdata.value   = data
    dut.wstrb.value   = 0xF
    dut.wvalid.value  = 1
    dut.bready.value  = 0

    # Wait until awready is high (from previous WR_IDLE cycle), then handshake
    while not int(dut.awready.value):
        await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)   # handshake edge
    dut.awvalid.value = 0
    dut.wvalid.value  = 0

    # Wait for B response, then accept it
    while not int(dut.bvalid.value):
        await RisingEdge(dut.clk)
    dut.bready.value = 1
    await RisingEdge(dut.clk)   # wr_commit fires this edge
    dut.bready.value = 0
    await RisingEdge(dut.clk)   # settle: WR_IDLE re-asserts awready


async def axi_write_aw_first(dut, addr, data):
    """AXI4-Lite write: AW channel arrives before W."""
    # AW only
    dut.awaddr.value  = addr
    dut.awvalid.value = 1
    dut.wvalid.value  = 0
    dut.bready.value  = 0

    while not int(dut.awready.value):
        await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.awvalid.value = 0

    # W follows (wready is already 1 from WR_IDLE)
    dut.wdata.value  = data
    dut.wstrb.value  = 0xF
    dut.wvalid.value = 1

    while not int(dut.wready.value):
        await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.wvalid.value = 0

    while not int(dut.bvalid.value):
        await RisingEdge(dut.clk)
    dut.bready.value = 1
    await RisingEdge(dut.clk)
    dut.bready.value = 0
    await RisingEdge(dut.clk)


async def axi_write_w_first(dut, addr, data):
    """AXI4-Lite write: W channel arrives before AW."""
    # W only
    dut.wdata.value   = data
    dut.wstrb.value   = 0xF
    dut.wvalid.value  = 1
    dut.awvalid.value = 0
    dut.bready.value  = 0

    while not int(dut.wready.value):
        await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.wvalid.value = 0

    # AW follows (awready is already 1 from WR_IDLE's unconditional set)
    dut.awaddr.value  = addr
    dut.awvalid.value = 1

    while not int(dut.awready.value):
        await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.awvalid.value = 0

    while not int(dut.bvalid.value):
        await RisingEdge(dut.clk)
    dut.bready.value = 1
    await RisingEdge(dut.clk)
    dut.bready.value = 0
    await RisingEdge(dut.clk)


async def axi_read(dut, addr):
    """AXI4-Lite read. Returns the 32-bit register value."""
    dut.araddr.value  = addr
    dut.arvalid.value = 1
    dut.rready.value  = 0

    while not int(dut.arready.value):
        await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)   # AR handshake edge
    dut.arvalid.value = 0

    while not int(dut.rvalid.value):
        await RisingEdge(dut.clk)

    data = int(dut.rdata.value)
    dut.rready.value = 1
    await RisingEdge(dut.clk)   # R handshake edge
    dut.rready.value = 0
    await RisingEdge(dut.clk)   # settle

    return data


# ---------------------------------------------------------------------------
# Tests
# ---------------------------------------------------------------------------

@cocotb.test()
async def test_reset_values(dut):
    """After reset, tile registers are 1, go is 0, status is 0."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    assert int(dut.go.value)      == 0
    assert int(dut.m_tiles.value) == 1
    assert int(dut.n_tiles.value) == 1
    assert int(dut.k_tiles.value) == 1

    assert await axi_read(dut, STATUS) == 0, "STATUS should be 0 after reset"
    assert await axi_read(dut, CTRL)   == 0, "CTRL should be 0 after reset"


@cocotb.test()
async def test_write_read_back(dut):
    """Write M/N/K_TILES and read them back via both ports."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    await axi_write(dut, M_TILES, 4)
    await axi_write(dut, N_TILES, 8)
    await axi_write(dut, K_TILES, 2)

    assert int(dut.m_tiles.value) == 4
    assert int(dut.n_tiles.value) == 8
    assert int(dut.k_tiles.value) == 2

    assert await axi_read(dut, M_TILES) == 4
    assert await axi_read(dut, N_TILES) == 8
    assert await axi_read(dut, K_TILES) == 2


@cocotb.test()
async def test_ctrl_write_zero_no_go(dut):
    """Writing 0 to CTRL[0] must not assert go (W1S: write-0 is a no-op)."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    await axi_write(dut, CTRL, 0)
    assert int(dut.go.value) == 0, "go must not assert when writing 0 to CTRL"


@cocotb.test()
async def test_ctrl_write_one_asserts_go(dut):
    """Writing 1 to CTRL[0] asserts go for exactly one cycle."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    # Drive AW+W manually so we can observe go on the exact commit cycle
    dut.awaddr.value  = CTRL
    dut.awvalid.value = 1
    dut.wdata.value   = 1
    dut.wstrb.value   = 0xF
    dut.wvalid.value  = 1
    dut.bready.value  = 0

    while not int(dut.awready.value):
        await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)   # handshake edge
    dut.awvalid.value = 0
    dut.wvalid.value  = 0

    while not int(dut.bvalid.value):
        await RisingEdge(dut.clk)

    dut.bready.value = 1
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)   # wr_commit fires; go gets set this edge
    assert int(dut.go.value) == 1, "go should be 1 on the commit cycle"
    dut.bready.value = 0

    await RisingEdge(dut.clk)   # default clears go
    assert int(dut.go.value) == 0, "go should auto-clear after one cycle"


@cocotb.test()
async def test_ts_busy_blocks_go(dut):
    """go must not pulse when ts_busy is high."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    dut.ts_busy.value = 1
    await axi_write(dut, CTRL, 1)
    assert int(dut.go.value) == 0, "go should be blocked while ts_busy is high"


@cocotb.test()
async def test_ctrl_reads_busy(dut):
    """CTRL[1] reflects ts_busy live."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    dut.ts_busy.value = 1
    ctrl = await axi_read(dut, CTRL)
    assert ctrl & 0x2, f"CTRL[1] should be 1 when ts_busy is high, got {ctrl:#x}"

    dut.ts_busy.value = 0
    ctrl = await axi_read(dut, CTRL)
    assert not (ctrl & 0x2), f"CTRL[1] should be 0 when ts_busy is low, got {ctrl:#x}"


@cocotb.test()
async def test_ts_done_sets_status(dut):
    """A ts_done pulse should set STATUS[0] and hold it."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    dut.ts_done.value = 1
    await RisingEdge(dut.clk)
    dut.ts_done.value = 0
    await RisingEdge(dut.clk)

    status = await axi_read(dut, STATUS)
    assert status & 1, f"STATUS[0] should be set after ts_done pulse, got {status}"


@cocotb.test()
async def test_go_clears_done(dut):
    """Writing go=1 should clear STATUS[0]."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    dut.ts_done.value = 1
    await RisingEdge(dut.clk)
    dut.ts_done.value = 0
    await RisingEdge(dut.clk)

    assert await axi_read(dut, STATUS) & 1, "STATUS[0] should be set"

    await axi_write(dut, CTRL, 1)
    assert await axi_read(dut, STATUS) == 0, "STATUS[0] should clear after go"


@cocotb.test()
async def test_status_is_read_only(dut):
    """Writes to STATUS should be silently ignored."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    await axi_write(dut, STATUS, 0xFFFFFFFF)
    assert await axi_read(dut, STATUS) == 0, "STATUS is RO — write must have no effect"


@cocotb.test()
async def test_aw_before_w(dut):
    """Write with AW channel arriving before W channel."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    await axi_write_aw_first(dut, M_TILES, 7)
    assert int(dut.m_tiles.value) == 7
    assert await axi_read(dut, M_TILES) == 7


@cocotb.test()
async def test_w_before_aw(dut):
    """Write with W channel arriving before AW channel."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    await axi_write_w_first(dut, N_TILES, 3)
    assert int(dut.n_tiles.value) == 3
    assert await axi_read(dut, N_TILES) == 3
