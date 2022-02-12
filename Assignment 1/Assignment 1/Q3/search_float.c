#include <stdio.h>
#include "./func.h"


int main(){
    float array[10] = {4.5,1.11,34,5.6,7.8,9.9,3.2,2.3,4.5,1.11};
    int i, search_method, found = -1;
    float n;

    printf("Enter the number to search for: ");
    scanf("%f", &n);
    printf("1. Linear Search \n2. Binary Search\n");
    printf("Choose option : ");
    scanf("%d",&search_method);


    switch (search_method)
    {
        case 1:
            found = linear_search_float_in_array(array, 10, n);
            break;
        case 2:
            sort_array_float(array, 10);
            found = binary_search_float_in_array(array, 10, n);
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
