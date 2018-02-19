#pragma once
#ifndef FUNCTIONTIMER_H
#define FUNCTIONTIMER_H
#include <ctime>

using namespace std;

class FunctionTimer {
private:
	clock_t start;
	
	void startTimer();
	double getTimerDuration();
public:
	double getExecutionTime(function<void()> func);
	double getExecutionTime(function<void()> func, int iterations);
};

#endif
