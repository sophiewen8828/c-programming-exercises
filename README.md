# Five Classic C Programming Exercises

A compact C11 practice repository built around five classic problems. Each problem
comes with a readable reference solution, a black-box test suite, and a detailed
illustrated study guide.

**5 problems · 47 tests · C11 · no external dependencies**

> **First visit?** This page is the quick overview. For the full analysis—design
> blueprints, worked traces, correctness arguments, complexity, and common
> pitfalls—open the
> [illustrated study guide](https://sophiewen8828.github.io/c-programming-exercises/README.html).
> The guide is also available in Traditional Chinese as
> [C 語言經典習題必要技巧學習重點筆記](https://sophiewen8828.github.io/c-programming-exercises/C_Programming_Essential_Techniques_Notes.html).

## Problems

| # | Problem | Core technique | Solution | Tests |
|---|---------|----------------|----------|-------|
| 1 | General Banded Matrix Multiplication | Band intersection and boundary clamping | [`banded_matrix_multiplication.c`](banded_matrix_multiplication.c) | [`tests/banded`](tests/banded) |
| 2 | Josephus Problem | Renumbering and a linear recurrence | [`josephus_problem.c`](josephus_problem.c) | [`tests/josephus`](tests/josephus) |
| 3 | Balanced Parentheses | Stack / LIFO matching | [`balanced_parentheses.c`](balanced_parentheses.c) | [`tests/parentheses`](tests/parentheses) |
| 4 | Spiral Matrix Traversal | Shrinking boundary simulation | [`spiral_matrix_traversal.c`](spiral_matrix_traversal.c) | [`tests/spiral`](tests/spiral) |
| 5 | Tree Exploration | BFS distances plus level ordering | [`tree_exploration.c`](tree_exploration.c) | [`tests/tree`](tests/tree) |

## Quick start

**Requirements:** a C11 compiler (`gcc` or `clang`), `bash`, and `diff`.

```bash
git clone https://github.com/sophiewen8828/c-programming-exercises.git
cd c-programming-exercises
./run_tests.sh
```

Expected final line:

```text
ALL TESTS PASSED
```

To use a different compiler:

```bash
CC=clang ./run_tests.sh
```

To compile and run one solution manually:

```bash
gcc -std=c11 -Wall -Wextra -O2 -o /tmp/spiral spiral_matrix_traversal.c
/tmp/spiral < tests/spiral/test2.in
```

## Repository layout

```text
.
├── README.md                                  # this overview
├── README.html                                # illustrated study guide
├── index.html                                 # GitHub Pages landing redirect
├── C_Programming_Essential_Techniques_Notes.html
├── banded_matrix_multiplication.c
├── josephus_problem.c
├── balanced_parentheses.c
├── spiral_matrix_traversal.c
├── tree_exploration.c
├── run_tests.sh
├── S__36421651.jpg … S__36421655.jpg          # original problem statements
└── tests/
    ├── banded/          # 8 cases
    ├── josephus/        # 8 cases
    ├── parentheses/     # 11 cases
    ├── spiral/          # 10 cases
    └── tree/            # 10 cases
```

## Test suites

| Suite | Cases | Focus |
|-------|:-----:|-------|
| `tests/banded` | 8 | Band arithmetic, signed `%04d` formatting, minimum/maximum sizes, triangular matrices |
| `tests/josephus` | 8 | Samples, `N=1`, large `K`, `N=K=1000` |
| `tests/parentheses` | 11 | All bracket types, crossing, unclosed input, 500-level nesting, 1000-character limits |
| `tests/spiral` | 10 | Square and rectangular shapes, single row/column, negatives, even and odd dimensions |
| `tests/tree` | 10 | Samples, single node, chains, stars, reversed edges, level-order tie-breaking |

Each case is a pair of files:

```text
tests/<suite>/testN.in    # standard input
tests/<suite>/testN.out   # exact expected standard output
```

`run_tests.sh` compiles every solution, feeds each `.in` file to the binary, and
compares stdout with the `.out` file using `diff -u`. Output is compared
byte-for-byte, so whitespace and formatting matter.

### Adding a test

Create `tests/<suite>/testN.in` and `tests/<suite>/testN.out`. The harness
discovers them automatically—no script changes required. Keep the expected file's
final newline intact.

## Documentation

- [**Illustrated study guide (HTML)**](https://sophiewen8828.github.io/c-programming-exercises/README.html) —
  problem statements, visual design blocks, step-by-step algorithms, traces,
  correctness proofs, complexity analysis, pitfalls, checkpoint questions, and
  complete code listings.
- [**Traditional Chinese notes**](https://sophiewen8828.github.io/c-programming-exercises/C_Programming_Essential_Techniques_Notes.html) —
  a condensed reference for the techniques used across all five problems.
- [**Original problem statements**](S__36421651.jpg) — the five screenshot files
  (`S__36421651.jpg` … `S__36421655.jpg`) are kept in the repository.

Both HTML documents are intended to be read through GitHub Pages. The repository
root link <https://sophiewen8828.github.io/c-programming-exercises/> redirects to
the illustrated guide via `index.html`.

## Suggested study workflow

1. **Read the statement only.** Restate the input, output, and formatting rules in
   your own words.
2. **Implement before looking at the reference.** Draw the data structure and
   write down the loop invariant first.
3. **Run the test suite.** A program that passes only the samples is not yet
   verified.
4. **Compare designs.** Read the guide's correctness argument and complexity
   analysis, then ask whether your approach is also correct and what it costs.
5. **Add a boundary test.** Try a minimum size, a maximum size, a degenerate
   dimension, or a negative value that the suite does not already cover.

## A note on the reference solutions

The solutions favor clarity over micro-optimization. Fixed-size arrays are used
where the constraints are small, and each file is self-contained so it can be
compiled and studied independently. The accompanying guide explains why each
design works, not just what the code does.
