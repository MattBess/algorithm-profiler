#include "stdafx.h"
#include "CountingSort.h"

void CountingSort::CountingSortDemo::countingSortDemo()
{
}

void CountingSort::CountingSortDemo::countingSortDemo(int numFuncIterations)
{
}

/**
@param A -> unsorted array
@param sortedArray -> where the sorted array will be held in this algorithm
@param k -> the largest value that occurs in the array
@param size -> the size of input-array A[]
*/
void CountingSort::countingSort(int A[], int sortedArray[], int k, int size)
{
	//This array provides temporary working storage
	int *C = new int[k];
	for (int i = 0; i < k; i++) {
		C[i] = 0;
	}

	//Counting the # of elements equal to eachother in A
	for (int i = 0; i < size; i++) {
		C[A[i]] = C[A[i]] + 1;
	}
	//C[i] now contains the number of elements equal to i

	//Count the # of elements less than or equal to i
	for (int i = 1; i < k; i++) {
		C[i] = C[i] + C[i - 1];
	}
	//C[i] now contains the # of elements <= to i

	//This is where the sorting happens
	for (int i = size-1; i >= 0; i--) {
		//Find the # of elements <= to value at index A[i]
		sortedArray[C[A[i]]] = A[i];
		//Decrement the # of elements <= to value at index A[i} because it's been added to sorted array
		C[A[i]] = C[A[i]] - 1;
	}

	delete[] C;
}
