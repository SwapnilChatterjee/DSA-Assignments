#include <string.h>
#include <stdlib.h>


// For float type
int linear_search_float_in_array(float *array, int size, float value){
    int found = 0;
    for(int i = 0; i < size; i++){
        if(array[i] == value){
            found = 1;
            break;
        }
    }
    return found;
}

int binary_search_float_in_array(float *array, int size, float value){
    int found = 0;
    int low = 0;
    int high = size - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(array[mid] == value){
            found = 1;
            break;
        }
        else if (value > array[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }                      
    }
    return found;
}

void sort_array_float(float *array, int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(array[i] > array[j]){
                float temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


// For integer type
int linear_search_int_in_array(int *array, int size, int value){
    int found = 0;
    for(int i = 0; i < size; i++){
        if(array[i] == value){
            found = 1;
            break;
        }
    }
    return found;
}

int binary_search_int_in_array(int *array, int size, int value){
    int found = 0;
    int low = 0;
    int high = size - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(array[mid] == value){
            found = 1;
            break;
        }
        else if (value > array[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }                      
    }
    return found;
}

void sort_array_int(int *array, int size){
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


// For word
int linear_search_word_in_array(char **array, int size, char* value){
    int found = 0;
    for(int i = 0; i < 10; i++){
        if(strcmp(array[i], value) == 0){
            found = 1;
            break;
        }
    }
    return found;
}

int binary_search_word_in_array(char **array, int size, char *value){
    int found = 0;
    int low = 0;
    int high = size - 1;


    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            if(strcmp(array[i], array[j]) > 0){
                char *temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    while(low <= high){
        int mid = (low + high) / 2;
        if(strcmp(array[mid], value) == 0){
            found = 1;
            break;
        } 
        else if(strcmp(array[mid], value) < 0){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }              
    }

    return found;
}