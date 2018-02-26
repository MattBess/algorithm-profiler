#include "Pallindrome.h"
#include "stdafx.h"

string Pallindrome::reverseString(string str)
{
	string reversedStr = "";
	for (string::reverse_iterator it = str.rbegin(); it != str.rend(); ++it) {
		reversedStr += *it;
	}

	return reversedStr;
}

//This reverses the string and compares each character in the two strings
bool Pallindrome::isPallindrome1(string str)
{
	string reversedStr = reverseString(str);

	int len = str.length();
	for (int i = 0; i < len; i++) {
		char x = str.at(i);
		char y = reversedStr.at(i);

		if (x != y) return false;
	}

	return true;
}

//It compares each opposite corresponding element in the string by indexing
//the element at that spot.
bool Pallindrome::isPallindrome2(string str)
{
	int mid = str.size() / 2;

	for (int i = 0; i < mid; i++) {
		if (str.substr(i, 1) != str.substr(str.size() - i - 1, 1)) {
			return false;
		}
	}

	return true;
}

//The fastest of the 3 algorithms (so far)
//It compares each opposite corresponding element in the string by using
//an iterator rather than indexing each element
bool Pallindrome::isPallindrome3(string str)
{
	int mid = str.size() / 2;

	string::iterator end = str.end() - 1;

	for (string::iterator it = str.begin(); it <= end; it++) {
		if (*it != *end) return false;
		else end--;
	}

	return true;
}

void Pallindrome::PallindromeDemo::pallindromeDemo()
{
	return pallindromeDemo(1);
}

void Pallindrome::PallindromeDemo::pallindromeDemo(int numFuncIterations)
{
	FunctionTimer funcTimer;
	double execTime;

	//Pallindrome operations
	Pallindrome pallindrome;
	bool isPallindrome;

	cout << "\n\n\n________________________________________\n\n\n";
	cout << "~~~\tPallindrome Operations\t~~~" << endl << endl;
	
	//String 1
	string str1 = "madam";
	cout << "Word: " << str1 << endl;
	cout << "Function 1 -" << endl;

	isPallindrome = pallindrome.isPallindrome1(str1);
	execTime = funcTimer.getExecutionTime(bind(&Pallindrome::isPallindrome1, &pallindrome, str1), numFuncIterations);
	
	cout << "\t| Pallindrome: " << isPallindrome << "\t|" << endl;
	cout << "\t| Time: " << execTime << " seconds" << "\t|" << endl;
	cout << "\t| Iterations: " << numFuncIterations << "\t|" << endl;

	cout << "Function 2 -" << endl;
	isPallindrome = pallindrome.isPallindrome2(str1);
	execTime = funcTimer.getExecutionTime(bind(&Pallindrome::isPallindrome2, &pallindrome, str1), numFuncIterations);
	cout << "\t| Pallindrome: " << isPallindrome << "\t|" << endl;
	cout << "\t| Time: " << execTime << " seconds" << "\t|" << endl;
	cout << "\t| Iterations: " << numFuncIterations << "\t|" << endl;

	cout << "Function 3 -" << endl;
	isPallindrome = pallindrome.isPallindrome3(str1);
	execTime = funcTimer.getExecutionTime(bind(&Pallindrome::isPallindrome3, &pallindrome, str1), numFuncIterations);
	cout << "\t| Pallindrome: " << isPallindrome << "\t|" << endl;
	cout << "\t| Time: " << execTime << " seconds" << "\t|" << endl;
	cout << "\t| Iterations: " << numFuncIterations << "\t|" << endl << endl << endl;
	//End String 1



	//String 2
	string str2 = "darn";
	cout << "Word: " << str2 << endl;
	cout << "Function 1 -" << endl;
	isPallindrome = pallindrome.isPallindrome1(str2);
	execTime = funcTimer.getExecutionTime(bind(&Pallindrome::isPallindrome1, &pallindrome, str2), numFuncIterations);
	cout << "\t| Pallindrome: " << isPallindrome << "\t|" << endl;
	cout << "\t| Time: " << execTime << " seconds" << "\t|" << endl;
	cout << "\t| Iterations: " << numFuncIterations << "\t|" << endl;

	cout << "Function 2 -" << endl;
	isPallindrome = pallindrome.isPallindrome2(str2);
	execTime = funcTimer.getExecutionTime(bind(&Pallindrome::isPallindrome2, &pallindrome, str2), numFuncIterations);
	cout << "\t| Pallindrome: " << isPallindrome << "\t|" << endl;
	cout << "\t| Time: " << execTime << " seconds" << "\t|" << endl;
	cout << "\t| Iterations: " << numFuncIterations << "\t|" << endl;

	cout << "Function 3 -" << endl;
	isPallindrome = pallindrome.isPallindrome3(str2);
	execTime = funcTimer.getExecutionTime(bind(&Pallindrome::isPallindrome3, &pallindrome, str2), numFuncIterations);
	cout << "\t| Pallindrome: " << isPallindrome << "\t|" << endl;
	cout << "\t| Time: " << execTime << " seconds" << "\t|" << endl;
	cout << "\t| Iterations: " << numFuncIterations << "\t|" << endl;
	//End String 2

	//End pallindrome operations

	cout << "\n\n\n________________________________________\n\n\n";
}
