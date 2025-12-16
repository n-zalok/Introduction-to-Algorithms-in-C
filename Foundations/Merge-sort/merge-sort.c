#include <math.h>

void merge_sort(int arr[], int p, int r) {
    void merge(int arr[], int p, int q, int r);

    if (p < r) {
        int q = floor((p + r)/2);
        merge_sort(arr, p, q);
        merge_sort(arr, q+1, r);
        merge(arr, p, q, r);
    }
}