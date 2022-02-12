#include <stdio.h>

void swap(int *p, int *q)
{
	int t;

	t = *p;
	*p = *q;
	*q = t;
}

void sort(int a[], int n)
{
	int i, j, temp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
		}
	}
}

void max_filter(int arr[], int n, int k)
{
	int j, max;
	for (int i = 0; i <= n - k; i++)
	{
		max = arr[i];

		for (j = 1; j < k; j++)
		{
			if (arr[i + j] > max)
				max = arr[i + j];
		}
		printf("%d ", max);
	}
	printf("\n");
}

void min_filter(int arr[], int n, int k)
{
	int j, min;

	for (int i = 0; i <= n - k; i++)
	{
		min = arr[i];

		for (j = 1; j < k; j++)
		{
			if (arr[i + j] < min)
				min = arr[i + j];
		}
		printf("%d ", min);
	}
	printf("\n");
}

void median_filter(int arr[], int n, int k)
{
	int j, median;
	int tmpArr[k];

	for (int i = 0; i <= n - k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			tmpArr[j] = arr[i + j];
			printf("%d ", tmpArr[j]);
		}
		sort(tmpArr, k);

		if ((k) % 2 == 0)
		{
			median = (tmpArr[(k - 1) / 2] + tmpArr[k / 2]) / 2;
		}
		else
			median = tmpArr[(k / 2)];
		printf(" = %d\n ", median);
	}
	printf("\n");
}
