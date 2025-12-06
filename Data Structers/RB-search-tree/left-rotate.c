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

void left_rotate(struct tree *T, struct node *x) {
    struct node *y = x->right;
    x->right = y->left;

    if (y->left != T->null) {
        y->left->p = x;
    }
    y->p = x->p;

    if (x->p == T->null) {
        T->root = y;
    }
    else if (x == x->p->left) {
        x->p->left = y;
    }
    else {
        x->p->right = y;
    }

    y->left = x;
    x->p = y;
}