//
//  main.cpp
//  Assignment 2
//
//  Created by Vanessa Miranda on 5/20/24.
//

#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

// Define a struct to group all related variables for expression evaluation
struct ExpressionData {
    stack<double> values;
    stack<char> operators;
    stack<string> steps;
    string expression;
};

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

double evaluateExpression(ExpressionData &data) {
    for (size_t i = 0; i < data.expression.length(); i++) {
        if (data.expression[i] == ' ')
            continue;

        if (isdigit(data.expression[i])) {
            double num = 0;
            while (i < data.expression.length() && isdigit(data.expression[i]))
                num = num * 10 + (data.expression[i++] - '0');
            data.values.push(num);
            i--;
        }
        else if (data.expression[i] == '(')
            data.operators.push(data.expression[i]);
        else if (data.expression[i] == ')') {
            while (!data.operators.empty() && data.operators.top() != '(') {
                double b = data.values.top(); data.values.pop();
                double a = data.values.top(); data.values.pop();
                char op = data.operators.top(); data.operators.pop();
                data.values.push(applyOperation(a, b, op));
                data.steps.push(removeTrailingZeroes(to_string(a)) + " " + op + " " + removeTrailingZeroes(to_string(b)));
            }
            data.operators.pop();
        }
        else {
            while (!data.operators.empty() && precedence(data.operators.top()) >= precedence(data.expression[i])) {
                double b = data.values.top(); data.values.pop();
                double a = data.values.top(); data.values.pop();
                char op = data.operators.top(); data.operators.pop();
                data.values.push(applyOperation(a, b, op));
                data.steps.push(removeTrailingZeroes(to_string(a)) + " " + op + " " + removeTrailingZeroes(to_string(b)));
            }
            data.operators.push(data.expression[i]);
        }
    }

    while (!data.operators.empty()) {
        double b = data.values.top(); data.values.pop();
        double a = data.values.top(); data.values.pop();
        char op = data.operators.top(); data.operators.pop();
        data.values.push(applyOperation(a, b, op));
        data.steps.push(removeTrailingZeroes(to_string(a)) + " " + op + " " + removeTrailingZeroes(to_string(b)));
    }

    cout << "Steps to solve the expression: ";
    while (!data.steps.empty()) {
        cout << data.steps.top();
        data.steps.pop();
        if (!data.steps.empty())
            cout << " -> ";
    }
    cout << endl;

    return data.values.top();
}

int main() {
    ExpressionData data;
    char choice;

    do {
        cout << "Enter an expression: ";
        getline(cin, data.expression);

        double result = evaluateExpression(data);
        cout << "The problem answer is " << result << "." << endl;

        cout << "Do you want to evaluate another expression? (y/n): ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character from previous input

        // Clear the stacks for the next expression
        while (!data.values.empty()) data.values.pop();
        while (!data.operators.empty()) data.operators.pop();
        while (!data.steps.empty()) data.steps.pop();

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the calculator!" << endl;

    return 0;
}
