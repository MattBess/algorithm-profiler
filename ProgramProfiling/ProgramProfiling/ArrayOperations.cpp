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