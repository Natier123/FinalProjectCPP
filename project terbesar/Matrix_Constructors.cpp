// Matrix_Constructors.cpp
#include "Matrix.h"
#include <stdexcept>

// Default constructor: 0x0 matrix
Matrix::Matrix() : data() {}

// Constructor with rows and cols
Matrix::Matrix(std::size_t rows, std::size_t cols)
    : data(rows, std::vector<double>(cols, 0.0)) {
    if (rows > 200 || cols > 200) {
        throw std::length_error("Matrix dimensions exceed 200");
    }
}

// Constructor from 2D vector
Matrix::Matrix(const std::vector<std::vector<double>>& values)
    : data(values) {
    if (data.size() > 200) {
        throw std::length_error("Matrix row count exceeds 200");
    }
    if (!data.empty() && data[0].size() > 200) {
        throw std::length_error("Matrix column count exceeds 200");
    }
}

std::size_t Matrix::rows() const {
    return data.size();
}

std::size_t Matrix::cols() const {
    return data.empty() ? 0 : data[0].size();
}

// Row access
std::vector<double>& Matrix::operator[](std::size_t r) {
    return data[r]; // no bounds check
}

const std::vector<double>& Matrix::operator[](std::size_t r) const {
    return data[r];
}
