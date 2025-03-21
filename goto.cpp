#include <stdio.h>

int main() {
   int i = 0;

   loop:   // labeled statement
   printf("%d ", i);
   i++;

   if (i < 5) {
      goto loop;  // jump to labeled statement
   }

   return 0;
}

