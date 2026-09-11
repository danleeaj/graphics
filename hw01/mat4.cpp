// Implementation of a 4x4 matrix.

#include "mat4.h"
#include <cmath>
#include <stdexcept>

// Constructors

// > No argument constructor:
mat4::mat4() : data{vec4(1.f, 0.f, 0.f, 0.f),
           vec4(0.f, 1.f, 0.f, 0.f),
           vec4(0.f, 0.f, 1.f, 0.f),
           vec4(0.f, 0.f, 0.f, 1.f)} {}

// > Diagonal constructor:
mat4::mat4(float diag) : data{vec4(diag, 0.f, 0.f, 0.f),
           vec4(0.f, diag, 0.f, 0.f),
           vec4(0.f, 0.f, diag, 0.f),
           vec4(0.f, 0.f, 0.f, diag)} {}

// > Column constructor:
mat4::mat4(const vec4 &col0, const vec4 &col1,
           const vec4 &col2, const vec4 &col3)
    : data{col0, col1, col2, col3} {}

// > Copy constructor:
mat4::mat4(const mat4 &m2) : data(m2.data) {}


// Indexing

vec4 mat4::operator[](unsigned int index) const {
    if (index > 3) {
        throw std::out_of_range("mat4: index out of range.");
    }
    return data[index];
}

vec4& mat4::operator[](unsigned int index) {
    if (index > 3) {
        throw std::out_of_range("mat4: index out of range.");
    }
    return data[index];
}

vec4 row(const mat4 &m, unsigned int index) {
    if (index > 3) {
        throw std::out_of_range("mat4: row index out of range.");
    }

    return vec4(m[0][index],
                m[1][index],
                m[2][index],
                m[3][index]);
}

// 3d rotation matrix

mat4 mat4::rotate(float angle, float x, float y, float z) {
    return mat4();
}

// 3d trasnaltion matrix

mat4 mat4::translate(float x, float y, float z) {
    return mat4(vec4(1.f, 0.f, 0.f, 0.f),
                vec4(0.f, 1.f, 0.f, 0.f),
                vec4(0.f, 0.f, 1.f, 0.f),
                vec4(x, y, z, 1.f));
}

// 3d scale matrix

mat4 mat4::scale(float x, float y, float z) {
    return mat4(vec4(x,   0.f, 0.f, 0.f),
                vec4(0.f, y,   0.f, 0.f),
                vec4(0.f, 0.f, z,   0.f),
                vec4(0.f, 0.f, 0.f, 1.f));
}

// identity matrix

mat4 mat4::identity() {
    return mat4();
}

// Assignment

mat4& mat4::operator=(const mat4 &m2) {
    if (this != &m2) {
        data = m2.data;
    }
    return *this;
}


// Comparitors

bool mat4::operator==(const mat4 &m2) const {
    for (unsigned int i = 0; i < 4; i++) {
        if (data[i] != m2.data[i]) {
            return false;
        }
    }
    return true;
}

bool mat4::operator!=(const mat4 &m2) const {
    for (unsigned int i = 0; i < 4; i++) {
        if (data[i] != m2.data[i]) {
            return true;
        }
    }
    return false;
}


// Matrix arithmetic operators

mat4& mat4::operator+=(const mat4 &m2) {
    for (unsigned int i = 0; i < 4; i++) {
        data[i] += m2.data[i];
    }
    return *this;
}

mat4& mat4::operator-=(const mat4 &m2) {
    for (unsigned int i = 0; i < 4; i++) {
        data[i] -= m2.data[i];
    }
    return *this;
}

mat4& mat4::operator*=(float c) {
    for (unsigned int i = 0; i < 4; i++) {
        data[i] *= c;
    }
    return *this;
}

mat4& mat4::operator/=(float c) {
    for (unsigned int i = 0; i < 4; i++) {
        data[i] /= c;
    }
    return *this;
}

mat4 mat4::operator+(const mat4 &m2) const {
    mat4 result = *this;
    result += m2;
    return result;
}

mat4 mat4::operator-(const mat4 &m2) const {
    mat4 result = *this;
    result -= m2;
    return result;
}

mat4 mat4::operator*(float c) const {
    mat4 result = *this;
    result *= c;
    return result;
}

mat4 mat4::operator/(float c) const {
    mat4 result = *this;
    result /= c;
    return result;
}

mat4 mat4::operator*(const mat4 &m2) const {
    return mat4(*this * m2[0],
                *this * m2[1],
                *this * m2[2],
                *this * m2[3]);
}

vec4 mat4::operator*(const vec4 &v) const {
    return vec4(dot(row(*this, 0), v),
                dot(row(*this, 1), v),
                dot(row(*this, 2), v),
                dot(row(*this, 3), v));
}


// Matrix operations

mat4 transpose(const mat4 &m) {
    return mat4(row(m, 0),
                row(m, 1),
                row(m, 2),
                row(m, 3));
}

mat4 operator*(float c, const mat4 &m) {
    return m * c;
}

vec4 operator*(const vec4 &v, const mat4 &m) {
    return vec4(dot(v, m[0]),
                dot(v, m[1]),
                dot(v, m[2]),
                dot(v, m[3]));
}


// Pretty print

std::ostream& operator<<(std::ostream &o, const mat4 &m) {
    for (unsigned int i = 0; i < 4; i++) {
        o << row(m, i);
        if (i < 3) {
            o << std::endl;
        }
    }
    return o;
}