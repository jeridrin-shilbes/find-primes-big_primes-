#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
void print(bool *arr,int a,int b);
int main()
{
    int a=1000000;
    int sqrt_a=sqrt(a)+1;
    bool *num=malloc(sqrt_a * sizeof(bool));
    if(num==NULL)
    {
        printf("memory allocation failed:1");
        return 1;
    }
    for(int i=0;i<sqrt_a;i++)
    {
        num[i]=true;
    }
    for(int i=0;i<sqrt_a;i++)
    {
        if(i && num[i])
        {
            int j=i+1;
            int current=i;
            while(current<sqrt_a)
            {
                current+=j;
                num[current]=false;
            }
        }
    }

    print(num,0,sqrt_a);
    free(num);
}

void print(bool *arr,int start,int end)
{
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