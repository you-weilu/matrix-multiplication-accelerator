# Software Model Overview

This document describes how the Python software model abstracts the RTL design. It allows us to simulate the accelerator before synthesizing hardware.

## Why a software model?

Writing a cycle-accurate Python model before (or alongside) the RTL allows us to:
- Validate the algorithm and data flow quickly
- Catch architectural bugs early (wrong skew, overflow, off-by-one in FSM states)
- Generate golden reference outputs to compare against RTL simulation

## One class per hardware module

Each block in the block diagram maps to one Python class in `sw_model/`. The class constructor takes its port signals as arguments (see below), and exposes a `tick()` method that models one clock cycle.

```
sw_model/
  top.py    # instantiates all modules and wires them together
  ethernet_mac.py
  rx_fifo.py
  tx_fifo.py
  parser.py
  weight_bram.py
  activation_bram.py
  systolic_data_setup.py
  systolic_array.py
  accumulator_bank.py
  output_bram.py
  control_fsm.py
```

## How modules talk to each other: shared Signal objects

We model the connecting wires between modules with small `Signal` objects that hold a single value. The `top.py` module creates these signals and passes them into each module's constructor, similar to port connections in an RTL netlist.

```python
class Signal:
    def __init__(self, val=0):
        self.val = val

# In top.py:
rx_tdata  = Signal()
rx_tvalid = Signal()
rx_tready = Signal()

mac     = EthernetMAC(..., out_data=rx_tdata, out_valid=rx_tvalid, in_ready=rx_tready)
rx_fifo = RxFifo(in_data=rx_tdata, in_valid=rx_tvalid, out_ready=rx_tready, ...)
```

Both `mac` and `rx_fifo` hold a reference to the same `Signal` object, so when one writes `sig.val`, the other immediately reads the updated value — same as a shared wire.

For AXI-Stream buses (which appear on the FIFO↔MAC interfaces), the three signals `tdata`, `tvalid`, and `tready` are bundled into a small struct to reduce the number of arguments:

```python
class AXIStream:
    tdata:  Signal
    tvalid: Signal
    tready: Signal
```

## Clock model: the tick() loop

The top-level simulation loop calls `tick()` on every module in topological dataflow order once per simulated clock cycle:

```python
def tick(self):
    self.mac.tick()
    self.rx_fifo.tick()
    self.parser.tick()
    self.weight_bram.tick()
    self.activation_bram.tick()
    self.systolic_data_setup.tick()
    self.systolic_array.tick()
    self.accumulator_bank.tick()
    self.output_bram.tick()
    self.control_fsm.tick()
```

Each `tick()` reads its input signals, computes new values, and writes its output signals. Because order follows the dataflow graph, a value written by an upstream module is visible to a downstream module within the same cycle, matching synchronous RTL behavior.

The Control FSM is special: because it connects to all blocks (see block diagram), it naturally holds references to every module and can inspect or drive their signals directly.

## FIFO implementation: collections.deque

Both `RxFifo` and `TxFifo` use `collections.deque` as their internal buffer. This gives O(1) enqueue and dequeue, and we set an explicit depth to model the real FIFO capacity.

The FIFO class exposes `full` and `empty` properties and drives `tvalid`/`tready` accordingly, matching the AXI-Stream handshake:

```python
class RxFifo:
    DEPTH = 512

    def __init__(self, ...):
        self._buf = deque()

    def full(self):
        return len(self._buf) >= self.DEPTH

    def empty(self):
        return len(self._buf) == 0

    def tick(self):
        if self.in_valid.val and not self.full:
            self._buf.append(self.in_data.val)
        self.out_valid.val = not self.empty
        if not self.empty and self.out_ready.val:
            self.out_data.val = self._buf.popleft()
        self.in_ready.val = not self.full
```