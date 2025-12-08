// any element in the left subtree is smaller than the node
// any element in the right subtree is larger than the node
struct node {
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
};

struct tree {
    struct node *root;
};

void transplant(struct tree *T, struct node *u, struct node *v) { // put v in u's place
    #define NULL ((void *)0)

    if (u->p == NULL) {
        T->root = v;
    }
    else if (u == u->p->left) {
        u->p->left = v;
    }
    else {
        u->p->right = v;
    }

    if (v != NULL) {
        v->p = u->p;
    }
}