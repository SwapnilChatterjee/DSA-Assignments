#include <stdio.h>
#include <stdlib.h>
#include "./func.h"

int main()
{
    int matrix_size, mask_width;
    int **n, **m, **p;
    matrix_size = dimensions(); 
    mask_width = dimensions(); 
    n = dynamic_allocation(matrix_size);
    m = dynamic_allocation(mask_width);
    p = dynamic_allocation(matrix_size);
    n = accept_values(n, matrix_size);
    m = accept_values(m, mask_width);
    p = mul(n, m, p, matrix_size, mask_width);
    print(n, matrix_size);
    print(m, mask_width);
    print(p, matrix_size);
    return 0;
}