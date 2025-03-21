#include <stdio.h>

int main() {
    float num1, num2, result;
    char op;

    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &op);

    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    switch(op) {
        case '+':
            result = num1 + num2;
            printf("%.2f + %.2f = %.2f", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2f - %.2f = %.2f", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2f * %.2f = %.2f", num1, num2, result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Division by zero error");
            } else {
                result = num1 / num2;
                printf("%.2f / %.2f = %.2f", num1, num2, result);
            }
            break;
        default:
            printf("Invalid operator");
    }

    return 0;
}

