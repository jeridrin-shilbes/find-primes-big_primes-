#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void print(bool *arr,long long a,long long b);
int total_primes=0;
int main()
{
    long long a=10000000000;
    double sqrt_a=sqrt(a);
    bool *num=malloc(sqrt_a * sizeof(bool));
    if(num==NULL)
    {
        printf("memory allocation failed:1");
        return 1;
    }
    bool *part_num=malloc(sqrt_a*sizeof(bool));
        if(part_num==NULL)
        {
            printf("memory allocation failed:2");
            return 2;
        }
    for(int i=0;i<sqrt_a;i++)
    {
        num[i]=true;
    }
    for(int i=1;i<sqrt_a;i++)
    {
        if( num[i])
        {
            int j=i+1;
            int current=i;
            while(current+j<sqrt_a)
            {
                current+=j;
                num[current]=false;
            }
        }
    }
    print(num,0,sqrt_a);
 
    long long last=sqrt_a;
    while(last<a)
    {
        // printf("loop_started\n");
        long long end=(a-last>sqrt_a)?last+sqrt_a:a;
        memset(part_num,1,sqrt_a*sizeof(bool));
        for(int i=1;i<sqrt_a;i++)
        {
            if(num[i])
            {
                int j=i+1;
                long long start=((last+j-1)/j)*j;
                for(long long k=start;k<=end;k+=j)
                {
                    part_num[k-last-1]=false;
                }
                
            }
        }

        print(part_num,last,end);
        last=end;
    }
    free(num);
    free(part_num);
    total_primes--;  //the number one is also counted as prime
    printf("\nTotal primes: %i",total_primes);
}

void print(bool *arr,long long start,long long end)
{
    // printf("print_started_from_%d_to_%d\n",start,end);
    long long n=end-start;
    for(int i=0;i<n;i++)
    {
        if(*(arr+i))
        {
            total_primes++;
            printf("\033[31m%lld",start+i+1);
        }
        else
        {
            printf("\033[32m%lld",start+i+1);
        }
        if((start+1+i)%10)
        {
            printf("\033[0m ");
        }
        else
        {
            printf("\033[0m \n");
        }
    }

}