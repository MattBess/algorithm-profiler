#pragma once
#ifndef ARRAYUTILS_H
#define ARRAYUTILS_H

using namespace std;

class ArrayUtils {
public:
	static void printArray(int A[], int size);
	static void makeAsPositiveArray(int A[], int size);
	static void makeAsMixedArray(int A[], int size);
	static void makeAsNegativeArray(int A[], int size);
};

#endif