#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Print_list(int a[], int n)
{
    printf("The list : ");
    for (int i = 0; i < n; i++)
        printf("%d,\t", a[i]);
    printf("\n");
}

int makef()
{
    FILE *fptr;
    int n = 0, c = 0;
    while ((fptr = fopen("nums.txt", "w")) == NULL);
    while (true)
    {
        printf("Enter\n1.To enter number\nAnything else to exit\nEnter choice : ");
        scanf("%d", &c);
        if (c == 1)
        {
            printf("Enter number : ");
            scanf("%d", &c);
            fprintf(fptr, "%d\n", c);
            n++;
        }
        else
            break;
        printf("\n");
    }
    fclose(fptr);
    return n;
}

void Build_list(int a[], int n)
{
    FILE *fptr;
    struct node *ptr;
    int i = 0;
    while ((fptr = fopen("nums.txt", "r")) == NULL)
        ;
    if (fptr == NULL)
        printf("Cannot open File!");
    while (++i <= n)
    {
        fscanf(fptr, "%d", &(a[i - 1]));
    }
    fclose(fptr);
}

void Build_list_reverse(int a[], int n)
{
    FILE *fptr;
    struct node *ptr;
    int i = 0;
    while ((fptr = fopen("nums.txt", "r")) == NULL)
        ;
    if (fptr == NULL)
        printf("Cannot open File!");
    while (++i <= n)
    {
        fscanf(fptr, "%d", &(a[n - i]));
    }
    fclose(fptr);
}

int main()
{
    printf("Enter nos:-\n");
    int n = makef();
    int* a1 = (int*)malloc(sizeof(int) * n);
    int* a2 = (int*)malloc(sizeof(int) * n);
    printf("\nNo of elements entered : %d\n\n", n);
    Build_list(a1, n);
    printf("For 1st list,");
    Print_list(a1, n);
    Build_list_reverse(a2, n);
    printf("\nFor 2nd list,");
    Print_list(a2, n);
    return 0;
}
