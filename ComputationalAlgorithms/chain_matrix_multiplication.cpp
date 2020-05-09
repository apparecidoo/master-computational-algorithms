#include "pch.h"
#include "chain_matrix_multiplication.h"

void ChainMatrixMultiplication::Initialize()
{
	_numberMatricesAdded = 0;
	_matrices = new Matrix<long long int>*[_numberMatrices + 1];
	_mS = Helper<long long int>().CreateMatrix(_numberMatrices + 1, _numberMatrices + 1);
	_mResult = Helper<long long int>().CreateMatrix(_numberMatrices + 1, _numberMatrices + 1);
	_vP = new long long int[_numberMatrices + 1];
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

void ChainMatrixMultiplication::AddFakeMatrix(int row, int col)
{
	if (_numberMatricesAdded != _numberMatrices) {
		_matrices[_numberMatricesAdded + 1] = new Matrix<long long int>(NULL, row, col);
		_numberMatricesAdded++;
	}
}

ChainMatrixMultiplication::ChainMatrixMultiplication(int numberMatrices)
{
	_numberMatrices = numberMatrices;
	Initialize();
}

void ChainMatrixMultiplication::AddRandomMatrix(int row, int col)
{
	long long int** m = Helper<long long int>().CreateMatrix(row, col, true);

	if (_numberMatricesAdded != _numberMatrices) {
		_matrices[_numberMatricesAdded + 1] = new Matrix<long long int>(m, row, col);
		_numberMatricesAdded++;
	}
}

void ChainMatrixMultiplication::AddMatrix(long long int ** m, int row, int col)
{
	if (_numberMatricesAdded != _numberMatrices) {
		_matrices[_numberMatricesAdded + 1] = new Matrix<long long int>(m, row, col);
		_numberMatricesAdded++;
	}
}

int ChainMatrixMultiplication::Run()
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

	return Minimize(1, _numberMatrices);
}

void ChainMatrixMultiplication::PrintResults()
{
	cout << "=== Matrices ===" << endl;
	char name = 'A';
	for (int i = 1; i <= _numberMatrices; i++)
	{
		cout << "Matrix " << name << " = " << _matrices[i]->row << "x" << _matrices[i]->col << endl;
		name++;
	}

	cout << endl << "=== Vector of P's ===" << endl;
	cout << "V = ";
	for (int i = 0; i <= _numberMatrices; i++)
	{
		cout << _vP[i] << "\t\t";
	}

	cout << endl << endl << "=== Matrix of Min Values ===" << endl;
	Helper<long long int>().PrintMatrix(_mResult, _numberMatrices + 1, _numberMatrices + 1);

	cout << "=== Matrix of Min K's ===" << endl;
	Helper<long long int>().PrintMatrix(_mS, _numberMatrices + 1, _numberMatrices + 1);

	cout << "=== Min Value ===" << endl;
	cout << "Value: " << _mResult[1][_numberMatrices] << endl;

	cout << endl << "=== Sequence Result ===" << endl;
	name = 'A';
	cout << ReadResult(1, _numberMatrices, name) << endl << endl;
}

void ChainMatrixMultiplication::Test()
{
	cout << "=== Class Example ===" << endl;
	_numberMatrices = 6;
	Initialize();

	AddFakeMatrix(30, 35);
	AddFakeMatrix(35, 15);
	AddFakeMatrix(15, 5);
	AddFakeMatrix(5, 10);
	AddFakeMatrix(10, 20);
	AddFakeMatrix(20, 25);

	Run();
	PrintResults();

	cout << "=== Examples ===" << endl;
	int tests = 5;
	_numberMatrices = 10;

	for (int i = 0; i < tests; i++)
	{
		Initialize();
	
		int lastSizeRow = Random().generate(100, 1000);
		int lastSizeCol = Random().generate(100, 1000);
		AddFakeMatrix(lastSizeRow, lastSizeCol);

		for (int j = 0; j < _numberMatrices - 1; j++)
		{
			lastSizeRow = lastSizeCol;
			lastSizeCol = Random().generate(100, 1000);
			AddFakeMatrix(lastSizeRow, lastSizeCol);
		}

		Run();
		PrintResults();
	}

	cout << "=== Stress Examples ===" << endl;
	tests = 20;

	for (int i = 0; i < tests; i++)
	{
		int variation = (100 * i);
		_numberMatrices = 10 + variation;
		Initialize();

		int lastSizeRow = Random().generate(100 + variation, 1000 + variation);
		int lastSizeCol = Random().generate(100 + variation, 1000 + variation);
		AddFakeMatrix(lastSizeRow, lastSizeCol);

		for (int j = 0; j < _numberMatrices - 1; j++)
		{
			lastSizeRow = lastSizeCol;
			lastSizeCol = Random().generate(100 + variation, 1000 + variation);
			AddFakeMatrix(lastSizeRow, lastSizeCol);
		}

		std::chrono::time_point<chrono::steady_clock> tStart = std::chrono::high_resolution_clock::now();
		Run();
		cout << i << " - " << _numberMatrices << " - " << std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - tStart).count() << endl;
	}
}
