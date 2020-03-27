#include "pch.h"
#include <iostream>
#include "greatest_common_divisor.h"

int main()
{
	GreatestCommonDivisor test = GreatestCommonDivisor(32, 16);
	cout << "Result: " << test.Solve() << endl;
	cout << "Result Recursive: " << test.Solve(true) << endl;

	system("pause");
}