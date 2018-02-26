#pragma once
#ifndef ARRAYOPERATIONS_H
#define ARRAYOPERATIONS_H
#include"ArrayUtils.h"

using namespace std;

//Performs various algorithms on arrays (sorts, searches, max sub-array, etc..)
class ArrayOperations {
private:

	class MaxSubArray {
	typedef tuple<int, int, int> SubArrayData;
	private:
		static tuple<int, int, int> findMaxCrossingSubArray(int A[], int low, int mid, int high);
	public:
		static tuple<int, int, int> findMaxSubArray(int A[], int low, int high);
	};

public:
	tuple<int, int, int> findMaxSubArray(int A[], int low, int high);

	//Demo for ArrayOperations
	class ArrayOperationsDemo {
	public:
		void arrayOperationsDemo();
		void arrayOperationsDemo(int numFuncIterations);
	};
};

#endif // !ARRAYOPERATIONS_H
