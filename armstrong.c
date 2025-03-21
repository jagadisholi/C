#include <stdio.h>
#include <math.h>

int main() {
    int number, original_number, sum = 0, digit_count = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    original_number = number;

    while(number != 0) {
        int digit = number % 10;
        digit_count++;
        number /= 10;
    }

    number = original_number;

    while(number != 0) {
        int digit = number % 10;
        sum += pow(digit, digit_count);
        number /= 10;
    }

    if(original_number == sum) {
        printf("%d is an Armstrong number.\n", original_number);
    } else {
        printf("%d is not an Armstrong number.\n", original_number);
    }

    return 0;
}

