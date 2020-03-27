#include <iostream>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>

#ifndef GREATEST_COMMON_DIVISOR_H
#define GREATEST_COMMON_DIVISOR_H

using namespace std;

class GreatestCommonDivisor {
private:
	int _major;
	int _minor;
	int SolveRecursive(int major, int minor);

public:
	GreatestCommonDivisor(int first, int second);
	~GreatestCommonDivisor();

	int Solve(bool recursive = false);
};

#endif
