#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    void random_array(int arr[], int n, int min, int max);
    void matrix_chain_order(int *p, int n, int **m, int **s);
    void print_optimal_parens(int **s, int i, int j);
    int n, min, max;

    // get array size, min and max
    do {
        printf("Enter number of matrices(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);
    // get min and max dimension
    do {
        printf("Enter min dimension(min>0): ");
        scanf("%d", &min);
    }
    while (min <= 0);
    do {
        printf("Enter max dimension(max>0): ");
        scanf("%d", &max);
    }
    while (max <= 0);

    // generate dimensions array
    int p[n+1];
    random_array(p, n+1, min, max);

    printf("Dimensions array: [");
    for (int i=0; i<=n; i++) {
        printf(" %d ", p[i]);
    }
    printf("]\n");


    // create array of pointers to represent a matrix    
    int** m = (int**)malloc((n+1) * sizeof(int*));
    int** s = (int**)malloc((n+1) * sizeof(int*));
    // assign each pointer to an n array
    for (int i=0; i<=n; i++) {
        m[i] = (int*)malloc((n+1) * sizeof(int));
        s[i] = (int*)malloc((n+1) * sizeof(int));
    }

    matrix_chain_order(p, n, m, s);
    printf("Parenthesization: ");
    print_optimal_parens(s, 1, n);
    printf("\n");

    return 0;
}