// any element in the left subtree is smaller than the node
// any element in the right subtree is larger than the node
struct node {
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
};

struct node* tree_minimum(struct node *x) {
    #define NULL ((void *)0)

    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}