struct node {
    int key;
    int satalite;
};

void direct_address_delete(struct node *T, struct node *x) {
    #define NIL -1

    T[x->key].key = NIL;
}