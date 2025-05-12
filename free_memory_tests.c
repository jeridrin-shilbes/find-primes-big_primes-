#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool **a=malloc(100 * sizeof(bool));
    for(int i=0;i<100;i++)
    {
        a[i]=false;
    }
    int b;
    scanf("%i",&b);
    free(a[b]);
    if (a[b]==NULL)
    {
        printf("freed");
    }
    if (a[b])printf("yes");
    if (!a[b])printf("no");
    
}