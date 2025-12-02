// Matrix_UserDefined.cpp
#include "Matrix.h"
#include "Vector.h"   // need full Vector for outerProduct
#include <cmath>
#include <stdexcept>

// Frobenius norm: sqrt(sum of squares of all entries)
double Matrix::norm() const {
    double sum = 0.0;
    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < cols(); ++j) {
            double x = data[i][j];
            sum += x * x;
        }
    }
    return std::sqrt(sum);
}

// Transpose: (rows x cols) -> (cols x rows)
Matrix Matrix::transpose() const {
    if (rows() == 0 || cols() == 0) {
        return Matrix();
    }

    Matrix t(cols(), rows());
    for (std::size_t i = 0; i < rows(); ++i) {
        for (std::size_t j = 0; j < cols(); ++j) {
            t[j][i] = data[i][j];
        }
    }
    return t;
}

// ===== Implementation of Vector::outerProduct =====
// v (m) x w (n) -> Matrix (m x n)
Matrix Vector::outerProduct(const Vector& other) const {
    Matrix result(size(), other.size());
    for (std::size_t i = 0; i < size(); ++i) {
        for (std::size_t j = 0; j < other.size(); ++j) {
            result[i][j] = (*this)[i] * other[j];
        }
    }
    return result;
}
