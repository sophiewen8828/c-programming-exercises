#include <stdio.h>

#define MAXN 100

int main(void)
{
    int n;
    int adj[MAXN + 1][MAXN + 1] = {0};
    int dist[MAXN + 1];
    int queue[MAXN];
    int head = 0, tail = 0;
    int order[MAXN];
    int count = 0;
    int a, b;
    int i, j;

    if (scanf("%d", &n) != 1)
        return 0;
    if (n < 1 || n > MAXN)
        return 0;

    for (i = 0; i < n - 1; i++) {
        if (scanf(" { %d , %d }", &a, &b) != 2)
            return 0;
        if (a < 1 || a > n || b < 1 || b > n)
            return 0;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    for (i = 1; i <= n; i++)
        dist[i] = -1;

    /* Breadth-first search from node 1 records each node's distance. */
    dist[1] = 0;
    queue[tail++] = 1;
    while (head < tail) {
        int u = queue[head++];

        for (j = 1; j <= n; j++) {
            if (adj[u][j] && dist[j] == -1) {
                dist[j] = dist[u] + 1;
                queue[tail++] = j;
            }
        }
    }

    /* Visit order is by distance, then by node number within a distance. */
    for (i = 1; i <= n; i++)
        if (dist[i] != -1)
            order[count++] = i;

    for (i = 1; i < count; i++) {
        int key = order[i];

        j = i - 1;
        while (j >= 0 &&
               (dist[order[j]] > dist[key] ||
                (dist[order[j]] == dist[key] && order[j] > key))) {
            order[j + 1] = order[j];
            j--;
        }
        order[j + 1] = key;
    }

    for (i = 0; i < count; i++) {
        if (i > 0)
            putchar(' ');
        printf("%d", order[i]);
    }
    putchar('\n');

    return 0;
}
