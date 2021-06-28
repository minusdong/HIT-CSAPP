#include <stdio.h>

// x in %edx, y in %esi, t in %edi
int func4 (int x, int y, int t) {
    int n = x - y;
    int m = n / 2 + y;
    if (m == t)
        return m;
    else if (m > t)
        return (m + func4 (m - 1, y, t));
    else
        return (m + func4 (x, m + 1, t));
}

int main () {
    int ret, t;
    for (t = 0; t <= 14; t++)
    {
        ret = func4 (14, 0, t);
        printf ("%d ", t);
        if (ret == 35)
            printf("%d\n", t);
        else
            printf("%d wrong\n", ret);
    }
    return 0;
}