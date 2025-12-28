struct node {
    int key;
    int rank;
    struct node *p;
};

struct node* find_set(struct node *x) {
    if (x != x->p) {
        x->p = find_set(x->p);
    }

    return x->p;
}