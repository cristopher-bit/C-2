#include <iostream>
#include "Complex.h"

int main() {
    // Create Complex objects
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);

    // Display original complex numbers
    std::cout << "Original Complex Numbers:" << std::endl;
    c1.display();
    c2.display();

    // Test addition
    Complex sum = c1 + c2;
    std::cout << "Sum: ";
    sum.display();

    // Test subtraction
    Complex difference = c1 - c2;
    std::cout << "Difference: ";
    difference.display();

    // Test multiplication
    Complex product = c1 * c2;
    std::cout << "Product: ";
    product.display();

    // Display the number of Complex objects created
    std::cout << "Number of Complex objects created: " << Complex::getObjectCount() << std::endl;

    return 0;
}
