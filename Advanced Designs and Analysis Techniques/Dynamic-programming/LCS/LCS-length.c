// X and Y are the two sequences and m and n are their length
// c[i][j] contains the length of LCS of sequences <x1, x2, ..., xi> and <y1, y2, ..., yj>
// b[i][j] contains the direction that leads to the table's entry corresponding to
// optimal subproblem solution chosen when computing c[i][j] (-1 = left, 1 = up, 0 = up-left)
void LCS_length(char *X, char *Y, int m, int n, int **b, int **c) {
    for (int i=1; i<=m; i++) {  // base condition
        c[i][0] = 0;
    }
    for (int j=0; j<=n; j++) {  // base condition
        c[0][j] = 0;
    }

    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (X[i] == Y[j]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 0;  // Xm-1 Yn-1
            }
            else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 1;  // Xm-1 Yn
            }
            else {
                c[i][j] = c[i][j-1];
                b[i][j] = -1;  // Xm Yn-1
            }
        }
    }
}