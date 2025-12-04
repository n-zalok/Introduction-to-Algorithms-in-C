struct node {
    int key;           
    struct node *next;
    struct node *prev; 
};

// Doubly linked list (dll)
struct dll {
    struct node *head;
};

struct node* chained_hash_search(struct dll *T, int k, int m) {
    struct node* list_search(struct dll L, int k);
    int hash(int k, int m);

    return list_search(T[hash(k, m)], k);
}