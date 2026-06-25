# Top
#
# Wires all blocks together and drives the simulation tick loop.
#
# Tick order each cycle:
#   1. TileSequencerFSM - drives start, final_pass; advances tiling state
#   2. DataSetup - reads start, feeds weights/activations into array
#   3. propagate - copy col_out --> partial_in, set row_valid
#   4. AccumulatorBank - reads partial_in/row_valid, writes output buffer

from signal           import Signal
from csr_block        import CSRBlock
from pingpong_buffers import PingPongBuffer
from systolic_array   import SystolicArray
from systolic_data_setup import DataSetup
from accumulator_bank import AccumulatorBank
from output_buffer    import OutputBuffer
from tile_sequencer_fsm import TileSequencerFSM

class Top:

    def __init__(self, host_a, host_b, host_c, M, K, N):
        # shared signals
        ds_start   = Signal(0)
        ds_done    = Signal(0)
        final_pass = Signal(0)
        tile_done  = Signal(0)
        rst        = Signal(0)
        partial_in = Signal([0] * 16)
        row_valid  = Signal(0)

        # blocks
        self.csr        = CSRBlock()
        self.weight_buf = PingPongBuffer()
        self.act_buf    = PingPongBuffer()
        self.array      = SystolicArray()
        self.output_buf = OutputBuffer()
        self.acc_bank   = AccumulatorBank(partial_in, row_valid, final_pass,
                                          tile_done, rst, self.output_buf)
        self.data_setup = DataSetup(self.weight_buf, self.act_buf, self.array,
                                    ds_start, ds_done)
        self.fsm        = TileSequencerFSM(self.csr, self.weight_buf, self.act_buf,
                                           self.data_setup, self.acc_bank, self.output_buf,
                                           host_a, host_b, host_c)

        self._partial_in = partial_in
        self._row_valid  = row_valid

        self.csr.M = M
        self.csr.K = K
        self.csr.N = N

    def tick(self):
        self.fsm.tick()
        self.data_setup.tick()

        # propagate systolic array bottom output to accumulator bank
        self._partial_in.val = list(self.array.col_out)
        self._row_valid.val  = 1 if self.data_setup._state == 'FEED' else 0

        self.acc_bank.tick()

    def run(self):
        self.csr.start.val = 1
        while not self.csr.interrupt.val:
            self.tick()
