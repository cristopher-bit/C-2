#include "Complex.h"
#include <iostream>

// Initialize static member
int Complex::objectCount = 0;

// No-argument constructor
Complex::Complex() : real(0), imag(0) {
    objectCount++;
}

// Parameterized constructor
Complex::Complex(double r, double i) : real(r), imag(i) {
    objectCount++;
}

// Destructor
Complex::~Complex() {
    objectCount--;
}

// Method to display complex number
void Complex::display() const {
    std::cout << "Complex Number: " << real << " + " << imag << "i" << std::endl;
}

// Static method to get the object count
int Complex::getObjectCount() {
    return objectCount;
}

// Operator overload for addition
Complex Complex::operator+(const Complex& other) const {
    return Complex(this->real + other.real, this->imag + other.imag);
}

// Operator overload for subtraction
Complex Complex::operator-(const Complex& other) const {
    return Complex(this->real - other.real, this->imag - other.imag);
}

// Operator overload for multiplication
Complex Complex::operator*(const Complex& other) const {
    return Complex(this->real * other.real - this->imag * other.imag,
                   this->real * other.imag + this->imag * other.real);
}
