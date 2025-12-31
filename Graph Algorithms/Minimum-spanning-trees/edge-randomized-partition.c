#include <stdlib.h>
#include <time.h>

struct edge {
    int from;
    int to;
    int w;  // weight
};

int edge_randomized_partition(struct edge *E, int p, int r) {
    int edge_partition(struct edge *A, int p, int r);

    srand(time(NULL));
    int i = (rand() % (r - p + 1)) + p;  // random integer between p and r [p,r]

    int temp;
    // exchange A[r] with A[i] to make A[i] the pivot point
    temp = E[r].w;
    E[r].w = E[i].w;
    E[i].w = temp;

    temp = E[r].from;
    E[r].from = E[i].from;
    E[i].from = temp;

    temp = E[r].to;
    E[r].to = E[i].to;
    E[i].to = temp;

    return edge_partition(E, p, r);
}