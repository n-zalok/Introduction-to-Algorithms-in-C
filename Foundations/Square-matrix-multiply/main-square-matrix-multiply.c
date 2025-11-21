#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int** random_matrix(int n, int min, int max);
    int** square_matrix_multiply(int** A, int** B, int n);
    int n, min, max;

    // get matrix size, min and max
    do {
        printf("Enter matrix size(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);
    printf("Enter matrix min: ");
    scanf("%d", &min);
    printf("Enter matrix max: ");
    scanf("%d", &max);

    // generate random matrices
    srand(time(NULL));
    int** A = random_matrix(n, min, max);
    int** B = random_matrix(n, min, max);

    printf("matrices:\n");
    for (int i=0; i<n; i++) {
        printf("[");
        for (int j=0; j<n; j++) {
            printf(" %d ", A[i][j]);
        }

        printf("]    [");

        for (int j=0; j<n; j++) {
            printf(" %d ", B[i][j]);
        }
        printf("]\n");
    }

    // multiply A and B
    int** C = square_matrix_multiply(A, B, n);

    printf("multiplication:\n");
    for (int i=0; i<n; i++) {
        printf("[");
        for (int j=0; j<n; j++) {
            printf(" %d ", C[i][j]);
        }
        printf("]\n");
    }

    return 0;
}