//
//  main.cpp
//  Assignment 2
//
//  Created by Vanessa Miranda on 5/20/24.
//
#include <iostream>
#include <cmath>

using namespace std;

// Define a struct to group all related variables
struct CalculatorData {
    char choice;
    char operation;
    double num1;
    double num2;
    double result;
};

int main() {
    CalculatorData calcData; // Create an instance of the struct
    calcData.choice = 'y'; // Initialize choice to 'y' to enter the loop at least once

    while (calcData.choice == 'y' || calcData.choice == 'Y') {
        cout << "Welcome to the Calculator !" << endl;
        cout << "To use the calculator, use the following: +, -, *, /, ^, s for sine, c for cosine, t for tangent, l for logarithm, n for natural logarithm, e for exponential, a for arcsine, b for arccosine, g for arctangent, or type 'eq' for equation " << endl;
        cout << "Enter operation: ";
        cin >> calcData.operation;

        if (calcData.operation == '+' || calcData.operation == '-' || calcData.operation == '*' || calcData.operation == '/' || calcData.operation == '^' || calcData.operation == 'l') {
            cout << "Enter two operands: ";
            cin >> calcData.num1 >> calcData.num2;
        }
        else if (calcData.operation == 's' || calcData.operation == 'c' || calcData.operation == 't' || calcData.operation == 'n' || calcData.operation == 'e' || calcData.operation == 'a' || calcData.operation == 'b' || calcData.operation == 'g') {
            cout << "Enter angle in radians: ";
            cin >> calcData.num1;
        }
        else if (calcData.operation == 'eq') {
            cout << "Enter equation: ";
            // Code to handle equation input can be added here
            // For simplicity, let's just print a message
            cout << "Equation input is not implemented in this version." << endl;
            continue;
        }
        else {
            cout << "Invalid operation." << endl;
            return 1;
        }

        switch(calcData.operation) {
            case '+':
                calcData.result = calcData.num1 + calcData.num2;
                break;
            case '-':
                calcData.result = calcData.num1 - calcData.num2;
                break;
            case '*':
                calcData.result = calcData.num1 * calcData.num2;
                break;
            case '/':
                if (calcData.num2 != 0)
                    calcData.result = calcData.num1 / calcData.num2;
                else {
                    cout << "Division by zero error." << endl;
                    return 1;
                }
                break;
            case '^':
                calcData.result = pow(calcData.num1, calcData.num2);
                break;
            case 's':
                calcData.result = sin(calcData.num1);
                break;
            case 'c':
                calcData.result = cos(calcData.num1);
                break;
            case 't':
                calcData.result = tan(calcData.num1);
                break;
            case 'l':
                calcData.result = log10(calcData.num1);
                break;
            case 'n':
                calcData.result = log(calcData.num1);
                break;
            case 'e':
                calcData.result = exp(calcData.num1);
                break;
            case 'a':
                calcData.result = asin(calcData.num1);
                break;
            case 'b':
                calcData.result = acos(calcData.num1);
                break;
            case 'g':
                calcData.result = atan(calcData.num1);
                break;
            default:
                cout << "Invalid operation." << endl;
                return 1;
        }

        cout << "Result: " << calcData.result << endl;

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> calcData.choice;
    }

    cout << "Thank you for using my calculator!" << endl;

    return 0;
}

