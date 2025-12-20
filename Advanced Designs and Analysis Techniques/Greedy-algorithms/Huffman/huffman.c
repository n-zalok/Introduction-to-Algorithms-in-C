#include <stdlib.h>

struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
};

struct heap {
    struct node *arr;
    int length;
    int heap_size;
};

// C and n are the alphabet and its size
struct node* huffman(struct node *C, int n) {
    void build_min_heap(struct heap *A);
    struct node* heap_extract_min(struct heap *A);
    void min_heap_insert(struct heap *A, struct node *z);

    // initialize the heap
    struct heap *Q = malloc(sizeof(struct heap));
    Q->arr = C;
    Q->length = n;

    // build a min heap
    build_min_heap(Q);

    for (int i=0; i<(n-1); i++) {
        struct node *z = malloc(sizeof(struct node));  // create z
        z->left = heap_extract_min(Q);                 // make the least and the second least
        z->right = heap_extract_min(Q);                // elements its children
        z->frequency = z->left->frequency + z->right->frequency;  // make its frequency the sum of theirs
        z->character = '!';  // representing a node to distinguish it from leaf
        min_heap_insert(Q, z);
    }

    // return root of the tree
    return heap_extract_min(Q);
}

