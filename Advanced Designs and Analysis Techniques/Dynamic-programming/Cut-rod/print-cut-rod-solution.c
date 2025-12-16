#include <stdio.h>

void print_cut_rod_solution(int n, int *s) {
    printf("Cut: [");
    while (n > 0) {
        printf(" %d ", s[n]);
        n -= s[n];
    }
    printf("]\n");
}