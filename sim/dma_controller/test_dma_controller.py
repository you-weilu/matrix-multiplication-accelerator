import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge

# XDMA AXI4-Lite register offsets for the Run bit
XDMA_H2C_CH0_CTRL = 0x0000_0004
XDMA_H2C_CH1_CTRL = 0x0000_1004
XDMA_C2H_CH0_CTRL = 0x0001_0004


async def reset(dut):
    dut.rst_n.value              = 0
    dut.fill_start.value         = 0
    dut.writeback_start.value    = 0
    dut.tile_i.value             = 0
    dut.tile_j.value             = 0
    dut.k_tile.value             = 0
    dut.base_addr_a.value        = 0
    dut.base_addr_b.value        = 0
    dut.base_addr_c.value        = 0
    dut.k_tiles.value            = 1
    dut.n_tiles.value            = 1
    dut.pp_weight_axi_base.value = 0x0000_1000
    dut.pp_act_axi_base.value    = 0x0000_2000
    dut.output_buf_axi_base.value= 0x0000_3000
    # AXI4-Lite slave side (testbench drives these)
    dut.axil_awready.value       = 0
    dut.axil_wready.value        = 0
    dut.axil_bvalid.value        = 0
    dut.axil_bresp.value         = 0
    dut.axil_arready.value       = 0
    dut.axil_rvalid.value        = 0
    dut.axil_rdata.value         = 0
    dut.axil_rresp.value         = 0
    # Descriptor bypass handshake
    dut.h2c_dsc_byp_ready_0.value = 0
    dut.h2c_dsc_byp_ready_1.value = 0
    dut.c2h_dsc_byp_ready_0.value = 0
    # XDMA status (bit 3 pulses on descriptor done)
    dut.h2c_sts_0.value = 0
    dut.h2c_sts_1.value = 0
    dut.c2h_sts_0.value = 0

    for _ in range(4):
        await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)


async def axil_slave_respond(dut):
    """Accept one AW+W transaction and reply with OKAY bresp.
    Returns the write address so the caller can check it."""
    # Wait for AW
    while True:
        await RisingEdge(dut.clk)
        if dut.axil_awvalid.value:
            break
    addr = int(dut.axil_awaddr.value)
    dut.axil_awready.value = 1
    await RisingEdge(dut.clk)
    dut.axil_awready.value = 0

    # Wait for W
    while True:
        await RisingEdge(dut.clk)
        if dut.axil_wvalid.value:
            break
    data = int(dut.axil_wdata.value)
    dut.axil_wready.value = 1
    await RisingEdge(dut.clk)
    dut.axil_wready.value = 0

    # B response
    dut.axil_bvalid.value = 1
    dut.axil_bresp.value  = 0
    while True:
        await RisingEdge(dut.clk)
        if dut.axil_bready.value:
            break
    await RisingEdge(dut.clk)  # hold bvalid through the handshake edge (bready is registered)
    dut.axil_bvalid.value = 0

    return addr, data


async def complete_init(dut):
    """Service the 3 AXI-Lite writes the init FSM issues at startup.
    Returns list of (addr, data) in order."""
    writes = []
    for _ in range(3):
        addr, data = await axil_slave_respond(dut)
        writes.append((addr, data))
    return writes


# ---------------------------------------------------------------------------
# Tests
# ---------------------------------------------------------------------------

@cocotb.test()
async def test_init_sequence(dut):
    """After reset the DMA controller writes Run=1 to H2C ch0, H2C ch1, C2H ch0
    via AXI4-Lite in that order, then asserts init_done."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    assert dut.init_done.value == 0, "init_done should be 0 immediately after reset"

    writes = await complete_init(dut)

    assert writes[0][0] == XDMA_H2C_CH0_CTRL, \
        f"first write addr: expected {XDMA_H2C_CH0_CTRL:#010x}, got {writes[0][0]:#010x}"
    assert writes[1][0] == XDMA_H2C_CH1_CTRL, \
        f"second write addr: expected {XDMA_H2C_CH1_CTRL:#010x}, got {writes[1][0]:#010x}"
    assert writes[2][0] == XDMA_C2H_CH0_CTRL, \
        f"third write addr: expected {XDMA_C2H_CH0_CTRL:#010x}, got {writes[2][0]:#010x}"
    for i, (_, data) in enumerate(writes):
        assert data == 1, f"write {i}: expected Run=1 (data=1), got {data}"

    # init_done should be combinatorially high after the last B handshake
    await RisingEdge(dut.clk)
    assert dut.init_done.value == 1, "init_done should be 1 after all three Run writes"


@cocotb.test()
async def test_fill_descriptor_fields(dut):
    """On fill_start the DMA controller asserts load on both H2C channels with
    correct src_addr, dst_addr, len=256, ctl=0x0003."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)
    await complete_init(dut)
    await RisingEdge(dut.clk)  # let init_done settle

    BASE_A    = 0x0000_AAAA_0000
    BASE_B    = 0x0000_BBBB_0000
    TI, TJ, TK = 2, 3, 1
    K_TILES   = 4

    dut.base_addr_a.value = BASE_A
    dut.base_addr_b.value = BASE_B
    dut.k_tiles.value     = K_TILES
    dut.tile_i.value      = TI
    dut.tile_j.value      = TJ
    dut.k_tile.value      = TK

    # Assert fill_start for one cycle
    dut.fill_start.value          = 1
    dut.h2c_dsc_byp_ready_0.value = 1
    dut.h2c_dsc_byp_ready_1.value = 1
    await RisingEdge(dut.clk)
    dut.fill_start.value = 0

    # Wait for both load pulses (they may come the same cycle since ready was pre-asserted)
    load0_seen = False
    load1_seen = False
    src0 = dst0 = len0 = ctl0 = 0
    src1 = dst1 = len1 = ctl1 = 0

    for _ in range(10):
        await RisingEdge(dut.clk)
        if dut.h2c_dsc_byp_load_0.value and not load0_seen:
            load0_seen = True
            src0 = int(dut.h2c_dsc_byp_src_addr_0.value)
            dst0 = int(dut.h2c_dsc_byp_dst_addr_0.value)
            len0 = int(dut.h2c_dsc_byp_len_0.value)
            ctl0 = int(dut.h2c_dsc_byp_ctl_0.value)
        if dut.h2c_dsc_byp_load_1.value and not load1_seen:
            load1_seen = True
            src1 = int(dut.h2c_dsc_byp_src_addr_1.value)
            dst1 = int(dut.h2c_dsc_byp_dst_addr_1.value)
            len1 = int(dut.h2c_dsc_byp_len_1.value)
            ctl1 = int(dut.h2c_dsc_byp_ctl_1.value)
        if load0_seen and load1_seen:
            break

    assert load0_seen, "h2c_dsc_byp_load_0 never pulsed"
    assert load1_seen, "h2c_dsc_byp_load_1 never pulsed"

    # Expected addresses
    # Weight (B): src = BASE_B + (tile_j * k_tiles + k_tile) * 256
    exp_src0 = BASE_B + (TJ * K_TILES + TK) * 256
    # Act (A):    src = BASE_A + (tile_i * k_tiles + k_tile) * 256
    exp_src1 = BASE_A + (TI * K_TILES + TK) * 256

    assert src0 == exp_src0, f"H2C ch0 src_addr: expected {exp_src0:#018x}, got {src0:#018x}"
    assert dst0 == 0x0000_1000, f"H2C ch0 dst_addr: expected pp_weight_axi_base, got {dst0:#018x}"
    assert len0 == 256, f"H2C ch0 len: expected 256, got {len0}"
    assert ctl0 == 0x0003, f"H2C ch0 ctl: expected 0x0003, got {ctl0:#06x}"

    assert src1 == exp_src1, f"H2C ch1 src_addr: expected {exp_src1:#018x}, got {src1:#018x}"
    assert dst1 == 0x0000_2000, f"H2C ch1 dst_addr: expected pp_act_axi_base, got {dst1:#018x}"
    assert len1 == 256, f"H2C ch1 len: expected 256, got {len1}"
    assert ctl1 == 0x0003, f"H2C ch1 ctl: expected 0x0003, got {ctl1:#06x}"


@cocotb.test()
async def test_writeback_descriptor_fields(dut):
    """On writeback_start the DMA controller loads C2H ch0 with correct
    src_addr=output_buf_axi_base, dst_addr in matrix C, len=1024, ctl=0x0003."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)
    await complete_init(dut)
    await RisingEdge(dut.clk)

    BASE_C  = 0x0000_CCCC_0000
    TI, TJ  = 3, 2
    N_TILES = 5

    dut.base_addr_c.value         = BASE_C
    dut.n_tiles.value             = N_TILES
    dut.tile_i.value              = TI
    dut.tile_j.value              = TJ
    dut.c2h_dsc_byp_ready_0.value = 1

    dut.writeback_start.value = 1
    await RisingEdge(dut.clk)
    dut.writeback_start.value = 0

    load_seen = False
    src0 = dst0 = len0 = ctl0 = 0
    for _ in range(10):
        await RisingEdge(dut.clk)
        if dut.c2h_dsc_byp_load_0.value and not load_seen:
            load_seen = True
            src0 = int(dut.c2h_dsc_byp_src_addr_0.value)
            dst0 = int(dut.c2h_dsc_byp_dst_addr_0.value)
            len0 = int(dut.c2h_dsc_byp_len_0.value)
            ctl0 = int(dut.c2h_dsc_byp_ctl_0.value)
            break

    assert load_seen, "c2h_dsc_byp_load_0 never pulsed"

    exp_dst = BASE_C + (TI * N_TILES + TJ) * 1024

    assert src0 == 0x0000_3000, f"C2H src_addr: expected output_buf_axi_base, got {src0:#018x}"
    assert dst0 == exp_dst,     f"C2H dst_addr: expected {exp_dst:#018x}, got {dst0:#018x}"
    assert len0 == 1024,        f"C2H len: expected 1024, got {len0}"
    assert ctl0 == 0x0003,      f"C2H ctl: expected 0x0003, got {ctl0:#06x}"


@cocotb.test()
async def test_writeback_done_pulses(dut):
    """writeback_done pulses for exactly one cycle after c2h_sts_0[3] fires."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)
    await complete_init(dut)
    await RisingEdge(dut.clk)

    dut.c2h_dsc_byp_ready_0.value = 1
    dut.writeback_start.value     = 1
    await RisingEdge(dut.clk)
    dut.writeback_start.value = 0

    # Wait for load pulse
    for _ in range(10):
        await RisingEdge(dut.clk)
        if dut.c2h_dsc_byp_load_0.value:
            break

    # Simulate XDMA done: pulse c2h_sts_0[3]
    await RisingEdge(dut.clk)
    dut.c2h_sts_0.value = 0b0000_1000  # bit 3
    await RisingEdge(dut.clk)
    await FallingEdge(dut.clk)
    dut.c2h_sts_0.value = 0

    assert dut.writeback_done.value == 1, "writeback_done should be high the cycle sts fires"
    await RisingEdge(dut.clk)
    await FallingEdge(dut.clk)
    assert dut.writeback_done.value == 0, "writeback_done should deassert after one cycle"


@cocotb.test()
async def test_fill_waits_for_both_channels(dut):
    """H2C ch0 and ch1 FSMs are independent: staggering ready signals works."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)
    await complete_init(dut)
    await RisingEdge(dut.clk)

    # Only ch1 ready initially
    dut.h2c_dsc_byp_ready_0.value = 0
    dut.h2c_dsc_byp_ready_1.value = 1
    dut.fill_start.value           = 1
    await RisingEdge(dut.clk)
    dut.fill_start.value = 0

    # ch1 should load quickly, ch0 should not yet
    load1_seen = False
    for _ in range(5):
        await RisingEdge(dut.clk)
        if dut.h2c_dsc_byp_load_1.value:
            load1_seen = True
        assert dut.h2c_dsc_byp_load_0.value == 0, \
            "ch0 should not load while ready_0 is deasserted"

    assert load1_seen, "ch1 should have loaded while ready_1 was asserted"

    # Now raise ready_0
    dut.h2c_dsc_byp_ready_0.value = 1
    load0_seen = False
    for _ in range(5):
        await RisingEdge(dut.clk)
        if dut.h2c_dsc_byp_load_0.value:
            load0_seen = True
            break

    assert load0_seen, "ch0 should load once ready_0 is asserted"


@cocotb.test()
async def test_back_to_back_fills(dut):
    """A second fill_start after sts fires triggers a new descriptor push."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)
    await complete_init(dut)
    await RisingEdge(dut.clk)

    dut.h2c_dsc_byp_ready_0.value = 1
    dut.h2c_dsc_byp_ready_1.value = 1

    for fill_num in range(2):
        dut.fill_start.value = 1
        await RisingEdge(dut.clk)
        dut.fill_start.value = 0

        # Wait for both loads
        load0 = load1 = False
        for _ in range(10):
            await RisingEdge(dut.clk)
            if dut.h2c_dsc_byp_load_0.value:
                load0 = True
            if dut.h2c_dsc_byp_load_1.value:
                load1 = True
            if load0 and load1:
                break
        assert load0 and load1, f"fill {fill_num}: both channels must load"

        # Complete both channels via sts
        await RisingEdge(dut.clk)
        dut.h2c_sts_0.value = 0b0000_1000
        dut.h2c_sts_1.value = 0b0000_1000
        await RisingEdge(dut.clk)
        dut.h2c_sts_0.value = 0
        dut.h2c_sts_1.value = 0
        await RisingEdge(dut.clk)
