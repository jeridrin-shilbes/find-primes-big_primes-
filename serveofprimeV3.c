#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    const int a=1000000;
    bool **num = malloc(a * sizeof(bool *));  
    
    if (num == NULL) {
        printf("Memory allocation failed:1\n");
        return 1;  
    }
    double tpn=0; //total primes counted

    //loop to initialise "a" bools
    for (int i = 0; i < a; i++) {
        num[i]=malloc(sizeof(bool));
        *num[i] = true;
    }

    //set the prime indexes to false
    for (int i=1; i*i<a;i++)
    {
        if(*num[i])
        {
            int j=i+1;
            int current=i+j;
            while( (current<a) )
            {
                *num[current]=false;
                current+=j;
            }
        }
    }
    //initialise useful ints
    int cnp=0; //consecutive non prime lines
    int tnp=0; //total non prime lines

    //printing stage
    //looping every line
    for (int i = 0; i < a/10; i++) 
    {
        printf("\033[32m"); //evry num is set to print in green by default
        bool prime_found=false;

        //checking if line has a prime
        for(int j=i*10;j<(i*10)+10;j+=2)
        {
            if(*num[j])
            {
                prime_found=true;
                break;
            }
        }

        if (!prime_found)printf("\033[42m\033[37m");//white numbers in green background
        for(int j=i*10;j<(i*10)+10;j++)
        {
            if(*num[j]) {printf("\033[31m%i \033[32m",j+1);tpn++;}
            else printf("%i ",j+1);
        }

        if (!prime_found)
        {
            printf("\b\033[0m \033[41m%i",++cnp);
            tnp++;
        }
        else cnp=0;
        printf("\033[0m\n");
    }
 
    for(int i=0;i<a;i++)
    {
        free(num[i]);
    }
    free(num); 
    printf("V2:\nThe total number of \n");
    printf("                     ");
    printf("primes counted       : %.0f\n",tpn);
    printf("                     ");
    printf("lines without primes : %d\n",tnp);
    return 0;
}