#include <stdio.h>

int main(void)
{
    int n, k;
    int survivor = 0; /* 0-based position of the survivor for 1 person */
    int i;

    if (scanf("%d %d", &n, &k) != 2)
        return 0;

    /* J(1) = 0, J(i) = (J(i-1) + k) % i  (0-based) */
    for (i = 2; i <= n; i++)
        survivor = (survivor + k) % i;

    printf("%d\n", survivor + 1); /* convert back to 1-based */

    return 0;
}
