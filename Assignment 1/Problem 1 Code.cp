//
//  main.cpp
//  Assignment 1
//
//  Created by Vanessa Miranda on 3/16/24.
//

#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

double applyOperation(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0.0;
    }
}

string removeTrailingZeroes(string str) {
    size_t found = str.find_last_not_of('0');
    if (found != string::npos) {
        if (str[found] == '.')
            found--; // In case the last non-zero character is a decimal point
        str = str.substr(0, found + 1);
    }
    return str;
}

double evaluateExpression(string expression) {
    stack<double> values;
    stack<char> operators;
    stack<string> steps;

    for (size_t i = 0; i < expression.length(); i++) {
        if (expression[i] == ' ')
            continue;

        if (isdigit(expression[i])) {
            double num = 0;
            while (i < expression.length() && isdigit(expression[i]))
                num = num * 10 + (expression[i++] - '0');
            values.push(num);
            i--;
        }
        else if (expression[i] == '(')
            operators.push(expression[i]);
        else if (expression[i] == ')') {
            while (!operators.empty() && operators.top() != '(') {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
                steps.push(removeTrailingZeroes(to_string(a)) + " " + op + " " + removeTrailingZeroes(to_string(b)));
            }
            operators.pop();
        }
        else {
            while (!operators.empty() && precedence(operators.top()) >= precedence(expression[i])) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
                steps.push(removeTrailingZeroes(to_string(a)) + " " + op + " " + removeTrailingZeroes(to_string(b)));
            }
            operators.push(expression[i]);
        }
    }

    while (!operators.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(applyOperation(a, b, op));
        steps.push(removeTrailingZeroes(to_string(a)) + " " + op + " " + removeTrailingZeroes(to_string(b)));
    }

    cout << "Steps to solve the expression: ";
    while (!steps.empty()) {
        cout << steps.top();
        steps.pop();
        if (!steps.empty())
            cout << " -> ";
    }
    cout << endl;

    return values.top();
}

int main() {
    string expression;
    char choice;

    do {
        cout << "Enter an expression: ";
        getline(cin, expression);

        double result = evaluateExpression(expression);
        cout << "The problem answer is " << result << "." << endl;

        cout << "Do you want to evaluate another expression? (y/n): ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character from previous input
    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the calculator!" << endl;

    return 0;
}



