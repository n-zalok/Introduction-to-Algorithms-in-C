#include <stdio.h>

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