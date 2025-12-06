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

void RB_delete(struct tree *T, struct node *z) {
    void RB_transplant(struct tree *T, struct node *u, struct node *v);
    struct node* RB_tree_minimum(struct tree *T, struct node *x);
    void RB_delete_fixup(struct tree *T, struct node *x);

    struct node *x;
    struct node *y = z;
    char y_original_color = y->color;

    if (z->left == T->null) {
        x =  z->right;
        RB_transplant(T, z, z->right);
    }
    else if (z->right == T->null) {
        x = z->right;
        RB_transplant(T, z, z->left);
    }
    else {
        y = RB_tree_minimum(T, z->right);
        x = y->right;

        if (y->p == z) {
            x->p = y;
        }
        else {
            RB_transplant(T, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }

        RB_transplant(T, z, y);
        y->left = z->left;
        y->left->p = y;
        y->color = z->color;

        if (y_original_color == 'b') {
            RB_delete_fixup(T, x);
        }
    }
}