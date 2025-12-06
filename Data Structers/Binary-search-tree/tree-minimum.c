struct node {
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
};

struct node* tree_minimum(struct node *x) {
    #define NULL ((void *)0)

    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}