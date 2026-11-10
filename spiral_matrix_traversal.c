#include <stdio.h>

#define MAX 30

static void emit(int value, int *first)
{
    if (!*first)
        putchar(' ');
    printf("%d", value);
    *first = 0;
}

int main(void)
{
    int n, m;
    int a[MAX][MAX];
    int top = 0, bottom, left = 0, right;
    int first = 1;
    int i, j;

    if (scanf("%d %d", &n, &m) != 2)
        return 0;
    if (n < 1 || n > MAX || m < 1 || m > MAX)
        return 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return 0;

    bottom = n - 1;
    right = m - 1;

    while (top <= bottom && left <= right) {
        /* Left to right across the top row. */
        for (j = left; j <= right; j++)
            emit(a[top][j], &first);
        top++;

        /* Top to bottom down the right column. */
        for (i = top; i <= bottom; i++)
            emit(a[i][right], &first);
        right--;

        /* Right to left across the bottom row, if it is still unvisited. */
        if (top <= bottom) {
            for (j = right; j >= left; j--)
                emit(a[bottom][j], &first);
            bottom--;
        }

        /* Bottom to top up the left column, if it is still unvisited. */
        if (left <= right) {
            for (i = bottom; i >= top; i--)
                emit(a[i][left], &first);
            left++;
        }
    }

    putchar('\n');

    return 0;
}
