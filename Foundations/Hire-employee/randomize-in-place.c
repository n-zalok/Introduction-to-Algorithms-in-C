#include <stdlib.h>
#include <time.h>

void randomize_in_place(int arr[], int n) {
    srand(time(NULL));
    int temp, index;

    for (int i=0; i<n; i++) {
        index = (rand() % (n - i)) + i;  // random index from i to n-1

        // exchange arr[i] with arr[index]
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
}