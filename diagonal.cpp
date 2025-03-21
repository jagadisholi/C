#include <stdio.h>

int main() {
    int matrix[3][3], i, j, sum = 0;

    // Read in the matrix from the user
    printf("Enter the elements of the 3x3 matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate the sum of the main diagonal
    for (i = 0; i < 3; i++) {
        sum += matrix[i][i];
    }
    /*
        for (i = 1; i < 3; i++) {
        sum += matrix[i][i];
    }
        for (i = 2; i < 3; i++) {
        sum += matrix[i][i];
    }
    */

    // Calculate the sum of the other diagonal
    for (i = 0, j = 2; i < 3; i++, j--) {
        sum += matrix[i][j];
    }

    // Print the diagonal sum
    printf("The diagonal sum of the matrix is: %d\n", sum);

    return 0;
}

