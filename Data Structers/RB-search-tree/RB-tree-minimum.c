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

struct node* RB_tree_minimum(struct tree *T, struct node *x) {
    while (x->left != T->null) {
        x = x->left;
    }
    return x;
}