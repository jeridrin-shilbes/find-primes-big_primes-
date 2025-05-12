#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    const int a = 10000;  
    int *num = malloc(a * sizeof(int));  
    
    if (num == NULL) {
        printf("Memory allocation failed\n");
        return 1;  
    }


    free(num);
    return 0;
}