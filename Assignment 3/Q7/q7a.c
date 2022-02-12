#include <stdio.h>
#include <stdlib.h>
#define MAX 70

typedef struct
{
   int digit[MAX];
} bigint; // consider last bit as sign bit

int size(bigint a)
{
   int pos = 0;
   for (int i = 0; i < MAX - 1; i++) // last non zero digit
      if (a.digit[i] != 0)
         pos = i;
   return pos + 1;
}

void reverse(int *a, int len)
{
   for (int i = 0; i < len / 2; i++)
   {
      int temp = a[i];
      a[i] = a[len - i - 1];
      a[len - i - 1] = temp;
   }
   return;
}

bigint init()
{
   bigint a;
   for (int i = 0; i < MAX; i++)
      a.digit[i] = 0; // set everything to 0
   return a;
}

void print(bigint a)
{
   int s = size(a);
   if (a.digit[MAX - 1] == 1) // if negative
      printf("- ");
   for (int i = s - 1; i >= 0; i--)
      printf("%d ", a.digit[i]);
   return;
}

bigint get_int()
{
   printf("Enter the number of digits : ");
   int n;
   scanf("%d", &n);
   int arr[n];
   printf("Enter digit one by one : ");
   for (int i = 0; i < n; i++)
      scanf("%d", &arr[i]);
   bigint a = init();
   for (int i = 0; i < n; i++)
      a.digit[i] = arr[n - 1 - i];
   return a;
}

bigint add(bigint a, bigint b)
{
   int s1 = size(a);
   int s2 = size(b);

   bigint res = init();
   int c = 0;
   int carry = 0;
   while (c < s1 && c < s2)
   {
      int val = a.digit[c] + b.digit[c] + carry; // add digit wise
      res.digit[c] = val % 10;
      carry = val / 10; // propagate carry
      c++;
   }

   while (c < s1)
   {
      int val = a.digit[c] + carry; // if two numbers have unequal size
      res.digit[c] = val % 10;
      carry = val / 10;
      c++;
   }

   while (c < s2)
   {
      int val = b.digit[c] + carry;
      res.digit[c] = val % 10;
      carry = val / 10;
      c++;
   }

   if (carry) // final end around carry generated
   {
      if (c == MAX - 1)
         perror("Overflow\n");
      res.digit[c] = carry;
      c++;
   }
   return res;
}

bigint multiply_digit(bigint a, int d) // logic similar to add but multiply a digit instead
{
   int s1 = size(a);

   bigint res = init();
   int c = 0;
   int carry = 0;
   while (c < s1)
   {
      int val = a.digit[c] * d + carry;
      res.digit[c] = val % 10;
      carry = val / 10;
      c++;
   }

   if (carry)
   {
      if (c == MAX - 1)
         perror("Overflow\n");
      res.digit[c] = carry;
      c++;
   }
   return res;
}

bigint subtract(bigint a, bigint b)
{
   int s1 = size(a);
   int s2 = size(b);

   int c = 0;
   int borrow = 0;
   bigint res = init();
   while (c < s1 && c < s2)
   {
      int val = a.digit[c] + borrow - b.digit[c]; // use borrow
      if (val >= 0)
      {
         res.digit[c] = val;
         borrow = 0;
      } // propagate borrow
      else
      {
         res.digit[c] = val + 10;
         borrow = -1;
      }
      c++;
   }

   while (c < s1) // if unequal sizes
   {
      int val = a.digit[c] + borrow;
      if (val >= 0)
      {
         res.digit[c] = val;
         borrow = 0;
      }
      else
      {
         res.digit[c] = val + 10;
         borrow = -1;
      }
      c++;
   }

   while (c < s2)
   {
      int val = borrow - b.digit[c];
      if (val >= 0)
      {
         res.digit[c] = val;
         borrow = 0;
      }
      else
      {
         res.digit[c] = val + 10;
         borrow = -1;
      }
      c++;
   }

   if (borrow) // final borrow generated, number in 10s complement format and negative
   {
      int s3 = size(res);
      bigint ten = init();
      ten.digit[s3] = 1;        // power of 10 just above number
      res = subtract(ten, res); // subtract ans from it
      res.digit[MAX - 1] = 1;   // set sign bit
   }
   return res;
}

void shift(bigint *a, int s) // multiplying by 10^s
{
   int len = size(*a);
   if (len + s > MAX)
      perror("Overflow\n");
   for (int i = len + s - 1; i >= s; i--)
      a->digit[i] = a->digit[i - s];
   for (int i = 0; i < s; i++)
      a->digit[i] = 0;
   return;
}

bigint multiply(bigint a, bigint b)
{
   bigint res = init();
   int s2 = size(b);
   for (int i = 0; i < s2; i++)
   {
      bigint temp = multiply_digit(a, b.digit[i]); // multiply digit
      shift(&temp, i);                             // shift required amount
      res = add(res, temp);                        // add
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
   printf("Addition is\n");
   print(d);
   printf("\nSubtraction is\n");
   print(c);
   printf("\nMultiplication is\n");
   print(e);
}
