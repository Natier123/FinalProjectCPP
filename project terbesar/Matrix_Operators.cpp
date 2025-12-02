// Matrix_Operators.cpp
#include "Matrix.h"
#include "Vector.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>

// Matrix-vector multiplication: M * v
Vector Matrix::operator*(const Vector& v) const {
    if (cols() != v.size()) {
        throw std::invalid_argument("Matrix columns must match vector size for multiplication");
    }

    Vector result(rows());
    for (std::size_t i = 0; i < rows(); ++i) {
        double sum = 0.0;
        for (std::size_t j = 0; j < cols(); ++j) {
            sum += data[i][j] * v[j];
        }
        result[i] = sum;
    }
    return result;
}

// Matrix addition: M + N
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows() != other.rows() || cols() != other.cols()) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }

    Matrix result(rows(), cols());
    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < cols(); ++j) {
            result[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Matrix subtraction: M - N
Matrix Matrix::operator-(const Matrix& other) const {
    if (rows() != other.rows() || cols() != other.cols()) {
        throw std::invalid_argument("Matrix dimensions must match for subtraction");
    }

    Matrix result(rows(), cols());
    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < cols(); ++j) {
            result[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

// Matrix multiplication: M * N
Matrix Matrix::operator*(const Matrix& other) const {
    if (cols() != other.rows()) {
        throw std::invalid_argument("Inner matrix dimensions must match for multiplication");
    }

    Matrix result(rows(), other.cols());
    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < other.cols(); ++j) {
            double sum = 0.0;
            for (std::size_t k = 0; k < cols(); ++k) {
                sum += data[i][k] * other.data[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

// Scalar division: M / a
Matrix Matrix::operator/(double a) const {
    if (a == 0.0) {
        throw std::invalid_argument("Division by zero");
    }

    Matrix result(rows(), cols());
    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < cols(); ++j) {
            result[i][j] = data[i][j] / a;
        }
    }
    return result;
}

// Unary negation: -M
Matrix Matrix::operator-() const {
    Matrix result(rows(), cols());
    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < cols(); ++j) {
            result[i][j] = -data[i][j];
        }
    }
    return result;
}

// Equality: same size and all elements equal
bool Matrix::operator==(const Matrix& other) const {
    if (rows() != other.rows() || cols() != other.cols()) return false;

    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < cols(); ++j) {
            if (data[i][j] != other.data[i][j]) return false;
        }
    }
    return true;
}

// Inequality: negation of equality
bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

// Prefix increment: ++M (add 1 to each entry)
Matrix& Matrix::operator++() {
    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < cols(); ++j) {
            ++data[i][j];
        }
    }
    return *this;
}

// Postfix increment: M++
Matrix Matrix::operator++(int) {
    Matrix temp(*this);
    ++(*this);
    return temp;
}

// Prefix decrement: --M (subtract 1 from each entry)
Matrix& Matrix::operator--() {
    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < cols(); ++j) {
            --data[i][j];
        }
    }
    return *this;
}

// Postfix decrement: M--
Matrix Matrix::operator--(int) {
    Matrix temp(*this);
    --(*this);
    return temp;
}

// Stream output
std::ostream& operator<<(std::ostream& os, const Matrix& M) {
    os << std::fixed << std::setprecision(3);
    for (std::size_t i = 0; i < M.rows(); ++i) {
        os << "[";
        for (std::size_t j = 0; j < M.cols(); ++j) {
            os << M[i][j];
            if (j + 1 < M.cols()) {
                os << " ";
            }
        }
        os << "]\n";
    }
    return os;
}
