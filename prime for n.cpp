#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
   int i;
   for (i = 2; i <= num / 2; i++) {
      if (num % i == 0) {
         return 0;
      }
   }
   return 1;
}

int main() {
   int n, count = 0, num = 2;
   printf("Enter the value of n: ");
   scanf("%d", &n);

   // Loop to print first n prime numbers
   while (count < n) {
      if (isPrime(num)) {
         printf("%d ", num);
         count++;
      }
      num++;
   }
   return 0;
}

