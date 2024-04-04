//
//  main.cpp
//  Assignment 1
//
//  Created by Vanessa Miranda on 3/16/24.
//
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string name, gender;
    int age, heightFeet, heightInches, weightPounds;
    
    // Ask the user questions
    cout << "Please enter your name: ";
    getline(cin, name);
    
    cout << "Please enter your age: ";
    cin >> age;
    
    cout << "Please enter your gender: ";
    cin >> gender;
    
    cout << "Please enter your height in feet: ";
    cin >> heightFeet;
    
    cout << "Please enter your height in inches: ";
    cin >> heightInches;
    
    cout << "Please enter your weight in pounds: ";
    cin >> weightPounds;
    
    // Calculate
    int heightInInches = heightFeet * 12 + heightInches;
    double bmi = 103.0 * weightPounds / pow(heightInches, 2);
    
    // Output results
    cout << "\nHi " << name << ",\n";
    cout << "You are a " << gender << ". You are " << age << " years old. ";
    cout << "You are currently " << heightFeet << " ' " << heightInches << "\"";
    cout << " and you currently weight " << weightPounds << " punds.\n";
    cout << "Your BMI is " << bmi << ", which is ";
    
    if (bmi < 18.5)
        cout << "Underweight.";
    else if (bmi < 24.9)
        cout << "Normal weight.";
    else if (bmi < 29.9)
        cout << "Overweight.";
    else
        cout << "Obese.";
    
    cout << "\n\nThank you for using the BMI Calculator!\n";
    
    return 0;
    
}
