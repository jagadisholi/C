#include <stdio.h>

int main()
{
    int n, i, sum = 0;
    float avg;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    for(i = 1; i <= n; ++i)
    {
        sum += i;
    }

    avg = (float)sum / n;

    printf("The sum of first %d natural numbers is %d\n", n, sum);
    printf("The average of first %d natural numbers is %.2f\n", n, avg);

    return 0;
}

