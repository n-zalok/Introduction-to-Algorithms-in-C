// p[i] is the probability of ki and q[i] is the probability of di
// n is the number of keys
// e[i][j] contains the cost of optimal subtree having <ki, ..., kj> and <di-1, ..., dj>
// root[i][j] contains the root of optimal subtree having <ki, ..., kj> and <di-1, ..., dj>
void optimal_BST(double *p, double *q, int n, double **e, int **root) {
    #define INF 1.0/0.0

    // w[i][j] is the increase of cost of optimal subtrees containing
    // <ki, ..., kr> or <kr, ..., kj> where i<= r <=j
    double w[n+2][n+2];
    for (int i=1; i<=(n+1); i++) {
        e[i][i-1] = q[i-1];
        w[i][i-1] = q[i-1];
    }
    
    for (int l=1; l<=n; l++) {  // l is number of keys
        for (int i=1; i<=(n-l+1); i++) {
            int j = i+l-1;
            e[i][j] = INF;
            w[i][j] = w[i][j-1] + p[j] + q[j];

            for (int r=i; r<=j; r++) {
                double t = e[i][r-1] + e[r+1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;     // save optimal cost
                    root[i][j] = r;  // save root
                }
            }
        }
    }
}