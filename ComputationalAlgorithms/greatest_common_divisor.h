#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <chrono>
#include <random>
#include <iomanip>

#ifndef GREATEST_COMMON_DIVISOR_H
#define GREATEST_COMMON_DIVISOR_H

using namespace std;

class GreatestCommonDivisor {
private:
	double _major;
	double _minor;
	double SolveRecursive(double first, double second);

public:
	GreatestCommonDivisor(double first, double second);
	~GreatestCommonDivisor();

	int Solve(bool recursive = false);
	void Test();
};

#endif
