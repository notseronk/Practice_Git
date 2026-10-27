#include <stdio.h>
#include <stdlib.h>

int main()
{
int age;
printf("what is your age?\n");
scanf("%d",&age);

if (age <= 5)
    printf("\nyou're still a baby!");

else if (age>5 && age<=12)

    printf("\nThe junior years");

else if (age >12 && age<20)

    printf("\nThe teenage years");/* code */

else
    printf("downhill all the way now!");

return 0;
}