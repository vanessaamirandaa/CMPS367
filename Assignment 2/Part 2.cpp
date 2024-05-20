//
//  main.cpp
//  Assignment 2
//
//  Created by Vanessa Miranda on 5/20/24.
//
#include <iostream>
#include <string>

using namespace std;

// Define a struct to group all input variables
struct Birthday {
    int month;
    int day;
    int year;
};

// Function to display the meaning of the month
void displayMonthMeaning(int month) {
    switch(month) {
        case 1:
            cout << "The month of January means Janus" << endl;
            break;
        case 2:
            cout << "The month of February means Februalia" << endl;
            break;
        case 3:
            cout << "The month of March means Mars" << endl;
            break;
        case 4:
            cout << "The month of April means Aperire" << endl;
            break;
        case 5:
            cout << "The month of May means Maia" << endl;
            break;
        case 6:
            cout << "The month of June means Youth" << endl;
            break;
        case 7:
            cout << "The month of July means Julius Caesar" << endl;
            break;
        case 8:
            cout << "The month of August means Augustus Caesar" << endl;
            break;
        case 9:
            cout << "The month of September means Seven" << endl;
            break;
        case 10:
            cout << "The month of October means Eight" << endl;
            break;
        case 11:
            cout << "The month of November means Nine" << endl;
            break;
        case 12:
            cout << "The month of December means Ten" << endl;
            break;
        default:
            cout << "Invalid month" << endl;
    }
}

// Function to display the meaning of the day
void displayDayMeaning(int day) {
    switch(day) {
        case 1:
            cout << "The 1st day of the month means Self-Started" << endl;
            break;
        case 2:
            cout << "The 2nd day of the month means Determination" << endl;
            break;
        case 3:
            cout << "The 3rd day of the month means Expression" << endl;
            break;
        case 4:
            cout << "The 4th day of the month means Stability" << endl;
            break;
        case 5:
            cout << "The 5th day of the month means Flexibility" << endl;
            break;
        case 6:
            cout << "The 6th day of the month means Nurturer" << endl;
            break;
        case 7:
            cout << "The 7th day of the month means Refined Mind" << endl;
            break;
        case 8:
            cout << "The 8th day of the month means Success" << endl;
            break;
        case 9:
            cout << "The 9th day of the month means Compassionate" << endl;
            break;
        case 10:
            cout << "The 10th day of the month means Leadership" << endl;
            break;
        case 11:
            cout << "The 11th day of the month means Awareness" << endl;
            break;
        case 12:
            cout << "The 12th day of the month means Creativity" << endl;
            break;
        case 13:
            cout << "The 13th day of the month means Conscientious" << endl;
            break;
        case 14:
            cout << "The 14th day of the month means Open-Minded" << endl;
            break;
        case 15:
            cout << "The 15th day of the month means Powerful Love" << endl;
            break;
        case 16:
            cout << "The 16th day of the month means Inquisitive Mind" << endl;
            break;
        case 17:
            cout << "The 17th day of the month means Quality" << endl;
            break;
        case 18:
            cout << "The 18th day of the month means Open-Minded and Open-Hearted" << endl;
            break;
        case 19:
            cout << "The 19th day of the month means Independence" << endl;
            break;
        case 20:
            cout << "The 20th day of the month means Relatability" << endl;
            break;
        case 21:
            cout << "The 21st day of the month means Socialable" << endl;
            break;
        case 22:
            cout << "The 22nd day of the month means Power of Creativity" << endl;
            break;
        case 23:
            cout << "The 23rd day of the month means Expression" << endl;
            break;
        case 24:
            cout << "The 24th day of the month means Eager" << endl;
            break;
        case 25:
            cout << "The 25th day of the month means Heart of Gold" << endl;
            break;
        case 26:
            cout << "The 26th day of the month means Desire to Succeed" << endl;
            break;
        case 27:
            cout << "The 27th day of the month means Compassionate" << endl;
            break;
        case 28:
            cout << "The 28th day of the month means Capable and Compassionate" << endl;
            break;
        case 29:
            cout << "The 29th day of the month means Togetherness" << endl;
            break;
        case 30:
            cout << "The 30th day of the month means Innovation" << endl;
            break;
        case 31:
            cout << "The 31st day of the month means Organization" << endl;
            break;
        // Add more cases as needed
        default:
            cout << "The " << day << "th day of the month means Something Special" << endl;
            break;
    }
}

// Function to display the meaning of the year
void displayYearMeaning(int year) {
    switch(year) {
        case 2000:
            cout << "The year 2000 means that you are moody and overconfident." << endl;
            break;
        case 2001:
            cout << "The year 2001 means that you are energy and passionate." << endl;
            break;
        case 2002:
            cout << "The year 2002 means that you are the center of attention and need discipline." << endl;
            break;
        case 2003:
            cout << "The year 2003 means that you worry and have a need for control." << endl;
            break;
        case 2004:
            cout << "The year 2004 means that you are strong-willed, intelligent, and creative." << endl;
            break;
        case 2005:
            cout << "The year 2005 means that you are honest, intelligent, and ambitious." << endl;
            break;
        case 2006:
            cout << "The year 2006 means that you are straightforward in thought and speech." << endl;
            break;
        case 2007:
            cout << "The year 2007 means that you are honest and appreciative of friendship." << endl;
            break;
        case 2008:
            cout << "The year 2008 means that you are easygoing and adaptable." << endl;
            break;
        case 2009:
            cout << "The year 2009 means that you are silent and hardworking." << endl;
            break;
        case 2010:
            cout << "The year 2010 means that you have a tendency to resist authority and want to do your own thing." << endl;
            break;
        case 2011:
            cout << "The year 2011 means that you are overly sensitive." << endl;
            break;
        case 2012:
            cout << "The year 2012 means that you are impatient." << endl;
            break;
        case 2013:
            cout << "The year 2013 means that you are energetic." << endl;
            break;
        case 2014:
            cout << "The year 2014 means that you desire a high-profile career and love to be surrounded by admirers." << endl;
            break;
        case 2015:
            cout << "The year 2015 means that you are of strong faith." << endl;
            break;
        case 2016:
            cout << "The year 2016 means that you are gentle, warm, and trustworthy." << endl;
            break;
        case 2017:
            cout << "The year 2017 means that you are faithful, smart, and caring." << endl;
            break;
        case 2018:
            cout << "The year 2018 means that you are moody and overconfident." << endl;
            break;
        case 2019:
            cout << "The year 2019 means that you are energy and passionate." << endl;
            break;
        case 2020:
            cout << "The year 2020 means that you are timid." << endl;
            break;
        case 2021:
            cout << "The year 2021 means that you are passionate." << endl;
            break;
        case 2022:
            cout << "The year 2022 means that you are overly anxious." << endl;
            break;
        case 2023:
            cout << "The year 2023 means that you are faithful." << endl;
            break;
        // Add more
        default:
            cout << "The year " << year << " means something special!" << endl;
            break;
    }
}

int main() {
    cout << "Welcome to Birthday Generator!" << endl;
    char choice = '\0';
    Birthday birthday; // Create an instance of the Birthday struct

    do {
        // Input month
        cout << "Enter your birth month (1-12): ";
        cin >> birthday.month;

        // Input day
        cout << "Enter your birth day: ";
        cin >> birthday.day;

        // Input year
        cout << "Enter your birth year (2000-2023): ";
        cin >> birthday.year;

        // Validate inputs
        if (birthday.month < 1 || birthday.month > 12 || birthday.day < 1 || birthday.day > 31 || birthday.year < 2000 || birthday.year > 2023) {
            cout << "Invalid input! Please enter valid values." << endl;
            continue;
        }

        // Display meanings
        displayMonthMeaning(birthday.month);
        displayDayMeaning(birthday.day);
        displayYearMeaning(birthday.year);

        // Ask if the user wants to try another one
        cout << "Do you want to generate another birthday? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "Thanks for using the Birthday Generator!" << endl;

    return 0;
}

