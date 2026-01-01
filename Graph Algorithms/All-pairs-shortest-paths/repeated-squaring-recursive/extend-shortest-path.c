#include <stdlib.h>

int*** extend_shortest_path(int **L, int **W, int **P, int n) {
    #define INF 2147483647
    #define NIL -1

    int **L_ = malloc(sizeof(int*) * n);
    int **P_ = malloc(sizeof(int*) * n);
    for (int i=0; i<n; i++) {
        L_[i] = malloc(sizeof(int) * n);
        P_[i] = malloc(sizeof(int) * n);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            L_[i][j] = INF;
            P_[i][j] = NIL;
            for (int k=0; k<n; k++) {
                if (L[i][k] != INF && W[k][j] != INF && L_[i][j] > (L[i][k] + W[k][j])) {
                    L_[i][j] = L[i][k] + W[k][j];

                    if (k != j) {
                        P_[i][j] = k;
                    }
                    else {
                        P_[i][j] = P[i][j];
                    }
                }
            }
        }
    }

    int ***location = malloc(sizeof(int**) * 2);
    location[0] = L_;
    location[1] = P_;    

    return location;
}