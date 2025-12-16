void LCS_length(char *X, char *Y, int m, int n, int **b, int **c) {
    for (int i=1; i<=m; i++) {
        c[i][0] = 0;
    }
    for (int j=0; j<=n; j++) {
        c[0][j] = 0;
    }

    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (X[i] == Y[j]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 0;
            }
            else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 1;
            }
            else {
                c[i][j] = c[i][j-1];
                b[i][j] = -1;
            }
        }
    }
}