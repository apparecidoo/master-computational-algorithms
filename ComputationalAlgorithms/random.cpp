#include "pch.h"
#include "random.h"

double Random::generate(double intervalA, double intervalB)
{
	random_device rd;
	mt19937 eng(rd());
	uniform_real_distribution<double> randGcd(intervalA, intervalB);

	return randGcd(eng);
}

float Random::generate(float intervalA, float intervalB)
{
	random_device rd;
	mt19937 eng(rd());
	uniform_real_distribution<float> randGcd(intervalA, intervalB);

	return randGcd(eng);
}

int Random::generate(int intervalA, int intervalB)
{
	random_device rd;
	mt19937 eng(rd());
	uniform_real_distribution<float> randGcd(intervalA, intervalB);

	return (int)randGcd(eng);
}

void Random::generate(int array[], int size, int intervalA, int intervalB)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = (int)generate(intervalA, intervalB);
	}
}

void Random::generate(double array[], int size, double intervalA, double intervalB)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = generate(intervalA, intervalB);
	}
}

void Random::generate(float array[], int size, float intervalA, float intervalB)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = generate(intervalA, intervalB);
	}
}
