struct node {
    int key;
    int rank;
    struct node *p;
};

void make_set(struct node *x) {
    x->p = x;
    x->rank = 0;
}