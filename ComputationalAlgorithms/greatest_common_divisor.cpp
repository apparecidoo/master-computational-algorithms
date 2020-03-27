#include "pch.h"
#include "greatest_common_divisor.h"

GreatestCommonDivisor::GreatestCommonDivisor(int first, int second)
{
	if (first > second) {
		_major = first;
		_minor = second;
	}
	else {
		_major = second;
		_minor = first;
	}
}

GreatestCommonDivisor::~GreatestCommonDivisor()
{
}

int GreatestCommonDivisor::SolveRecursive(int major, int minor)
{
	if (minor == 0)
		return major;

	return SolveRecursive(minor, major % minor);
}

int GreatestCommonDivisor::Solve(bool recursive)
{
	int auxMajor = _major;
	int auxMinor = _minor;

	if (recursive) {
		return SolveRecursive(auxMajor, auxMinor);
	}
	else {
		int result = 1;

		while (result != 0)
		{
			result = auxMajor % auxMinor;
			auxMajor = auxMinor;
			auxMinor = result;
		}

		return auxMajor;
	}
}
