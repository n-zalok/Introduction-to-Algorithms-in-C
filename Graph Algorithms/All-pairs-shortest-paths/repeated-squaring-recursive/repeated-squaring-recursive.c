#include <stdlib.h>

int*** repeated_squaring_recursive(int **W, int **P, int n) {
    int*** extend_shortest_path(int **L, int **W, int **P, int n);
    
    int **L = malloc(sizeof(int*) * n);
    int **P_ = malloc(sizeof(int*) * n);
    for (int i=0; i<n; i++) {
        L[i] = malloc(sizeof(int) * n);
        P_[i] = malloc(sizeof(int) * n);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            L[i][j] = W[i][j];
            P_[i][j] = P[i][j];
        }
    }

    int ***location = malloc(sizeof(int**) * 2);
    int m = 1;
    while (m < (n-1)) {
        location = extend_shortest_path(L, W, P_, n);
        L = location[0];
        P_ = location[1];
        m = 2 * m;
    }

    
    location[0] = L;
    location[1] = P_;

    return location;
}