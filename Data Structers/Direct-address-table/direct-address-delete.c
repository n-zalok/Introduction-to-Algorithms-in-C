struct node {
    int key;
    int satalite;
};

void direct_address_delete(struct node *T, struct node x) {
    T[x.key].key = -1;
}