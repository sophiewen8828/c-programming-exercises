#include <stdio.h>

int main(void)
{
    int n, p, q, r, s;
    int A[20][20] = {0};
    int B[20][20] = {0};
    int C[20][20] = {0};
    int i, j, k;

    if (scanf("%d %d %d %d %d", &n, &p, &q, &r, &s) != 5)
        return 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (scanf("%d", &A[i][j]) != 1)
                return 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (scanf("%d", &B[i][j]) != 1)
                return 0;

    /* C[i][j] = sum over k of A[i][k]*B[k][j].
     * A[i][k] is non-zero only for i-p <= k <= i+q,
     * B[k][j] is non-zero only for j-s <= k <= j+r.
     * Intersect those ranges with [0, n-1]. */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int lo = i - p;
            int hi = i + q;

            if (j - s > lo)
                lo = j - s;
            if (j + r < hi)
                hi = j + r;
            if (lo < 0)
                lo = 0;
            if (hi > n - 1)
                hi = n - 1;

            C[i][j] = 0;
            for (k = lo; k <= hi; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j > 0)
                putchar(' ');
            printf("%04d", C[i][j]);
        }
        putchar('\n');
    }

    return 0;
}
