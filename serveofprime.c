#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int a = 1000000;  
    int *num = malloc(a * sizeof(int));  
    
    if (num == NULL) {
        printf("Memory allocation failed\n");
        return 1;  
    }
    
    for (int i = 0; i < a; i++) {
        num[i] = i+1;
    }
    for (int i=0; i*i<a;i++)
    {
        if(num[i] && num[i]!=1)
        {
            int j=num[i];
            int current=i+j;
            while( (current<a))
            {
                num[current]=0;
                current+=j;
            }
        }
    }
    for (int i = 0; i < a; i++) {

        if(num[i]) {printf("\033[31m%i\033[0m ",num[i]);}
        else printf("\033[32m%i\033[0m ",i+1);
        if((i%10==9)) printf("\n");
    }
    
    
    free(num);  
    printf("V1\n");
    return 0;
}