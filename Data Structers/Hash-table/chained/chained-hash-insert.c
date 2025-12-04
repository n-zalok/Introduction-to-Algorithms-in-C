struct node {
    int key;           
    struct node *next;
    struct node *prev; 
};

// Doubly linked list (dll)
struct dll {
    struct node *head;
};

void chained_hash_insert(struct dll *T, int k, int m) {
    void list_insert(struct dll *L, int k);
    int hash(int k, int m);

    list_insert(&T[hash(k, m)], k);
}