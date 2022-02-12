#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void generateNumbers(int min_number, int max_number, char filename[]){
    FILE *fp = fopen(filename, "w");
    int random_number;
    int no_of_numbers_written = 0;
    int *arr;

    arr = (int*)calloc(max_number+1, sizeof(int));



    while (no_of_numbers_written!=max_number){
        random_number = rand()%max_number+1;
        if (arr[random_number] == 0){
            fprintf(fp, "%d\n", random_number);
            arr[random_number] = 1;
            no_of_numbers_written++;
        }
    }

    free(arr);

    fclose(fp); 
}