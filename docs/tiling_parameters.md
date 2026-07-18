# Tiling Parameters Reference

## The computation: C = A × B

```
A: M × K   (activations)
B: K × N   (weights)
C: M × N   (output)
```

Each matrix is divided into 16×16 tiles. The number of tiles along each dimension:

| Parameter | Meaning | Example (M=64, K=32, N=48) |
|-----------|---------|---------------------------|
| `m_tiles` | number of row tiles (M/16) | 4 |
| `k_tiles` | number of K-dimension tiles (K/16) | 2 |
| `n_tiles` | number of column tiles (N/16) | 3 |

`m_tiles` is not a signal in the design — `tile_i` always stays within bounds because the FSM controls the loop limits.

---

## The three loop indices

```
for tile_i in [0, m_tiles):     ← which row of output tiles
  for tile_j in [0, n_tiles):   ← which column of output tiles
    for k_tile in [0, k_tiles): ← K-dimension accumulation pass
      fetch A[tile_i][k_tile]
      fetch B[k_tile][tile_j]
      accumulate into C[tile_i][tile_j]
    writeback C[tile_i][tile_j]
```

| Signal | What it selects | Changes every... |
|--------|----------------|-----------------|
| `tile_i` | which row of C (and A) we are computing | outer loop step |
| `tile_j` | which column of C (and B) we are computing | middle loop step |
| `k_tile` | which K-slice we are on within this (i,j) accumulation | inner loop step |

---

## Why each address formula uses what it uses

**Matrix A tile** — shape M×K, stored row-major in tiles:

```
src_addr_a = base_addr_a + (tile_i * k_tiles + k_tile) * 256
```
- `tile_i` selects which row of tiles (row stride = k_tiles tiles)
- `k_tile` selects which tile within that row
- No `tile_j` because A does not depend on which output column we're in

**Matrix B tile** — shape K×N, stored column-major in tiles:

```
src_addr_b = base_addr_b + (tile_j * k_tiles + k_tile) * 256
```
- `tile_j` selects which column of tiles (column stride = k_tiles tiles)
- `k_tile` selects which tile within that column
- No `tile_i` because B does not depend on which output row we're in

**Matrix C tile** — shape M×N, stored row-major in tiles (INT32, so 1024 bytes):

```
dst_addr_c = base_addr_c + (tile_i * n_tiles + tile_j) * 1024
```
- `tile_i` selects which row of output tiles (row stride = n_tiles tiles)
- `tile_j` selects which column within that row
- No `k_tile` because C is the accumulated result — its location is fixed for the whole inner loop

---

## Why k_tile appears in both A and B but not C

`k_tile` is the shared dimension being reduced. For a given output tile `C[tile_i][tile_j]`:
- You need all K-slices of the corresponding A row: `A[tile_i][0..k_tiles-1]`
- You need all K-slices of the corresponding B column: `B[0..k_tiles-1][tile_j]`
- C accumulates across all k_tile iterations, so its address is fully determined by `(tile_i, tile_j)` alone

---

## Quick cheat sheet

```
tile_i  → row in A and C
tile_j  → column in B and C
k_tile  → inner loop, appears in A and B fetch addresses
k_tiles → total K tiles, used as stride in A and B address formulas
n_tiles → total column tiles, used as stride in C address formula
```
