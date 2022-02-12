#include <stdio.h>
#include <time.h>
#include "./func.h"



int main(){
    clock_t start, end;
    double cpu_time_used;
    unsigned long long int n, result;

    printf("Enter number: ");
    scanf("%lld", &n);

    start = clock();

    result = fibonacciIterativeUnsignedLongLong(n);



    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("time taken : %f\n", cpu_time_used );

    printf("result : %lld\n", result);
    return 0;
}