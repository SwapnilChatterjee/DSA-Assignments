
#include "./sparse.h"

int main(){
    int choice;
    while(1){
        // printing the options
        printf("\nCurrent index(starts with 1) = %d\n",avail);
        printf("1. Enter a sparse matrix\n");
        printf("2. Print a sparse matrix\n");
        printf("3. Multiply a sparse matrix with a constant\n");
        printf("4. Add two sparse matrix\n");
        printf("5. Transpose the sparse matrix\n");
        printf("6. Multiply two sparse matrix\n");
        printf("Enter  -1 to exit:\n ");
        printf("\n Enter the choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: {
                int row,column;
                printf("Give the dimension of sparse matrix : ");
                scanf("%d %d",&row,&column);
         		printf("Set the value 0 to terminate.\n");
                read_spar(avail,row,column);
                break;
            }
            case 2: {
                printf("Enter the sparse index : ");
                int index;
                scanf("%d", &index);
                printf("Your sparse matrix : \n");
                print_spar(index);
                break;
	       }
            case 3: {
                printf("Enter the sparse index and the constant respectively: ");
                int index;
                double k;
                scanf("%d %lf", &index, &k);
                mult_spar_const(index, k);
                break;
            }

            case 4: {
                int index1, index2;
                printf("Enter the sr no of 1st sparse matrix: ");
                scanf("%d", &index1);
                printf("Enter the sr no of 2nd sparse matrix: ");
                scanf("%d", &index2);
                add_spar(index1, index2);
                break;
            }
            case 5: {
                printf("Enter the sparse index: ");
                int index;
                scanf("%d",&index);
                trans_spar(index);
                break;
            }
            case 6: {
                int index1,index2;
                printf("Give the sro nos of sparse matrix : ");
                scanf("%d %d",&index1,&index2);
                mult_spar(index1,index2);
                break;
            }
       }
       if(choice == -1){
            break;
       }
    }
    return 0;
}