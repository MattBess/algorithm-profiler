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