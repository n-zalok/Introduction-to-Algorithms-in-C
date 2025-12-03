struct node {
    int key;           
    struct node *next;
    struct node *prev; 
};

// Doubly linked list (dll)
struct dll {
    struct node *head;
};

void list_delete(struct dll *L, struct node x) {
    #define NULL ((void *)0)

    if (x.prev != NULL) {
        (*(x.prev)).next = x.next;
    }
    else {
        L->head = x.next;
    }

    if (x.next != NULL) {
        (*(x.next)).prev = x.prev;
    }
}