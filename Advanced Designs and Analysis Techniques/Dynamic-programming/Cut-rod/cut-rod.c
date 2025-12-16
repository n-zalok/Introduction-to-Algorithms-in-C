int cut_rod(int *p, int n) {
    #define INF 2147483647
    
    if (n == 0) {
        return 0;
    }

    int q = -INF;
    int r;
    for (int i=1; i<=n; i++) {
        r = p[i] + cut_rod(p, n-i);
        q = (q > r) ? q : r;
    }

    return q;
}