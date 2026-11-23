#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int square_function(int root){
    int squared = root*root;

return squared;
}

int fibb_function(int value, int value_prev)
{
int fibb=value+value_prev;
return fibb;
}

int main(void)
{
    int n, d, s, next;
    int fib_prev = 0, fib = 1;

    printf("select your starting number\n");
    scanf("%d", &d);

    printf("select your ending number\n");
    scanf("%d", &n);

    for (; d <= n; d++)
    {
        s = square_function(d);
        printf("\n%d, squared: %d", d, s);
    }

    // n-th Fibonacci number
    for (int i = 1; i < n; i++)
    {
        next = fibb_function(fib, fib_prev);
        fib_prev = fib;
        fib = next;
    }
    printf("\nfibb = %d\n", fib);
    return 0;
}