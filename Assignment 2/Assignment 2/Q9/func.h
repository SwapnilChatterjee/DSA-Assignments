#include <stdio.h>
#include <stdlib.h>


void merge(int a[], int b[], int m, int n)
{
    for (int i=n-1; i>=0; i--)
    { 
        int j, end = a[m-1];
        for (j=m-2; j >= 0 && a[j] > b[i]; j--)
            a[j+1] = a[j]; 
        if (j != m-2 || end > b[i])
        {
            a[j+1] = b[i];
            b[i] = end;
        }
    }
}