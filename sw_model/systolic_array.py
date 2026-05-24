# Systolic Array
# 16x16 mesh of weight-stationary PEs.
#
# Weight loading (shift_weights, called 16 times):
#   Each call shifts all rows down by one and places the new row at the top.
#   The SDS feeds rows in reverse order (row 15 first) so PE[i][j] ends up holding B[i][j].
#
# Compute (step):
#   Activations flow left to right; partial sums flow top to bottom.
#   Each PE: psum_out = psum_in + weight * act_in; passes act_in rightward.
#   col_out[j] is the partial sum exiting the bottom of column j this cycle.
#
# Timing: the output for row r of the result exits column j at cycle r+j+15
# from the start of feeding. Column 15's last output doesn't arrive until
# cycle 45, so there is a 15-cycle tail after the 31-cycle feed phase ends.
# The caller must keep calling step() with zeros through that tail.

class SystolicArray:
    TILE_SIZE = 16

    def __init__(self):
        N = self.TILE_SIZE
        # _weights[i][j] = weight at PE row i, column j
        self._weights = [[0] * N for _ in range(N)]
        # _act[i][j] = activation output of PE[i][j] last cycle
        self._act     = [[0] * N for _ in range(N)]
        # _psum[i][j] = partial sum output of PE[i][j] last cycle
        self._psum    = [[0] * N for _ in range(N)]
        # partial sums currently exiting the bottom of each column
        self.col_out  = [0] * N

    def shift_weights(self, row_data):
        # shift all rows down by one, place new row at the top
        N = self.TILE_SIZE
        for i in range(N - 1, 0, -1):
            self._weights[i] = self._weights[i - 1]
        self._weights[0] = list(row_data)

    def step(self, activations):
        # advance one compute cycle --> activations[k] feeds into row k
        N = self.TILE_SIZE
        new_act  = [[0] * N for _ in range(N)]
        new_psum = [[0] * N for _ in range(N)]

        for i in range(N):
            for j in range(N):
                act_in   = activations[i] if j == 0 else self._act[i][j - 1]
                psum_in  = 0             if i == 0 else self._psum[i - 1][j]
                psum_out = psum_in + self._weights[i][j] * act_in
                new_act[i][j]  = act_in
                new_psum[i][j] = psum_out

        self._act    = new_act
        self._psum   = new_psum
        self.col_out = [new_psum[N - 1][j] for j in range(N)]
