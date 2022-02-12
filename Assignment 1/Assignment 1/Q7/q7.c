#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./func.h"

int main()
{
	srand(0);
	long P=1000;
    int loop = 7;
    long L[100];
    long R[100];
    int i;

    while(loop--){
        while(is_prime(P)==0)
        {
            P++;
        }
        printf("\n4 digit prime number : %ld\n",P);


        for(i=0;i<100;i++)
        {
            L[i]=random_generate(10000,100000);
            R[i]=L[i]%P;
            printf("i = %d \t Li = %ld \t Ri = %ld \n",i+1,L[i],R[i]);
        }
        P++;
    }

	return 0;
	
}
