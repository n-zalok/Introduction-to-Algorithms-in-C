struct node {
    int key;
    char color;
    struct node *p;
    struct node *left;
    struct node *right;
};

struct tree {
    struct node *root;
    struct node *null;
};

struct node* RB_iterative_tree_search(struct tree *T, struct node *x, int k) {
    while (x != T->null && k != x->key) {
        if (k < x->key) {
            x = x->left;
        }
        else {
            x = x->right;
        }
    }

    return x;
}