// Base code written by Jan Allbeck, Chris Czyzewicz, Cory Boatright, Tiantian Liu, Benedict Brown, and Adam Mally
// University of Pennsylvania

// At least some C++ compilers do funny things
// to C's math.h header if you don't define this
#define _USE_MATH_DEFINES

#include "vec4.h"
#include "mat4.h"
#include <iostream>
#include <math.h>
using namespace std;


void vec4AddTest() {
    std::cout << "> Adding" << std::endl;
    vec4 a = vec4(1.f, 2.f, 3.f, 4.f);
    vec4 b = vec4(2.f, 4.f, 6.f, 8.f);
    std::cout << "vec4 + vec4 expected value: (3.0, 6.0, 9.0, 12.0)" << std::endl;
    std::cout << "vec4 + vec4 actual value: " << (a + b) << std::endl;

    a += b;
    std::cout << "vec4 += vec4 actual value: " << a << std::endl;
}

void vec4SubTest() {
    std::cout << "> Subtracting" << std::endl;
    vec4 a = vec4(1.f, 2.f, 3.f, 4.f);
    vec4 b = vec4(1.f, 2.f, 3.f, 4.f);
    std::cout << "vec4 - vec4 expected value: (0.0, 0.0, 0.0, 0.0)" << std::endl;
    std::cout << "vec4 - vec4 actual value: " << (a - b) << std::endl;

    a -= b;
    std::cout << "vec4 -= vec4 actual value: " << a << std::endl;
}

void vec4MulTest() {
    std::cout << "> Multiplying" << std::endl;
    vec4 a = vec4(1.f, 2.f, 3.f, 4.f);
    float c = 2.f;
    std::cout << "vec4 * float expected value: (2.0, 4.0, 6.0, 8.0)" << std::endl;
    std::cout << "vec4 * float actual value: " << (a * c) << std::endl;
    std::cout << "float * vec4 expected value: (2.0, 4.0, 6.0, 8.0)" << std::endl;
    std::cout << "float * vec4 actual value: " << (c * a) << std::endl;

    a *= c;
    std::cout << "vec4 *= float actual value: " << a << std::endl;
}

void vec4DivTest() {
    std::cout << "> Dividing" << std::endl;
    vec4 a = vec4(2.f, 4.f, 6.f, 8.f);
    float c = 2.f;
    std::cout << "vec4 / float expected value: (1.0, 2.0, 3.0, 4.0)" << std::endl;
    std::cout << "vec4 / float actual value: " << (a / c) << std::endl;

    a /= c;
    std::cout << "vec4 /= float actual value: " << a << std::endl;
}

void vec4ArithTest() {
    std::cout << ">> ARITHMETICS" << std::endl;
    vec4AddTest();
    vec4SubTest();
    vec4MulTest();
    vec4DivTest();
}

void vec4ConstructorTest() {
    std::cout << ">> CONSTRUCTORS" << std::endl;
    vec4 a = vec4();
    std::cout << "vec4() expected value: (0.0, 0.0, 0.0, 0.0)" << std::endl;
    std::cout << "vec4() actual value: " << a << std::endl;
    vec4 b = vec4(1.f, 1.f, 1.f, 1.f);
    std::cout << "vec4(x, y, z, w) expected value: (1.0, 1.0, 1.0, 1.0)" << std::endl;
    std::cout << "vec4(x, y, z, w) actual value: " << b << std::endl;
    vec4 c = vec4(b);
    std::cout << "vec4(vec4) expected value: ((1.0, 1.0, 1.0, 1.0)" << std::endl;
    std::cout << "vec4(vec4) actual value: " << c << std::endl;
}

void vec4ComparatorTest() {
    std::cout << ">> COMPARATORS" << std::endl;
    vec4 a = vec4();
    vec4 b = vec4(1.f, 1.f, 1.f, 2.f);
    vec4 c = vec4(1.f, 1.f, 1.f, 2.f);
    std::cout << "vec4() == vec4(1,1,1,2) expected value: 0" << std::endl;
    std::cout << "vec4() == vec4(1,1,1,2) actual value: " << (a == b) << std::endl;
    std::cout << "vec4(1,1,1,2) == vec4(1,1,1,2) expected value: 1" << std::endl;
    std::cout << "vec4(1,1,1,2) == vec4(1,1,1,2) actual value: " << (b == c) << std::endl;
    std::cout << "vec4(1,1,1,2) != vec4(1,1,1,2) expected value: 0" << std::endl;
    std::cout << "vec4(1,1,1,2) != vec4(1,1,1,2) actual value: " << (b != c) << std::endl;
}


int main() {
	// Example test (won't work until you implement vec4's operator+ and operator<<)
    vec4ConstructorTest();
    vec4ArithTest();
    vec4ComparatorTest();
	// Add your own tests here
}