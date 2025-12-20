#include <stdio.h>

void print_cut_rod_solution(int n, int *s) {
    printf("Cut: [");
    while (n > 0) {
        printf(" %d ", s[n]);  // print the length of the initial cut
        n -= s[n];  // set the length to the remaining rod
    }
    printf("]\n");
}