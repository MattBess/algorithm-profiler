#pragma once
#ifndef PALLINDROME_H
#define PALLINDROME_H
#include<string>

using namespace std;

class Pallindrome {
private:
	string reverseString(string str);
public:
	bool isPallindrome1(string str);
	bool isPallindrome2(string str);
	bool isPallindrome3(string str);

	class PallindromeDemo {
	public:
		void pallindromeDemo();
		void pallindromeDemo(int numFuncIterations);
	};
};

#endif // !PALLINDROME_H