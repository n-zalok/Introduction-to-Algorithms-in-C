#include <stdio.h>
#include <errno.h>

struct heap {
    int *arr;
    int length;
    int heap_size;
};

void heap_increase_key(struct heap A, int i, int key) {
    int parent(int i);

    if (key < A.arr[i]) {
        perror("ERROR: new key is smaller than current key");
    }

    A.arr[i] = key;

    int temp;
    while (i > 0 && A.arr[parent(i)] < A.arr[i]) {
        temp = A.arr[i];
        A.arr[i] = A.arr[parent(i)];
        A.arr[parent(i)] = temp;

        i = parent(i);
    }
}