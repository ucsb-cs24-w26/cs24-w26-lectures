#include "Complex.h"

// Constructor - uses initializer list
Complex::Complex(double r, double i) : real(r), imag(i) {
    // Body empty - all initialization in initializer list!
}

// Getter for real part
double Complex::getReal() const {
    return real;
}

// Getter for imaginary part
double Complex::getImag() const {
    return imag;
}

// TODO: Implement operator<< (Instructor will demo this LIVE!)
// This is a FREE FUNCTION (not a member), so it is defined outside the class.
//
// Key points to demonstrate:
// 1. Return type is ostream& (for chaining)
// 2. Takes ostream& as first parameter (the output stream)
// 3. Takes Complex by const reference (efficient, no copy)
// 4. Must return the ostream at the end
//
// Format: Print as "3 + 4j" or "3 - 4j"
ostream& operator<<(ostream& out, const Complex& c) {
    // INSTRUCTOR WILL LIVE-CODE THIS!
    // Expected implementation:
    out << c.getReal() <<" + " << c.getImag() << "j" << endl;
    // Placeholder for now:
    //out << "TODO: Implement me!";
    return out;
}

// TODO: Implement operator+ (Students will do this in Activity 1B!)
// Addition of complex numbers: (a + bi) + (c + di) = (a+c) + (b+d)i
//
// Key points:
// 1. Return type is Complex (NOT Complex&) - why?
// 2. We're creating a NEW complex number
// // 3. Returns by value (not reference to local variable!)
// Complex operator+(const Complex& lhs, const Complex& rhs) {
//     // YOUR CODE HERE (Students Activity 1B):
//     // 1. Add the real parts
//     // 2. Add the imaginary parts
//     // 3. Return a NEW Complex with those values
   
//     // Placeholder:
//     return Complex(lhs.getReal() + rhs.getReal(), 
//                    lhs.getImag() + rhs.getImag());
// }

// OPTIONAL: operator== for comparison
// Two complex numbers are equal if both real and imag parts match
bool operator==(const Complex& lhs, const Complex& rhs) {
    return true; // Placeholder;
}
