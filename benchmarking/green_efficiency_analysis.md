# Green Efficiency Analysis

## Measurement Methodology

All measurements were taken inside the same Holberton sandbox (Ubuntu, single session) using three provided C programs. Each program measures time with `clock()` from `<time.h>` and converts ticks to seconds by dividing by `CLOCKS_PER_SEC`. Because `clock()` reports processor time used by the program, not wall-clock time, the results reflect CPU work rather than time spent waiting.

- `baseline_loop.c` performs 100,000,000 iterations of a modulo-and-add operation and was executed three consecutive times.
- `comparison_algorithms.c` counts even numbers in a 50,000-element array with two implementations (a nested-loop "naive" version and a single-pass version) and was executed three times.
- `instrumentation_lab.c` was instrumented with separate `clock()` calls around each phase (build, process, reduce) plus one around the whole sequence, and was executed three times.

The source logic was not modified; only timing instrumentation was added where the task required it.

## Observed Performance Differences

The baseline loop was very stable: 0.230959 s, 0.236051 s and 0.231241 s (mean ≈ 0.2328 s). The largest difference between runs is about 0.005 s, roughly 2%, which shows that identical work does not produce identical timings, but the variation is small.

The algorithm comparison showed the largest difference. The naive version took 2.837764 s, 2.893495 s and 2.842305 s (mean ≈ 2.858 s), while the single-pass version took 0.000106 s in all three runs. The naive version was therefore about 27,000 times slower. Its nested loop checks every element from index 0 up to `i` for each `i`, which is about 1.25 billion checks for 50,000 elements, compared with 50,000 checks for the single pass. It is important to note that the two functions do not return the same value (625025000 versus 25000): the naive version counts even values cumulatively across prefixes, so it does more work and also computes a different quantity.

In the instrumented program, the first run was the slowest (TOTAL 0.001503 s, BUILD_DATA 0.000754 s), while runs two and three were close to each other (TOTAL 0.001177 s and 0.001161 s). In the steady runs, BUILD_DATA took about 0.0005 s (≈43% of total), PROCESS about 0.00049 s (≈42%), and REDUCE about 0.00017 s (≈15%). The higher first-run value is most likely a warm-up effect such as cold caches or page faults on the static array, since the code is identical in every run.

## Relation Between Runtime and Energy Consumption

These programs are CPU-bound: they do arithmetic in loops without waiting for input or disk. For this kind of workload, energy used is approximately average power multiplied by the time the CPU is busy. Under that assumption, the naive algorithm, which kept the CPU busy for about 2.86 s instead of about 0.0001 s, would consume several orders of magnitude more energy for its run. The baseline loop's consistent 0.23 s gives a reference for how much work 100 million simple operations cost on this machine. No power meter was available, so this relation is an inference from runtime, not a direct energy measurement.

## Limitations of the Experiment

- Energy was not measured directly; it is estimated from CPU time only.
- Only three runs were recorded per program, which is too few for strong statistical conclusions.
- The sandbox is a shared virtual machine, so other workloads may have influenced timings (as seen in the slower first instrumented run).
- Timings around 0.0001 s are close to the resolution of `clock()`, so the single-pass and phase timings are less precise.
- The two counting algorithms return different results, so the comparison measures cost of approach, not two equivalent solutions.
- Programs were compiled without optimization flags; results could change with `-O2`.

## Practical Engineering Takeaway

The measurements show that algorithm choice dominates performance far more than run-to-run noise: a 2% variation in the baseline is negligible next to a 27,000× gap between O(n²) and O(n) approaches. Before optimizing small details, engineers should first remove unnecessary repeated work. Measuring each phase separately, as in the instrumented program, is the practical way to find where time (and therefore energy) is actually spent.
