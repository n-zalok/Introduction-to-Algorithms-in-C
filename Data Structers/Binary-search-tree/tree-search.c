// any element in the left subtree is smaller than the node
// any element in the right subtree is larger than the node
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

    if (k < x->key) {  // search the left branch
        return tree_search(x->left, k);
    }
    else {  // search the right branch
        return tree_search(x->right, k);
    }
}