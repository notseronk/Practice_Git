#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a;
    
    printf("select a number\n");
    scanf("%d",&a);

    if (a==0)
        printf("the number is in range"); 
    else
        printf("the number is not in range");
	   
    return 0;   // Exit from main

}