// p[i] contains the revenue of piece of length i
int cut_rod(int *p, int n) {  // find max revenue for rod with length n
    #define INF 2147483647
    
    if (n == 0) {
        return 0;
    }

    int q = -INF;
    int r;
    for (int i=1; i<=n; i++) {  // find max revenue for length n
        r = p[i] + cut_rod(p, n-i);
        q = (q > r) ? q : r;
    }

    return q;
}