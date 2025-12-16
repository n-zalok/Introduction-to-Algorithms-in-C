#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char* DNA(int n);
    void LCS_length(char *X, char *Y, int m, int n, int **b, int **c);
    void print_LCS(int **b, char *X, int i, int j);
    int m, n;

    // get X and Y lenghth
    do {
        printf("Enter X length(m>0): ");
        scanf("%d", &m);
    }
    while (m <= 0);
    do {
        printf("Enter Y length(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);

    // generate X and Y
    char *X = DNA(m);
    char *Y = DNA(n);

    printf("X: [");
    for (int i=1; i<=m; i++) {
        printf(" %c ", X[i]);
    }
    printf("]\n");

    printf("Y: [");
    for (int j=1; j<=n; j++) {
        printf(" %c ", Y[j]);
    }
    printf("]\n");


    // create array of pointers to represent a matrix    
    int** b = (int**)malloc((m+1) * sizeof(int*));
    int** c = (int**)malloc((m+1) * sizeof(int*));
    // assign each pointer to an n array
    for (int i=0; i<=m; i++) {
        b[i] = (int*)malloc((n+1) * sizeof(int));
        c[i] = (int*)malloc((n+1) * sizeof(int));
    }

    LCS_length(X, Y, m, n, b, c);
    printf("LCS length: %d\n", c[m][n]);
    printf("LCS: [");
    print_LCS(b, X, m, n);
    printf("]\n");

    return 0;
}