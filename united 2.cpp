#include <stdio.h>
#include<conio.h>
int main() {
    int a, b, c, max;
   	printf("enter the first number :");
	scanf("%d",&a);
	printf("enter the second number :");
	scanf("%d",&b);
	printf("enter the third number :");
	scanf("%d",&c);
    if (a > b && a > c) {
        max = a;
    } else if (b > c) {
        max = b;
    } else {
        max = c;
    }

    printf("The largest number is: %d", max);
    return 0;
}

