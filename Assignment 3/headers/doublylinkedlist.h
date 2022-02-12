#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int x;
    struct node *next;
    struct node *prev;
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
    (*a)->prev = b;
    b->prev = NULL;
    *a = b;
    printf("Element %d inserted at front\n\n", b->x);
}

void insend(struct node **a, struct node *b)
{
    if (atend(*a))
    {
        *a = b;
        b->next = NULL;
        b->prev = NULL;
    }
    else
    {
        struct node *p = *a;
        while (!atend(p->next))
            p = p->next;
        p->next = b;
        b->prev = p;
        b->next = NULL;
    }
    printf("Element %d inserted at end\n\n", b->x);
}

void insaft(struct node *a, struct node *b)
{
    b->next = a->next;
    a->next = b;
    b->prev = a;
    (b->next)->prev = b;
    printf("Element %d inserted at after%d\n\n", b->x, a->x);
}

void delfrt(struct node **a)
{
    struct node *b = *a;
    if (!atend(b))
    {
        (*a) = (*a)->next;
        (*a)->prev = NULL;
        printf("Element %d deleted at front\n\n", b->x);
        free(b);
    }
    else
        printf("List empty, cant delete\n\n");
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
        printf("List empty, cant delete\n\n");
}

void delaft(struct node *p)
{
    struct node *t = p->next;
    if (!atend(t))
    {
        p->next = t->next;
        (t->next)->prev = p;
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