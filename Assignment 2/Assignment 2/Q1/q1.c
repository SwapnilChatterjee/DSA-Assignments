#include <stdio.h>
#include <stdlib.h>
#include "./poly.h"

int main()
{
    addANewPolynomial();
    addANewPolynomial();
    // cmult(0, 3);
    mult(0,1);
    // addANewPolynomial();
    // addTwoPolynomials(0,1);
    printAllPolynomials();
    printf("Coef : %f\n",Coef(2, 0));
    printf("Coef : %f\n",Coef(4, 0));
    printf("Iszero : %d\n", IsZero(0));
    printf("Degree : %d\n", getDegree(0));

    return 0;
}