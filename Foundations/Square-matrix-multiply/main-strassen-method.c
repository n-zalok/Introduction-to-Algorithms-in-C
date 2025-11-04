#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int** random_matrix(int n, int min, int max);
    int** strassen_method(int** A, int** B, int n);
    int n, min, max;

    printf("Enter matrix size: ");
    scanf("%d", &n);
    printf("Enter matrix min: ");
    scanf("%d", &min);
    printf("Enter matrix max: ");
    scanf("%d", &max);

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

    int** C = strassen_method(A, B, n);

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