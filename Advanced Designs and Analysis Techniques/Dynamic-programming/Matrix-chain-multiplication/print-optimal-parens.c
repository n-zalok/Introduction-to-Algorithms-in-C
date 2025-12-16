#include <stdio.h>

void print_optimal_parens(int **s, int i, int j) {
    if (i == j) {
        printf("A%d", i);
    }
    else {
        printf("(");
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j]+1, j);
        printf(")");
    }
}