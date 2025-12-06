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

void right_rotate(struct tree *T, struct node *x) {
    struct node *y = x->left;
    x->left = y->right;

    if (y->right != T->null) {
        y->right->p = x;
    }
    y->p = x->p;

    if (x->p == T->null) {
        T->root = y;
    }
    else if (x == x->p->right) {
        x->p->right = y;
    }
    else {
        x->p->left = y;
    }

    y->right = x;
    x->p = y;
}