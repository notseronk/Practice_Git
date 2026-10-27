#include <stdio.h>
#include <stdlib.h>

int main()
{
int colour;

switch (colour)
{
case 0:
    printf("black");
    break;

case 1:
    printf("brown");
    break;

case 2:
    printf("red");
    break; 

case 3:
    printf("orange");
    break;

case 4:
    printf("yellow");
    break;

case 5:
    printf("green");
    break;

case 6:
    printf("blue");
    break;

case 7:
    printf("violet");
    break;

case 8:
    printf("grey");
    break;

case 9:
    printf("white");
    break;

    default:
    printf("invalid!");
    
}

return 0;
}