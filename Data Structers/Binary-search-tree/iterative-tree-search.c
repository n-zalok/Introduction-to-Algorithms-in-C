// any element in the left subtree is smaller than the node
// any element in the right subtree is larger than the node
struct node {
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
};

struct node* iterative_tree_search(struct node *x, int k) {
    #define NULL ((void *)0)

    while (x != NULL && k != x->key) {
        if (k < x->key) {  // search the left branch
            x = x->left;
        }
        else {  // search the right branch
            x = x->right;
        }
    }

    return x;
}