#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
    double real;
    double imag;
    static int objectCount; // Static data member to count objects

public:
    // No-argument constructor
    Complex();

    // Parameterized constructor
    Complex(double r, double i);

    // Destructor
    ~Complex();

    // Method to display complex number
    void display() const;

    // Static method to get the object count
    static int getObjectCount();

    // Operator overloads
    Complex operator+(const Complex& other) const; // Overload +
    Complex operator-(const Complex& other) const; // Overload -
    Complex operator*(const Complex& other) const; // Overload *
};

#endif // COMPLEX_H
