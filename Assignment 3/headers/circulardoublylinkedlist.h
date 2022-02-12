#include <stdio.h>
#include <stdlib.h>
struct node
{
    int x;
    struct node *next;
    struct node *prev;
};

void init(struct node **a)
{
    *a = (struct node *)malloc(sizeof(struct node));
}

void insfrt(struct node *a, struct node *b)
{
    if (a->x == 0)
    {
        a->next = b;
        b->next = b;
        a->prev = b;
        b->prev = b;
        a->x++;
    }
    else
    {
        b->next = a->next;
        b->prev = a->prev;
        (a->next)->prev = b;
        (a->prev)->next = b;
        a->next = b;
        a->x++;
    }
}

void insend(struct node *a, struct node *b)
{
    if (a->x == 0)
    {
        a->next = b;
        b->next = b;
        a->prev = b;
        b->prev = b;
        a->x++;
    }
    else
    {
        b->next = a->next;
        b->prev = a->prev;
        (a->next)->prev = b;
        (a->prev)->next = b;
        a->prev = b;
        a->x++;
    }
}

void insaft(struct node *a, struct node *b, int n)
{
    struct node *p = NULL;
    int i;
    for (p = a, i = 0; i < n; i++, p = p->next)
        ;
    b->next = p->next;
    p->next = b;
    b->prev = p;
    (b->next)->prev = b;
    a->x++;
}

void delfrt(struct node *a)
{
    if (a->x == 0)
        printf("List empty, cant delete\n\n");
    else if (a->x == 1)
    {
        struct node *p = a->next;
        printf("Element %d deleted at front\n\n", p->x);
        a->x--;
        a->next = NULL;
        a->prev = NULL;
        free(p);
    }
    else
    {
        struct node *p = a->next;
        (p->next)->prev = a->prev;
        (a->prev)->next = p->next;
        printf("Element %d deleted at front\n\n", p->x);
        a->next = p->next;
        free(p);
        a->x--;
    }
}

void delend(struct node *a)
{
    if (a->x == 0)
        printf("List empty, cant delete\n\n");
    else if (a->x == 1)
    {
        struct node *p = a->prev;
        printf("Element %d deleted at front\n\n", p->x);
        a->x--;
        a->next = NULL;
        a->prev = NULL;
        free(p);
    }
    else
    {
        struct node *p = a->prev;
        (p->prev)->next = a->next;
        (a->next)->prev = p->prev;
        printf("Element %d deleted at front\n\n", p->x);
        a->prev = p->prev;
        free(p);
        a->x--;
    }
}

void delaft(struct node *a, int n)
{
    if (a->x == 1)
        printf("Element %d is the only element, cant delete after\n\n", (a->next)->x);
    else
    {
        struct node *p = NULL;
        int i;
        for (p = a, i = 0; i <= n; i++, p = p->next)
            ;
        (p->prev)->next = p->next;
        (p->next)->prev = p->prev;
        if (a->x == n)
            a->next = p->next;
        if (a->x == n - 1)
            a->prev = p->prev;
        printf("Element %d deleted\n\n", p->x);
        free(p);
        a->x--;
    }
}

void show(struct node *a)
{
    printf("The list : ");
    struct node *p = NULL;
    int i = 0;
    for (p = a->next, i = 0; i < a->x; i++, p = p->next)
        printf("%d,\t", p->x);
    printf("\n\n");
}