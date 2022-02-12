#include <stdio.h>
#include <stdlib.h>
#include "./func.h"

int main()
{
    int m,n,i;
    printf("Enter size of arrays : ");
    scanf("%d %d",&m, &n);
    int a[m];
    int b[n];
    printf("Enter elements of 1st array : ");
    for(i=0;i<m;i++)
        scanf("%d",(a+i));
    printf("Enter elements of 2nd array : ");
    for(i=0;i<n;i++)
        scanf("%d",(b+i));

    merge(a, b, m, n);
 
    printf("After Merging\n");
    for (i=0; i<m; i++)
        printf("%d ",a[i]);
    for (i=0; i<n; i++)
        printf("%d ",b[i]);
    printf("\n");
    return 0;
}


