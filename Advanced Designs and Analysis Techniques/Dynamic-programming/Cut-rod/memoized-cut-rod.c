#include <stdlib.h>

#define INF 2147483647

// p[i] contains the revenue of piece of length i
int* memoized_cut_rod(int *p, int n) {
    int memoized_cut_rod_aux(int *p, int n, int *r);

    int *r = (int *)malloc((n+1) * sizeof(int));
    for (int i=0; i<=n; i++) {
        r[i] = -INF;
    }

    memoized_cut_rod_aux(p, n, r);
    return r;
}

// r[i] contains max revenue for length n
int memoized_cut_rod_aux(int *p, int n, int *r) {  
    if (r[n] >= 0) {  // if max revenue for length n was calculated before use it
        return r[n];
    }

    int q;
    if (n == 0) {  // base condition
        q = 0;
    }
    else {
        q = -INF;
        int s;
        for (int i=1; i<=n; i++) {  // find max revenue for length n
            s = p[i] + memoized_cut_rod_aux(p, n-i, r);
            q = (q > s) ? q : s;
        }
    }

    // save max revenue for length n
    r[n] = q;

    return q;
}