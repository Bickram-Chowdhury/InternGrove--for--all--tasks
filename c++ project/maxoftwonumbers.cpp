#include <iostream>
using namespace std;

int main() {
    double num1, num2;

    // Prompt the user to enter two numbers
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Find the maximum of the two numbers
    double maxNumber = (num1 > num2) ? num1 : num2;

    // Display the result
    cout << "The maximum of the two numbers is: " << maxNumber << endl;

    return 0;
}
