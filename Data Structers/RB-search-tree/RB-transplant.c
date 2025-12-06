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

void RB_transplant(struct tree *T, struct node *u, struct node *v) {
    if (u->p == T->null) {
        T->root = v;
    }
    else if (u == u->p->left) {
        u->p->left = v;
    }
    else {
        u->p->right = v;
    }

    v->p = u->p;
}