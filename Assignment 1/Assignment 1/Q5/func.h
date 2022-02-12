#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void random_string(char *str, size_t size)
{
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
}

void generate_and_write_string(int max_number, int length, char filename[]){
    int present = 0;
    char random_str[length*sizeof(char)];
    int no_of_strings_written = 0;

    char arr[max_number+1][length*sizeof(char)];


    FILE *fp = fopen(filename, "w");


    while (no_of_strings_written!=max_number){
        random_string(random_str, length);
        present = 0;

        for (int i = 0; i < no_of_strings_written; i++)
        {
            if(strcmp(random_str, arr[i]) == 0){
                present = 1;
                break;
            }
        }
        

        
        if (present == 0){
            strcpy(arr[no_of_strings_written], random_str);
            fprintf(fp, "%s\n", random_str);
            no_of_strings_written++;
        }
        
    }
    
    fclose(fp); 
}