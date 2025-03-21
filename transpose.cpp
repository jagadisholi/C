#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int matrix[ROWS][COLS], transpose[COLS][ROWS];
    int i, j;

    // Get input from the user
    printf("Enter elements of matrix (%dx%d):\n", ROWS, COLS);
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Find transpose of matrix
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    // Print original matrix
    printf("Original matrix:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Print transpose of matrix
    printf("Transpose matrix:\n");
    for (i = 0; i < COLS; i++) {
        for (j = 0; j < ROWS; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}

