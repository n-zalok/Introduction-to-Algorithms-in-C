#include <stdio.h>
#include <errno.h>

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

void heap_decrease_key(struct heap A, int i, int key) {
    int parent(int i);

    // error if new key is larger than current key
    if (key > A.arr[i].frequency) {
        perror("ERROR: new key is larger than current key");
    }

    A.arr[i].frequency = key;

    // re-minimize the heap
    struct node temp;
    while (i > 0 && A.arr[parent(i)].frequency > A.arr[i].frequency) {
        temp = A.arr[i];
        A.arr[i] = A.arr[parent(i)];
        A.arr[parent(i)] = temp;

        i = parent(i);
    }
}