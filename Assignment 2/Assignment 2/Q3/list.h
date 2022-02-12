#include<stdio.h>
#include<stdlib.h>


// For swaping
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Initialize a list
int *ini(int *size_of_list){
    int *list,choice;
    list= (int*)malloc(sizeof(int)*1000);
    while(1){
        (*size_of_list)++;
        printf("Enter the %d element of list  :  ",*size_of_list);
        scanf("%d",&list[(*size_of_list)-1]);
        printf("\nYou want to Enter More elements (1.Yes / 2.No) : ");
        scanf("%d",&choice);
        if(choice == 1)
            continue;
        else
            return list;
    }

}

// Print a list
void print_list(int *list,int size_of_list){

    printf("Your list is : \n");
    for (int i = 0; i < size_of_list; i++)
        printf("%d\n",list[i]);
    printf("\n");
}

// Print the value at ith position
void print_value(int *list,int pos){
    printf("The value at  %d position is : %d\n",pos,list[pos-1]);
}

// Change the value at ith position
void change_value(int *list,int pos){
    printf("\nEnter your new value : ");
    scanf("%d",&list[pos-1]);
    printf("The value has changed \n");
}


// Insert at ith position
void insert_pos(int *list,int *size_of_list,int pos){
    
    (*size_of_list)++;
    for(int i = (*size_of_list);i>pos-1;i--)
        list[i]=list[i-1];
    printf("\nEnter your new value : ");
    scanf("%d",&list[pos-1]);
    printf("The new element is inserted \n");
}


// Delete at ith position
void delete_pos(int *list,int *size_of_list,int pos){
    
    (*size_of_list)--;
    for(int i = pos-1;i<(*size_of_list);i++)
        list[i]=list[i+1];
    printf("The element is deleted \n");
}

// Search a value
int search_val(int *list,int size_of_list,int val){

    int i;
    for (i = 0; i < size_of_list; i++)
        if(list[i] == val)
            return i;
    return -1;
    
}

// Sort the list
void sort_list(int *list,int size_of_list){

    int min;
    for(int i=0;i<size_of_list-1;i++){
        min = i;
        for (int j = i+1; j < size_of_list; j++){
            if(list[j]<list[min])
                min=j;
        }
        swap(&list[i],&list[min]);
    }

}

