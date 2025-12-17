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

struct node* huffman(struct node *C, int n) {
    void build_min_heap(struct heap *A);
    struct node* heap_extract_min(struct heap *A);
    void min_heap_insert(struct heap *A, struct node *z);

    struct heap *Q = malloc(sizeof(struct heap));
    Q->arr = C;
    Q->length = n;
    build_min_heap(Q);

    for (int i=0; i<(n-1); i++) {
        struct node *z = malloc(sizeof(struct node));
        z->left = heap_extract_min(Q);
        z->right = heap_extract_min(Q);
        z->frequency = z->left->frequency + z->right->frequency;
        z->character = '!';
        min_heap_insert(Q, z);
    }

    return heap_extract_min(Q);
}

