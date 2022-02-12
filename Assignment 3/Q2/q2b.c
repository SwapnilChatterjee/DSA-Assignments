#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Q1/doublylinkedlist.h"

int makef()
{
    FILE *fptr;
    int n = 0, c = 0;
    while ((fptr = fopen("nums.txt", "w")) == NULL)
        ;
    while (true)
    {
        printf("1. Add number\n2. Exit \nEnter choice : ");
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

void Build_list(struct node **a, int n)
{
    FILE *fptr;
    struct node *ptr;
    *a = NULL;
    int i = 0;
    while ((fptr = fopen("nums.txt", "r")) == NULL)
        ;
    if (fptr == NULL)
        printf("Memory allocation failed");
    while (++i <= n)
    {
        init(&ptr);
        fscanf(fptr, "%d", &(ptr->x));
        insend(a, ptr);
    }
    fclose(fptr);
}

void Build_list_reverse(struct node **a, int n)
{
    FILE *fptr;
    struct node *ptr;
    *a = NULL;
    int i = 0;
    while ((fptr = fopen("nums.txt", "r")) == NULL)
        ;
    if (fptr == NULL)
        printf("Memory allocation failed !");
    while (++i <= n)
    {
        init(&ptr);
        fscanf(fptr, "%d", &(ptr->x));
        insfrt(a, ptr);
    }
    fclose(fptr);
}

int main()
{
    struct node *a1 = NULL, *a2 = NULL;
    int n = makef();
    printf("\nNo of elements entered : %d\n\n", n);
    Build_list(&a1, n);
    printf("For 1st list,s");
    show(a1);
    Build_list_reverse(&a2, n);
    printf("\nFor 2nd list,");
    show(a2);
    return 0;
}