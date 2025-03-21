Employee/
│── Employee.h            (Base class declaration)
│── Employee.cpp          (Base class implementation)
│── PermEmployee.h        (Derived class declaration - Permanent Employee)
│── PermEmployee.cpp      (Derived class implementation)
│── ContractEmployee.h    (Derived class declaration - Contract Employee)
│── ContractEmployee.cpp  (Derived class implementation)
│── main.cpp              (Main program - Demonstrating polymorphism)
1️⃣ Employee.h (Abstract Base Class)
cpp
Copy
Edit
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
using namespace std;

// Abstract Base Class
class Employee {
protected:
    string name;
    int empID;
public:
    Employee(string n, int id);
    virtual double CalcSalary() = 0; // Pure Virtual Function
    virtual void displaySalary();
    virtual ~Employee(); // Virtual Destructor
};

#endif
2️⃣ Employee.cpp (Base Class Implementation)
cpp
Copy
Edit
#include "Employee.h"

// Constructor
Employee::Employee(string n, int id) : name(n), empID(id) {}

// Virtual Function: Display Salary (Calls Overridden CalcSalary())
void Employee::displaySalary() {
    cout << "Employee: " << name << " (ID: " << empID << ") has salary: $" << CalcSalary() << endl;
}

// Virtual Destructor
Employee::~Employee() {}
3️⃣ PermEmployee.h (Derived Class - Permanent Employee)
cpp
Copy
Edit
#ifndef PERMEMLOYEE_H
#define PERMEMLOYEE_H

#include "Employee.h"

class PermEmployee : public Employee {
private:
    double basicSalary;
    double benefits;
public:
    PermEmployee(string n, int id, double salary, double ben);
    double CalcSalary() override;
};

#endif
4️⃣ PermEmployee.cpp (Permanent Employee Implementation)
cpp
Copy
Edit
#include "PermEmployee.h"

// Constructor
PermEmployee::PermEmployee(string n, int id, double salary, double ben) 
    : Employee(n, id), basicSalary(salary), benefits(ben) {}

// Overridden Salary Calculation
double PermEmployee::CalcSalary() {
    return basicSalary + benefits;
}
5️⃣ ContractEmployee.h (Derived Class - Contract Employee)
cpp
Copy
Edit
#ifndef CONTRACTEMPLOYEE_H
#define CONTRACTEMPLOYEE_H

#include "Employee.h"

class ContractEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;
public:
    ContractEmployee(string n, int id, double rate, int hours);
    double CalcSalary() override;
};

#endif
6️⃣ ContractEmployee.cpp (Contract Employee Implementation)
cpp
Copy
Edit
#include "ContractEmployee.h"

// Constructor
ContractEmployee::ContractEmployee(string n, int id, double rate, int hours) 
    : Employee(n, id), hourlyRate(rate), hoursWorked(hours) {}

// Overridden Salary Calculation
double ContractEmployee::CalcSalary() {
    return hourlyRate * hoursWorked;
}
7️⃣ main.cpp (Main Program)
cpp
Copy
Edit
#include "PermEmployee.h"
#include "ContractEmployee.h"

int main() {
    // Array of Base Class Pointers
    Employee* employees[2];

    employees[0] = new PermEmployee("Alice", 101, 5000, 1000);
    employees[1] = new ContractEmployee("Bob", 102, 50, 160);

    cout << "Employee Salary Details:\n";
    for (int i = 0; i < 2; i++) {
        employees[i]->displaySalary(); // Calls overridden CalcSalary() dynamically
    }

    // Cleanup
    for (int i = 0; i < 2; i++) {
        delete employees[i]; // Prevent memory leak
    }

    return 0;
}
💡 Explanation
🔹 Base Class (Employee)
Abstract class with a pure virtual function CalcSalary().
Provides a common interface for different types of employees.
Virtual destructor ensures proper cleanup.
🔹 Derived Classes
PermEmployee
Has basicSalary + benefits.
Overrides CalcSalary() to return total salary.
ContractEmployee
Has hourlyRate * hoursWorked.
Overrides CalcSalary() to return total earnings.
🔹 Main Program (main.cpp)
Demonstrates runtime polymorphism:
Uses base class pointers to call overridden functions dynamically.
Stores PermEmployee and ContractEmployee in an array of base class pointers.
Calls displaySalary(), which invokes the overridden CalcSalary() dynamically.
Deletes allocated memory to prevent leaks.
📌 Expected Output
yaml
Copy
Edit
Employee Salary Details:
Employee: Alice (ID: 101) has salary: $6000
Employee: Bob (ID: 102) has salary: $8000
✅ Key Concepts Used
✔ Abstract Class (Employee)
✔ Pure Virtual Function (CalcSalary())
✔ Function Overriding (PermEmployee & ContractEmployee)
✔ Runtime Polymorphism (Base class pointer calling overridden methods)
✔ Separate Files for Modularity
✔ Memory Management (Using delete)
