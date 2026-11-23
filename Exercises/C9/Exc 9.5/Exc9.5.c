#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(void)
{
	int n,d,s,f;
    printf("select your starting number\n");
    scanf("%d",&d);
    f=d;
    
    printf("select your ending number\n");
      scanf("%d",&n);

    for (;d<=n;)
    {
    s=d*d;
    printf("\n%d, squared: %d",d,s);
    Sleep(500);
    d=(d+1);
    f=f+d;
    }
    printf("\nfibb = %d",f);
    return 0;
}