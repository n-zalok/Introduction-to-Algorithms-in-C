#include <stdlib.h>
#include <math.h>

int** square_matrix_multiply(int** A, int** B, int n) {
    int** square_matrix_scale(int** M, int before, int after, int fill);
    int** power_of_two_square_matrix_multiply(int** A, int** B, int n);

    int power_of_two_n = (int)pow(2, (int)ceil(log2(n)));  // scaling dimension 

    if (n != power_of_two_n) {
        // scale matrices A and B filling with zero
        int** A_scaled = square_matrix_scale(A, n, power_of_two_n, 0);
        int** B_scaled = square_matrix_scale(B, n, power_of_two_n, 0);

        int** C_power_of_two = power_of_two_square_matrix_multiply(A_scaled, B_scaled, power_of_two_n);
        int** C = square_matrix_scale(C_power_of_two, power_of_two_n, n, 0);  // scale C down to nxn
        return C;
    }

    else {
        int** C = power_of_two_square_matrix_multiply(A, B, n);
        return C;
    }
}

int** power_of_two_square_matrix_multiply(int** A, int** B, int n) {
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

        // sum the result of multiplication of splits
        matrix_sum(C11, power_of_two_square_matrix_multiply(A11, B11, n/2), power_of_two_square_matrix_multiply(A12, B21, n/2), n/2, 1);
        matrix_sum(C12, power_of_two_square_matrix_multiply(A11, B12, n/2), power_of_two_square_matrix_multiply(A12, B22, n/2), n/2, 1);
        matrix_sum(C21, power_of_two_square_matrix_multiply(A21, B11, n/2), power_of_two_square_matrix_multiply(A22, B21, n/2), n/2, 1);
        matrix_sum(C22, power_of_two_square_matrix_multiply(A21, B12, n/2), power_of_two_square_matrix_multiply(A22, B22, n/2), n/2, 1);

        // combine splits into a full nxn matrix
        matrix_combine(C, C11, C12, C21, C22, n);
    }

    return C;
}