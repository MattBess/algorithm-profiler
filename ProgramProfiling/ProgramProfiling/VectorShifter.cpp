#pragma once
#include"VectorShifter.h"
#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

VectorShifter::VectorShifter()
{
	for (int i = 0; i < 10; i++) {
		this->vector.push_back(i);
	}
}

VectorShifter::VectorShifter(int amt)
{
	if (amt <= 0) amt = 10;

	for (int i = 0; i < amt; i++) {
		this->vector.push_back(i);
	}
}

void VectorShifter::shiftLeft(int units)
{
	if (units <= this->vector.size()) {
		std::reverse(this->vector.begin(), this->vector.begin() + units);
		std::reverse(this->vector.begin() + units, this->vector.end());
		std::reverse(this->vector.begin(), this->vector.end());
	}
		
}

void VectorShifter::shiftRight(int units)
{
	if (units <= this->vector.size()) {
		std::reverse(this->vector.end()- units, this->vector.end());
		std::reverse(this->vector.begin(), this->vector.end() - units);
		std::reverse(this->vector.begin(), this->vector.end());
	}
}

string VectorShifter::asString()
{
	string printedVector = "";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++) {
		printedVector += to_string(*it) + " ";
	}
	
	return printedVector;
}

void VectorShifter::VectorShifterDemo::vectorShifterDemo()
{
	return vectorShifterDemo(1);
}

void VectorShifter::VectorShifterDemo::vectorShifterDemo(int numFuncIterations)
{
	FunctionTimer funcTimer;
	double execTime;

	cout << "\n\n\n________________________________________\n\n\n";
	cout << "~~~\tVector Operations\t~~~" << endl << endl;
	cout << "Normal Vector: ";

	VectorShifter vectorShifter(10);
	cout << vectorShifter.asString() << endl;

	execTime = 0.0;
	cout << endl << "Right Shift: " << endl;
	execTime = funcTimer.getExecutionTime(bind(&VectorShifter::shiftRight, &vectorShifter, 3), numFuncIterations);
	cout << "\tTime: " << execTime << " seconds" << endl;
	cout << "\tIterations: " << numFuncIterations << endl;
	cout << "\tNew Vector: " << vectorShifter.asString() << endl;

	execTime = 0.0;
	cout << endl << "Left Shift: " << endl;
	execTime = funcTimer.getExecutionTime(bind(&VectorShifter::shiftLeft, &vectorShifter, 3), numFuncIterations);
	cout << "\tTime: " << execTime << " seconds" << endl;
	cout << "\tIterations: " << numFuncIterations << endl;
	cout << "\tNew Vector: " << vectorShifter.asString() << endl;

	cout << "\n\n\n________________________________________\n\n\n";
}
