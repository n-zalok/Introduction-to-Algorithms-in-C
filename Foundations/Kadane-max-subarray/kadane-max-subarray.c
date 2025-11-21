struct subarray {
    int low;   // index of enter element
    int high;  // index of exit element
    int sum;   // sum of elements from low to high
};

struct subarray kadane_max_subarray(int arr[], int n) {
    #define INF 2147483647

    int sum = -INF;
    int current_low, current_high;
    struct subarray result = {0, 0, -INF};

    for (int i=0; i<n; i++) {
        current_high = i;
        // if the current sum is positive add the element to the subarray
        if(sum > 0) {
            sum += arr[i];
        }

        // else make the element the start of a new subarray
        else {
            current_low = i;
            sum = arr[i];
        }

        // if the current sum is larger than the largest sum replace it
        if (sum > result.sum) {
            result = (struct subarray){current_low, current_high, sum};
        }
    }

    return result;
}