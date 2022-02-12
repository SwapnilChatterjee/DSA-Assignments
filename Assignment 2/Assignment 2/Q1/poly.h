#include <stdio.h>
#include <stdlib.h>


#define max_terms 36000
#define max_polynomials 1200

typedef struct __term
{
    int exp;
    float coef;
} term;

typedef struct __polynomial
{
    int begin;
    int end;
} polynomial;



term PolynomialTerms[max_terms];
polynomial Polynomials[max_polynomials];
int noOfPolynomials = 0;
int noOfTerms = 0;


void printPolynomial(int index)
{
    for (int i = Polynomials[index].begin; i <= Polynomials[index].end; i++)
    {
        printf("%fx^%d", PolynomialTerms[i].coef, PolynomialTerms[i].exp);
        if (i != Polynomials[index].end)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

void printAllPolynomials()
{
    int begin, end;
    for (int i = 0; i < noOfPolynomials; i++)
    {
        printf("Printing elements of polynomial : %d\n", i);
        printPolynomial(i);
    }
}

void addANewPolynomial()
{
    int tmp, exp;
    float coef;
    printf("Enter no of elemets you want to enter in this polynomial : ");
    scanf("%d", &tmp);
    Polynomials[noOfPolynomials].begin = noOfTerms;
    for (int i = 0; i < tmp; i++)
    {
        printf("Enter coeficient & exponent : ");
        scanf("%f %d", &coef, &exp);
        PolynomialTerms[noOfTerms].exp = exp;
        PolynomialTerms[noOfTerms].coef = coef;
        noOfTerms++;
    }
    Polynomials[noOfPolynomials].end = noOfTerms - 1;
    noOfPolynomials++;
}

float Coef(int exp, int polyIndex)
{
    if (polyIndex > noOfPolynomials - 1)
        return -1.0;
    for (int i = Polynomials[polyIndex].begin; i <= Polynomials[polyIndex].end; i++)
    {
        if (PolynomialTerms[i].exp == exp)
        {
            return PolynomialTerms[i].coef;
        }
    }

    return -1.0;
}

int IsZero(int polyIndex)
{
    for (int i = Polynomials[polyIndex].begin; i <= Polynomials[polyIndex].end; i++)
    {
        if (PolynomialTerms[i].coef != 0)
        {
            return 0;
        }
    }

    return 1;
}

int getDegree(int index)
{
    if (IsZero(index))
        return -1;
    int degree = 0;
    for (int i = Polynomials[index].begin; i <= Polynomials[index].end; i++)
    {
        if (PolynomialTerms[i].coef != 0 && PolynomialTerms[i].exp > degree)
        {
            degree = PolynomialTerms[i].exp;
        }
    }
    return degree;
}

int addTwoPolynomials(int polyAIndex, int polyBIndex)
{
    Polynomials[noOfPolynomials].begin = noOfTerms;

    int startA = Polynomials[polyAIndex].begin;
    int finishA = Polynomials[polyAIndex].end;

    int startB = Polynomials[polyBIndex].begin;
    int finishB = Polynomials[polyBIndex].end;

    while (startA <= finishA && startB <= finishB)
    {
        printf("%d %d\n", startA, startB);

        if (PolynomialTerms[startA].exp == PolynomialTerms[startB].exp)
        {
            printf("%d\n", PolynomialTerms[startA].exp);
            PolynomialTerms[noOfTerms].exp = PolynomialTerms[startA].exp;
            PolynomialTerms[noOfTerms].coef = (PolynomialTerms[startA].coef + PolynomialTerms[startB].coef);
            startA++;
            startB++;
            noOfTerms++;
        }
        else if (PolynomialTerms[startA].exp < PolynomialTerms[startB].exp)
        {
            PolynomialTerms[noOfTerms].exp = PolynomialTerms[startB].exp;
            PolynomialTerms[noOfTerms].coef = PolynomialTerms[startB].coef;
            noOfTerms++;
            startB++;
        }
        else if (PolynomialTerms[startA].exp > PolynomialTerms[startB].exp)
        {
            PolynomialTerms[noOfTerms].exp = PolynomialTerms[startA].exp;
            PolynomialTerms[noOfTerms].coef = PolynomialTerms[startA].coef;
            noOfTerms++;
            startA++;
        }
    }

    while (startA <= finishA)
    {
        PolynomialTerms[noOfTerms].exp = PolynomialTerms[startA].exp;
        PolynomialTerms[noOfTerms].coef = PolynomialTerms[startA].coef;
        noOfTerms++;
        startA++;
    }

    while (startB <= finishB)
    {
        PolynomialTerms[noOfTerms].exp = PolynomialTerms[startB].exp;
        PolynomialTerms[noOfTerms].coef = PolynomialTerms[startB].coef;
        noOfTerms++;
        startB++;
    }

    Polynomials[noOfPolynomials].end = noOfTerms - 1;
    noOfPolynomials++;

    return noOfPolynomials - 1;
}

int cmult(int index, int k)
{
    Polynomials[noOfPolynomials].begin = noOfTerms;
    for (int i = Polynomials[index].begin; i <= Polynomials[index].end; i++)
    {
        PolynomialTerms[noOfTerms].exp = PolynomialTerms[i].exp;
        PolynomialTerms[noOfTerms].coef = PolynomialTerms[i].coef * k;
        noOfTerms++;
    }

    Polynomials[noOfPolynomials].end = noOfTerms - 1;
    noOfPolynomials++;
    return noOfPolynomials - 1;
}

int mult(int polyAIndex, int polyBIndex)
{
    int maxDegree = getDegree(polyAIndex) + getDegree(polyBIndex);
    int k = maxDegree;
    Polynomials[noOfPolynomials].begin = noOfTerms;
    while (k >= 0)
    {
        float d = 0;
        for (int i = Polynomials[polyAIndex].begin; i <= Polynomials[polyAIndex].end; i++)
        {
            for (int j = Polynomials[polyBIndex].begin; j <= Polynomials[polyBIndex].end; j++)
            {
                if(PolynomialTerms[i].exp + PolynomialTerms[j].exp == k){
                    d = d + (PolynomialTerms[i].coef * PolynomialTerms[j].coef); 
                }
            }
        }

        if(d != 0.0){
            PolynomialTerms[noOfTerms].exp = k;
            PolynomialTerms[noOfTerms].coef = d;
            noOfTerms++;
        }

        k--;
    }

    Polynomials[noOfPolynomials].end = noOfTerms-1;
    noOfPolynomials++;
    return noOfPolynomials-1;

}
