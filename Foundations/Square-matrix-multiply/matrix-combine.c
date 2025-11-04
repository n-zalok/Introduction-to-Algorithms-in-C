int matrix_combine(int** M, int** M11, int** M12, int** M21, int** M22, int n) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i < n/2 && j < n/2) {
                M[i][j] = M11[i][j];
            }
            else if (i < n/2 && j >= n/2) {
                M[i][j] = M12[i][j-(n/2)];
            }
            else if (i >= n/2 && j < n/2) {
                M[i][j] = M21[i-(n/2)][j];
            }
            else if (i >= n/2 && j >= n/2) {
                M[i][j] = M22[i-(n/2)][j-(n/2)];
            }
        }
    }
}