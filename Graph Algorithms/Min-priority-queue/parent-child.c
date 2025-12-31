#include <math.h>

int parent(int i) {
    return floor((i-1)/2);
}

int left(int i) {
    return ((2*i) + 1);
}

int right(int i) {
    return (2 * (i+1));
}