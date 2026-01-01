#include <stdlib.h>

int** transitive_closure(int **W, int n) {
    #define INF 2147483647

    int **Tk_1 = malloc(sizeof(int*) * n);
    int **Tk = malloc(sizeof(int*) * n);
    for (int i=0; i<n; i++) {
        Tk_1[i] = malloc(sizeof(int) * n);
        Tk[i] = malloc(sizeof(int) * n);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j || W[i][j] != INF) {
                Tk_1[i][j] = 1;
            }
            else {
                Tk_1[i][j] = 0;
            }
        }
    }

    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                Tk[i][j] = Tk_1[i][j] | (Tk_1[i][k] & Tk_1[k][j]);
            }
        }

        int **temp = Tk;
        Tk = Tk_1;
        Tk_1 = temp;
    }

    return Tk_1;
}