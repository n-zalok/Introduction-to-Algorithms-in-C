#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    srand(time(NULL));
    void random_double_array(double arr[], int n, double min, double max);
    void double_merge_sort(double arr[], int p, int r);
    void optimal_BST(double *p, double *q, int n, double **e, int **root);
    void construct_optimal_BST(int **root, int n);
    int n;

    // get number of keys
    do {
        printf("Enter number of keys(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);

    // generate keys probability array
    double p[n+1];
    random_double_array(p, n+1, -1, 1);
    // generate dummy keys probability array
    double q[n+1];
    random_double_array(q, n+1, -1, 1);

    // softmax
    double sum = exp(q[0]);
    for (int i=1; i<=n; i++) {
        sum += exp(q[i]);
        sum += exp(p[i]);
    }

    q[0] = exp(q[0]) / sum;
    for (int i=1; i<=n; i++) {
        q[i] = exp(q[i]) / sum;
        p[i] = exp(p[i]) / sum;
    }
    sum = 0.0;

    // sorting
    double_merge_sort(p, 1, n);
    double_merge_sort(q, 0, n);

    // printing keys and dummy keys
    printf("Keys array:       [");
    for (int i=1; i<=n; i++) {
        printf(" %f ", p[i]);
        sum += p[i];
    }
    printf("]\n");

    printf("Dummy keys array: [");
    for (int i=0; i<=n; i++) {
        printf(" %f ", q[i]);
        sum += q[i];
    }
    printf("]\n");

    // make sure probabilities sum to one
    printf("Sum of keys and dummy keys probabilities: %f\n", sum);


    // create array of pointers to represent a matrix    
    double** e = (double**)malloc((n+2) * sizeof(double*));
    int** root = (int**)malloc((n+1) * sizeof(int*));
    // assign each pointer to an n array
    for (int i=0; i<=n; i++) {
        e[i] = (double*)malloc((n+1) * sizeof(double));
        root[i] = (int*)malloc((n+1) * sizeof(int));
    }
    e[n+1] = (double*)malloc((n+1) * sizeof(double));

    // get optimal binary search tree
    optimal_BST(p, q, n, e, root);
    printf("Optimal BST cost: %f\n", e[1][n]);
    construct_optimal_BST(root, n);

    return 0;
}