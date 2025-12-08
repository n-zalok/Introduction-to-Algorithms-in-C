#include <stdio.h>

// any element in the left subtree is smaller than the node
// any element in the right subtree is larger than the node
struct node {
    int key;
    struct node *p;
    struct node *left;
    struct node *right;
};

void inorder_tree_walk(struct node *x) {
    #define NULL ((void *)0)

    if (x != NULL) {
        inorder_tree_walk(x->left);
        printf(" %d ", x->key);
        inorder_tree_walk(x->right);
    } 
}