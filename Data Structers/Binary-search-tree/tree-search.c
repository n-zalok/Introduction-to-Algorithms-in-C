struct node {
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
};

struct node* tree_search(struct node *x, int k) {
    #define NULL ((void *)0)

    if (x == NULL || k == x->key) {
        return x;
    }

    if (k < x->key) {
        return tree_search(x->left, k);
    }
    else {
        return tree_search(x->right, k);
    }
}