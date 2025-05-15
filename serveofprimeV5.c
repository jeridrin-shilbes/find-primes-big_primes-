#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
void print(bool *arr,unsigned long long a,unsigned long long b,FILE *file);
unsigned long long total_primes=-1;//the number one is also counted as prime
bool d=true;
int main()
{
    unsigned long long a=100000000000;
    char time_n[50];
    char file_n[100];
    time_t now = time(NULL);
    struct tm *t=localtime(&now);
    strftime(time_n,sizeof(file_n),"primelogs_%H_%M_%S.txt",t);
    sprintf(file_n,"logs/%llu_%s",a,time_n);
    FILE *file=fopen(file_n,"w");
    if(file == NULL)
    {
        printf("failed to open the file\nerror code:012");
        return 12;
    }
    unsigned int sqrt_a=sqrt(a);
    bool *num=malloc(sqrt_a * sizeof(bool));
    if(num==NULL)
    {
        printf("memory allocation failed:1");
        return 1;
    }
    else{
        printf("\033[32m memory allocated succesfully for parent array\033[0m\n");
    }
    bool *part_num=malloc(sqrt_a*sizeof(bool));
        if(part_num==NULL)
        {
            printf("memory allocation failed:2");
            return 2;
        }
        else
        {
            printf("\033[32m memory allocated succesfully for segement sieve array\033[0m\n");
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
    print(num,0,sqrt_a,file);
 
    unsigned long long last=sqrt_a;
    while(last<a)
    {
        // printf("loop_started\n");
        unsigned  long end=(a-last>sqrt_a)?last+sqrt_a:a;
        memset(part_num,1,sqrt_a*sizeof(bool));
        for(int i=1;i<sqrt_a;i++)
        {
            if(num[i])
            {
                int j=i+1;
                unsigned long start=((last+j-1)/j)*j;
                for(unsigned long long k=start;k<=end;k+=j)
                {
                    part_num[k-last-1]=false;
                }
                
            }
        }

        print(part_num,last,end,file);
        last=end;
    }
    free(num);
    free(part_num);
    fprintf(file,"\nTotal primes: %llu in %llu\n",total_primes,a);
    fclose(file);
    printf("\nTotal primes: %llu in %llu\n",total_primes,a);
    return 0;
}

void print(bool *arr,unsigned long long start,unsigned long long end,FILE *file)
{
    // printf("print_started_from_%d_to_%d\n",start,end);
    long long n=end-start;
    for(int i=0;i<n;i++)
    {
        if(*(arr+i))
        {
            total_primes++;
            d=true;
            if(start+i)
            {
                fprintf(file,"%llu",start+i+1);
                        if(!(total_primes%100) && d)
                        {
                            fprintf(file,"  : line_no_%llu\n",total_primes/100);
                            d=false;
                        }
                        else fprintf(file,",");
            }

        }
    }

}