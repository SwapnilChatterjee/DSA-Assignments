#include<stdio.h>
#include<stdlib.h>


// For swaping
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// For Removing Duplicate element
void remove_duplicate(int *set,int *size_of_set){
    printf("\nYES\n");
    int i ,j,k;
    for(i=0; i<(*size_of_set); i++){
        for(j=i+1; j<(*size_of_set); j++){
            /* If any duplicate found */
            if(set[i] == set[j]){
                /* Delete the current duplicate element */
                for(k=j; k < (*size_of_set)- 1; k++)
                    set[k] = set[k + 1];

                /* Decrement size after removing duplicate element */
                (*size_of_set)--;

                /* If shifting of elements occur then don't increment j */
                j--;
            }
        }
    }
}


// Initialize a set
int *ini(int *size_of_set){
    int *set,choice;
    set= (int*)malloc(sizeof(int)*1000);
    while(1){
        (*size_of_set)++;
        printf("Enter the %d element of set  :  ",*size_of_set);
        scanf("%d",&set[(*size_of_set)-1]);
        printf("You want to Enter More elements [1.yes / 2. no]: ");
        scanf("%d",&choice);
        if(choice == 1)
            continue;
        else
            return set;
    }

}

// Print a set
void print_set(int *set,int size_of_set){

    printf("Your set is : \n");
    for (int i = 0; i < size_of_set; i++)
        printf("%d\n",set[i]);
    printf("\n");
}

// Print the value at ith position
void print_value(int *set,int pos){
    printf("The value at  %d position is : %d\n",pos,set[pos-1]);
}

// Change the value at ith position
void change_value(int *set,int pos){
    printf("\nEnter your new value : ");
    scanf("%d",&set[pos-1]);
    printf("The value has changed \n");
}


// Insert at ith position
void insert_pos(int *set,int *size_of_set,int pos){
    
    (*size_of_set)++;
    for(int i = (*size_of_set);i>pos-1;i--)
        set[i]=set[i-1];
    printf("\nEnter your new value : ");
    scanf("%d",&set[pos-1]);
    printf("The new element is inserted \n");
}


// Delete at ith position
void delete_pos(int *set,int *size_of_set,int pos){
    
    (*size_of_set)--;
    for(int i = pos-1;i<(*size_of_set);i++)
        set[i]=set[i+1];
    printf("The element is deleted \n");
}

// Search a value
int search_val(int *set,int size_of_set,int val){

    int i;
    for (i = 0; i < size_of_set; i++)
        if(set[i] == val)
            return i;
    return -1;
    
}

// Sort the set
void sort_set(int *set,int size_of_set){

    int min;
    for(int i=0;i<size_of_set-1;i++){
        min = i;
        for (int j = i+1; j < size_of_set; j++){
            if(set[j]<set[min])
                min=j;
        }
        swap(&set[i],&set[min]);
    }

}

