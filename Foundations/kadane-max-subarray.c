struct subarray {
    int low;
    int high;
    int sum;
};

struct subarray kadane_max_subarray(int arr[], int n) {
    #define INF 2147483647

    int sum = -INF;
    int current_low, current_high;
    struct subarray result = {0, 0, -INF};

    for (int i=0; i<n; i++) {
        current_high = i;
        if(sum > 0) {
            sum += arr[i];
        }
        else {
            current_low = i;
            sum = arr[i];
        }

        if (sum > result.sum) {
            result = (struct subarray){current_low, current_high, sum};
        }
    }

    return result;
}