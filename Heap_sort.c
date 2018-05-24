#include <stdio.h>

#define LEFT(i) 	 	2 * i + 1
#define RIGHT(i) 		2 * (i  + 1)
#define PARENT(i) 	(i  - 1) / 2

void Swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void MaxHeapify(int *A, int length, int i)
{
	int large;
	int l = LEFT(i);
	int r = RIGHT(i);

	if (l < length && (A[i]  <  A[l]) )
		large = l;
	else
		large = i;
	if (r < length  && (A[r] > A[large]) )
		large = r;
	if (large != i)
	{
		Swap(&A[i], &A[large]);
		MaxHeapify(A, length, large);
	}
}


void BuildMaxHeap(int *A, int length)
{
	for (int i = length/2 -1; i >= 0; i--)
	{
		MaxHeapify(A, length , i);
	}
}

void HeapSort(int *A, int length)
{
	BuildMaxHeap(A, length);
	for (int i = length - 1; i >0; i--)
	{
		Swap(&A[i], &A[0]);
		MaxHeapify(A, i, 0);
	}
}
int main(int argc, char const *argv[])
{

	int arr[] = {5, 3, 17, 10, 84, 19, 6, 22, 9};
	int length = sizeof(arr) / sizeof(int);
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	HeapSort(arr, length);
	// BuildMaxHeap(arr, length);

	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}