//
//  main.cpp
//  Assignment 2
//
//  Created by Vanessa Miranda on 5/20/24.
//
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Define a struct to group all user data variables
struct UserData {
    string name;
    string gender;
    int age;
    int heightFeet;
    int heightInches;
    int weightPounds;
    int heightInInches;
    double bmi;
};

int main() {
    UserData user; // Create an instance of the UserData struct

    // Ask the user questions
    cout << "Please enter your name: ";
    getline(cin, user.name);

    cout << "Please enter your age: ";
    cin >> user.age;

    cout << "Please enter your gender: ";
    cin >> user.gender;

    cout << "Please enter your height in feet: ";
    cin >> user.heightFeet;

    cout << "Please enter your height in inches: ";
    cin >> user.heightInches;

    cout << "Please enter your weight in pounds: ";
    cin >> user.weightPounds;

    // Calculate
    user.heightInInches = user.heightFeet * 12 + user.heightInches;
    user.bmi = 103.0 * user.weightPounds / pow(user.heightInInches, 2);

    // Output results
    cout << "\nHi " << user.name << ",\n";
    cout << "You are a " << user.gender << ". You are " << user.age << " years old. ";
    cout << "You are currently " << user.heightFeet << "' " << user.heightInches << "\"";
    cout << " and you currently weigh " << user.weightPounds << " pounds.\n";
    cout << "Your BMI is " << user.bmi << ", which is ";

    if (user.bmi < 18.5)
        cout << "Underweight.";
    else if (user.bmi < 24.9)
        cout << "Normal weight.";
    else if (user.bmi < 29.9)
        cout << "Overweight.";
    else
        cout << "Obese.";

    cout << "\n\nThank you for using the BMI Calculator!\n";

    return 0;
}

