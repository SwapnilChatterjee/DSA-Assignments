# include <stdio.h>
# include <stdlib.h>
# include "./string.h"


int main(){

	int choice,index1,index2,value,no_of_string=0;
    char *String[10];
	do{
        printf("1. Enter a new String \n");
        printf("2. Print all Strings \n");
        printf("3. Find Length of a String \n");
        printf("4. Comapre 2 String \n");
        printf("5. Concatinate string into a new String\n");
        printf("6. Copy String\n");
        printf("7. Find Substring\n");
        printf("8. No of Words in a String\n");
        printf("9. Remove Spaces From the string\n");
        printf("10. Reverse a String\n");
        printf("11. Exit\n");
        printf("Enter Your Choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				readstr(&String[no_of_string]);
				no_of_string++;
				printf("%s\n",String[0]);
				break;
			case 2:
				if(no_of_string==0){
					printf("List Is Empty\n");
				}
				else{
					int i=0;
					while(i<no_of_string){
						printf("%d . %s\n",i,String[i]);
						i++;
					}
				}
				break;
			case 3:
				printf("Enter i to print length of Str[i]\n");
				scanf("%d",&index1);
				if(index1<no_of_string){
					printf("Length = %d\n",lenstr(String[index1]));
				}
				else{
					printf("Index Out Of Range\n");
				}
				break;
			case 4:
				printf("Enter i, j to compare Str[i] & Str[j]\n");
				scanf("%d %d",&index1,&index2);
				if(index1<no_of_string && index2<no_of_string){
					value=compare_str(String[index1],String[index2]);
					printf("%d\n",value);

					if(value==0)
						printf("Both Are Equal\n");
					else if (value>0)
						printf("%s > %s\n",String[index1],String[index2]);
					else
						printf("%s < %s\n",String[index1],String[index2]);

				}
				else{
					printf("Index Out Of Range\n");
				}
				break;
			case 5:
                    printf("Enter i, j to concatinate Str[i] & Str[j]\n");
                    scanf("%d %d",&index1,&index2);
                    if(index1<no_of_string && index2<no_of_string){
                        int l1=lenstr(String[index1]),l2=lenstr(String[index2]);
                        String[no_of_string]=(char *)(malloc((l1+l2+1)*sizeof(char)));
                        copystr(String[no_of_string],concatstr(String[index1],String[index2]));
                        no_of_string++;
                        printf("The Concatinated String is :\n%s\n",String[no_of_string-1]);
                    }
                    else
                        printf("Index Out Of Range\n");

				break;
			case 6:
                    printf("Enter i, j to copy Str[j] in Str[i]\n");
                    scanf("%d %d",&index1,&index2);
                    if(index1<no_of_string && index2<no_of_string){
                        copystr(String[index1],String[index2]);
                        printf("Copied %s into Str[%d]\n",String[index2],index1);
                    }
                    else
                        printf("Index Out Of Range\n");
				break;
			case 7:
                    printf("Enter i, j to find if Str[i] is Substring of Str[j]\n");
                    scanf("%d %d",&index1,&index2);
                    if(index1<no_of_string && index2<no_of_string){
                        if(is_substring(String[index1],String[index2]))
					        printf("Substring\n");
					    else
                            printf("Not A Substring\n");

				    }
                    else
                        printf("Index Out Of Range\n");
                                
				break;
			case 8:
                printf("Enter i to find number of words in Str[i]\n");
                scanf("%d",&index1);
                if(index1<no_of_string){
                    printf("The number of words in %s is %d",String[index1],countword(String[index1]));
                }
                else{
                    printf("Index Out Of Range\n");
                }
                break;
			case 9:
                printf("Enter i to remove spaces in Str[i]\n");
                scanf("%d",&index1);
                if(index1<no_of_string){
                    copystr(String[index1],remove_space(String[index1]));
                    printf("The Changed String is :\n%s\n",String[index1]);
                }
                else{
                    printf("Index Out Of Range\n");
                }
                break;

			case 10:
                printf("Enter i to reverse Str[i]\n");
                scanf("%d",&index1);
                if(index1<no_of_string){
                    copystr(String[index1],revstr(String[index1]));
                    printf("The Reversed String is :\n%s\n",String[index1]);
                }
                else{
                    printf("Index Out Of Range\n");
                }
                break;


			default:
                break;
		}
	}while(choice != 11);
			
    return 0;
}