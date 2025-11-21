#include <stdlib.h>
#include <math.h>

int** strassen_method(int** A, int** B, int n) {
    int** square_matrix_scale(int** M, int before, int after, int fill);
    int** power_of_two_strassen(int** A, int** B, int n);

    int power_of_two_n = (int)pow(2, (int)ceil(log2(n)));  // scaling dimension

    if (n != power_of_two_n) {
        // scale matrices A and B filling with zero
        int** A_scaled = square_matrix_scale(A, n, power_of_two_n, 0);
        int** B_scaled = square_matrix_scale(B, n, power_of_two_n, 0);

        int** C_power_of_two = power_of_two_strassen(A_scaled, B_scaled, power_of_two_n);
        int** C = square_matrix_scale(C_power_of_two, power_of_two_n, n, 0);  // scale C down to nxn
        return C;
    }

    else {
        int** C = power_of_two_strassen(A, B, n);
        return C;
    }
}

int** power_of_two_strassen(int** A, int** B, int n) {
    int** random_matrix(int n, int min, int max);
    int*** matrix_split(int** M, int n);
    void matrix_sum(int** C, int** M1, int** M2, int n, int sign);
    void matrix_combine(int** M, int** M11, int** M12, int** M21, int** M22, int n);

    // empty matrix with zero entries to caontain the multiplication result
    int** C = random_matrix(n, 0, 0);

    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
    }

    else {
        // split each nxn matrix into n/2xn/2 matrix
        int*** A_split = matrix_split(A, n);
        int*** B_split = matrix_split(B, n);
        int*** C_split = matrix_split(C, n);

        int** A11 = A_split[0]; int** A12 = A_split[1]; int** A21 = A_split[2]; int** A22 = A_split[3];
        int** B11 = B_split[0]; int** B12 = B_split[1]; int** B21 = B_split[2]; int** B22 = B_split[3];
        int** C11 = C_split[0]; int** C12 = C_split[1]; int** C21 = C_split[2]; int** C22 = C_split[3];

        int** S1 = random_matrix(n/2, 0, 0); matrix_sum(S1, B12, B22, n/2, -1);  //  S1 = B12 - B22 
        int** S2 = random_matrix(n/2, 0, 0); matrix_sum(S2, A11, A12, n/2, 1);   //  S2 = A11 + A12
        int** S3 = random_matrix(n/2, 0, 0); matrix_sum(S3, A21, A22, n/2, 1);   //  S3 = A21 + A22
        int** S4 = random_matrix(n/2, 0, 0); matrix_sum(S4, B21, B11, n/2, -1);  //  S4 = B21 - B11
        int** S5 = random_matrix(n/2, 0, 0); matrix_sum(S5, A11, A22, n/2, 1);   //  S5 = A11 + A22
        int** S6 = random_matrix(n/2, 0, 0); matrix_sum(S6, B11, B22, n/2, 1);   //  S6 = B11 + B22
        int** S7 = random_matrix(n/2, 0, 0); matrix_sum(S7, A12, A22, n/2, -1);  //  S7 = A12 - A22
        int** S8 = random_matrix(n/2, 0, 0); matrix_sum(S8, B21, B22, n/2, 1);   //  S8 = B21 + B22
        int** S9 = random_matrix(n/2, 0, 0); matrix_sum(S9, A11, A21, n/2, -1);  //  S9 = A11 - A21   
        int** S10 = random_matrix(n/2, 0, 0); matrix_sum(S10, B11, B12, n/2, 1); // S10 = B11 + B12

        int** P1 = power_of_two_strassen(A11, S1, n/2);  // P1 = A11 * S1
        int** P2 = power_of_two_strassen(S2, B22, n/2);  // P2 = S2  * B22
        int** P3 = power_of_two_strassen(S3, B11, n/2);  // P3 = S3  * B11
        int** P4 = power_of_two_strassen(A22, S4, n/2);  // P4 = A22 * S4
        int** P5 = power_of_two_strassen(S5, S6, n/2);   // P5 = S5  * S6
        int** P6 = power_of_two_strassen(S7, S8, n/2);   // P6 = S7  * S8
        int** P7 = power_of_two_strassen(S9, S10, n/2);  // P7 = S9  * S10

        int** temp1 = random_matrix(n/2, 0, 0);
        int** temp2 = random_matrix(n/2, 0, 0);

        // C11 = P5 + P4 - P2 + P6
        matrix_sum(temp1, P4, P5, n/2, 1); matrix_sum(temp2, P6, P2, n/2, -1); matrix_sum(C11, temp1, temp2, n/2, 1);
        // C12 = P1 + P2
        matrix_sum(C12, P1, P2, n/2, 1);
        // C21 = P3 + P4
        matrix_sum(C21, P3, P4, n/2, 1);
        // C22 = P5 + P1 - P3 - P7
        matrix_sum(temp1, P1, P3, n/2, -1); matrix_sum(temp2, P5, P7, n/2, -1); matrix_sum(C22, temp1, temp2, n/2, 1);

        // combine splits into a full nxn matrix
        matrix_combine(C, C11, C12, C21, C22, n);
    }

    return C;
}