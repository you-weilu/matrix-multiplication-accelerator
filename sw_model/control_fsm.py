# Control FSM
# Sequences WAIT_LOAD → COMPUTE → DRAIN → WAIT_LOAD.
#
# DRAIN exists because DataSetup only feeds for 31 cycles, but the last partial
# sums don't exit the bottom of the array until cycle 45. Those 15 tail cycles
# require the FSM to keep clocking the array with zero activations.

from .signal import Signal
from .parser import Parser

class ControlFsm:
    TILE_SIZE     = 16
    _DRAIN_CYCLES = TILE_SIZE - 1  # 15 tail cycles after DataSetup.done

    def __init__(self, parser, data_setup, array, rst):
        self.parser     = parser
        self.data_setup = data_setup
        self.array      = array
        self.rst        = rst

        self.state        = 'WAIT_LOAD'
        self.weight_rows  = 0
        self.act_rows     = 0
        self._drain_cycle = 0

    def reset(self):
        self.state                = 'WAIT_LOAD'
        self.weight_rows          = 0
        self.act_rows             = 0
        self._drain_cycle         = 0
        self.data_setup.start.val = 0

    def tick(self):
        if self.rst.val:
            self.reset()
            return

        if self.state == 'WAIT_LOAD':
            if self.parser.write_signal.val:
                if self.parser.opcode == Parser.LOAD_WEIGHT:
                    self.weight_rows += 1
                else:
                    self.act_rows += 1

            if self.weight_rows == self.TILE_SIZE and self.act_rows == self.TILE_SIZE:
                self.weight_rows          = 0
                self.act_rows             = 0
                self.data_setup.start.val = 1
                self.state                = 'COMPUTE'

        elif self.state == 'COMPUTE':
            self.data_setup.start.val = 0

            if self.data_setup.done.val:
                self._drain_cycle = 0
                self.state        = 'DRAIN'

        elif self.state == 'DRAIN':
            self.array.step([0] * self.TILE_SIZE)
            self._drain_cycle += 1
            if self._drain_cycle == self._DRAIN_CYCLES:
                self.state = 'WAIT_LOAD'

