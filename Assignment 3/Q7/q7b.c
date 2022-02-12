#include "list.h"

typedef struct
{
   node *head;
} bigint; // bigint is just a linked list

bigint init()
{
   bigint b;
   b.head = init_l();
   return b;
}

void print_number(node *head)
{
   if (head == NULL)
      return;

   print_number(head->next);
   printf("%d ", head->val);
}

int size_list(node *head)
{
   int c = 0;
   while (!empty_l(head))
   {
      c++;
      head = head->next;
   } // traverse to end
   return c;
}

void reverse_list(node **headptr) // reverse a linked list
{
   node *curr = *headptr;
   node *nexti = init_l();
   node *prev = init_l();

   while (!empty_l(curr))
   {
      nexti = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nexti;
   }
   *headptr = prev;
   return;
}

bigint get_int()
{
   bigint a = init();
   printf("Enter the number of digits : ");
   int n;
   scanf("%d", &n);

   printf("Enter the digits one by one : ");
   int temp;
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &temp);
      insert_front(create_node(temp), &a.head);
   }
   return a;
}

bigint add(bigint a, bigint b)
{
   int carry = 0;
   bigint res = init();
   node *head1 = a.head;
   node *head2 = b.head;

   while (!empty_l(head1) && !empty_l(head2))
   {
      int val = head1->val + head2->val + carry; // add digit wise
      insert_front(create_node(val % 10), &(res.head));
      carry = val / 10; // propagate carry
      head1 = head1->next;
      head2 = head2->next;
   }

   while (!empty_l(head1)) // if unequal sizes
   {
      int val = head1->val + carry;
      insert_front(create_node(val % 10), &res.head);
      carry = val / 10;
      head1 = head1->next;
   }

   while (!empty_l(head2))
   {
      int val = head2->val + carry;
      insert_front(create_node(val % 10), &res.head);
      carry = val / 10;
      head2 = head2->next;
   }

   if (carry)
   {
      insert_front(create_node(carry), &res.head);
   }
   reverse_list(&res.head); // reverse done as insert_front builds list in reverse order

   return res;
}

bigint subtract(bigint a, bigint b)
{
   int borrow = 0;
   bigint res = init();
   node *head1 = a.head;
   node *head2 = b.head;

   while (!empty_l(head1) && !empty_l(head2))
   {
      int val = head1->val + borrow - head2->val; // use borrow
      if (val >= 0)
      {
         insert_front(create_node(val), &res.head);
         borrow = 0; // propagate borrow
      }

      if (val < 0)
      {
         insert_front(create_node(val + 10), &res.head);
         borrow = -1;
      }
      head1 = head1->next;
      head2 = head2->next;
   }

   while (!empty_l(head1))
   {
      int val = head1->val + borrow;
      if (val >= 0)
      {
         insert_front(create_node(val), &res.head);
         borrow = 0;
      }

      if (val < 0)
      {
         insert_front(create_node(val + 10), &res.head);
         borrow = -1;
      }
      head1 = head1->next;
   }

   while (!empty_l(head2))
   {
      int val = borrow - head2->val;
      if (val >= 0)
      {
         insert_front(create_node(val), &res.head);
         borrow = 0;
      }

      if (val < 0)
      {
         insert_front(create_node(val + 10), &res.head);
         borrow = -1;
      }
      head2 = head2->next;
   }
   reverse_list(&res.head);

   if (borrow) // negative ans found in 10's complement
   {
      bigint temp = init();
      int s3 = size_list(res.head);
      insert_front(create_node(1), &temp.head);
      for (int i = 0; i < s3; i++)
         insert_front(create_node(0), &temp.head); // find next largest power of 10
      res = subtract(temp, res);                   // subtract
      insert_front(create_node(-1), &res.head);    // insert -1 at beginning to signify negative
   }
   return res;
}

bigint multiply_digit(bigint a, int d) // multiply digit same logic as add
{
   bigint res = init();
   int val;
   int carry = 0;
   node *head = a.head;
   while (!empty_l(head))
   {
      val = d * head->val + carry;
      insert_front(create_node(val % 10), &res.head);
      carry = val / 10;
      head = head->next;
   }

   if (carry)
   {
      insert_front(create_node(carry), &res.head);
   }
   reverse_list(&res.head);
   return res;
}

void shift(bigint *a, int s) // shift by a power of 10
{
   for (int i = 0; i < s; i++)
      insert_front(create_node(0), &a->head);
   return;
}

bigint multiply(bigint a, bigint b)
{
   node *head2 = b.head;
   int count = 0;
   bigint res = init();

   while (!empty_l(head2))
   {
      bigint temp = init();
      temp = multiply_digit(a, head2->val); // multiply
      shift(&temp, count);                  // shift
      res = add(res, temp);                 // add
      count++;
      head2 = head2->next;
   }
   return res;
}

int main()
{
   bigint a = get_int();
   bigint b = get_int();
   bigint c = subtract(a, b);
   bigint d = add(a, b);
   bigint e = multiply(a, b);
   printf("Subtraction is\n");
   print_number(c.head);
   printf("\nAddition is\n");
   print_number(d.head);
   printf("\nMultiplication is\n");
   print_number(e.head);
}
