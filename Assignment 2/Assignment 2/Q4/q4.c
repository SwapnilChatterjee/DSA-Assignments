#include<stdio.h>
#include"./set.h"

int main(){

    int *set,size=0,choice,pos,val;
    set = NULL;

    do{
        printf("\n1. Create a New Set(If old set exists it will be deleted)\n");
        printf("2. Find out the length of set\n");
        printf("3. Display the set\n");
        printf("4. Print the ith element of the set\n");
        printf("5. Store the new value at ith position\n");
        printf("6. Insert at ith Position \n");
        printf("7. Delete at ith Position \n");
        printf("8. Search the set for the specified Value \n");
        printf("9. Sort The set \n");
        printf("10. End  \n");
        printf("Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:  
            if(set != NULL){
                free(set); 
                size = 0;
            }
            set = ini(&size);
            remove_duplicate(set,&size);
            break;
        case 2:   
            printf("The length of the set is:  %d",size);
            break;
        case 3:   
            print_set(set,size);
            break;
        case 4:   
            printf("Enter the position : ");
            scanf("%d",&pos);
            print_value(set,pos);  
            break;
        case 5: 
            printf("Enter the position : ");
            scanf("%d",&pos);
            change_value(set,pos);
            remove_duplicate(set,&size);  
            break;
        case 6: 
            printf("Enter the position : ");
            scanf("%d",&pos);
            insert_pos(set,&size,pos);
            remove_duplicate(set,&size);  
            break;
        case 7: 
            printf("Enter the position : ");
            scanf("%d",&pos);
            delete_pos(set,&size,pos);  
            break;
            break;
        case 8: 
            printf("Enter the value to be searched : ");
            scanf("%d",&val);
            int k = search_val(set,size,val);
            if(k>=0)
                printf("The value is present at index : %d",k);
            else
                printf("The value is not present");  
            break;
        case 9: 
            sort_set(set,size);
            printf("set is sorted in ascending Order");
            break;

        default:
            break;
        }

        
    } while (choice!=10);
    


}