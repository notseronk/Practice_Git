#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char name[50];	// Declare variable, no need to initialise this time 
    
    printf("Enter your name: ");
    scanf("%49s", name);// as we read into it before it is tested against
        while(1)
        {
        printf("your name is %s\n", name);
       }
    
    return 0;
}