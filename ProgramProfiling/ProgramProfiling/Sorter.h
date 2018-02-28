#pragma once
#ifndef SORTER_H
#define SORTER_H

using namespace std;

//Used for demoing different kinds of sorting algorithms
class Sorter{
private:
	//Returns a pivot-point for quick-sort algorithm
	int medianOfThree(int A[], int left, int right);
	void swap(int A[], int left, int right);
public:
	void insertionSort(int A[], int size);
	void quickSort(int A[], int low, int high);

	class SorterDemo {
	public:
		void sorterDemo();
		void sorterDemo(int numFuncIterations);
	};
};

#endif // !SORTER_H