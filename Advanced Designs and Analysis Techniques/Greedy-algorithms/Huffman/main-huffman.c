#include <stdio.h>
#include <time.h>
#include <stdlib.h>

struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
};

struct node_ll {
    char character;
    char *code;           
    struct node_ll *next;
};

// linked list (ll)
struct ll {
    struct node_ll *head;
};

int main() {
    srand(time(NULL));
    void random_array(int arr[], int n, int min, int max);
    struct node* huffman(struct node *C, int n);
    struct node_ll* huffman_table(struct node *root);
    int n, min, max;

    // get number of characters in the alphabet
    do {
        printf("Enter number of characters(0<n<=26): ");
        scanf("%d", &n);
    }
    while (n <= 0 || n > 26);

    // get min and max frequency
    do {
        printf("Enter min frequency(min>0): ");
        scanf("%d", &min);
    }
    while (min <= 0);
    do {
        printf("Enter max frequency(max>=min): ");
        scanf("%d", &max);
    }
    while(max < min);

    // generate random array of frequencies
    int freq[n];
    random_array(freq, n, min, max);

    // create the alphabet
    struct node C[n];
    for (int i=0; i<n; i++) {
        C[i].frequency = freq[i];
        C[i].character = 65 + i;
        C[i].left = NULL;
        C[i].right = NULL;
    }

    // print the alphabet alongside frequencies
    printf("Alphabet array (character, frequency): [");
    for (int i=0; i<n; i++) {
        printf(" (%c, %d) ", C[i].character, C[i].frequency);
    }
    printf("]\n");

    // get optimal coding tree
    struct node *root = huffman(C, n);
    
    // get codewords then print them
    struct node_ll *current = huffman_table(root);
    while (current != NULL) {
        printf(" %c : ", current->character);

        char *bit = current->code;
        int i = 0;
        while (bit[i] != '\0') {
            printf("%c", bit[i++]);
        }
        printf("\n");

        current = current->next;
    }

    return 0;
}