struct node {
    int key;
    int satalite;
};

struct node* direct_address_search(struct node *T, int k) {
    return &T[k];
}