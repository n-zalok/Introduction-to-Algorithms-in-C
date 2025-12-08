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

void RB_insert_fixup(struct tree *T, struct node *z) {
    void left_rotate(struct tree *T, struct node *x);
    void right_rotate(struct tree *T, struct node *x);

    struct node *y;

    while (z->p->color == 'r') {
        if (z->p == z->p->p->left) {
            y = z->p->p->right;
            
            if (y->color == 'r') {  // case 1
                z->p->color = 'b';
                y->color = 'b';
                z->p->p->color = 'b';
                z = z->p->p;
            }
            else {
                if (z == z->p->right) {  // case 2
                    z = z->p;
                    left_rotate(T, z);
                }
                
                // case 3
                z->p->color = 'b';
                z->p->p->color = 'r';
                right_rotate(T, z->p->p);
            }
        }
        else {  // same but with left and right exchanged
            y = z->p->p->left;
            
            if (y->color == 'r') {
                z->p->color = 'b';
                y->color = 'b';
                z->p->p->color = 'b';
                z = z->p->p;
            }
            else {
                if (z == z->p->left) {
                    z = z->p;
                    right_rotate(T, z);
                }
                z->p->color = 'b';
                z->p->p->color = 'r';
                left_rotate(T, z->p->p);
            }
        }

    }

    T->root->color = 'b';
}