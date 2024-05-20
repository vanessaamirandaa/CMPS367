//
//  main.cpp
//  Final
//
//  Created by Vanessa Miranda on 5/19/24.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

// Function to perform a recursive bubble sort
void recursiveBubbleSort(int arr[], int n) {
    // Base case
    if (n == 1)
        return;

    // One pass of bubble sort
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

    // Largest element is fixed, recur for remaining array
    recursiveBubbleSort(arr, n - 1);
}

// Function to calculate average score
double calculateAverage(int arr[], int n, int pointsPossible) {
    int totalScore = 0;
    for (int i = 0; i < n; i++) {
        totalScore += arr[i];
    }
    return ((totalScore * 100.0) / (n * pointsPossible));
}

// Function to find the minimum score
int findMinScore(int arr[], int n) {
    return *min_element(arr, arr + n);
}

// Function to find the maximum score
int findMaxScore(int arr[], int n) {
    return *max_element(arr, arr + n);
}

int main() {
    string courseDept, courseNum, courseName, assignmentName;
    int pointsPossible, numStudents;

    cout << "Welcome to Grade Calculator!" << endl;
    cout << "Enter the course dept: ";
    cin >> courseDept;
    cout << "Enter the course number: ";
    cin >> courseNum;
    cin.ignore(); // To ignore newline character after course number input
    cout << "Enter the course name: ";
    getline(cin, courseName);
    cout << "Enter the name of the assignment: ";
    getline(cin, assignmentName);
    cout << "Enter points possible: ";
    cin >> pointsPossible;
    cout << "Enter the number of students that will be scored: ";
    cin >> numStudents;

    int *scores = new int[numStudents];
    for (int i = 0; i < numStudents; i++) {
        cout << "Enter the score for student " << i + 1 << ": ";
        cin >> scores[i];
    }

    // Sort scores using recursive bubble sort
    recursiveBubbleSort(scores, numStudents);

    // Calculate average, min, and max scores
    double averageScore = calculateAverage(scores, numStudents, pointsPossible);
    int minScore = findMinScore(scores, numStudents);
    int maxScore = findMaxScore(scores, numStudents);

    // Output results
    cout << "\nCourse: " << courseDept << " " << courseNum << ": " << courseName << endl;
    cout << "Scores: ";
    for (int i = 0; i < numStudents; i++) {
        cout << scores[i] << " ";
    }
    cout << "\nAverage: " << fixed << setprecision(2) << averageScore << "%" << endl;
    cout << "Lowest Score: " << minScore << endl;
    cout << "Highest Score: " << maxScore << endl;

    cout << "Thank you for using the grade calculator!" << endl;

    // Clean up dynamically allocated memory
    delete[] scores;

    return 0;
}
