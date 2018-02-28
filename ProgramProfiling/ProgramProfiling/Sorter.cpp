#include"Sorter.h"
#include"stdafx.h"

using namespace std;

void Sorter::quickSort(int A[], int low, int high)
{
	if (low < high) {
		int pivot = medianOfThree(A, low, high);
		quickSort(A, low, pivot - 1);
		quickSort(A, pivot + 1, high);
	}
}

int Sorter::medianOfThree(int A[], int left, int right)
{
	int mid = (left + right) / 2;
	
	//Sorting the 3 elements at specified indexs (Used as pivot points)
	if (A[right] > A[left]) swap(A, left, right);
	if (A[mid] < A[left]) swap(A, mid, left);
	if (A[right] < A[mid]) swap(A, right, mid);

	int i = left - 1;
	for (int j = left; j < right - 1; j++) {
		if (A[i] < mid) {
			swap(A, A[i], A[j]);
		}
	}

	swap(A, A[i], A[right]);

	return mid + 1;
}

void Sorter::swap(int A[], int left, int right)
{
	int temp = A[left];
	A[left] = A[right];
	A[right] = temp;
}

void Sorter::insertionSort(int A[], int size)
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

void Sorter::SorterDemo::sorterDemo()
{
	sorterDemo(1);
}

void Sorter::SorterDemo::sorterDemo(int numFuncIterations)
{
}
