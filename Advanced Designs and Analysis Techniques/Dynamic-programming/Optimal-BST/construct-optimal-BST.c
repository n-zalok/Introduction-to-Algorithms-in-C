#include <stdio.h>

void construct_optimal_BST(int **root, int n) {
    void print_recursive(int **root, int i, int j, char direction);

    int r = root[1][n];
    printf("k%d is the root\n", r);

    print_recursive(root, 1, r-1, 'l');
    print_recursive(root, r+1, n, 'r');
}

void print_recursive(int **root, int i, int j, char direction) {
    if (i > j) {
        if (direction == 'l') {
            printf("d%d is the left child of k%d\n", i-1, i);
        }
        else {
            printf("d%d is the right child of k%d\n", j, j);
        }
    }

    else {
        int r = root[i][j];

        if (direction == 'l') {
            printf("k%d is the left child of k%d\n", r, j+1);
            
        }
        else {
            printf("k%d is the right child of k%d\n", r, i-1);
        }

        print_recursive(root, i, r-1, 'l');
        print_recursive(root, r+1, j, 'r');
    }
}