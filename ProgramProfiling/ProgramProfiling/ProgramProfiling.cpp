// ProgramProfiling.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main()
{
	srand(time(NULL));

	ArrayOperations::ArrayOperationsDemo arrayOperationsDemo;
	arrayOperationsDemo.arrayOperationsDemo(100);

	VectorShifter::VectorShifterDemo vectorShifterDemo;
	vectorShifterDemo.vectorShifterDemo(100);

	Pallindrome::PallindromeDemo pallindromeDemo;
	pallindromeDemo.pallindromeDemo(100);

	//TODO Implement demo functionality in CountingSort
	int A[20] = {};
	ArrayUtils::makeAsPositiveArray(A, 20);
	int B[20] = {};
	for (int i = 0; i < 20; i++) B[i] = 0;

	CountingSort cs;
	cs.countingSort(A, B, 100, 20);

	for (int i = 0; i < 20; i++) cout << B[i] << " ";

	char cont;
	cin >> cont;
    return 0;
}