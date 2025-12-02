// Vector_Operators.cpp
#include "Vector.h"
#include <iostream>
#include <stdexcept>

// Vector addition: v + w
Vector Vector::operator+(const Vector& other) const {
    if (size() != other.size()) {
        throw std::invalid_argument("Vector dimensions must match for addition");
    }

    Vector result(size());
    for (std::size_t i = 0; i < size(); ++i) {
        result[i] = data[i] + other.data[i];
    }
    return result;
}

// Vector subtraction: v - w
Vector Vector::operator-(const Vector& other) const {
    if (size() != other.size()) {
        throw std::invalid_argument("Vector dimensions must match for subtraction");
    }

    Vector result(size());
    for (std::size_t i = 0; i < size(); ++i) {
        result[i] = data[i] - other.data[i];
    }
    return result;
}

// Scalar division: v / a
Vector Vector::operator/(double a) const {
    if (a == 0.0) {
        throw std::invalid_argument("Division by zero");
    }

    Vector result(size());
    for (std::size_t i = 0; i < size(); ++i) {
        result[i] = data[i] / a;
    }
    return result;
}

// Unary negation: -v
Vector Vector::operator-() const {
    Vector result(size());
    for (std::size_t i = 0; i < size(); ++i) {
        result[i] = -data[i];
    }
    return result;
}

// Equality: elementwise equality and same size
bool Vector::operator==(const Vector& other) const {
    if (size() != other.size()) return false;

    for (std::size_t i = 0; i < size(); ++i) {
        if (data[i] != other.data[i]) return false;
    }
    return true;
}

// Inequality: negation of equality
bool Vector::operator!=(const Vector& other) const {
    return !(*this == other);
}

// Prefix increment: ++v (add 1 to each element)
Vector& Vector::operator++() {
    for (double& x : data) {
        ++x;
    }
    return *this;
}

// Postfix increment: v++
Vector Vector::operator++(int) {
    Vector temp(*this);
    ++(*this);  // reuse prefix version
    return temp;
}

// Prefix decrement: --v (subtract 1 from each element)
Vector& Vector::operator--() {
    for (double& x : data) {
        --x;
    }
    return *this;
}

// Postfix decrement: v--
Vector Vector::operator--(int) {
    Vector temp(*this);
    --(*this);  // reuse prefix version
    return temp;
}

// Scalar multiplication: a * v
Vector operator*(double a, const Vector& v) {
    Vector result(v.size());
    for (std::size_t i = 0; i < v.size(); ++i) {
        result[i] = a * v[i];
    }
    return result;
}

// Scalar multiplication: v * a
Vector operator*(const Vector& v, double a) {
    return a * v; // reuse above
}

// Stream output: print as [x0 x1 x2 ...]
std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "[";
    for (std::size_t i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i + 1 < v.size()) {
            os << " ";
        }
    }
    os << "]";
    return os;
}
