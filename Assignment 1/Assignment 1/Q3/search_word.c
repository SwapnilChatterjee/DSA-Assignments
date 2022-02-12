#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./func.h"



int main(){

    char testarray[10][50] = {"sun","cat","computer","yoyo","bat","ball","mobile","laptop","online","study"};
    char **array ;
    int i, search_method, found = -1;
    char search_word[50];

    array = (char **)malloc(sizeof(char *) * 10);
    for(i = 0; i < 10; i++){
        array[i] = (char *)malloc(sizeof(char) * 50);
    }

    for(i = 0; i < 10; i++){
        strcpy(array[i], testarray[i]);
    }

    printf("Enter the word to search for: ");
    scanf("%s", search_word);
    printf("1. Linear Search \n2. Binary Search\n");
    printf("Choose option : ");
    scanf("%d",&search_method);


    switch (search_method)
    {
        case 1:
            found = linear_search_word_in_array(array, 10, search_word);
            break;
        case 2:
            found = binary_search_word_in_array(array, 10, search_word);
            break;

        default:
            break;
    };


    switch (found)
    {
    case 0:
        printf("Not found\n");
        break;
    
    case 1:
        printf("Found\n");
        break;

    default:
        printf("Unknown command\n");
        break;
    }
    return 0;
}
