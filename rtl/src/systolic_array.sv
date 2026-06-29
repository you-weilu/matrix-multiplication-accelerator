// Systolic Array
//
// 16x16 mesh of weight-stationary PEs.
//
// Weight loading (weight_load_en high for 16 cycles, driven by SDS):
//   Weight values enter the top of each column and shift down one PE per cycle.
//   After 16 cycles PE[i][j] holds weight B[i][j].
//
// Compute (weight_load_en low):
//   Activations flow left to right across each row.
//   Partial sums flow top to bottom down each column.
//   col_out[j] carries the partial sum exiting the bottom of column j each cycle.
//
// All PE outputs are registered. weight_load_en is broadcast to every PE.
