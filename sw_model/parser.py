# Parser
# Description: reads AXI-Stream data from the RX FIFO and decodes incoming
# UDP packets. Skips the 28-byte IP+UDP header, then extracts the opcode and
# row address from a single packed byte (bits 7-6: opcode, bits 5-2: address).
# Routes completed rows to the Weight or Activation BRAM, or signals the
# Control FSM to reset.
#
# State machine: IDLE -> SKIP_HEADER -> READ_OPCODE -> READ_DATA -> WRITE -> IDLE
#
# Opcodes: LOAD_WEIGHT=00, LOAD_ACT=01, RESET=10

from signal import Signal, AXIStream
from bram import BRAM

class Parser:
    LOAD_WEIGHT = 0b00
    LOAD_ACT = 0b01
    RESET = 0b10

    def __init__(self, axis_in: AXIStream, weight_bram: BRAM, act_bram: BRAM, rst_out: Signal, rst: Signal):
        self.state = "IDLE"
        self.byte_count = 0
        self.row_buf = []
        self.opcode = None
        self.address = None
        self.axis_in = axis_in
        self.weight_bram = weight_bram
        self.act_bram = act_bram
        self.rst_out = rst_out
        self.rst = rst

    def tick(self):
        if self.rst.val:
            self.state = "IDLE"
            self.byte_count = 0
            self.row_buf = []
            self.opcode = None
            self.address = None
            return

        self.axis_in.tready.val = (self.state != "WRITE")

        if not (self.axis_in.tvalid.val and self.axis_in.tready.val):
            return

        byte = self.axis_in.tdata.val
        tlast = self.axis_in.tlast.val

        if self.state == "IDLE":
            self.state = "SKIP_HEADER"
            self.byte_count = 1

        elif self.state == "SKIP_HEADER":
            self.byte_count += 1
            if tlast:
                self.state = "IDLE"
                self.byte_count = 0
            elif self.byte_count == 28:
                self.state = "READ_OPCODE"

        elif self.state == "READ_OPCODE":
            self.opcode  = (byte >> 6) & 0b11
            self.address = (byte >> 2) & 0b1111
            if tlast or self.opcode == self.RESET:
                self.rst_out.val = (self.opcode == self.RESET)
                self.state = "IDLE"
                self.byte_count = 0
            else:
                self.state = "READ_DATA"
                self.byte_count = 0

        elif self.state == "READ_DATA":
            if tlast and self.byte_count < 15:
                self.row_buf = []
                self.state = "IDLE"
                self.byte_count = 0
            else:
                self.row_buf.append(byte)
                self.byte_count += 1
                if self.byte_count == 16:
                    self.state = "WRITE"

        elif self.state == "WRITE":
            bram = self.weight_bram if self.opcode == self.LOAD_WEIGHT else self.act_bram
            bram.write(self.address, self.row_buf)
            self.row_buf = []
            self.byte_count = 0
            self.state = "IDLE"
