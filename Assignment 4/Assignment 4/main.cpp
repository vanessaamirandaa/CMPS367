//
//  main.cpp
//  Assignemtn 4
//
//  Created by Vanessa Miranda on 5/13/24.
//

#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265;

// Base Shape class
class Shape {
protected:
    double width, height;
public:
    Shape(double w, double h) : width(w), height(h) {}
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void display() const {
        cout << "Shape: ";
    }
};

// Rectangle class
class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : Shape(w, h) {}
    double area() const override {
        return width * height;
    }
    double perimeter() const override {
        return 2 * (width + height);
    }
    void display() const override {
        cout << "Shape: Rectangle";
    }
};

// Triangle class
class Triangle : public Shape {
public:
    Triangle(double w, double h) : Shape(w, h) {}
    double area() const override {
        return 0.5 * width * height;
    }
    double perimeter() const override {
        // Assuming this is a right triangle
        double hypotenuse = sqrt(width * width + height * height);
        return width + height + hypotenuse;
    }
    void display() const override {
        cout << "Shape: Triangle";
    }
};

// Circle class
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : Shape(0, 0), radius(r) {}
    double area() const override {
        return PI * radius * radius;
    }
    double perimeter() const override {
        return 2 * PI * radius;
    }
    void display() const override {
        cout << "Shape: Circle";
    }
};

// Square class
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : Shape(s, s), side(s) {}
    double area() const override {
        return side * side;
    }
    double perimeter() const override {
        return 4 * side;
    }
    void display() const override {
        cout << "Shape: Square";
    }
};

int main() {
    char choice;
    do {
        cout << "Welcome to the Shape Hierarchy!" << endl;
        cout << "Please use the CAPITALIZED first letter of the shape name" << endl;
        cout << "Choose a shape to calculate (R/T/C/S): ";
        cin >> choice;

        Shape *shape = nullptr;
        double dimension1, dimension2;

        switch (toupper(choice)) {
            case 'R':
                cout << "Enter width and height of the rectangle: ";
                cin >> dimension1 >> dimension2;
                shape = new Rectangle(dimension1, dimension2);
                break;
            case 'T':
                cout << "Enter base and height of the triangle: ";
                cin >> dimension1 >> dimension2;
                shape = new Triangle(dimension1, dimension2);
                break;
            case 'C':
                cout << "Enter radius of the circle: ";
                cin >> dimension1;
                shape = new Circle(dimension1);
                break;
            case 'S':
                cout << "Enter side length of the square: ";
                cin >> dimension1;
                shape = new Square(dimension1);
                break;
            default:
                cerr << "Invalid choice!";
                return 1;
        }

        if (shape) {
            shape->display();
            cout << "\nArea: " << shape->area() << endl;
            cout << "Perimeter: " << shape->perimeter() << endl;
            delete shape;
        }

        cout << "Do you want to perform another calculation? (Y/N): " ;
        cin >> choice;
    } while (toupper(choice) == 'Y');
        
    cout << "Thank you for using the Shape Heirarchy Calculator! " << endl;
    return 0;
}
