#include <stdlib.h>

#define INF 2147483647

int* memoized_cut_rod(int *p, int n) {
    int memoized_cut_rod_aux(int *p, int n, int *r);

    int *r = (int *)malloc((n+1) * sizeof(int));
    for (int i=0; i<=n; i++) {
        r[i] = -INF;
    }

    memoized_cut_rod_aux(p, n, r);
    return r;
}

int memoized_cut_rod_aux(int *p, int n, int *r) {
    if (r[n] >= 0) {
        return r[n];
    }

    int q;
    if (n == 0) {
        q = 0;
    }
    else {
        q = -INF;
        int s;
        for (int i=1; i<=n; i++) {
            s = p[i] + memoized_cut_rod_aux(p, n-i, r);
            q = (q > s) ? q : s;
        }
    }

    r[n] = q;
    return q;
}