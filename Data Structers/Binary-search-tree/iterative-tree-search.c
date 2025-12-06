struct node {
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
};

struct node* iterative_tree_search(struct node *x, int k) {
    #define NULL ((void *)0)

    while (x != NULL && k != x->key) {
        if (k < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }

    return x;
}