#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./func.h"






int main()
{
    FILE *first_file;
    int total_names = 0;
    char **list_of_names;
    char tmp;
    char *tmp_name;
    char largest_name[255];
    char shortest_name[255];



    first_file = fopen("list_of_names.txt", "r");
    

    // Count number of lines
    tmp = getc(first_file);
    while (tmp != EOF)
    {
        if (tmp == '\n')
        {
            total_names++;
        }
        tmp = getc(first_file);
    }
    total_names++;

    // Allocate memory for names
    list_of_names = (char **)malloc(total_names * sizeof(char *));

    for (int i = 0; i < total_names; i++){
        *(list_of_names + i) = (char *)malloc(255 * sizeof(char));
    }

    // Read names
    rewind(first_file);
    int current_line = 0;
    while(fgets(list_of_names[current_line], 255, first_file)) {
        current_line++;
    }


    strcpy(largest_name, list_of_names[0]);
    strcpy(shortest_name, list_of_names[0]);

    for (int i = 0; i < total_names; i++){
        if (strlen(list_of_names[i]) > strlen(largest_name)){
            strcpy(largest_name, list_of_names[i]);
        }
        if (strlen(list_of_names[i]) < strlen(shortest_name)){
            strcpy(shortest_name, list_of_names[i]);
        }
    }

    printf("Largest name: %s  Size : %ld\n", largest_name, strlen(largest_name));
    printf("Shortest name: %s  Size : %ld\n", shortest_name, strlen(shortest_name));



    store_names_in_file_sorted(list_of_names, total_names, "output.txt");



    fclose(first_file);
    return 0;
}