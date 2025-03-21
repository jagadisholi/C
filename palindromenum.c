#include <stdio.h>

int main() {
    int number, reversed_number = 0, original_number;

    printf("Enter a number: ");
    scanf("%d", &number);

    original_number = number;

    while(number != 0) {
        int digit = number % 10;
        reversed_number = reversed_number * 10 + digit;
        number /= 10;
    }

    if(original_number == reversed_number) {
        printf("%d is a palindrome number.\n", original_number);
    } else {
        printf("%d is not a palindrome number.\n", original_number);
    }

    return 0;
}

