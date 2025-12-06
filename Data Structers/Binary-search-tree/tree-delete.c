struct node {
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
};

struct tree {
    struct node *root;
};

void tree_delete(struct tree *T, struct node *z) {
    #define NULL ((void *)0)
    void transplant(struct tree *T, struct node *u, struct node *v);
    struct node* tree_minimum(struct node *x);

    if (z->left == NULL) {
        transplant(T, z, z->right);
    }
    else if (z->right == NULL) {
        transplant(T, z, z->left);
    }
    else {
        struct node *y = tree_minimum(z->right);
        if (y->p != z) {
            transplant(T, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }

        transplant(T, z, y);
        y->left = z->left;
        y->left->p = y;
    }

}