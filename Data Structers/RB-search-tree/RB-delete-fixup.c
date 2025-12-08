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

void RB_delete_fixup(struct tree *T, struct node *x) {
    void left_rotate(struct tree *T, struct node *x);
    void right_rotate(struct tree *T, struct node *x);

    struct node *w;

    while (x != T->root && x->color == 'b') {
        if (x == x->p->left) {
            w = x->p->right;

            if (x->color == 'r') {  // case 1
                w->color = 'b';
                x->p->color = 'r';
                left_rotate(T, x->p);
                w = x->p->right;
            }

            if (w->left->color == 'b' && w->right->color =='b') {  // case 2
                w->color = 'r';
                x = x->p;
            }
            else {
                if (w->right->color == 'b') { // case 3
                    w->left->color = 'b';
                    w->color = 'r';
                    right_rotate(T, w);
                    w = x->p->right;
                }

                // case 4
                w->color = x->p->color;
                x->p->color = 'b';
                w->right->color = 'b';
                left_rotate(T, x->p);
                x = T->root;
            }
        }
        else {  // same but with left and right exchanged
            w = x->p->left;

            if (x->color == 'r') {
                w->color = 'b';
                x->p->color = 'r';
                right_rotate(T, x->p);
                w = x->p->left;
            }

            if (w->right->color == 'b' && w->left->color =='b') {
                w->color = 'r';
                x = x->p;
            }
            else {
                if (w->left->color == 'b') {
                    w->right->color = 'b';
                    w->color = 'r';
                    left_rotate(T, w);
                    w = x->p->left;
                }
                w->color = x->p->color;
                x->p->color = 'b';
                w->left->color = 'b';
                right_rotate(T, x->p);
                x = T->root;
            }
        }
    }
}