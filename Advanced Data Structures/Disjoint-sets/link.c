struct node {
    int key;
    int rank;
    struct node *p;
};

void link(struct node *x, struct node *y) {
    if (x->rank > y->rank) {
        y->p = x;
    }
    else {
        x->p = y;
        if (x->rank == y->rank) {
            y->rank += 1;
        }
    }
}