#include <math.h>

// return parent of ith element
int parent(int i) {
    return floor((i-1)/2);
}

// return left child of ith element
int left(int i) {
    return ((2*i) + 1);
}

// return right child of ith element
int right(int i) {
    return (2 * (i+1));
}