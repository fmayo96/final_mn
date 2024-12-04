#pragma once

#include <vector>
#include <iostream>
#include <complex>

class Matrix
{
private:
	size_t mRows, mCols;
	std::vector<std::vector<std::complex<double>>> mElements;
public:
	Matrix(size_t mRows, size_t mCols);
	Matrix(const Matrix& other);
	Matrix(const std::vector<std::vector<std::complex<double>>> & other);
	size_t getRows() const;
	size_t getCols() const;
	std::complex<double>& operator() (size_t i, size_t j);
	Matrix operator+(const Matrix& other) const;
	Matrix operator-(const Matrix& other) const;
	Matrix& operator=(const Matrix& other);
	Matrix& operator=(const std::vector<std::vector<std::complex<double>>>& other);
	Matrix operator*(const Matrix& other) const;
	Matrix operator*(std::complex<double> scalar) const;
	Matrix operator/(std::complex<double> scalar) const;
	Matrix dot(const Matrix& other) const;
	Matrix trans() const;
	Matrix conj() const;
	Matrix dagger() const;
	friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
	friend Matrix operator*(std::complex<double> scalar, const Matrix& m);
	friend Matrix operator-(const Matrix& m);
	friend bool operator==(const Matrix& lhs, const Matrix& rhs);
};


