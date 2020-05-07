#include "random.h"

#ifndef HELPER_H
#define HELPER_H

using namespace std;

template <class T>
class Helper {
public:
	static void Copy(T from[], T to[], int size);
	static T** MatrixMultiplication(T** m1, T** m2, int m1_row, int m1_col, int m2_row, int m2_col);
	static T** CreateMatrix(int row, int col, bool randomValues = false);
};

template<class T>
inline void Helper<T>::Copy(T from[], T to[], int size)
{
	for (int i = 0; i < size; i++)
	{
		to[i] = from[i];
	}
}

template<class T>
inline T** Helper<T>::MatrixMultiplication(T** m1, T** m2, int m1_row, int m1_col, int m2_row, int m2_col)
{
	cout << "Row: " << m1_row << " - Col: " << m1_col << endl;
	cout << "Row: " << m2_row << " - Col: " << m2_col << endl;
	cout << "Result " << m1_row << "x" << m2_col << endl;
	T** mResult = CreateMatrix(m1_row, m2_col);

	for (int i = 0; i < m1_row; i++) {
		for (int j = 0; j < m1_row; j++) {
			for (int k = 0; k < m1_col; k++) {
				mResult[i][j] += (m1[i][k] * m2[k][j]);
			}
		}
	}

	return mResult;
}

template<class T>
inline T** Helper<T>::CreateMatrix(int row, int col, bool randomValues)
{
	T** matrix = new T*[row];
	
	for (int i = 0; i < row; i++)
	{
		matrix[row] = new T[col];

		for (int j = 0; j < col; j++)
		{
			matrix[row][col] = randomValues ? (T)Random().generate(1, 1000) : NULL;
		}
	}

	return matrix;
}

#endif