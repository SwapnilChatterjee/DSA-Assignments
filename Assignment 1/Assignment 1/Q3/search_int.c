#include <stdio.h>
#include "./func.h"

int main(){
    int array[10] = {454,232,12,456,21,23,45,23,45,23};
    int i,n, search_method, found = -1;

    printf("Enter the number to search for: ");
    scanf("%d", &n);
    printf("1. Linear Search \n2. Binary Search\n");
    printf("Choose option : ");
    scanf("%d",&search_method);


    switch (search_method)
    {
        case 1:
            found = linear_search_int_in_array(array, 10, n);
            break;
        case 2:
            sort_array_int(array, 10);
            found = binary_search_int_in_array(array, 10, n);
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
