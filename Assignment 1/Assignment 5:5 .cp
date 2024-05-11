//
//  main.cpp
//  Assignment 1
//
//  Created by Vanessa Miranda on 3/16/24.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char choice = 'y'; // Initialize choice to 'y' to enter the loop at least once
    while (choice == 'y' || choice == 'Y') {
        char operation;
        double num1, num2, result;

        cout << "Welcome to the Calculator !" << endl;
        cout << "To use the calculator, use the following: +, -, *, /, ^, s for sine, c for cosine, t for tangent, l for logarithm, n for natural logarithm, e for exponential, a for arcsine, b for arccosine, g for arctangent, or type 'eq' for equation " << endl;
        cout << "Enter operation: ";
        cin >> operation;

        if (operation == '+' || operation == '-' || operation == '*' || operation == '/' || operation == '^' || operation == 'l') {
            cout << "Enter two operands: ";
            cin >> num1 >> num2;
        }
        else if (operation == 's' || operation == 'c' || operation == 't' || operation == 'n' || operation == 'e' || operation == 'a' || operation == 'b' || operation == 'g') {
            cout << "Enter angle in radians: ";
            cin >> num1;
        }
        else if (operation == 'eq') {
            cout << "Enter equation: ";
            // Code to handle equation input can be added here
            // For simplicity, let's just print a message
            cout << "Equation input is not implemented in this version." << endl;
            continue;
        }
        else {
            cout << "Invalid operation.";
            return 1;
        }

        switch(operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0)
                    result = num1 / num2;
                else {
                    cout << "Division by zero error.";
                    return 1;
                }
                break;
            case '^':
                result = pow(num1, num2);
                break;
            case 's':
                result = sin(num1);
                break;
            case 'c':
                result = cos(num1);
                break;
            case 't':
                result = tan(num1);
                break;
            case 'l':
                result = log10(num1);
                break;
            case 'n':
                result = log(num1);
                break;
            case 'e':
                result = exp(num1);
                break;
            case 'a':
                result = asin(num1);
                break;
            case 'b':
                result = acos(num1);
                break;
            case 'g':
                result = atan(num1);
                break;
            default:
                cout << "Invalid operation.";
                return 1;
        }

        cout << "Result: " << result << endl;

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using my calculator!" << endl;

    return 0;
}
