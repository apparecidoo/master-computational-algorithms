#include "pch.h"
#include "chain_matrix_multiplication.h"

void ChainMatrixMultiplication::Initialize()
{
	_numberMatricesAdded = 0;
	_matrices = new Matrix<int>*[_numberMatrices + 1];
	_mS = Helper<int>().CreateMatrix(_numberMatrices + 1, _numberMatrices + 1);
	_mResult = Helper<int>().CreateMatrix(_numberMatrices + 1, _numberMatrices + 1);
	_vP = new int[_numberMatrices + 1];
}

int ChainMatrixMultiplication::Minimize(int i, int j)
{
	int minVal = INT_MAX;
	int minIndexK = i;

	if (i == j) {
		return 0;
	}

	if (_mResult[i][j] != NULL) {
		return _mResult[i][j];
	}
	
	for (int k = i; k < j; k++)
	{
		int minValK = Minimize(i, k) + Minimize(k + 1, j) + (_vP[i - 1] * _vP[k] * _vP[j]);
		if (minValK < minVal) {
			minVal = minValK;
			minIndexK = k;
		}
	}

	_mResult[i][j] = minVal;
	_mS[i][j] = minIndexK;

	return minVal;
}

void ChainMatrixMultiplication::PrintResults()
{
	cout << "=== Matrices ===" << endl;
	for (int i = 1; i <= _numberMatrices; i++)
	{
		cout << "Matrix[" << i << "] = " << _matrices[i]->row << "x" << _matrices[i]->col << endl;
	}

	cout << endl << "=== Vector of P's ===" << endl;
	cout << "V = ";
	for (int i = 0; i <= _numberMatrices; i++)
	{
		cout << _vP[i] << "\t\t";
	}

	cout << endl << endl << "=== Matrix of Min Values ===" << endl;
	Helper<int>().PrintMatrix(_mResult, _numberMatrices + 1, _numberMatrices + 1);

	cout << "=== Matrix of Min K's ===" << endl;
	Helper<int>().PrintMatrix(_mS, _numberMatrices + 1, _numberMatrices + 1);

	cout << "=== Min Value ===" << endl;
	cout << "Value: " << _mResult[1][_numberMatrices] << endl;

	cout << endl << "=== Sequence Result ===" << endl;
	char name = 'A';
	cout << ReadResult(1, _numberMatrices, name) << endl << endl;
}

// The code of printing was retired from https://www.geeksforgeeks.org/printing-brackets-matrix-chain-multiplication-problem/ and adapted
string ChainMatrixMultiplication::ReadResult(int i, int j, char &name)
{
	string result = "";
	int n = _numberMatrices;
	int bracket = _mS[i][j];

	if (i == j)
	{
		result += name++;
		return result;
	}

	result += "(";

	result += ReadResult(i, bracket, name);
	result += ReadResult(bracket + 1, j, name);

	result += ")";

	return result;
}

ChainMatrixMultiplication::ChainMatrixMultiplication(int numberMatrices)
{
	_numberMatrices = numberMatrices;
	Initialize();
}

void ChainMatrixMultiplication::AddRandomMatrix(int row, int col)
{
	int** m = Helper<int>().CreateMatrix(row, col, true);

	if (_numberMatricesAdded != _numberMatrices) {
		_matrices[_numberMatricesAdded + 1] = new Matrix<int>(m, row, col);
		_numberMatricesAdded++;
	}
}

void ChainMatrixMultiplication::AddMatrix(int ** m, int row, int col)
{
	if (_numberMatricesAdded != _numberMatrices) {
		_matrices[_numberMatricesAdded + 1] = new Matrix<int>(m, row, col);
		_numberMatricesAdded++;
	}
}

void ChainMatrixMultiplication::GetSolution()
{
	if (_numberMatricesAdded != _numberMatrices) {
		throw exception(_numberMatrices - _numberMatricesAdded + " matrices are missing");
	}

	// filling vector of p's
	for (int i = 1; i <= _numberMatrices; i++)
	{
		_vP[i - 1] = _matrices[i]->row;
	}
	_vP[_numberMatrices] = _matrices[_numberMatrices]->col;

	Minimize(1, _numberMatrices);

	PrintResults();
}

void ChainMatrixMultiplication::Test()
{
	_numberMatrices = 6;
	Initialize();

	AddRandomMatrix(30, 35);
	AddRandomMatrix(35, 15);
	AddRandomMatrix(15, 5);
	AddRandomMatrix(5, 10);
	AddRandomMatrix(10, 20);
	AddRandomMatrix(20, 25);

	GetSolution();
}
