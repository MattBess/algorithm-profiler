#include"InsertionSort.h"
#include"stdafx.h"

void InsertionSort::insertionSort(int A[], int size)
{
	for (int i = 1; i < size; i++) {
		int curr = A[i];

		int j = i - 1;
		while (j >= 0 && (A[j] > curr)) {
			A[j + 1] = A[j];
			A[j] = curr;
			j--;
		}
	}
}

void InsertionSort::InsertionSortDemo::insertionSortDemo()
{
	insertionSortDemo(1);
}

void InsertionSort::InsertionSortDemo::insertionSortDemo(int numFuncIterations)
{
}
