#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

/**
 * Complex - A simple complex number class for operator overloading demo
 *
 * This class demonstrates:
 * - Operator overloading (<<, +, ==)
 * - Friend functions
 * - Why we return references vs. values
 */
class Complex {
public:
    // Constructor with default parameters
    Complex(double r = 0.0, double i = 0.0);
    Complex operator+(const Complex& rhs){
         return Complex(real+ rhs.real, 
                   imag + rhs.imag);
        
    }

    // Accessors
    double getReal() const;
    double getImag() const;

private:
    double real;
    double imag;
};

// TODO: Implement operator<< (demo this live!)
// This allows: cout << complex_obj;
ostream& operator<<(ostream& out, const Complex& c);

// TODO: Implement operator+ (students do this in Activity 1B!)
// This allows: Complex c3 = c1 + c2;
//Complex operator+(const Complex& lhs, const Complex& rhs);

// Optional: operator== for comparison
// This allows: if (c1 == c2) { ... }
bool operator==(const Complex& lhs, const Complex& rhs);

#endif
