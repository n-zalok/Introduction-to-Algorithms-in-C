#include <stdlib.h>
#include <time.h>

void random_double_array(double arr[], int n, double min, double max) {
    srand(time(NULL));
    
    for (int i=0; i<n; i++) {
        // random double between min and max [min,max)
        double scale = (double)rand() / (RAND_MAX + 1.0);
        arr[i] = (scale * (max - min)) + min;
    }
}