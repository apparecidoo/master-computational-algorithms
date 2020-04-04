#include <random>

#ifndef RANDOM_H
#define RANDOM_H

using namespace std;

class Random {
public:
	static double generate(double intervalA, double intervalB);
	static float generate(float intervalA, float intervalB);
	static int generate(int intervalA, int intervalB);
	static void generate(int array[], int size, int intervalA, int intervalB);
	static void generate(double array[], int size, double intervalA, double intervalB);
	static void generate(float array[], int size, float intervalA, float intervalB);
};

#endif
