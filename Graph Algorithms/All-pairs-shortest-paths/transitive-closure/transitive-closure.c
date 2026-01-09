#include <stdlib.h>

// return Tk where Tk[i][j] is 1 if a path
// exists from i to j and 0 otherwise
// W is weight matrix
int** transitive_closure(int **W, int n) {
    #define INF 2147483647

    // initialize Tk_1 and Tk
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
                // if a path already exists from i to j Tk_1[i][j] = 1 or
                // both a path from i to k and a path from k to j exist Tk_1[i][k] = Tk_1[k][j] = 1
                // then a path exists from i to j
                Tk[i][j] = Tk_1[i][j] | (Tk_1[i][k] & Tk_1[k][j]);
            }
        }

        // exchange Tk_1 and Tk to use new values as Tk_1
        int **temp = Tk;
        Tk = Tk_1;
        Tk_1 = temp;
    }

    // since we exchange Tk_1 with Tk at the end of each iteration
    // Tk_1 contains latest values of Tk
    return Tk_1;
}