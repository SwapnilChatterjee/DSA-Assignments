#include <stdio.h>
#include <stdlib.h>
struct node
{
    int x;
    struct node *next;
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
        a->x++;
    }
    else
    {
        struct node *p = NULL;
        int i = 0;
        for (p = a, i = 0; i < a->x; i++, p = p->next)
            ;
        p->next = b;
        b->next = a->next;
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
        a->x++;
    }
    else
    {
        struct node *p = NULL;
        int i = 0;
        for (p = a, i = 0; i < a->x; i++, p = p->next)
            ;
        p->next = b;
        b->next = a->next;
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
        free(p);
    }
    else
    {
        struct node *p = NULL;
        int i = 0;
        for (p = a, i = 0; i < a->x; i++, p = p->next)
            ;
        p->next = (p->next)->next;
        p = a->next;
        printf("Element %d deleted at front\n\n", p->x);
        a->next = (a->next)->next;
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
        struct node *p = a->next;
        printf("Element %d deleted at end\n\n", p->x);
        a->x--;
        a->next = NULL;
        free(p);
    }
    else
    {
        struct node *p = NULL, *t = NULL;
        int i = 0;
        for (p = a, i = 1; i < a->x; i++, p = p->next)
            ;
        printf("Element %d deleted at end\n\n", (p->next)->x);
        t = p->next;
        p->next = t->next;
        free(t);
        a->x--;
    }
}

void delaft(struct node *a, int n)
{
    if (a->x == 1)
        printf("Element %d is the only element, cant delete after\n\n", (a->next)->x);
    else
    {
        struct node *p = NULL, *t = NULL;
        int i;
        for (p = a, i = 0; i < n; i++, p = p->next)
            ;
        t = p->next;
        p->next = t->next;
        if (a->x == n)
            a->next = (a->next)->next;
        printf("Element %d deleted\n\n", t->x);
        free(t);
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
