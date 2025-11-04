#include <math.h>

struct subarray {
    int low;
    int high;
    int sum;
};

struct subarray find_max_subarray(int arr[], int low, int high) {
    struct subarray find_max_crossing_subarray(int arr[], int low, int mid, int high);

    if(high == low) {
        struct subarray result = {low, high, arr[low]};
        return result;
    }

    else {
        int mid = floor((low + high)/2);
        struct subarray left = find_max_subarray(arr, low, mid);
        struct subarray right = find_max_subarray(arr, mid+1, high);
        struct subarray cross = find_max_crossing_subarray(arr, low, mid, high);

        if(left.sum >= right.sum && left.sum >= cross.sum) {
            return left;
        }
        else if(right.sum >= left.sum && right.sum >= cross.sum) {
            return right;
        }
        else {
            return cross;
        }
    }
}