#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/linkedlist.h"


int makef()
{
    FILE *fptr;
    int n = 0, c = 0;
    if((fptr = fopen("nums.txt", "w")) == NULL)
        printf("Error opening File!");
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
    if((fptr = fopen("nums.txt", "w")) == NULL)
        printf("Error opening File!");    
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
    if((fptr = fopen("nums.txt", "w")) == NULL)
        printf("Error opening File!");
    while (++i <= n)
    {
        init(&ptr);
        fscanf(fptr, "%d", &(ptr->x));
        insfrt(a, ptr);
    }
    fclose(fptr);
}
void Print_list(struct node* n)
{
    show(n);
}

int main()
{
    printf("Enter nos:-\n");
    struct node *a1 = NULL, *a2 = NULL;
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
