struct subarray {
    int low;   // index of enter element
    int high;  // index of exit element
    int sum;   // sum of elements from low to high
};

struct subarray find_max_crossing_subarray(int arr[], int low, int mid, int high) {
    #define INF 2147483647

    int L_sum = -INF;
    int sum = 0;
    int L_max;  // index of enter element
    for(int i=mid; i>=low; i--) {
        sum += arr[i];
        if(sum > L_sum) {
            L_sum = sum;
            L_max = i;
        }
    }

    int R_sum = -INF;
    sum = 0;
    int R_max;  // index of exit element
    for(int j=mid+1; j<=high; j++) {
        sum += arr[j];
        if(sum > R_sum) {
            R_sum = sum;
            R_max = j;
        }
    }

    struct subarray cross = {L_max, R_max, (L_sum+R_sum)};
    return cross;
}