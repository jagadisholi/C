#include <stdio.h>
#include <conio.h>
int main() {
    int num, fact = 1;
    char choice;

    do {
        printf("\nPlease choose an option: \n");
        printf("A. Find odd or even\n");
        printf("B. Find positive or negative\n");
        printf("C. Find factorial value\n");
        printf("D. Exit\n");
        printf("Enter your choice (A/B/C/D): ");

        scanf(" %c", &choice);

        switch(choice) {
            case 'A':
            case 'a':
                printf("Enter an integer: ");
                scanf("%d", &num);
                if (num % 2 == 0)
                    printf("%d is even\n", num);
                else
                    printf("%d is odd\n", num);
                break;

            case 'B':
            case 'b':
                printf("Enter an integer: ");
                scanf("%d", &num);
                if (num >= 0)
                    printf("%d is positive\n", num);
                else
                    printf("%d is negative\n", num);
                break;

            case 'C':
            case 'c':
                printf("Enter an integer: ");
                scanf("%d", &num);
                for (int i = 1; i <= num; i++) {
                    fact *= i;
                }
                printf("Factorial of %d is %d\n", num, fact);
                
                break;

            case 'D':
            case 'd':
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice == 'D' && choice == 'd');

    return 0;
}

