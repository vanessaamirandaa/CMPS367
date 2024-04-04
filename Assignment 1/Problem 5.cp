//
//  main.cpp
//  Assignment 1
//
//  Created by Vanessa Miranda on 3/16/24.
//
#include <iostream>
#include <cmath>

using namespace std;

// Function to perform addition
double add(double a, double b) {
    return a + b;
}

// Function to perform subtraction
double subtract(double a, double b) {
    return a - b;
}

// Function to perform multiplication
double multiply(double a, double b) {
    return a * b;
}

// Function to perform division
double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Error: Division by zero!" << endl;
        return NAN; // Not a Number
    }
}

// Function to perform modulus
int integerModulus(int a, int b) {
    if (b != 0) {
        return a % b;
    } else {
        cout << "Error: Modulus by zero!" << endl;
        return INT_MIN; // Minimum integer value
    }
}

// Function to perform exponentiation
double exponent(double base, double exponent) {
    return pow(base, exponent);
}

// Function to perform square root
double squareRoot(double value) {
    if (value >= 0) {
        return sqrt(value);
    } else {
        cout << "Error: Square root of a negative number!" << endl;
        return NAN;
    }
}

// Function to round to the nearest integer
double roundValue(double value) {
    return round(value);
}

int main() {
    char choice;
    do {
        char operand;
        double operand1, operand2;

        cout << "Enter the problem to solve (e.g., 5 + 3): ";
        cin >> operand1 >> operand >> operand2;

        double result;
        switch (operand) {
            case '+':
                result = add(operand1, operand2);
                break;
            case '-':
                result = subtract(operand1, operand2);
                break;
            case '*':
                result = multiply(operand1, operand2);
                break;
            case '/':
                result = divide(operand1, operand2);
                break;
            case '%':
                result = integerModulus(static_cast<int>(operand1), static_cast<int>(operand2));
                break;
            case '^':
                result = exponent(operand1, operand2);
                break;
            case 's':
                result = squareRoot(operand1);
                break;
            case 'r':
                result = roundValue(operand1);
                break;
            default:
                cout << "Invalid operand!" << endl;
                return 1;
        }

        cout << "Result: " << result << endl;

        cout << "Do you want to ask another question? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "Thank you for using the calculator!" << endl;

    return 0;
}


