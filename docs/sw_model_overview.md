# Software Model Overview

This document describes how the Python software model abstracts the RTL design. It allows us to simulate the accelerator before synthesizing hardware.

## Why a software model?

Writing a cycle-accurate Python model before (or alongside) the RTL allows us to:
- Validate the algorithm and data flow quickly
- Catch architectural bugs early (wrong skew, overflow, off-by-one in FSM states)
- Generate golden reference outputs to compare against RTL simulation

## Scope: what is and isn't modeled

The XDMA IP core and PCIe link are Xilinx IP and are not modeled in detail. In the sw model, the host injects tile data directly into the ping-pong buffers (bypassing DMA latency) and reads results directly from the Output Buffer. The Tile Sequencer FSM is modeled to validate the tiling loop logic and buffer-swap sequencing; actual AXI command generation is stubbed.

## One class per hardware module

Each block in the block diagram maps to one Python class in `sw_model/`. The class constructor takes its port signals as arguments, and exposes a `tick()` method that models one clock cycle.

```
sw_model/
  top.py                    # instantiates all modules and wires them together
  xdma.py                   # stub: injects tiles directly into buffers
  axi_interconnect.py       # routes AXI transactions (stub in sw model)
  csr_block.py              # holds dimension/address registers, START, DONE
  weight_buffer.py          # ping-pong pair of 256-byte tile buffers
  activation_buffer.py      # ping-pong pair of 256-byte tile buffers
  systolic_data_setup.py
  systolic_array.py
  accumulator_bank.py
  output_buffer.py          # 1 KB output tile register buffer
  tile_sequencer_fsm.py     # autonomous tiling loop controller
```

## How modules talk to each other: shared Signal objects

We model the connecting wires between modules with small `Signal` objects that hold a single value. The `top.py` module creates these signals and passes them into each module's constructor, similar to port connections in an RTL netlist.

```python
class Signal:
    def __init__(self, val=0):
        self.val = val

# In top.py:
start       = Signal()
m_tiles     = Signal()
k_tiles     = Signal()
n_tiles     = Signal()

csr     = CsrBlock(start=start, m_tiles=m_tiles, ...)
fsm     = TileSequencerFSM(start=start, m_tiles=m_tiles, ...)
```

Both `csr` and `fsm` hold a reference to the same `Signal` object, so when one writes `sig.val`, the other immediately reads the updated value, the same as a shared wire.

For the ping-pong buffers, the active/shadow select is a single `Signal` driven by the FSM and read by both the buffer and the Systolic Data Setup:

```python
ping_pong_sel = Signal()   # 0 = ping active, 1 = pong active

weight_buf = WeightBuffer(sel=ping_pong_sel, ...)
sds        = SystolicDataSetup(weight_sel=ping_pong_sel, ...)
fsm        = TileSequencerFSM(ping_pong_sel=ping_pong_sel, ...)
```

## Clock model: the tick() loop

The top-level simulation loop calls `tick()` on every module in topological dataflow order once per simulated clock cycle:

```python
def tick(self):
    self.csr_block.tick()
    self.tile_sequencer_fsm.tick()
    self.xdma.tick()                    # injects next tile if fetch pending
    self.weight_buffer.tick()
    self.activation_buffer.tick()
    self.systolic_data_setup.tick()
    self.systolic_array.tick()
    self.accumulator_bank.tick()
    self.output_buffer.tick()
```

Each `tick()` reads its input signals, computes new values, and writes its output signals. Because order follows the dataflow graph, a value written by an upstream module is visible to a downstream module within the same cycle, matching synchronous RTL behavior.

The Tile Sequencer FSM is special: because it connects to all blocks (see block diagram), it naturally holds references to every module and can inspect or drive their signals directly.

## Ping-pong buffer implementation

Each ping-pong pair (Weight and Activation) is implemented as two 256-element byte arrays. The `sel` signal from the FSM selects which half is the *active* buffer (read by the SDS) and which is the *shadow* buffer (written by the XDMA stub during fetch). The FSM toggles `sel` at the start of each COMPUTE phase.

```python
class WeightBuffer:
    def __init__(self, sel, ...):
        self._banks = [bytearray(256), bytearray(256)]
        self._sel = sel   # Signal

    @property
    def active(self):
        return self._banks[self._sel.val]

    @property
    def shadow(self):
        return self._banks[1 - self._sel.val]
```
