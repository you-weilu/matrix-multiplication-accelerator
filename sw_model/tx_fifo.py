# RX FIFO
# Description: buffers incoming AXI-Stream data
# from the Ethernet MAC before the Parser reads it.

from collections import deque
from signal import Signal, AXIStream

class RXFIFO:
    DEPTH = 512

    def __init__(self, axis_in: AXIStream, axis_out: AXIStream, rst: Signal):
        self._buffer = deque()
        self.axis_in = axis_in # driven by MAC
        self.axis_out = axis_out # drives Parser
        self.rst = rst

    def empty(self):
        return len(self._buffer) == 0

    def full(self):
        return len(self._buffer) >= self.DEPTH

    def clear(self):
        self._buffer.clear()

    def tick(self):
        # reset logic
        if self.rst.val:
            self.clear()
            self.axis_in.tready.val = False
            self.axis_out.tvalid.val = False
            return 

        # signals logic
        self.axis_in.tready.val = not self.full()
        self.axis_out.tvalid.val = not self.empty()

        # accept data from MAC (if valid && not full)
        if (self.axis_in.tvalid.val and self.axis_in.tready.val):
            self._buffer.append((self.axis_in.tdata.val, self.axis_in.tlast.val))

        # drive Parser (if ready && not empty)
        if (self.axis_out.tvalid.val and self.axis_out.tready.val):
            self.axis_out.tdata.val, self.axis_out.tlast.val = self._buffer.popleft()
        
        