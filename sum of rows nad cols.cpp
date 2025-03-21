#include <stdio.h>

int main() {
   int matrix[3][3];
   int row_sum[3] = {0}; // Initialize all elements to zero
   int col_sum[3] = {0};

   // Input the matrix
   printf("Enter the elements of the matrix:\n");
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         scanf("%d", &matrix[i][j]);
      }
   }

   // Calculate the row and column sums
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         row_sum[i] += matrix[i][j];
         col_sum[j] += matrix[i][j];
      }
   }

   // Output the results
   printf("Row sums: ");
   for (int i = 0; i < 3; i++) {
      printf("%d ", row_sum[i]);
   }
   printf("\n");

   printf("Column sums: ");
   for (int j = 0; j < 3; j++) {
      printf("%d ", col_sum[j]);
   }
   printf("\n");

   return 0;
}

