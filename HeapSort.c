#include<stdio.h>
#include<stdlib.h>
void MaxHeapify(int *a, int i, int n)
{
	int item = a[i];
	int j = 2 * i + 1;
	while(j < n)
	{
		if (j < n-1 && a[j] < a[j + 1])
			j++;
		if (a[j] <= item)
			break;
		a[i] = a[j];
		i = j;
		j = 2 * j + 1;
	}
	a[i] = item;
}
void HeapSort(int *a, int n)
{
	int i, temp;
	for (i = n/2 - 1; i >= 0; i--)
		MaxHeapify(a, i, n);
	while (n > 1)
	{
		temp = a[0];
		a[0] = a[n - 1];
		a[n - 1] = temp;
		n--;
		MaxHeapify(a, 0, n);
	}
}
int main()
{
	int *a, n, i;
	printf("\n  Enter the number of elements : ");
	scanf("%d", &n);
	a = (int*)calloc(n, sizeof(int));
	if (a == NULL)
	{
		printf("\n  Unable to allocate memory!!!");
		exit(1);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("  Enter a[%d] : ", i);
		scanf("%d", &a[i]);
	}
	HeapSort(a, n);
	printf("\n  The sorted array is : \n\n ");
	for (i = 0; i < n; i++)
	{
		printf(" %d", a[i]);
		if (i < n - 1)
			printf(",");
		else
			printf("\n");
	}
	return 0;
}
