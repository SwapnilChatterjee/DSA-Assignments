#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
typedef struct node
{
 int val;
 struct node* next;
}node;

node* create_node(int val)// allocates memory for node
{
 node* h = NULL;
 if((h=(node*)(malloc(sizeof(node))))==NULL)
    perror("Erron\n");
 else
    {h->val=val;
     h->next=NULL;}
 return h;
}

node* init_l()
{
 return NULL;
}

int empty_l(node* head)//check if null
{
 return (head==NULL);
}

int atend_l(node* target) //check if atend ie head->next==NULL
{
 if(target==NULL)
    return 1;
 return (target->next==NULL);
}

void insert_front(node* target,node** phead)
{
 target->next=*phead;
 *phead=target;
 return;
}

void delete_front(node** phead)
{
 node* cur;
 cur = *phead;
 *phead = (*phead)->next;
 free(cur);
 return;
}

void insert_after(node* target,node* prev)
{
 target->next=prev->next;
 prev->next=target;
 return;
}

void delete_after(node* prev)
{
 node* cur;
 if(!atend_l(prev)) //if atend cannot delete after
 {
  cur=prev->next;
  prev->next=cur->next;
  free(cur);
 }
 return;
}

node* delete_front_nullify(node** phead)//same as delete front but return front instead of free
{
 node* cur;
 cur = *phead;
 *phead = (*phead)->next;
 cur->next = init_l();
 return cur;
}

node *delete_after_nullify(node* prev)//same as delete after but return node instead of free
{
 node* cur;
 if(!atend_l(prev))
 {
  cur=prev->next;
  prev->next=cur->next;
  cur->next=NULL;
  return cur;
 }
 return NULL;
}



