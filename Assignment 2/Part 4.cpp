//
//  main.cpp
//  Assignment 2
//
//  Created by Vanessa Miranda on 5/20/24.
//
#include <iostream>

using namespace std;

// Define a struct to group all related variables
struct MultiplicationTableData {
    int startRange;
    int endRange;
    int startMultiplier;
    int endMultiplier;
    char createAnother;
};

int main() {
    MultiplicationTableData tableData; // Create an instance of the struct

    do {
        // Get user input for the starting and ending range of the multiplication table
        cout << "Enter the starting range for Multiplication Table: ";
        cin >> tableData.startRange;

        cout << "Enter the ending range for Multiplication Table: ";
        cin >> tableData.endRange;

        // Get user input for the starting and ending range of the multipliers
        cout << "Enter the starting range for multiplying the numbers in Multiplication Table: ";
        cin >> tableData.startMultiplier;

        cout << "Enter the ending range for multiplying the numbers in Multiplication Table: ";
        cin >> tableData.endMultiplier;

        // Display the multiplication table
        cout << "Here is the multiplication table for " << tableData.startRange << " to " << tableData.endRange
             << " in the range of " << tableData.startMultiplier << " to " << tableData.endMultiplier << endl;

        // Display the table headers
        cout << "X ";
        for (int i = tableData.startMultiplier; i <= tableData.endMultiplier; ++i) {
            cout << i << " ";
        }
        cout << endl;

        // Display the multiplication table
        for (int i = tableData.startRange; i <= tableData.endRange; ++i) {
            cout << i << " ";
            for (int j = tableData.startMultiplier; j <= tableData.endMultiplier; ++j) {
                cout << i * j << " ";
            }
            cout << endl;
        }

        // Ask the user if they want to create another multiplication table
        cout << "Do you want to create another multiplication table? (y/n): ";
        cin >> tableData.createAnother;

    } while (tableData.createAnother == 'y' || tableData.createAnother == 'Y');

    cout << "Thank you for using the multiplication table generator. Exiting program." << endl;

    return 0;
}

