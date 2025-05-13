#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
void print(bool *arr,int a,int b);
int main()
{
    double a=1000000000;
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
 
    int last=sqrt_a;
    while(last<a)
    {
        // printf("loop_started\n");
        int end=(a-last>sqrt_a)?last+sqrt_a:a;
        for(int i=0;i<sqrt_a;i++)part_num[i]=true;
        for(int i=1;i<sqrt_a;i++)
        {
            if(num[i])
            {
                int j=i+1;
                int start=((last+j-1)/j)*j;
                for(int k=start;k<=end;k+=j)
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
}

void print(bool *arr,int start,int end)
{
    // printf("print_started_from_%d_to_%d\n",start,end);
    int n=end-start;
    for(int i=0;i<n;i++)
    {
        if(*(arr+i))
        {
            printf("\033[31m%d",start+i+1);
        }
        else
        {
            printf("\033[32m%d",start+i+1);
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