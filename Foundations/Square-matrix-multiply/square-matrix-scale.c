int** square_matrix_scale(int** M, int before, int after, int fill) {
    int** random_matrix(int n, int min, int max);

    int** M_scaled = random_matrix(after, 0, 0);

    for (int i=0; i<after; i++) {
        for (int j=0; j<after; j++) {
            if (i >= before || j >= before) {
                M_scaled[i][j] = fill;
            }
            else {
                M_scaled[i][j] = M[i][j];
            }
        }
    }

    return M_scaled;
}