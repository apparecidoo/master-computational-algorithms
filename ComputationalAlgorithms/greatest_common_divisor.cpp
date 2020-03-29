#include "pch.h"
#include "greatest_common_divisor.h"

GreatestCommonDivisor::GreatestCommonDivisor(double first, double second)
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

double GreatestCommonDivisor::SolveRecursive(double major, double minor)
{
	if (minor == 0)
		return major;

	return SolveRecursive(minor, std::fmod(major,minor));
}

double GreatestCommonDivisor::SolveIterative(double major, double minor)
{
	double result = 1;

	while (result != 0)
	{
		result = std::fmod(major, minor);
		major = minor;
		minor = result;
	}

	return major;
}

int GreatestCommonDivisor::Solve(bool recursive)
{
	double auxMajor = _major;
	double auxMinor = _minor;

	if (recursive) {
		return SolveRecursive(auxMajor, auxMinor);
	}
	else {
		return SolveIterative(auxMajor, auxMinor);
	}
}

void GreatestCommonDivisor::Test()
{
	int i = 0;
	std::chrono::time_point<chrono::steady_clock> tStart;
	random_device rd;
	mt19937 eng(rd());
	uniform_real_distribution<double> randGcd(1000, 99999999);
	cout.setf(ios::fixed);

	while (i < 20)
	{
		double firstNumber = (int)randGcd(eng);
		double secondNumber = (int)randGcd(eng);
		GreatestCommonDivisor test = GreatestCommonDivisor(firstNumber, secondNumber);
		cout << "Numbers: (" << setprecision(0) << firstNumber << ", " << secondNumber << ")" << endl;
		tStart = std::chrono::high_resolution_clock::now();
		double solve = test.Solve();
		cout << "Result: " << setprecision(0) << solve << " | TimeExecution: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - tStart).count() << " microseconds" << endl;

		tStart = std::chrono::high_resolution_clock::now();
		double solveRecursive = test.Solve(true);
		cout << "Result Recursive: " << setprecision(0) << solveRecursive << " | TimeExecution: " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - tStart).count() << " microseconds" << endl << endl;

		i++;
	}
}
