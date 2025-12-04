struct node {
    int key;           
    struct node *next;
    struct node *prev; 
};

// Doubly linked list (dll)
struct dll {
    struct node *head;
};

struct node* list_search(struct dll L, int k) {
    #define NULL ((void *)0)

    struct node *x = L.head;
    while (x != NULL && x->key != k) {
        x = x->next;
    }
    
    return x;
}