#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int x;
    struct node *next;
};

bool atend(struct node *a)
{
    return (a == NULL);
}

void init(struct node **a)
{
    *a = (struct node *)malloc(sizeof(struct node));
}

void insfrt(struct node **a, struct node *b)
{
    b->next = *a;
    *a = b;
}

void insend(struct node **a, struct node *b)
{
    if (atend(*a))
        *a = b;
    else
    {
        struct node *p = *a;
        while (!atend(p->next))
            p = p->next;
        p->next = b;
    }
}

void insaft(struct node *a, struct node *b)
{
    b->next = a->next;
    a->next = b;
}

void delfrt(struct node **a)
{
    struct node *b = *a;
    if (!atend(b))
    {
        (*a) = (*a)->next;
        free(b);
    }
    else
        printf("List is empty \n");
}

void delend(struct node **a)
{
    struct node *p = *a;
    if (!atend(p))
    {
        struct node *t = p->next;
        if (!atend(t))
        {
            while (!atend(t->next))
            {
                t = t->next;
                p = p->next;
            }
            printf("Element %d deleted at end\n\n", t->x);
            p->next = NULL;
            free(t);
        }
        else
        {
            printf("Element %d deleted at end\n\n", p->x);
            *a = NULL;
            free(p);
        }
    }
    else
        printf("List is empty \n");
}

void delaft(struct node *p)
{
    struct node *t = p->next;
    if (!atend(t))
    {
        p->next = t->next;
        t->next = NULL;
        printf("Element %d deleted successfully\n\n", t->x);
        free(t);
    }
    else
        printf("%d is last element, cant delete after\n\n", p->x);
}

void show(struct node *a)
{
    printf("The list : ");
    while (!atend(a))
    {
        printf("%d,\t", a->x);
        a = a->next;
    }
    printf("\n\n");
}