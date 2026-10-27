#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void)
{
    float radius;
    float height;
    float SA;

    printf("please enter a radius\n");
    scanf("%f", &radius);

    printf("\nplease enter a height\n");
    scanf("%f", &height);

    SA=((2.0f*M_PI*radius*radius)+2.0f*M_PI*radius*height);

    printf("\nthe surface area of your cylinder is %.2f m^2", SA);

    return 0;


}