#include "random.h"

#ifndef MATRIX_H
#define MATRIX_H

using namespace std;

template <class T>
class Matrix {
public:
	T** content;
	int row;
	int col;

	Matrix(T** content, int row, int col);
	Matrix();
};

template<class T>
inline Matrix<T>::Matrix(T ** content, int row, int col)
{
	this->content = content;
	this->row = row;
	this->col = col;
}

template<class T>
inline Matrix<T>::Matrix()
{
	this->content = NULL;
	this->row = 0;
	this->col = 0;
}

#endif