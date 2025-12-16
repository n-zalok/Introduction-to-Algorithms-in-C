#include <stdio.h>
#include <time.h>

int main() {
    void random_increasing_array(int arr[], int n, int min, int max);
    int cut_rod(int *p, int n);
    int* memoized_cut_rod(int *p, int n);
    void extended_bottom_up_cut_rod(int *p, int n, int *r, int *s);
    void print_cut_rod_solution(int n, int *s);
    int n, min, max;

    // get rod length
    do {
        printf("Enter rod length(n>0): ");
        scanf("%d", &n);
    }
    while (n <= 0);

    // get min and max revenue
    do {
        printf("Enter min revenue(min>0): ");
        scanf("%d", &min);
    }
    while (min <= 0);
    do {
        printf("Enter max revenue(max>0): ");
        scanf("%d", &max);
    }
    while (max <= 0);

    // generate random revenue array
    int p[n+1];
    random_increasing_array(p, n+1, min, max);

    printf("Revenue array: [");
    for (int i=1; i<=n; i++) {
        printf(" %d ", p[i]);
    }
    printf("]\n");


    clock_t start, end;
    double cpu_time_used;

    start = clock();
    int recursive_revenue = cut_rod(p, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Recursive cut rod|  max_revenue: %d    time: %fs\n", recursive_revenue, cpu_time_used);

    start = clock();
    int* r_ = memoized_cut_rod(p, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    int memoized_revenue = r_[n];
    printf("Memoized cut rod |  max_revenue: %d    time: %fs\n", memoized_revenue, cpu_time_used);

    int r[n+1];
    int s[n+1];
    start = clock();
    extended_bottom_up_cut_rod(p, n, r, s);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    int  bottom_up_revenue = r[n];
    printf("Bottom-Up cut rod|  max_revenue: %d    time: %fs\n", bottom_up_revenue, cpu_time_used);


    print_cut_rod_solution(n, s);

    return 0;
}