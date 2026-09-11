// Implementation of a 4-dimensional vector.

#include "vec4.h"
#include <array>
#include <cmath>
#include <iomanip>


// Constructors

// > No argument constructor:
vec4::vec4() : data{0.f, 0.f, 0.f, 0.f} {}

// > All argument constructor:
vec4::vec4(float x, float y, float z, float w) : data{x, y, z, w} {}

// > Copy constructor
vec4::vec4(const vec4 &v2) : data(v2.data) {}

// Indexing

float vec4::operator[](unsigned int index) const {
    if (index > 3) {
        throw std::out_of_range("vec4: index out of range.");
    }
    return data[index];
}
float& vec4::operator[](unsigned int index) {
    if (index > 3) {
        throw std::out_of_range("vec4: index out of range.");
    }
    return data[index];
}

// Assignment

vec4& vec4::operator=(const vec4 &v2) {
    if (this != &v2) {
        data = v2.data;
    }
    return *this;
}

// Comparitors

bool vec4::operator==(const vec4 &v2) const {
    for (unsigned int i = 0; i < 4; i++) {
        if (data[i] != v2.data[i]) {
            return false;
        }
    }
    return true;
}

bool vec4::operator!=(const vec4 &v2) const {
    for (unsigned int i = 0; i < 4; i++) {
        if (data[i] != v2.data[i]) {
            return true;
        }
    }
    return false;
}

// Vector arithmetic operators

vec4& vec4::operator+=(const vec4 &v2) {
    for (unsigned int i = 0; i < 4; ++i) {
        data[i] += v2.data[i];
    }
    return *this;
}

vec4& vec4::operator-=(const vec4 &v2) {
    for (unsigned int i = 0; i < 4; ++i) {
        data[i] -= v2.data[i];
    }
    return *this;
}

vec4& vec4::operator*=(float c) {
    for (unsigned int i = 0; i < 4; ++i) {
        data[i] *= c;
    }
    return *this;
}

vec4& vec4::operator/=(float c) {
    for (unsigned int i = 0; i < 4; ++i) {
        data[i] /= c;
    }
    return *this;
}

vec4 vec4::operator+(const vec4 &v2) const {
    vec4 result = *this;
    result += v2;
    return result;
}

vec4 vec4::operator-(const vec4 &v2) const {
    vec4 result = *this;
    result -= v2;
    return result;
}

vec4 vec4::operator*(float c) const {
    vec4 result = *this;
    result *= c;
    return result;
}

vec4 vec4::operator/(float c) const {
    vec4 result = *this;
    result /= c;
    return result;
}

// Dot product
float dot(const vec4 &v1, const vec4 &v2) {
    float sum = 0.f;
    for (unsigned int i = 0; i < 4; i++) {
        sum += v1[i] * v2[i];
    }
    return sum;
}

// Cross product
vec4 cross(const vec4 &v1, const vec4 &v2) {
    float a = v1[1]*v2[2] - v1[2]*v2[1];
    float b = v1[2]*v2[0] - v1[0]*v2[2];
    float c = v1[0]*v2[1] - v1[1]*v2[0];
    return vec4(a, b, c, 0.f);
}

// Returns the geometric length of the input vector
float length(const vec4 &v) {
    float sum = 0.f;
    for (unsigned int i = 0; i < 4; i++) {
        sum += v[i] * v[i];
    }
    return std::sqrt(sum);
}

// Scalar multiplcation

vec4 operator*(float c, const vec4 &v) {
    return v * c;
}

vec4 normalize(const vec4& v) {
    float k = length(v);
    return v / k;
}

// Pretty print

std::ostream& operator<<(std::ostream &o, const vec4 &v) {
    o << std::fixed << std::setprecision(1);
    o << "(" << v[0] << ", " << v[1] << ", " << v[2] << ", " << v[3] << ")";
    return o;
}