#include <stdio.h>

void print_all_pairs_path(int **P, int i, int j) {
    #define NIL -1
    
    if (i == j) {
        printf("%d ", i);
    }
    else if (P[i][j] == NIL) {
        printf("no path from %d to %d exists ", i, j);
    }
    else {
        print_all_pairs_path(P, i, P[i][j]);
        printf("%d ", j);
    }
}