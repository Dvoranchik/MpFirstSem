#pragma once
#include "stdafx.h"
#include "Fun.h"

Matrix::Matrix(int str, int colom)
{
	this->colom = colom;
	this->str = str;
	_matrix = new int*[str];

	for (int i = 0; i < str; i++)
		_matrix[i] = new int[colom] {};
}

Matrix::Matrix(Matrix &matrix)
{
	this->colom = matrix.colom;
	this->str = matrix.str;

this->_matrix = new int*[matrix.str];

for (int i = 0; i < matrix.str; i++)
{
	this->_matrix[i] = new int[matrix.colom]{};

	for (int j = 0; j < matrix.colom; ++j)
		this->_matrix[i][j] = matrix._matrix[i][j];
}
}

Matrix::~Matrix()
{
	for (int i = 0; i < str; ++i)
	{
		delete[] this->_matrix[i];
	}
	delete[] _matrix;
}

const Matrix& Matrix::operator= (const Matrix &right)
{
	if (this == &right)
		return *this;
	for (int i = 0; i < str; ++i)
		delete[] this->_matrix[i];
	delete[] _matrix;

	this->_matrix = new int*[right.str];

	for (int i = 0; i < right.str; i++)
	{
		this->_matrix[i] = new int[right.colom]{};
		std::memcpy(_matrix[i], right._matrix[i], sizeof(int)*colom);
	}
	return *this;
}
int* Matrix::operator[](int index) const
{
	if (index < 0 || index >= this->str)
		throw std::runtime_error("Bad index");

	return this->_matrix[index];
}

Matrix Matrix::operator+(Matrix &right)
{
	if (this->colom != right.colom || this->str != right.str)
		throw std::runtime_error("Bad index");
	Matrix result(right.str, right.colom);

	for (int i = 0; i < this->str; ++i)
		for (int j = 0; j < this->colom; ++j)
			result._matrix[i][j] = this->_matrix[i][j] + right._matrix[i][j];

	return result;
}

bool operator== (Matrix &left, Matrix &right)
{
	if (left.colom != right.colom || left.str != right.str)
		return false;

	for (int i = 0; i < left.str; ++i)
		for (int j = 0; j < left.str; ++j)
			if (left[i][j] != right[i][j])
				return false;
	return true;
}

Matrix operator*(Matrix &left, Matrix &right)
{
	if (left.colom != right.str)
		throw std::runtime_error("Bad index");

	Matrix result(left.str, right.colom);
	int buffer = 0;

	for (int i = 0; i < left.str; ++i)
		for (int k = 0; k < right.colom; ++k)
		{
			for (int j = 0; j < right.str; ++j)
				result[i][k] += left[i][j] * right[j][k];
		}
	return result;
}

bool Matrix::setMatrix(const char *fileName)
{

	std::ifstream inpFile(fileName);
	if (!inpFile)
		return false;

	for (int i = 0; i < this->str; ++i)
		for (int j = 0; j < this->colom; ++j)
			if (!(inpFile >> this->_matrix[i][j]))
			throw std::runtime_error("Bad Matrix");
			
	return true;
}