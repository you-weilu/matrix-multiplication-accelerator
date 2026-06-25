# Systolic Data Setup
#
# Timing controller between the active ping-pong buffers and the systolic
# array. Operates on one 16x16 tile at a time per invocation.
#
# Phase 1 (both run in parallel):
#   1a: feed weight buffer rows in reverse into the top of the array
#   1b: copy activation buffer rows into the 256-byte working buffer
#
# Phase 2 (31 cycles):
#   Feed skewed activations from buffer into array rows.
#   At cycle t, row k receives buffer[t-k][k] = A[t-k][k] if t >= k, else 0.

from signal import Signal

class DataSetup:
    TILE_SIZE = 16
    _PRELOAD_CYCLES = TILE_SIZE
    _FEED_CYCLES    = 2 * TILE_SIZE - 1

    def __init__(self, weight_buf, act_buf, array, start: Signal, done: Signal):
        self._weight_buf = weight_buf
        self._act_buf    = act_buf
        self._array      = array
        self.start       = start  # Signal in: driven by Tile Sequencer FSM
        self.done        = done   # Signal out: read by Tile Sequencer FSM

        self._buffer = [[0] * self.TILE_SIZE for _ in range(self.TILE_SIZE)]
        self._state  = 'IDLE'
        self._cycle  = 0

    def tick(self):
        self.done.val = 0

        if self._state == 'IDLE':
            if self.start.val:
                self._state = 'PRELOAD'
                self._cycle = 0

        elif self._state == 'PRELOAD':
            weight_row = self.TILE_SIZE - 1 - self._cycle
            self._array.shift_weights(self._weight_buf.read(weight_row))
            self._buffer[self._cycle] = list(self._act_buf.read(self._cycle))

            self._cycle += 1
            if self._cycle == self._PRELOAD_CYCLES:
                self._state = 'FEED'
                self._cycle = 0

        elif self._state == 'FEED':
            activations = []
            for row in range(self.TILE_SIZE):
                t = self._cycle - row
                activations.append(self._buffer[t][row] if 0 <= t < self.TILE_SIZE else 0)
            self._array.step(activations)

            self._cycle += 1
            if self._cycle == self._FEED_CYCLES:
                self._state = 'IDLE'
                self.done.val = 1
