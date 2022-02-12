#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/doublylinkedlist.h"



void showrev(struct node *a)
{
    printf("The list : ");
    while (!atend(a->next))
        a = a->next;
    while (!atend(a->prev))
    {
        printf("%d\t", a->x);
        a = a->prev;
    }
    printf("\n\n");
}

int size(struct node *a)
{
    int n = 0;
    while (!atend(a))
    {
        a = a->next;
        n++;
    }
    return n;
}

bool equal(struct node *a, struct node *b)
{
    bool c = true;
    for (; c; a = a->next, b = b->next)
    {
        if (atend(a) || atend(b))
        {
            if (!(atend(a) && atend(b)))
                c = false;
        }
        else if (a->next != b->next)
            c = false;
    }
    return c;
}

void append(struct node *a, struct node *b)
{
    if (atend(a))
    {
        a = b;
        b = NULL;
    }
    else
    {
        while (!atend(a->next))
            a = a->next;
        a->next = b;
        b = NULL;
    }
}

struct node *search1(struct node *a, int k)
{
    struct node *p = NULL;
    for (p = a; !atend(p); p = p->next)
        if (p->x == k)
            break;
    if (!atend(p))
    {
        if (!atend(p->next))
            (p->next)->prev = p->prev;
        if (!atend(p->prev))
            (p->prev)->next = p->next;
    }
    p->next = NULL;
    p->prev = NULL;
    return p;
}

struct node *search2(struct node *a, int k)
{
    struct node *p = NULL;
    int u = size(a), l = 1, m = 0, i = 0;
    for (m = (l + u) / 2; l < u; m = (l + u) / 2)
    {
        for (p = a, i = 1; i < m; i++, p = p->next)
            ;
        if (p->x == k)
            break;
        else if (p->x > k)
            u = m - 1;
        else
            l = m + 1;
    }
    if (l < u)
        p = NULL;
    else
    {
        if (!atend(p->next))
            (p->next)->prev = p->prev;
        if (!atend(p->prev))
            (p->prev)->next = p->next;
    }
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void delete (struct node *a, int p)
{
    int n = size(a);
    if ((p - 1) * (p - n) > 0)
        printf("ListIndexOutOfBoundException\n\n");
    else if (p == 1)
        delfrt(&a);
    else if (p == n)
        delend(&a);
    else
    {
        struct node *t = a;
        for (int i = 1; i < p - 1; i++, t = t->next)
            ;
        delaft(t);
    }
}

bool order(struct node *a)
{
    bool c = true;
    for (; c && (!atend(a->next)); a = a->next)
        if (a->x > (a->next)->x)
            c = false;
    return c;
}

struct node *mergesort(struct node *a, struct node *b)
{
    struct node *c = NULL, *ptr = NULL;
    if (atend(a))
    {
        c = b;
        b = NULL;
    }
    else if (atend(b))
    {
        c = a;
        a = NULL;
    }
    else if (a->x < b->x)
    {
        c = a;
        a = a->next;
        c->next = NULL;
        c->prev = NULL;
    }
    else
    {
        c = b;
        b = b->next;
        c->next = NULL;
        c->prev = NULL;
    }
    for (ptr = c; !(atend(b) || atend(a));)
    {
        if (a->x < b->x)
        {
            ptr->next = a;
            a->prev = ptr;
            a = a->next;
            a->prev = NULL;
            ptr = ptr->next;
            ptr->next = NULL;
        }
        else
        {
            ptr->next = b;
            b->prev = ptr;
            b = b->next;
            b->prev = NULL;
            ptr = ptr->next;
            ptr->next = NULL;
        }
    }
    if (atend(a))
    {
        ptr->next = b;
        b->prev = ptr;
        b = NULL;
    }
    else
    {
        ptr->next = a;
        a->prev = ptr;
        a = NULL;
    }
    return (c);
}

void insert1(struct node *a, struct node *b, int k)
{
    if (a->x == k)
        insfrt(&a, b);
    else
    {
        struct node *p = NULL;
        for (p = a; !atend(p->next); p = p->next)
            if ((p->next)->x == k)
                break;
        if (!atend(p->next))
            insaft(p, b);
        else
            insend(&a, b);
    }
}

void insert2(struct node *a, struct node *b, int k)
{
    struct node *p = NULL;
    int u = size(a), l = 1, m = 0, i = 0;
    for (m = (l + u) / 2; l < u; m = (l + u) / 2)
    {
        for (p = a, i = 1; i < m; i++, p = p->next)
            ;
        if (p->x == k)
            break;
        else if (p->x > k)
            u = m - 1;
        else
            l = m + 1;
    }
    if (l < u)
        insend(&a, b);
    else if (m == 1)
        insfrt(&a, b);
    else
    {
        for (p = a, i = 1; i < m - 1; i++, p = p->next)
            ;
        insaft(p, b);
    }
}

void remove1(struct node *a)
{
    struct node *i = NULL, *j = NULL;
    for (i = a; !atend(i->next); i = i->next)
    {
        for (j = i; !atend(j->next);)
        {
            if (i->x == (j->next)->x)
                delaft(j);
            else
                j = j->next;
        }
    }
}

void remove2(struct node *a)
{
    struct node *p = NULL;
    for (p = a; !atend(p->next);)
    {
        if (p->x == (p->next)->x)
            delaft(p);
        else
            p = p->next;
    }
}

void pairswap(struct node *a)
{
    struct node *u = NULL, *v = NULL;
    for (u = a, v = a->next; !(atend(u) || atend(v)); u = v->next, v = u->next)
    {
        u->x += v->x;
        v->x = u->x - v->x;
        u->x -= v->x;
    }
}

void delalt(struct node *a)
{
    for (int i = 2; i <= size(a); delete (a, i), i++)
        ;
}

void rotate(struct node *a, int k)
{
    int n = size(a), i = 0;
    k %= n;
    if (k > 0)
    {
        struct node *p = NULL, *t = NULL;
        for (t = a, i = 1; i < k; i++, t = t->next)
            ;
        for (p = t->next; !atend(p->next); p = p->next)
            ;
        p->next = a;
        a->prev = p;
        a = t->next;
        a->prev = NULL;
        t->next = NULL;
    }
}

void lasttofirst(struct node *a)
{
    rotate(a, size(a) - 1);
}

void dellist(struct node *a)
{
    while (!atend(a))
        delfrt(&a);
}

void reverse(struct node **a)
{
    struct node *b = *a, *c = *a, *d = NULL;
    while (!atend(b))
    {
        c = c->next;
        b->next = d;
        d = b;
        b = c;
    }
    b = d;
    c = d;
    d = NULL;
    *a = d;
    while (!atend(b))
    {
        c = c->prev;
        b->prev = d;
        d = b;
        b = c;
    }
}

void sort(struct node *a)
{
    struct node *i = NULL, *j = NULL, *p = NULL;
    for (i = a; !atend(i->next); i = i->next, p = NULL)
    {
        for (j = i->next; !atend(j); j = j->next)
        {
            if (atend(p))
            {
                if (j->x < i->x)
                    p = j;
            }
            else
            {
                if (j->x < p->x)
                    p = j;
            }
        }
        if (!atend(p))
        {
            i->x += p->x;
            p->x = i->x - p->x;
            i->x -= p->x;
        }
    }
}

void main()
{
    struct node *ll = NULL, *ptr = NULL, *tmp = NULL;
    int c = 1, z = 0;
    while ((c - 1) * (c - 18) <= 0)
    {
        printf("----------------------------------------------------------------------");
        printf("\n1.print list\n2.print list in reverse\n3.get size of list\n");
        printf("4.check equality with another list\n5.search for a key\n6.append with another list\n");
        printf("7.delete a node\n8.check for order\n9.merge with a sorted list\n");
        printf("10.insert a node before a node\n11.remove dublicate\n12.swap elements pairwise\n");
        printf("13.move last element to front\n14.delete alternate nodes\n15.rotate by a no of nodes\n");
        printf("16.delete list\n17.reverse the list\n18.sort the list\nanything else to exit\n");
        printf("----------------------------------------------------------------------\n");
        printf("Enter choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            show(ll);
            break;
        case 2:
            showrev(ll);
            break;
        case 3:
            printf("Size : %d\n", size(ll));
            break;
        case 4:
            z = 1;
            while (z == 1)
            {
                printf("Enter\n1.to enter new element in new list\nanything else to exit\nEnter choice : ");
                scanf("%d", &z);
                if (z == 1)
                {
                    printf("Enter element : ");
                    init(&tmp);
                    scanf("%d", &(tmp->x));
                    insend(&ptr, tmp);
                    tmp = NULL;
                }
            }
            printf("Are the 2 lists same? %s\n", equal(ll, ptr) ? "yes" : "no");
            break;
        case 5:
            printf("Enter key : ");
            scanf("%d", &z);
            if (order(ll))
                ptr = search2(ll, z);
            else
                ptr = search1(ll, z);
            if (atend(ptr))
                printf("Key found\n");
            else
                printf("Key not found\n");
            delfrt(&ptr);
            break;
        case 6:
            z = 1;
            while (z == 1)
            {
                printf("Enter\n1.to enter new element in new list\nanything else to exit\nEnter choice : ");
                scanf("%d", &z);
                if (z == 1)
                {
                    printf("Enter element : ");
                    init(&tmp);
                    scanf("%d", &(tmp->x));
                    insend(&ptr, tmp);
                    tmp = NULL;
                }
            }
            append(ll, ptr);
            break;
        case 7:
            printf("Enter element index from list : ");
            scanf("%d", &z);
            delete (ll, z);
            break;
        case 8:
            printf("Is list ordered? %s\n", order(ll) ? "yes" : "no");
            break;
        case 9:
            if (!order(ll))
                sort(ll);
            z = 1;
            while (z == 1)
            {
                printf("Enter\n1.to enter new element in new list\nanything else to exit\nEnter choice : ");
                scanf("%d", &z);
                if (z == 1)
                {
                    printf("Enter element : ");
                    init(&tmp);
                    scanf("%d", &(tmp->x));
                    insend(&ptr, tmp);
                    tmp = NULL;
                }
            }
            if (!order(ptr))
                sort(ptr);
            show(ptr);
            mergesort(ll, ptr);
            break;
        case 10:
            printf("Enter element : ");
            init(&tmp);
            scanf("%d", &(tmp->x));
            printf("Enter element from list : ");
            scanf("%d", &z);
            if (order(ll))
                insert2(ll, tmp, z);
            else
                insert1(ll, tmp, z);
            break;
        case 11:
            if (order(ll))
                remove2(ll);
            else
                remove1(ll);
            break;
        case 12:
            pairswap(ll);
            break;
        case 13:
            lasttofirst(ll);
            break;
        case 14:
            delalt(ll);
            break;
        case 15:
            printf("Enter no of nodes to rotate by : ");
            scanf("%d", &z);
            rotate(ll, z);
            break;
        case 16:
            dellist(ll);
            break;
        case 17:
            reverse(&ll);
            break;
        case 18:
            sort(ll);
            break;
        default:
            exit(1);
        }
    }
}
