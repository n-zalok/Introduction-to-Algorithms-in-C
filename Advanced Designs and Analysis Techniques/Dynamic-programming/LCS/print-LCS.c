#include <stdio.h>

void print_LCS(int **b, char *X, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }

    if (b[i][j] == 0) {
        print_LCS(b, X, i-1, j-1);
        printf(" %c ", X[i]);
    }
    else if (b[i][j] == 1) {
        print_LCS(b, X, i-1, j);
    }
    else {
        print_LCS(b, X, i, j-1);
    }
}