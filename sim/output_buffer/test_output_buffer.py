import cocotb
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge
import random

N = 16  # tile dimension (16x16)


def to_signed32(v):
    v = int(v) & 0xFFFFFFFF
    return v if v < (1 << 31) else v - (1 << 32)


def extract_col(rdata_val, col_in_beat):
    """Extract a 32-bit INT32 from a 128-bit beat. col_in_beat is 0..3."""
    return to_signed32(rdata_val >> (32 * col_in_beat))


def beats_to_tile(beats):
    """Decode 64 rdata beats into a 16x16 tile. Layout:
       beat b → row b//4, columns (b%4)*4 .. (b%4)*4+3
       within beat: bits[31:0]=col+0, [63:32]=col+1, [95:64]=col+2, [127:96]=col+3
    """
    tile = [[0] * N for _ in range(N)]
    for b, val in enumerate(beats):
        row         = b // 4
        col_base    = (b % 4) * 4
        for k in range(4):
            tile[row][col_base + k] = extract_col(val, k)
    return tile


async def reset(dut):
    dut.rst_n.value   = 0
    dut.buf_wen.value = 0
    dut.buf_row.value = 0
    for j in range(N):
        dut.buf_data[j].value = 0
    dut.arvalid.value = 0
    dut.arid.value    = 0
    dut.araddr.value  = 0
    dut.arlen.value   = 0
    dut.arsize.value  = 0
    dut.arburst.value = 0
    dut.rready.value  = 0
    await RisingEdge(dut.clk)
    await RisingEdge(dut.clk)
    dut.rst_n.value = 1
    await RisingEdge(dut.clk)


async def write_tile(dut, tile):
    """Write 16 rows to the output buffer, one row per cycle."""
    for i in range(N):
        dut.buf_wen.value = 1
        dut.buf_row.value = i
        for j in range(N):
            dut.buf_data[j].value = tile[i][j] & 0xFFFFFFFF
        await RisingEdge(dut.clk)
    dut.buf_wen.value = 0


async def axi_burst_read(dut, base_addr=0):
    """Issue a 64-beat AXI4 burst read. Returns list of 64 rdata ints."""
    dut.arvalid.value = 1
    dut.araddr.value  = base_addr
    dut.arlen.value   = 63        # 64 beats
    dut.arsize.value  = 4         # 2^4 = 16 bytes per beat
    dut.arburst.value = 1         # INCR
    dut.arid.value    = 0
    dut.rready.value  = 1

    # Wait for AR handshake (arvalid && arready both high)
    while True:
        await RisingEdge(dut.clk)
        if int(dut.arvalid.value) and int(dut.arready.value):
            break
    dut.arvalid.value = 0

    # Collect beats until rlast
    beats = []
    while True:
        await RisingEdge(dut.clk)
        if int(dut.rvalid.value):
            beats.append(int(dut.rdata.value))
            if int(dut.rlast.value):
                break

    dut.rready.value = 0
    return beats


@cocotb.test()
async def test_reset(dut):
    """rvalid is deasserted immediately after reset."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)
    assert int(dut.rvalid.value) == 0


@cocotb.test()
async def test_write_read_basic(dut):
    """Write tile[i][j] = i*16+j, burst read back, verify all 256 values."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    tile = [[i * N + j for j in range(N)] for i in range(N)]
    await write_tile(dut, tile)

    beats = await axi_burst_read(dut)
    assert len(beats) == 64, f"expected 64 beats, got {len(beats)}"

    result = beats_to_tile(beats)
    for i in range(N):
        for j in range(N):
            assert result[i][j] == tile[i][j], \
                f"row {i} col {j}: expected {tile[i][j]}, got {result[i][j]}"


@cocotb.test()
async def test_write_read_signed(dut):
    """Negative INT32 values survive the write→read round trip."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    rng  = random.Random(42)
    tile = [[rng.randint(-(1 << 31), (1 << 31) - 1) for _ in range(N)] for _ in range(N)]
    await write_tile(dut, tile)

    beats  = await axi_burst_read(dut)
    result = beats_to_tile(beats)

    for i in range(N):
        for j in range(N):
            assert result[i][j] == tile[i][j], \
                f"row {i} col {j}: expected {tile[i][j]}, got {result[i][j]}"


@cocotb.test()
async def test_rlast_on_beat_63(dut):
    """rlast is low on beats 0-62 and high exactly on beat 63."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    await write_tile(dut, [[0] * N for _ in range(N)])

    dut.arvalid.value = 1
    dut.araddr.value  = 0
    dut.arlen.value   = 63
    dut.arsize.value  = 4
    dut.arburst.value = 1
    dut.arid.value    = 0
    dut.rready.value  = 1

    while True:
        await RisingEdge(dut.clk)
        if int(dut.arvalid.value) and int(dut.arready.value):
            break
    dut.arvalid.value = 0

    beat_num = 0
    while True:
        await RisingEdge(dut.clk)
        if int(dut.rvalid.value):
            if beat_num < 63:
                assert int(dut.rlast.value) == 0, \
                    f"rlast went high early on beat {beat_num}"
            else:
                assert int(dut.rlast.value) == 1, \
                    "rlast should be high on beat 63"
                break
            beat_num += 1

    dut.rready.value = 0


@cocotb.test()
async def test_rvalid_deasserts_after_burst(dut):
    """rvalid goes low the cycle after rlast."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    await write_tile(dut, [[0] * N for _ in range(N)])
    await axi_burst_read(dut)

    await RisingEdge(dut.clk)
    assert int(dut.rvalid.value) == 0, "rvalid should be low after burst completes"


@cocotb.test()
async def test_overwrite(dut):
    """Writing a row twice — second write wins when read back."""
    cocotb.start_soon(Clock(dut.clk, 10, unit="ns").start())
    await reset(dut)

    tile_a = [[0]         * N for _ in range(N)]
    tile_b = [[i * N + j + 100 for j in range(N)] for i in range(N)]

    await write_tile(dut, tile_a)
    await write_tile(dut, tile_b)

    beats  = await axi_burst_read(dut)
    result = beats_to_tile(beats)

    for i in range(N):
        for j in range(N):
            assert result[i][j] == tile_b[i][j], \
                f"row {i} col {j}: expected {tile_b[i][j]}, got {result[i][j]}"
