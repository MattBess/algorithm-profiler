#include "stdafx.h"
#include "ArrayUtils.h"

void ArrayUtils::printArray(int A[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}

void ArrayUtils::makeAsPositiveArray(int A[], int size)
{
	for (int i = 0; i < size; i++) {
		A[i] = rand() % 100;
	}
}

void ArrayUtils::makeAsMixedArray(int A[], int size)
{
	for (int i = 0; i < size; i++) {
		bool isNegative = rand() % 2;
		if (isNegative) {
			A[i] = -(rand() % 100);
		}
		else {
			A[i] = rand() % 100;
		}
	}
}

void ArrayUtils::makeAsNegativeArray(int A[], int size)
{
	for (int i = 0; i < size; i++) {
		A[i] = -(rand() % 100);
	}
}
