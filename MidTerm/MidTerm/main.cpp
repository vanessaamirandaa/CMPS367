//
//  main.cpp
//  MidTerm
//
//  Created by Vanessa Miranda on 4/17/24.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

struct BankAccount {
    string name;
    double balance;
    int accountNumber;
};

const int MAX_ACCOUNTS = 100;
BankAccount accounts[MAX_ACCOUNTS];
int numAccounts = 0;

// Function prototypes
void createAccount();
void deposit();
void withdraw();
void displayBalance();

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int choice;

    cout << "Welcome to Chase" << endl;

    do {
        cout << "Type a number that you would like to perform:" << endl;
        cout << "1. Create a new bank account" << endl;
        cout << "2. Deposit money into an account" << endl;
        cout << "3. Withdraw money from an account" << endl;
        cout << "4. Display the current balance of an account" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                displayBalance();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}

void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        cout << "Maximum number of accounts reached." << endl;
        return;
    }

    BankAccount newAccount;
    cout << "Enter your name: ";
    cin >> newAccount.name;
    cout << "Enter initial balance: ";
    cin >> newAccount.balance;

    newAccount.accountNumber = rand() % 10000 + 1000; // Generate random account number
    accounts[numAccounts++] = newAccount;

    cout << "Account created successfully." << endl;
    cout << "Account Number: " << newAccount.accountNumber << endl;
    cout << "Balance: $" << newAccount.balance << endl;
    cout << "Press any key to return to Main Menu." << endl;
    cin.ignore(); // Clear input buffer
    cin.get(); // Wait for user to press any key
}

void deposit() {
    int accountNumber;
    cout << "Enter your account number: ";
    cin >> accountNumber;

    int index = -1;
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountNumber == accountNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Account not found." << endl;
    } else {
        double depositAmount;
        cout << "Enter the amount you want to deposit: $";
        cin >> depositAmount;
        accounts[index].balance += depositAmount;
        cout << "Deposit successful." << endl;
        cout << "New balance: $" << accounts[index].balance << endl;
    }
    cout << "Press any key to return to Main Menu." << endl;
    cin.ignore();
    cin.get();
}

void withdraw() {
    int accountNumber;
    cout << "Enter your account number: ";
    cin >> accountNumber;

    int index = -1;
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountNumber == accountNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Account not found." << endl;
    } else {
        double withdrawAmount;
        cout << "Enter the amount you want to withdraw: $";
        cin >> withdrawAmount;
        if (withdrawAmount > accounts[index].balance) {
            cout << "Insufficient funds." << endl;
        } else {
            accounts[index].balance -= withdrawAmount;
            cout << "Withdrawal successful." << endl;
            cout << "New balance: $" << accounts[index].balance << endl;
        }
    }
    cout << "Press any key to return to Main Menu." << endl;
    cin.ignore();
    cin.get();
}

void displayBalance() {
    int accountNumber;
    cout << "Enter your account number: ";
    cin >> accountNumber;

    int index = -1;
    for (int i = 0; i < numAccounts; ++i) {
        if (accounts[i].accountNumber == accountNumber) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Account not found." << endl;
    } else {
        cout << "Current balance: $" << accounts[index].balance << endl;
    }
    cout << "Press any key to return to Main Menu." << endl;
    cin.ignore();
    cin.get();
}
