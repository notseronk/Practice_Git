#include <stdio.h>
#include <stdlib.h>
int main ()
{
    char name[50];
    printf("what is your name?\n");
    fgets(name, 100, stdin);
    printf("hello %s", name);

    return 0;
}
