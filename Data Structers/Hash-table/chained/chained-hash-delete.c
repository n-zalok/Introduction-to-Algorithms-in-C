struct node {
    int key;           
    struct node *next;
    struct node *prev; 
};

// Doubly linked list (dll)
struct dll {
    struct node *head;
};

void chained_hash_delete(struct dll *T, struct node x, int m) {
    void list_delete(struct dll *L, struct node x);
    int hash(int k, int m);

    list_delete(&T[hash(x.key, m)], x);
}