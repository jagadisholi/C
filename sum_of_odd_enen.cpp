#include <stdio.h>

int main() {
    int i, num, sum_even = 0, sum_odd = 0;

    for(i = 1; i <= 10; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);

        if(num % 2 == 0) {
            // Number is even
            sum_even += num;
        } else {
            // Number is odd
            sum_odd += num;
        }
    }

    printf("Sum of even numbers is %d\n", sum_even);
    printf("Sum of odd numbers is %d\n", sum_odd);

    return 0;
}

