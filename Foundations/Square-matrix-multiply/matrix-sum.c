void matrix_sum(int** C, int** M1, int** M2, int n, int sign) {
    // sum elements of M1 and M2
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            C[i][j] = M1[i][j] + (M2[i][j] * sign);
        }
    }
}