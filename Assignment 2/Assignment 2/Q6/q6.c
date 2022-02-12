#include "./func.h"
#include <stdlib.h>

// Driver Code
// int main()
// {
// 	int arr[] = {4, 5, 1, 13, 3, 25, 27, 18, 10, 3, 4, 9};
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	int k = 3;
// 	max_filter(arr, n, k);
// 	min_filter(arr, n, k);
// 	median_filter(arr, n, k);
// 	return 0;
// }

int main()
{
    int n, k, ch, c;
    int *arr;
    printf("Enter 1 for Maximum\nEnter 2 for Minimum\nEnter 3 for Median\n\n");
    do
    {
        printf("Enter your choice : ");
        scanf("%d", &ch);
        printf("Enter length of array : ");
        scanf("%d", &n);
        arr = (int *)malloc(sizeof(int) * n);
        printf("Enter size of sliding window : ");
        scanf("%d", &k);
        printf("Enter array elements : \n");
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        switch (ch)
        {
        case 1:
            max_filter(arr, n, k);
            break;
        case 2:
            min_filter(arr, n, k);
            break;
        case 3:
            median_filter(arr, n, k);
            break;
        default:
            printf("Wrong Choice!\n");
        }
        printf("\n");
        printf("\nDo you want to continue? Press 1 to continue : ");
        scanf("%d", &c);
    } while (c == 1);
}