#include <stdlib.h>
#include <time.h>

void random_array(int arr[], int n, int min, int max) {
    srand(time(NULL));
    
    for (int i=0; i<n; i++) {
        //  random integer between min and max [min,max]
        arr[i] = (rand() % (max - min + 1)) + min;
    }
}