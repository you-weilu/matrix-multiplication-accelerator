# Debug Story: Systolic Array Output Skew Bug

*Debugging the compute_pipeline integration test — good interview material for
"tell me about a hard bug you debugged" or "walk me through a design trade-off
you made."*

## The 30-second version

My matmul accelerator's per-module unit tests all passed, but the first
full-pipeline integration test returned all zeros. The output buffer debug
prints showed the correct results were being computed — but filed along a
diagonal instead of in rows. That diagonal was the signature of uncompensated
**output skew** from the systolic array: each column's results exit one cycle
later than the previous column's, and the accumulator bank assumed they all
arrived aligned. I fixed it with a deskew register triangle at the array
output, a deliberate trade-off against putting skew-aware addressing in the
accumulator (which is what TPU-scale designs do, and why).

## Symptom

`test_matmul_2x2tiles_k1` (cocotb + Verilator, full compute pipeline: ping-pong
buffers → SDS → 16x16 systolic array → accumulator bank → output buffer over
AXI) failed with every readback value = 0, for every tile.

## Debugging process

1. **Instrument the last known-good boundary.** Debug prints on the output
   buffer write port (`buf_wen`, `buf_row`, `buf_data`) showed the buffer *was*
   being written — with mostly nonzero data. So the datapath computed
   *something*; the question became "why doesn't the written data match, and
   why does readback see zeros?"

2. **Compare written data against expected values.** This was the key step.
   Expected row 0 was `[13465, 2444, 16168, 31754, ...]`. In the write dump:

   ```
   row=2  data[0]=13465    ← C[0][0]
   row=3  data[1]=2444     ← C[0][1]
   row=4  data[2]=16168    ← C[0][2]
   row=5  data[3]=31754    ← C[0][3]
   ```

   Every expected value was present but displaced: `C[r][c]` landed at buffer
   row `r + c + 2` instead of row `r`. A diagonal displacement that grows by
   one per column is the fingerprint of systolic output skew; the constant +2
   is a pipeline-latency offset. One dump, three bugs identified.

3. **Confirm against the RTL with a cycle-accurate trace.** Traced `C[0][0]`
   by hand through the pipeline: activation register in the SDS (1 cycle) +
   16 PE stages down the column ⇒ first valid result exits the bottom of
   column 0 during FEED cycle 17, and column `c` lags by `c` more cycles
   (activations ripple rightward one PE per cycle, so column `c`'s partial-sum
   wavefront is `c` cycles behind). Against the RTL as written:

   - `row_valid` asserted at FEED cycle 15 → 2 cycles early (the +2 offset).
   - `accumulator_bank` uses **one shared row counter** for all 16 columns:
     `buf_acc[row][j] += col_in[j]` for all j, then `row++`. That indexing
     assumes all 16 lanes carry the same result row each cycle — false with
     skewed outputs (the diagonal).
   - FEED ended at cycle 30 (when the last activation is *fed*), but the last
     result `C[15][15]` doesn't exit until cycle ~47 → the bottom-right
     triangle of every tile was never captured, and stale partial sums bled
     into the next tile's pass (explained the garbage seen in later tiles).

4. **Root-cause the root cause.** The bug wasn't a typo — the Python golden
   model (`sw_model/`) had the identical flaw (`row_valid` high for the whole
   FEED phase, single shared row counter, no drain phase). The RTL faithfully
   implemented a wrong spec. Lesson: unit tests that check a module against
   its own spec can't catch a spec that's wrong; only the integration test
   exposed the cross-module timing contract violation.

## Key insight worth stating in an interview

Each `col_out` value is already a **complete** dot product — the sum over k
happens spatially, down the column, inside the array. The accumulator bank
accumulates across K-tile *passes*, not across cycles. So skew isn't "harmless
zeros added early" — it's each value being filed under the wrong row index,
plus late values arriving after the capture window closed. The zeros added
during pipeline fill are indeed harmless; the misindexing is not.

## The fix

1. **Deskew triangle** (`systolic_array.sv`): delay column `c` by `15 − c`
   registers so `col_out` presents one fully aligned result row per cycle.
   Skew becomes a private implementation detail of the array module.
2. **Corrected timing window** (`systolic_data_setup.sv`): `row_valid` high
   for FEED cycles 32–47 (1 SDS act register + 16 PE stages + 15 deskew
   stages), FEED extended to cycle 47 so the array and deskew pipes fully
   drain before `pass_done`.
3. **Accumulator bank: zero changes.** It keeps its simple "one aligned row
   per cycle, one shared counter" contract — the whole point of the chosen
   architecture.
4. Golden model and the two timing-encoding unit tests updated to the new
   contract; full regression (9 testbenches) green.

## Architecture decision: deskew registers vs. skew-aware accumulator

Two sound ways to make the row indexing agree with physical reality:

| | Deskew triangle at array output | Skew-aware accumulator addressing |
|---|---|---|
| Idea | Delay column `c` by `N−1−c` regs; outputs exit aligned | Keep raw skewed outputs; accumulator uses per-column row index (`row − c`) and per-column valid |
| Cost | `N(N−1)/2` result-width registers | A few counters/offsets in control logic |
| At 16×16, 32-bit | 120 × 32b ≈ 3.8K flops — negligible | Cheaper, but control complexity |
| At 256×256 (TPU v1 scale) | ~32,640 × 32b ≈ 1M+ flops of pure buffering | Clearly wins |
| Coupling | Skew hidden inside the array; accumulator stays dumb | Array's internal timing leaks into accumulator control |

**The decision flips with N.** Google's TPU keeps outputs skewed and absorbs
the skew in accumulator addressing because at 256×256 the deskew area is
prohibitive — it's also why the TPU has a systolic data setup unit on the
*input* side only: input skew buffers 8-bit operands, output deskew would
buffer 32-bit results, 4× the cost per stage. At 16×16 I chose the deskew
triangle: the flop cost is noise, the accumulator keeps a trivially simple
contract, and anything attached to `col_out` later gets aligned data for free.
Being able to say *"I know what the TPU does, I know why, and I know why my
scale justifies the opposite choice"* is the interview-worthy part.

## Takeaways

- **Diagonal displacement in a systolic array's output = uncompensated skew.**
  Recognizing the fingerprint turned one debug dump into a complete diagnosis.
- **Integration tests catch contract bugs unit tests can't.** Every module
  matched its spec; the spec itself violated the inter-module timing contract.
- **Fix the golden model, not just the RTL.** The bug originated in the
  Python model; leaving it would re-plant the same bug in future modules.
- **A "valid" signal must encode the full pipeline latency** — fill *and*
  drain. Feeding done ≠ computing done.
