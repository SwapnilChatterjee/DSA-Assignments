#include <stdio.h>
#include <time.h>
#include "./func.h"





int main(){

    clock_t start, end;
    double cpu_time_used;

    unsigned long long int result=1;
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    start = clock();
    
    result = factorialRecursiveUnsignedLongLong(n);


    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken : %f\n", cpu_time_used );

    printf("factorial : %llu\n", result);
    return 0;
}

