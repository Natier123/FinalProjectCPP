// Vector_Constructors.cpp
#include "Vector.h"
#include <stdexcept>

// Default constructor: zero-length vector
Vector::Vector() : data() {}

// Constructor with size n, initialize with 0.0
Vector::Vector(std::size_t n) : data(n, 0.0) {
    if (n > 200) {
        throw std::length_error("Vector size exceeds 200");
    }
}

// Constructor from std::vector<double>
Vector::Vector(const std::vector<double>& values) : data(values) {
    if (data.size() > 200) {
        throw std::length_error("Vector size exceeds 200");
    }
}

// Return number of elements
std::size_t Vector::size() const {
    return data.size();
}

// Element access (modifiable)
double& Vector::operator[](std::size_t i) {
    return data[i]; // no bounds check (like std::vector::operator[])
}

// Element access (read-only)
const double& Vector::operator[](std::size_t i) const {
    return data[i];
}
