#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    
    float pii = 3.14f;
    float radius = 2; 
    float vol = ((4.0f/3.0f)* pii * radius * radius * radius);
    float SA = (4*pii*radius*radius);

    printf("my awesome volume correct answer is %.2f ahahahhah",vol);
    printf("\nmy awesome surface area correct answer is %.2f ahahahhah\n",SA);

    return 0;

}