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
