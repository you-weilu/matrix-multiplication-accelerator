# Shared signal primitives for cycle-accurate simulation.
# Signal models a single wire; AXIStream bundles AXI-Stream handshake signals.

class Signal:
    def __init__(self, val=0):
        self.val = val

class AXIStream:
    def __init__(self):
        self.tdata  = Signal(0)
        self.tvalid = Signal(False)
        self.tready = Signal(False)
        self.tlast  = Signal(False)
