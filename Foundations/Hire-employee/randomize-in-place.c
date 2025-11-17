#include <stdlib.h>
#include <time.h>

void randomize_in_place(int arr[], int n) {
    srand(time(NULL));
    
    for (int i=0; i<n; i++) {
        int temp = arr[i];
        int index = (rand() % (n - i)) + i;
        arr[i] = arr[index];
        arr[index] = temp;
    }
}