struct edge {
    int from;
    int to;
    int w;  // weight
};

int edge_partition(struct edge *E, int p, int r) {
    int x = E[r].w;  // pivot point
    int i = p - 1;
    int temp;

    for (int j=p; j<r; j++) {
        if (E[j].w <= x) {
            i += 1;
            //exchange A[i] with A[j]
            temp = E[i].w;
            E[i].w = E[j].w;
            E[j].w = temp;

            temp = E[i].from;
            E[i].from = E[j].from;
            E[j].from = temp;

            temp = E[i].to;
            E[i].to = E[j].to;
            E[j].to = temp;
        }
    }

    // set pivot point in its correct position
    temp = E[i+1].w;
    E[i+1].w = E[r].w;
    E[r].w = temp;

    temp = E[i+1].from;
    E[i+1].from = E[r].from;
    E[r].from = temp;

    temp = E[i+1].to;
    E[i+1].to = E[r].to;
    E[r].to = temp;

    // return pivot point index 
    return i+1;
}