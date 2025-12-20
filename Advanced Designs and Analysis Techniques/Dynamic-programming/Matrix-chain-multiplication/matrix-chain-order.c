// Dimensions of matrix Ai are p[i-1]*p[i]
// m[i][j] contains optimal cost of the multiplication Ai...Aj
// s[i][j] contains the place of split for the multiplication Ai...Aj
void matrix_chain_order(int *p, int n, int **m, int **s) {
    #define INF 2147483647
    
    for (int i=1; i<=n; i++) {  // base condition
        m[i][i] = 0;
    }

    for (int l=2; l<=n; l++) {  // l is length of chain
        for (int i=1; i<=(n-l+1); i++) {
            int j = i+l-1;
            m[i][j] = INF;

            for (int k=i; k<j; k++) {
                int q = m[i][k] + m[k+1][j] + (p[i-1]*p[k]*p[j]);
                if (q < m[i][j]) {
                    m[i][j] = q;  // save optimal cost
                    s[i][j] = k;  // save place of split
                }
            }
        }
    }
}