#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    // Constructor to initialize the balance
    BankAccount(double initialBalance = 0.0) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            cout << "Initial balance can't be negative. Setting balance to 0." << endl;
            balance = 0.0;
        }
    }

    // Function to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // Function to withdraw money from the account
    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                cout << "Withdrawn: $" << amount << endl;
            } else {
                cout << "Insufficient funds. Withdrawal failed." << endl;
            }
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }

    // Function to check the current balance
    double checkBalance() const {
        return balance;
    }
};

int main() {
    double initialBalance;
    cout << "Enter the initial balance for your account: $";
    cin >> initialBalance;

    BankAccount myAccount(initialBalance);

    int choice;
    double amount;

    do {
        cout << "\nBank Account Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                myAccount.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                myAccount.withdraw(amount);
                break;
            case 3:
                cout << "Current balance: $" << myAccount.checkBalance() << endl;
                break;
            case 4:
                cout << "Exiting the program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
