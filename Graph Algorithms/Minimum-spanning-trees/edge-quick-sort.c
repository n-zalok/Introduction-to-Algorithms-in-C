struct edge {
    int from;
    int to;
    int w;  // weight
};

// sort edges from E[p] to E[r]
void edge_quick_sort(struct edge *E, int p, int r) {
    int edge_randomized_partition(struct edge *E, int p, int r);

    if (p < r) {
        int q = edge_randomized_partition(E, p, r);
        edge_quick_sort(E, p, q-1);
        edge_quick_sort(E, q+1, r);
    }
}