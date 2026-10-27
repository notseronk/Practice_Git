#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    unsigned int A = 0x3C;
    unsigned int B = 0x0D;
    unsigned int R;

    R=++A;
    R=A++;

    printf("the value for A is %#x\nthe value for R is %#x",A, R);

    R=--B;
    R=B--;

    printf("\nthe value for B is %#x\nthe value for R is %#x",B, R);

    return(0);

}