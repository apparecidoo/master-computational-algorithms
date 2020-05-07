#include "pch.h"
#include <iostream>
#include <chrono>
#include <iomanip>
#include "random.h"
#include "greatest_common_divisor.h"
#include "sort.h"
#include "graph.h"
#include "chain_matrix_multiplication.h"

using namespace std;

int main()
{
	ChainMatrixMultiplication* cmm = new ChainMatrixMultiplication(0);
	cmm->Test();

	system("pause");
}