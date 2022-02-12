#include <time.h>
#include "./func.h"

int main(){
    clock_t start, end;
    double cpu_time_used;

    char filename[] = "random_numbers.txt";

    srand(time(0));
    start = clock();

    generateNumbers(0, 100000, filename);

    
    end = clock();
    cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("time taken : %f\n", cpu_time_used );



    return 0;
}
