//
//  main.cpp
//  Assignment 1
//
//  Created by Vanessa Miranda on 3/16/24.
//
#include <iostream>

using namespace std;

int main() {
    char createAnother;

    do {
        int startRange, endRange, startMultiplier, endMultiplier;

        // Get user input for the starting and ending range of the multiplication table
        cout << "Enter the starting range for Multiplication Table: ";
        cin >> startRange;

        cout << "Enter the ending range for Multiplication Table: ";
        cin >> endRange;

        // Get user input for the starting and ending range of the multipliers
        cout << "Enter the starting range for multiplying the numbers in Multiplication Table: ";
        cin >> startMultiplier;

        cout << "Enter the ending range for multiplying the numbers in Multiplication Table: ";
        cin >> endMultiplier;

        // Display the multiplication table
        cout << "Here is the multiplication table for " << startRange << " to " << endRange << " in the range of "
             << startMultiplier << " to " << endMultiplier << endl;

        // Display the table headers
        cout << "X ";
        for (int i = startMultiplier; i <= endMultiplier; ++i) {
            cout << i << " ";
        }
        cout << endl;

        // Display the multiplication table
        for (int i = startRange; i <= endRange; ++i) {
            cout << i << " ";
            for (int j = startMultiplier; j <= endMultiplier; ++j) {
                cout << i * j << " ";
            }
            cout << endl;
        }

        // Ask the user if they want to create another multiplication table
        cout << "Do you want to create another multiplication table? (y/n): ";
        cin >> createAnother;

    } while (createAnother == 'y' || createAnother == 'Y');

    cout << "Thank you for using the multiplication table generator. Exiting program." << endl;

    return 0;
}
