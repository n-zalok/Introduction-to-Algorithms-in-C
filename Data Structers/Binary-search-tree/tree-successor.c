struct node {
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
};

struct node* tree_successor(struct node *x) {
    #define NULL ((void *)0)
    struct node* tree_minimum(struct node *x);

    if (x->right != NULL) {
        return tree_minimum(x->right);
    }

    struct node *y = x->p;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->p;
    }
    return y;
}