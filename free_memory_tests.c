#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    bool **a=malloc(100 * sizeof(bool *));
    if(a==NULL)
    {
        printf("allocation failed");
    }
    for(int i=0;i<100;i++)
    {
        a[i]=malloc(sizeof(bool));
        if(a[i]==NULL)printf("memory allocation failed:2");
        *a[i]=true;
    }
    int b;
    scanf("%i",&b);
    printf("%s\n",*a[b]?"true":"false");
    free(a[b]);
    if (*a[b]==NULL)
    {
        printf("freed\n");
    }

    if (*a[b])printf("yes\n");
    if (!*a[b])printf("no\n");
    for (int i = 0; i < 100; i++) {
        a[i] = malloc(sizeof(bool));
    }
    free(a);
}