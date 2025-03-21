#include <stdio.h>

int main() {
    float radius, area;
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);
    area = 3.14 * radius * radius;
    printf("The area of the circle with radius %f is %f\n", radius, area);
    return 0;
}
