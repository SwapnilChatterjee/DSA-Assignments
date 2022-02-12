#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Q1/circulardoublylinkedlist.h"

void Print_list(struct node *a)
{
    printf("The list : ");
    struct node *p = NULL;
    int i = 0;
    for (p = a->next, i = 0; i < a->x; i++, p = p->next)
        printf("%d,\t", p->x);
    printf("\n\n");
}

int makef()
{
    FILE *fptr;
    int n = 0, c = 0;
    while ((fptr = fopen("nums.txt", "w")) == NULL)
        ;
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
        printf("Memory allocation failed");
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
    printf("Enter nos:-\n");
    struct node *a1 = NULL, *a2 = NULL;
    init(&a1);
    a1->x = 0;
    a1->next = NULL;
    a1->prev = NULL;
    init(&a2);
    a2->x = 0;
    a2->next = NULL;
    a2->prev = NULL;
    int n = makef();
    printf("\nNo of elements entered : %d\n\n", n);
    Build_list(&a1, n);
    printf("For 1st list,s");
    Print_list(a1);
    Build_list_reverse(&a2, n);
    printf("\nFor 2nd list,");
    Print_list(a2);
    return 0;
}