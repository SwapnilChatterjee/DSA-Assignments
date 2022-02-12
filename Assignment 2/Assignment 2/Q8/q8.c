#include <stdio.h>
#include <stdlib.h>
#include "./func.h"

int main()
{
    int m, result;
    printf("Enter size of array : ");
    scanf("%d",&m);
    int a[m];
    printf("Enter elements of array : ");  //input
    int i;
    for(i=0;i<m;i++)
        scanf("%d",(a+i));

    result = sortChecker(a, m);
    if(result == -1){
        printf("The elements are unsorted\n");
    }else if(result == 1){
        printf("The elements are  sorted in asscending order\n");
    }else if(result == 2){
        printf("The elements are sorted in descending order\n");
    }
}