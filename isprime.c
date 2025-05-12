#include <stdio.h>
int main()
{
    int num;
    // scanf("%d",&num);
    num =10000000;
    for(int i=0;i<=num;i++)
    {
        int isprime=1;
        for(int j=2;j*j<i;j++)
        {
            if (!(i%j))
            {
                isprime=0;
                break;
            }
        }
        if (isprime)
        {
            printf("\033[31m%i\033[0m ",i);
        }
        else{
            printf("\033[32m%i\033[0m ",i);
        }
        if(!(i%10))
        {
            printf("\n");
        }

    }
}