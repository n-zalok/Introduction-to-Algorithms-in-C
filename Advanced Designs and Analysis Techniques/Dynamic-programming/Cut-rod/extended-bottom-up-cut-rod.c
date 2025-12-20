// p[i] contains the revenue of piece of length i
// r[i] contains max revenue for length n
// s[i] contains length of initial cut for rod of length i
void extended_bottom_up_cut_rod(int *p, int n, int *r, int *s) {  
    #define INF 2147483647                                        
    
    r[0] = 0;  // base condition
    int q;

    for (int j=1; j<=n; j++) {  // find max revenue for length n
        q = -INF;
        for (int i=1; i<=j; i++) {
            if (q < (p[i] + r[j-i])) {
                q = p[i] + r[j-i];
                s[j] = i;  // save the length of initial cut for rod of length j
            }
        }

        // save max revenue for length n
        r[j] = q;
    }
}