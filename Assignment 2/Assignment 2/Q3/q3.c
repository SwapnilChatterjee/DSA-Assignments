#include<stdio.h>
#include "./list.h"

int main(){

    int *list,size=0,choice,pos,val;
    list = NULL;

    do{
        printf("\n1. Create a New List(If old list exists it will be deleted)\n");
        printf("2. Find out the length of list\n");
        printf("3. Display the list\n");
        printf("4. Print the ith element of the list\n");
        printf("5. Store the new value at ith position\n");
        printf("6. Insert at ith Position \n");
        printf("7. Delete at ith Position \n");
        printf("8. Search the list for the specified Value \n");
        printf("9. Sort The list \n");
        printf("10. End  \n");
        printf("Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:  
            if(list != NULL){
                free(list); 
                size = 0;
            }
            list = ini(&size);
            break;
        case 2:   
            printf("The length of the list is:  %d",size);
            break;
        case 3:   
            print_list(list,size);
            break;
        case 4:   
            printf("Enter the position : ");
            scanf("%d",&pos);
            print_value(list,pos);  
            break;
        case 5: 
            printf("Enter the position : ");
            scanf("%d",&pos);
            change_value(list,pos);
            break;
        case 6: 
            printf("Enter the position : ");
            scanf("%d",&pos);
            insert_pos(list,&size,pos);
            break;
        case 7: 
            printf("Enter the position : ");
            scanf("%d",&pos);
            delete_pos(list,&size,pos);  
            break;
            break;
        case 8: 
            printf("Enter the value to be searched : ");
            scanf("%d",&val);
            int k = search_val(list,size,val);
            if(k>=0)
                printf("The value is present at index : %d",k);
            else
                printf("The value is not present");  
            break;
        case 9: 
            sort_list(list,size);
            printf("List is sorted in ascending Order");
            break;

        default:
            break;
        }

        
    } while (choice!=10);
    


}