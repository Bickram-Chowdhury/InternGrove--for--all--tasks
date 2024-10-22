#include <iostream>
#include <string>
using namespace std;

// Base class: Employee
class Employee {
protected:
    string name;
    int employeeID;

public:
    // Constructor
    Employee(string name, int employeeID) : name(name), employeeID(employeeID) {}

    // Virtual function to calculate salary (to be overridden in derived classes)
    virtual double calculateSalary() const = 0;

    // Function to display employee details
    virtual void displayDetails() const {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
    }

    // Virtual destructor
    virtual ~Employee() {}
};

// Derived class: FullTimeEmployee
class FullTimeEmployee : public Employee {
private:
    double monthlySalary;

public:
    // Constructor
    FullTimeEmployee(string name, int employeeID, double monthlySalary)
        : Employee(name, employeeID), monthlySalary(monthlySalary) {}

    // Overridden function to calculate salary
    double calculateSalary() const override {
        return monthlySalary;
    }

    // Overridden function to display employee details
    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Employee Type: Full-Time" << endl;
        cout << "Monthly Salary: $" << monthlySalary << endl;
    }
};

// Derived class: PartTimeEmployee
class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    // Constructor
    PartTimeEmployee(string name, int employeeID, double hourlyRate, int hoursWorked)
        : Employee(name, employeeID), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    // Overridden function to calculate salary
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    // Overridden function to display employee details
    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Employee Type: Part-Time" << endl;
        cout << "Hourly Rate: $" << hourlyRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
        cout << "Total Salary: $" << calculateSalary() << endl;
    }
};

int main() {
    int choice;
    string name;
    int employeeID;
    double monthlySalary, hourlyRate;
    int hoursWorked;

    cout << "Enter Employee Type (1 for Full-Time, 2 for Part-Time): ";
    cin >> choice;

    cout << "Enter Employee Name: ";
    cin.ignore(); // To ignore the newline character from the previous input
    getline(cin, name);

    cout << "Enter Employee ID: ";
    cin >> employeeID;

    Employee* employee = nullptr; // Pointer to base class

    if (choice == 1) {
        cout << "Enter Monthly Salary: $";
        cin >> monthlySalary;
        employee = new FullTimeEmployee(name, employeeID, monthlySalary);
    } else if (choice == 2) {
        cout << "Enter Hourly Rate: $";
        cin >> hourlyRate;
        cout << "Enter Hours Worked: ";
        cin >> hoursWorked;
        employee = new PartTimeEmployee(name, employeeID, hourlyRate, hoursWorked);
    } else {
        cout << "Invalid choice! Please enter 1 for Full-Time or 2 for Part-Time." << endl;
    }

    if (employee != nullptr) {
        cout << "\nEmployee Details:\n";
        employee->displayDetails();
        cout << "Calculated Salary: $" << employee->calculateSalary() << endl;
        delete employee; // Clean up dynamically allocated memory
    }

    return 0;
}
