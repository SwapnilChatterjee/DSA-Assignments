#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void store_names_in_file_sorted(char *names[], int n, char *filename){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(strcmp(names[i], names[j]) > 0){
                char *temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }
    FILE *fp;
    fp = fopen(filename, "w");
    for(int i = 0; i < n; i++){
        fprintf(fp, "%s", names[i]);
    }
    fclose(fp);
}

