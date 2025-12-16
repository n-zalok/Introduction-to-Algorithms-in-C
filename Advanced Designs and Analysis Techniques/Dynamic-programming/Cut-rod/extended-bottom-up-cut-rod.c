void extended_bottom_up_cut_rod(int *p, int n, int *r, int *s) {
    #define INF 2147483647
    
    r[0] = 0;
    int q;

    for (int j=1; j<=n; j++) {
        q = -INF;
        for (int i=1; i<=j; i++) {
            if (q < (p[i] + r[j-i])) {
                q = p[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
}