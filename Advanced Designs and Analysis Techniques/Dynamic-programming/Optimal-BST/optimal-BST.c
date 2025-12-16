void optimal_BST(double *p, double *q, int n, double **e, int **root) {
    #define INF 1.0/0.0

    double w[n+2][n+2];
    for (int i=1; i<=(n+1); i++) {
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    
    for (int l=1; l<=n; l++) {
        for (int i=1; i<=(n-l+1); i++) {
            int j = i+l-1;
            e[i][j] = INF;
            w[i][j] = w[i][j-1] + p[j] + q[j];

            for (int r=i; r<=j; r++) {
                double t = e[i][r-1] + e[r+1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }
}