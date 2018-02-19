#include"stdafx.h"
#include "FunctionTimer.h"

using namespace std;

double FunctionTimer::getExecutionTime(function<void()> func)
{
	startTimer();

	func();

	return getTimerDuration();
}

double FunctionTimer::getExecutionTime(function<void()> func, int iterations)
{
	startTimer();

	for (int i = 0; i < iterations; i++) func();

	return getTimerDuration();
}

void FunctionTimer::startTimer()
{
	start = clock();
}

double FunctionTimer::getTimerDuration()
{
	clock_t stop = clock();
	double duration = (stop - start) / (double)CLOCKS_PER_SEC;
	return duration;
}