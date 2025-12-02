// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstddef>   // std::size_t
#include <iosfwd>    // std::ostream forward declaration

class Vector; // forward declaration

class Matrix {
private:
    std::vector<std::vector<double>> data; // rows x cols

public:
    // === Constructors ===
    Matrix();                                      // default 0x0
    Matrix(std::size_t rows, std::size_t cols);    // rows x cols, initialized to 0.0
    explicit Matrix(const std::vector<std::vector<double>>& values);

    // === Basic info & element access ===
    std::size_t rows() const;
    std::size_t cols() const;

    // Row access: M[row][col]
    std::vector<double>& operator[](std::size_t r);
    const std::vector<double>& operator[](std::size_t r) const;

    // === User-defined member functions ===
    double norm() const;        // Frobenius norm
    Matrix transpose() const;   // transpose

    // === Operator overloading (members) ===

    // Matrix-vector multiplication
    Vector operator*(const Vector& v) const;

    // Matrix + Matrix, Matrix - Matrix
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;

    // Matrix * Matrix
    Matrix operator*(const Matrix& other) const;

    // Scalar division: M / a
    Matrix operator/(double a) const;

    // Unary negation: -M
    Matrix operator-() const;

    // Equality / inequality
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    // Increment / decrement: ++M, M++, --M, M--
    Matrix& operator++();     // prefix ++M
    Matrix operator++(int);   // postfix M++
    Matrix& operator--();     // prefix --M
    Matrix operator--(int);   // postfix M--
    
    // === Non-member friend operators ===
    friend std::ostream& operator<<(std::ostream& os, const Matrix& M);
};

#endif // MATRIX_H
