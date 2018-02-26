#include "stdafx.h"
#include "ArrayOperations.h"
#include <cmath>

using namespace std;


tuple<int, int, int> ArrayOperations::findMaxSubArray(int A[], int low, int high)
{
	return MaxSubArray::findMaxSubArray(A, low, high);
}

tuple<int, int, int> ArrayOperations::MaxSubArray::findMaxSubArray(int A[], int low, int high)
{
	if (low == high) {
		//base case: only one element in array
		return SubArrayData(low, high, A[low]);
	}

	else {
		int mid = floor((low + high) / 2);

		int leftLow, leftHigh, leftSum;
		SubArrayData leftTuple = findMaxSubArray(A, low, mid);
		tie(leftLow, leftHigh, leftSum) = leftTuple;

		int rightLow, rightHigh, rightSum;
		SubArrayData rightTuple = findMaxSubArray(A, mid + 1, high);
		tie(rightLow, rightHigh, rightSum) = rightTuple;

		int crossLow, crossHigh, crossSum;
		SubArrayData crossTuple = findMaxCrossingSubArray(A, low, mid, high);
		tie(crossLow, crossHigh, crossSum) = crossTuple;

		if (leftSum >= rightSum && leftSum >= crossSum) {
			return leftTuple;
		}
		else if (rightSum >= leftSum && rightSum >= crossSum) {
			return rightTuple;
		}
		else {
			return crossTuple;
		}
	}
}

tuple<int, int, int> ArrayOperations::MaxSubArray::findMaxCrossingSubArray(int A[], int low, int mid, int high)
{
	//sum left side
	int leftSum = -INFINITY;
	int leftMax = -1;
	int sum = 0;
	for (int i = mid; i >= low; i--) {
		sum += A[i];
		if (sum > leftSum) {
			leftSum = sum;
			leftMax = i;
		}
	}

	//sum right side
	int rightSum = -INFINITY;
	int rightMax = -1;
	sum = 0;
	for (int i = mid + 1; i < high; i++) {
		sum += A[i];
		if (sum > rightSum) {
			rightSum = sum;
			rightMax = i;
		}
	}

	return SubArrayData(leftMax, rightMax, leftSum + rightSum);
}

void ArrayOperations::ArrayOperationsDemo::arrayOperationsDemo()
{
	return arrayOperationsDemo(1);
}

void ArrayOperations::ArrayOperationsDemo::arrayOperationsDemo(int numFuncIterations)
{
	const int ARRAY_SIZE = 10;
	int A[ARRAY_SIZE] = {};
	ArrayUtils::makeAsMixedArray(A, ARRAY_SIZE);

	cout << "________________________________________\n\n\n";
	cout << "~~~\tMaximum Subarray\t~~~" << endl << endl;
	cout << "Finding maximum subarray for " << ARRAY_SIZE << " element(s):\n";
	cout << "Elements: ";
	ArrayUtils::printArray(A, ARRAY_SIZE);

	ArrayOperations arrayOperations;
	tuple<int, int, int> maxSubArray = arrayOperations.findMaxSubArray(A, 0, ARRAY_SIZE);

	//Timer for algorithm for n iterations
	clock_t start = clock();

	for (int i = 0; i < numFuncIterations; i++) {
		arrayOperations.findMaxSubArray(A, 0, ARRAY_SIZE);
	}

	//The number of iterations to put each function through
	double execTime;
	execTime = (clock() - start) / (double)CLOCKS_PER_SEC;


	cout << "|Time:\t" << execTime << "s\t|" << endl;
	cout << "|Low:\t" << get<0>(maxSubArray) << "\t|" << endl;
	cout << "|High:\t" << get<1>(maxSubArray) << "\t|" << endl;
	cout << "|Sum:\t" << get<2>(maxSubArray) << "\t|" << endl;

	cout << "\n\n\n________________________________________\n\n\n";
}
