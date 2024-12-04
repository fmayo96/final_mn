#include "Matrix.h"
#include <stdexcept>

Matrix::Matrix(size_t rows, size_t cols) : mRows(rows), mCols(cols) {
	mElements = std::vector<std::vector<std::complex<double>>>(rows, std::vector<std::complex<double>>(cols, 0.0));
}
Matrix::Matrix(const Matrix& other) : mRows(other.mRows), mCols(other.mCols) {
	mElements = other.mElements;
}
Matrix::Matrix(const std::vector<std::vector<std::complex<double>>>& other) {
	mRows = other.size();
	mCols = other[0].size();
	mElements = other;
}
size_t Matrix::getCols() const {
	return mCols;
}
size_t Matrix::getRows() const {
	return mRows;
} 
std::complex<double>& Matrix::operator() (size_t i, size_t j) {
	return mElements[i][j];
}
Matrix Matrix::operator+(const Matrix& other) const {
	if (mCols != other.mCols || mRows != other.mRows) {
		throw std::exception("operator + only works for matrices of the same shape.");
	}
	Matrix res(2,2);
	for (int row = 0; row < mRows; row++) {
		for (int col = 0; col < mCols; col++) {
			res(row, col) = mElements[row][col] + other.mElements[row][col];
		}
	}
	return res;
}
Matrix Matrix::operator-(const Matrix& other) const {
	if (mCols != other.mCols || mRows != other.mRows) {
		throw std::exception("operator - only works for matrices of the same shape.");
	}
	Matrix res(2, 2);
	for (int row = 0; row < mRows; row++) {
		for (int col = 0; col < mCols; col++) {
			res(row, col) = mElements[row][col] - other.mElements[row][col];
		}
	}
	return res;
}
Matrix& Matrix::operator=(const Matrix& other) {
	mCols = other.mCols;
	mRows = other.mRows;
	mElements = other.mElements;
	return *this;
}
Matrix& Matrix::operator=(const std::vector<std::vector<std::complex<double>>>& other) {
	mRows = other.size();
	mCols = other[0].size();
	mElements = other;
	return *this;
}
Matrix Matrix::operator*(const Matrix& other) const {
	if (mCols != other.mCols || mRows != other.mRows) {
		throw std::exception("operator * only works for matrices of the same shape.");
	}
	Matrix res(mRows, mCols);
	for (int row = 0; row < mRows; row++) {
		for (int col = 0; col < mCols; col++) {
			res(row, col) = mElements[row][col] * other.mElements[row][col];
		}
	}
	return res;
}
Matrix Matrix::dot(const Matrix& other) const {
	if (mCols != other.mRows) {
		throw std::exception("dot product only works for matrices of shapes (n, m) * (m, k) -> (n, k).");
	}
	Matrix res(mRows, other.mCols);
	for (int i = 0; i < mRows; i++) {
		for (int j = 0; j < other.mCols; j++) {
			for (int k = 0; k < mCols; k++) {
				res(i, j) += mElements[i][k] * other.mElements[k][j];
			}
		}
	}
	return res;
}
std::ostream& operator<<(std::ostream& os, const Matrix& m) {
	for (int row = 0; row < m.mRows; row++) {
		for (int col = 0; col < m.mCols; col++) {
			os << m.mElements[row][col] << " ";
		}
		os << "\n";
	}
	return os;
}
Matrix Matrix::operator*(std::complex<double> scalar) const {
	Matrix res(*this);
	for (int row = 0; row < mRows; row++) {
		for (int col = 0; col < mCols; col++) {
			res(row ,col) = mElements[row][col] * scalar;
		}
	}
	return res;
}
Matrix Matrix::operator/(std::complex<double> scalar) const {
	return *this * (1.0 / scalar);
}
Matrix Matrix::trans() const {
	Matrix res(mRows, mCols);
	for (int row = 0; row < mRows; row++) {
		for (int col = 0; col < mCols; col++) {
			res(row, col) = mElements[col][row];
		}
	}
	return res;
}
Matrix Matrix::conj() const {
	Matrix res(*this);
	for (int row = 0; row < mRows; row++) {
		for (int col = 0; col < mCols; col++) {
			res(row, col) = std::conj(mElements[row][col]);
		}
	}
	return res;
}
Matrix Matrix::dagger() const {
	Matrix res(*this);
	return res.trans().conj();
}
Matrix operator*(std::complex<double> scalar, const Matrix& m) {
	Matrix res(m);
	return res * scalar;
}
Matrix operator-(const Matrix& m) {
	return -1 * m;
}
bool operator==(const Matrix& lhs, const Matrix& rhs) {
	const std::complex<double> eps = std::complex<double>(1e-16, 1e-16);
	if (lhs.getCols() != rhs.getCols() || lhs.getRows() != rhs.getRows())
		return false;
	for (int row = 0; row < lhs.getRows(); row++) {
		for (int col = 0; col < lhs.getCols(); col++) {
			if (lhs.mElements[row][col] != rhs.mElements[row][col])
				return false;
		}
	}
	return true;
}