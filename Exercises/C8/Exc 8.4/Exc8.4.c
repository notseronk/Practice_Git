#include <stdio.h>
#include <stdlib.h>

int main()
{
int colour;

printf("select a colour\n");
scanf("%d", &colour);

switch (colour)
{
case 0:
    printf("\nblack");
    break;

case 1:
    printf("\nbrown");
    break;

case 2:
    printf("\nred");
    break; 

case 3:
    printf("\norange");
    break;

case 4:
    printf("\nyellow");
    break;

case 5:
    printf("\ngreen");
    break;

case 6:
    printf("\nblue");
    break;

case 7:
    printf("\nviolet");
    break;

case 8:
    printf("\ngrey");
    break;

case 9:
    printf("\nwhite");
    break;

    default:
    printf("\ninvalid!");
    
}

return 0;
}