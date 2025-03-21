#include <stdio.h>

int main() {
    int i, num, largest;

    // Read the first number as the initial largest number
    printf("Enter the first number: ");
    scanf("%d", &largest);

    // Check the remaining 9 numbers
    for(i = 2; i <= 10; i++) {
        printf("Enter number %d: ", i);
        scanf("%d", &num);

        // Update the largest number if necessary
        if(num > largest) {
            largest = num;
        }
    }

    // Output the largest number
    printf("The largest number is %d\n", largest);

    return 0;
}

