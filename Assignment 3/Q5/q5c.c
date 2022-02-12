#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./headers/circularDoubleLinkedList.h"
bool atend(struct node *a) { return (a == NULL); }

void showrev(struct node *a)
{
    int i = 0, n = a->x;
    for (a = a->prev, i = 1; i <= n; i++, a = a->prev)
        printf("%d,\t", a->x);
    printf("\n\n");
}

int size(struct node *a)
{
    return a->x;
}

bool equal(struct node *a, struct node *b)
{
    bool c = (a->x == b->x);
    int i = 0, n = 0;
    if (c)
    {
        n = a->x;
        a = a->next;
        b = b->next;
        for (i = 1; (i <= n) && c; a = a->next, b = b->next, i++)
            if (a->next != b->next)
                c = false;
    }
    return c;
}

struct node *search1(struct node *a, int k)
{
    struct node *p = NULL;
    int i = 0, n = a->x;
    for (p = a->next, i = 0; i < n; i++, p = p->next)
        if (p->x == k)
            break;
    if (i == n)
        p = NULL;
    else
    {
        if (i == 0)
            a->next = p->next;
        if (i == n - 1)
            a->prev = p->prev;
        (p->next)->prev = p->prev;
        (p->prev)->next = p->next;
        p->next = NULL;
        p->prev = NULL;
    }
    return p;
}

struct node *search2(struct node *a, int k)
{
    struct node *p = NULL, *t = NULL;
    int u = a->x, l = 1, m = 0, i = 0;
    for (m = (l + u) / 2; l < u; m = (l + u) / 2)
    {
        for (p = a, i = 1; i < m; i++, p = p->next)
            ;
        if ((p->next)->x == k)
            break;
        else if ((p->next)->x > k)
            u = m - 1;
        else
            l = m + 1;
    }
    if (l < u)
        p = NULL;
    else
    {
        if (m == 0)
            a->next = p->next;
        if (m == a->x - 1)
            a->prev = p->prev;
        (p->next)->prev = p->prev;
        (p->prev)->next = p->next;
        p->next = NULL;
        p->prev = NULL;
    }
    return p;
}

void append(struct node *a, struct node *b)
{
    struct node *p = NULL;
    int i = 0;
    if (a->x == 0)
    {
        p = a;
        a = b;
        b = NULL;
        free(p);
    }
    else
    {
        (a->prev)->next = b->next;
        (b->next)->prev = a->prev;
        (a->next)->prev = b->prev;
        (b->prev)->next = a->next;
        a->prev = b->prev;
        a->x += b->x;
        b->next = NULL;
        b->prev = NULL;
    }
}

void delete (struct node *a, int p)
{
    int n = a->x;
    if ((p - 1) * (p - n) > 0)
        printf("ListIndexOutOfBoundException\n\n");
    else if (p == 1)
        delfrt(a);
    else if (p == n)
        delend(a);
    else
        delaft(a, p);
}

bool order(struct node *a)
{
    bool c = true;
    int n = a->x, i = 0;
    struct node *p = NULL;
    for (p = a->next, i = 1; c && (i < n); i++, a = a->next)
        if (a->x > (a->next)->x)
            c = false;
    return c;
}

struct node *mergesort(struct node *a, struct node *b)
{
    struct node *c = NULL, *p = NULL;
    init(&c);
    c->x = 0;
    int z = 0;
    while ((a->x > 0) || (b->x > 0))
    {
        if (a->x == 0)
        {
            z = (b->next)->x;
            delfrt(b);
            init(&p);
            p->x = z;
            insfrt(c, p);
        }
        else if (b->x == 0)
        {
            z = (a->next)->x;
            delfrt(a);
            init(&p);
            p->x = z;
            insfrt(c, p);
        }
        else
        {
            if ((a->next)->x > (b->next)->x)
            {
                z = (a->next)->x;
                delfrt(a);
                init(&p);
                p->x = z;
                insfrt(c, p);
            }
            else
            {
                z = (b->next)->x;
                delfrt(b);
                init(&p);
                p->x = z;
                insfrt(c, p);
            }
        }
    }
    return (c);
}

void insert1(struct node *a, struct node *b, int k)
{
    if ((a->x > 0) && ((a->next)->x == k))
        insfrt(a, b);
    else
        insaft(a, b, k);
}

void insert2(struct node *a, struct node *b, int k)
{
    struct node *p = NULL;
    int u = a->x, l = 1, m = 0, i = 0;
    for (m = (l + u) / 2; l < u; m = (l + u) / 2)
    {
        for (p = a->next, i = 1; i < m; i++, p = p->next)
            ;
        if (p->x == k)
            break;
        else if (p->x > k)
            u = m - 1;
        else
            l = m + 1;
    }
    if (l < u)
        insend(a, b);
    else if (m == 1)
        insfrt(a, b);
    else
    {
        for (p = a, i = 1; i < m - 1; i++, p = p->next)
            ;
        insaft(a, b, m);
    }
}

void remove1(struct node *a)
{
    struct node *p = NULL, *t = NULL;
    int i = 0, j = 0;
    for (p = a->next, i = 1; i < a->x; i++, p = p->next)
    {
        for (t = p, j = i; j < a->x;)
        {
            if (p->x == (t->next)->x)
                delaft(a, j);
            else
            {
                j++;
                t = t->next;
            }
        }
    }
}

void remove2(struct node *a)
{
    struct node *p = NULL;
    int i = 0;
    for (p = a, i = 0; i < a->x;)
    {
        if (p->x == (p->next)->x)
            delaft(a, i);
        else
        {
            i++;
            p = p->next;
        }
    }
}

void pairswap(struct node *a)
{
    struct node *u = NULL, *v = NULL;
    int i = 0;
    for (u = a->next, v = (a->next)->next, i = 1; i < a->x; u = v->next, v = u->next, i += 2)
    {
        u->x += v->x;
        v->x = u->x - v->x;
        u->x -= v->x;
    }
}

void delalt(struct node *a)
{
    for (int i = 2; i <= a->x; delete (a, i), i++)
        ;
}

void rotate(struct node *a, int k)
{
    int i = 0;
    k %= a->x;
    if (k > 0)
    {
        for (i = 1; i < k; i++, a->prev = (a->prev)->next, a->next = (a->next)->next)
            ;
    }
}

void lasttofirst(struct node *a)
{
    rotate(a, a->x - 1);
}

void dellist(struct node *a)
{
    while (!atend(a))
        delfrt(a);
}

void reverse(struct node *a)
{
    struct node *b = NULL, *c = NULL, *d = NULL;
    int i = 0;
    (a->next)->prev = NULL;
    (a->prev)->next = NULL;
    b = a->next;
    c = b;
    a->next = NULL;
    a->prev = NULL;
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
    a->next = d;
    while (!atend(b))
    {
        c = c->prev;
        b->prev = d;
        d = b;
        b = c;
    }
    a->prev = d;
    (a->prev)->next = a->next;
    (a->next)->prev = a->prev;
}

void sort(struct node *a)
{
    struct node *u = NULL, *v = NULL, *p = NULL;
    int i = 0, j = 0;
    for (u = a->next, i = 1; i < a->x; u = u->next, i++, p = NULL)
    {
        for (v = u->next, j = i + 1; j <= a->x; v = v->next, j++)
        {
            if (atend(p))
            {
                if (v->x < u->x)
                    p = v;
            }
            else
            {
                if (v->x < p->x)
                    p = v;
            }
        }
        if (!atend(p))
        {
            u->x += p->x;
            p->x = u->x - p->x;
            u->x -= p->x;
        }
    }
}

void main()
{
    struct node *ll = NULL, *ptr = NULL, *tmp = NULL;
    int c = 1, z = 0;
    init(&ll);
    ll->x = 0;
    ll->next = NULL;
    ll->prev = NULL;
    init(&ptr);
    ptr->x = 0;
    ptr->next = NULL;
    ptr->prev = NULL;
    while ((c - 1) * (c - 18) <= 0)
    {
        printf("----------------------------------------------------------------------");
        printf("\n1.print list\n2.print list in reverse\n3.get size of list\n");
        printf("4.check equality with another list\n5.search for a key\n6.append with another list\n");
        printf("7.delete a node\n8.check for order\n9.merge with a sorted list\n");
        printf("10.insert a node before a node\n11.remove dublicate\n12.swap elements pairwise");
        printf("13.move last element to front\n14.delete alternate nodes\n15.rotate by a no of nodes\n");
        printf("16.delete list\n17.reverse the list\n18.sort the list\nanything else to exit\n");
        printf("----------------------------------------------------------------------");
        printf("Enter choice : ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            show(ll);
            break;
        case 2:
            showrev(ll->next);
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
                    insend(ptr, tmp);
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
            delfrt(ptr);
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
                    insend(ptr, tmp);
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
                    insend(ptr, tmp);
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
            reverse(ll);
            break;
        case 18:
            sort(ll);
            break;
        default:
            exit(1);
        }
    }
}
