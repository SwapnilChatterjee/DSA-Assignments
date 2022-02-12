#include <stdio.h>
#include <stdlib.h>

// Returns 
// -1 => Unsorted
//  1 => Sorted in asscending order
//  2 => Sorted in descending order

int sortChecker(int *a, int m){
    int i;
    if(a[0]<a[1])
    {
        for(i=2;i<m-1;i++)                //checking if it's in ascending order
        {
            if(a[i-1]>a[i] || a[i]>a[i+1])
            {
                return -1;
            }
        }
        return 1;
    }
    else
    {
        for(i=2;i<m-1;i++)               //checking if it's in descending order
        {
            if(a[i-1]<a[i] || a[i]<a[i+1])
            {
                return -1;
            }
        
        }
        return 2;
    }
}