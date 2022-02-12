#include <stdio.h>
#include <time.h>
#include "./func.h"


int main(){

    unsigned long  long int result=1;

    clock_t start, end;
    double cpu_time_used;

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    start = clock();


    result = factorialIterativeUnsignedLongLong(n);


    end = clock();
    cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("time taken : %f\n", cpu_time_used );


    printf("factorial : %llu\n", result);
    return 0;
}
