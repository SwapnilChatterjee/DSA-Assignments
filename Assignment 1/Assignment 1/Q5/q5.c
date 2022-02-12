#include <time.h>
#include "./func.h"

int main(){
    clock_t start, end;
    double cpu_time_used;

    int max_number = 100000;
    char filename[] = "random_strings.txt";

    srand(time(0));
    start = clock();

    generate_and_write_string(max_number, 10, filename);

    end = clock();
    cpu_time_used = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("time taken : %f\n", cpu_time_used );


    return 0;
}