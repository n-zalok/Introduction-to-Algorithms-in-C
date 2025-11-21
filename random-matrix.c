#include <stdlib.h>

int** random_matrix(int n, int min, int max) {
    // create array of pointers to represent a matrix    
    int** matrix = (int**)malloc(n * sizeof(int*));

    // assign each pointer to an n array
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //  random integer between min and max [min,max]
            matrix[i][j] = (rand() % (max - min + 1)) + min;
        }
    }

    return matrix;
}