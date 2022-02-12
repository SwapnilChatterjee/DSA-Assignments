#include <stdio.h>
#include <stdlib.h>

long random_generate(long a,long b)
{
	return a+ rand()%(b-a);
}

int is_prime(int a)
{
	int i;
	for(i=2;i<a;i++)
		if(a%i==0) return 0;
	return 1;
}

