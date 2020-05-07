#include "pch.h"
#include "chain_matrix_multiplication.h"

void ChainMatrixMultiplication::Initialize()
{
	_numberMatricesAdded = 0;
	_matrices = new Matrix<int>*[_numberMatrices];
	_mS = Helper<int>().CreateMatrix(_numberMatrices, _numberMatrices);
	_mResult = Helper<int>().CreateMatrix(_numberMatrices, _numberMatrices);
	_vP = new int[_numberMatrices];
}

void ChainMatrixMultiplication::Minimize(int i, int j)
{

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
		_matrices[_numberMatricesAdded] = new Matrix<int>(m, row, col);
		_numberMatricesAdded++;
	}
}

void ChainMatrixMultiplication::AddMatrix(int ** m, int row, int col)
{
	if (_numberMatricesAdded != _numberMatrices) {
		_matrices[_numberMatricesAdded] = new Matrix<int>(m, row, col);
		_numberMatricesAdded++;
	}
}

void ChainMatrixMultiplication::GetSolution()
{
	if (_numberMatricesAdded != _numberMatrices) {
		throw exception(_numberMatrices - _numberMatricesAdded + " matrices are missing");
	}
	else {
		Minimize(0, _numberMatrices - 1);
	}
}

void ChainMatrixMultiplication::Test()
{
	_numberMatrices = 3;
	Initialize();

	AddRandomMatrix(2, 2);
	AddRandomMatrix(2, 2);
	AddRandomMatrix(2, 2);
	
	GetSolution();
}
