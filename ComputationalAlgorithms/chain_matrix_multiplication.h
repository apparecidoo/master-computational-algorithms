#include <iostream>
#include "matrix.h"
#include "helper.h"
#include "random.h"

#include <chrono>
#include <string>

#ifndef CHAIN_MATRIX_MULTIPLICATION_H
#define CHAIN_MATRIX_MULTIPLICATION_H

using namespace std;

class ChainMatrixMultiplication {
private:
	int* _vP; // vector of p's
	int** _mResult; // matrix resulting
	int** _mS; // matrix of k's
	int _numberMatrices;
	int _numberMatricesAdded;
	Matrix<int>** _matrices;

	void Initialize();
	int Minimize(int i, int j);
	string ReadResult(int i, int j, char &name);
	void AddFakeMatrix(int row, int col);

public:
	ChainMatrixMultiplication(int numberMatrices);
	void AddRandomMatrix(int row, int col);
	void AddMatrix(int** m, int row, int col);
	int Run(); // return the min value of multiplications
	void PrintResults();
	void Test();
};

#endif