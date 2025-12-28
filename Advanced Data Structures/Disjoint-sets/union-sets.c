struct node {
    int key;
    int rank;
    struct node *p;
};

void union_sets(struct node *x, struct node *y) {
    void link(struct node *x, struct node *y);
    struct node* find_set(struct node *x);
    
    link(find_set(x), find_set(y));
}