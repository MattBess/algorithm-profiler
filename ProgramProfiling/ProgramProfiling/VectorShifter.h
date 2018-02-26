#ifndef VECTORSHIFTER_H
#define VECTORSHIFTER_H
#include<vector>

using namespace std;

class VectorShifter {
private:
	vector<int> vector;
public:
	VectorShifter();
	VectorShifter(int amt);
	void shiftLeft(int units);
	void shiftRight(int units);
	string asString();

	class VectorShifterDemo {
	public:
		void vectorShifterDemo();
		void vectorShifterDemo(int numFuncIterations);
	};
};

#endif