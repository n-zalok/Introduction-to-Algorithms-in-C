struct node {
    int key;
    int rank;
    struct node *p;
};

int same_component(struct node *u, struct node *v) {
    struct node* find_set(struct node *x);

    if (find_set(u) == find_set(v)) {
        return 1;
    }
    else {
        return 0;
    }
}