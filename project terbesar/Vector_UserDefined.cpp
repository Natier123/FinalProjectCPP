// Vector_UserDefined.cpp
#include "Vector.h"
#include <cmath>
#include <stdexcept>

// Euclidean norm: sqrt(sum_i data[i]^2)
double Vector::norm() const {
    double sum = 0.0;
    for (double x : data) {
        sum += x * x;
    }
    return std::sqrt(sum);
}

// Inner product (dot product) with another vector
double Vector::innerProduct(const Vector& other) const {
    if (size() != other.size()) {
        throw std::invalid_argument("Vector dimensions must match for inner product");
    }

    double sum = 0.0;
    for (std::size_t i = 0; i < size(); ++i) {
        sum += data[i] * other.data[i];
    }
    return sum;
}

/*
 * NOTE: outerProduct(const Vector&) is only declared in Vector.h for now.
 * You will implement it later, in a .cpp file that also includes the full
 * Matrix definition (once your Matrix class is ready).
 *
 * Signature (for later):
 *
 *   Matrix Vector::outerProduct(const Vector& other) const {
 *       // uses Matrix(rows, cols) and operator[] on Matrix
 *   }
 */
