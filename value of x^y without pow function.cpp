#include <stdio.h>

int power(int x, int y) {
    int i, result = 1;
    
    for(i = 1; i <= y; i++) {
        result = result * x;
    }
    
    return result;
}

int main() {
    int x, y, result;
    
    printf("Enter the value of x: ");
    scanf("%d", &x);
    
    printf("Enter the value of y: ");
    scanf("%d", &y);
    
    result = power(x, y);
    
    printf("%d ^ %d = %d\n", x, y, result);
    
    return 0;
}

