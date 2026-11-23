#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float degreestoradians(float deg)
{
    float rad=(M_PI)*(deg)/180.0;

    return rad;
}

int main(void){
    
    float degrees;
    printf("insert a value in degrees");
    scanf("%f",&degrees);
    float radians = degreestoradians(degrees);
    printf("\ndegrees:%f\nradians:%f",degrees,radians);

    return 0;
}
