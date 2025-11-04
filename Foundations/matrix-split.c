#include <stdlib.h>

int*** matrix_split(int** M, int n) {
    int** random_matrix(int n, int min, int max);

    int** M11 = random_matrix(n/2, 0, 0);
    int** M12 = random_matrix(n/2, 0, 0);
    int** M21 = random_matrix(n/2, 0, 0);
    int** M22 = random_matrix(n/2, 0, 0);

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i < n/2 && j < n/2) {
                M11[i][j] = M[i][j];
            }
            else if (i < n/2 && j >= n/2) {
                M12[i][j-(n/2)] = M[i][j];
            }
            else if (i >= n/2 && j < n/2) {
                M21[i-(n/2)][j] = M[i][j];
            }
            else if (i >= n/2 && j >= n/2) {
                M22[i-(n/2)][j-(n/2)] = M[i][j];
            }
        }
    }

    int*** arr = (int***)malloc(4 * sizeof(int**));
    arr[0] = M11; arr[1] = M12; arr[2] = M21; arr[3] = M22; 

    return arr;
}