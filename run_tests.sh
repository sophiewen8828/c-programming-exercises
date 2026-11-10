#!/usr/bin/env bash
# Build every solution and check every test case in tests/.
set -u

cd "$(dirname "$0")"

CC=${CC:-gcc}
CFLAGS="-std=c11 -Wall -Wextra -O2"
TMP=$(mktemp -d)
trap 'rm -rf "$TMP"' EXIT

fail=0
run_suite() {
    local name="$1" src="$2" dir="$3"
    echo "== $name =="
    if ! $CC $CFLAGS -o "$TMP/$name" "$src"; then
        echo "  BUILD FAILED"
        fail=1
        return
    fi
    for in_file in "$dir"/*.in; do
        case_name=$(basename "$in_file" .in)
        expected="$dir/$case_name.out"
        actual="$TMP/$case_name.actual"
        "$TMP/$name" < "$in_file" > "$actual"
        if diff -u "$expected" "$actual" > "$TMP/$case_name.diff"; then
            echo "  PASS  $case_name"
        else
            echo "  FAIL  $case_name"
            cat "$TMP/$case_name.diff"
            fail=1
        fi
    done
}

run_suite banded     banded_matrix_multiplication.c tests/banded
run_suite josephus   josephus_problem.c            tests/josephus
run_suite parentheses balanced_parentheses.c       tests/parentheses
run_suite spiral      spiral_matrix_traversal.c    tests/spiral
run_suite tree        tree_exploration.c           tests/tree

if [ "$fail" -eq 0 ]; then
    echo "ALL TESTS PASSED"
else
    echo "SOME TESTS FAILED"
fi
exit "$fail"
