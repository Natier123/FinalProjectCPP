// Vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <vector>
#include <cstddef>   // for std::size_t
#include <iosfwd>    // for std::ostream forward declaration

class Matrix; // forward declaration; full definition will come later

class Vector {
private:
    std::vector<double> data; // internal storage, size <= 200

public:
    // === Constructors ===
    Vector();                                // default constructor
    explicit Vector(std::size_t n);          // size constructor
    explicit Vector(const std::vector<double>& values); // from std::vector

    // === Basic info & element access ===
    std::size_t size() const;

    double& operator[](std::size_t i);
    const double& operator[](std::size_t i) const;

    // === User-defined member functions ===
    double norm() const;                         // Euclidean norm
    double innerProduct(const Vector& other) const; // dot product

    // Declared here; will be defined later once Matrix is fully implemented
    Matrix outerProduct(const Vector& other) const;

    // === Operator overloading (member) ===

    // Vector + Vector, Vector - Vector
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;

    // Scalar division v / a
    Vector operator/(double a) const;

    // Unary negation -v
    Vector operator-() const;

    // Equality / inequality
    bool operator==(const Vector& other) const;
    bool operator!=(const Vector& other) const;

    // Increment / decrement: ++v, v++, --v, v--
    // (defined as add/subtract 1 to each component)
    Vector& operator++();     // prefix ++v
    Vector operator++(int);   // postfix v++
    Vector& operator--();     // prefix --v
    Vector operator--(int);   // postfix v--

    // === Operator overloading (non-member friends) ===

    // Scalar multiplication a * v, v * a
    friend Vector operator*(double a, const Vector& v);
    friend Vector operator*(const Vector& v, double a);

    // Stream output
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);
};

#endif // VECTOR_H
