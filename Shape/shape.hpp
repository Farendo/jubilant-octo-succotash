#pragma once
#include <iostream>


struct Point {
    Point();
    Point(double _x, double _y);
    ~Point();

    double GetX();
    double GetY();
    void SetX(double _x);
    void SetY(double _y);

private:
    double x;
    double y;
};

double calculateDistance(Point p1, Point p2);

class Shape {
public:
    Shape();
    virtual ~Shape();

    virtual double GetPerimeter() = 0;
    virtual double GetSquare() = 0;
};

class Circle : public Shape {
private:
    Point centre;
    double r = 0;

public:
    Circle();
    Circle(Point& _centre, double _r);
    ~Circle();

    double GetPerimeter() override;
    double GetSquare() override;
};

class Rectangle : public Shape {
protected:
    Point a, b, c;
    double firstSide = 0.0, secondSide = 0.0;

public:
    Rectangle();
    Rectangle(Point& _a, Point& _b, Point& _c);
    ~Rectangle();

    double GetPerimeter() override;
    double GetSquare() override;
};

class Triangle : public Shape {
protected:
    Point a, b, c;
    double firstSide = 0.0, secondSide = 0.0, thirdSide = 0.0;

public:
    Triangle();
    Triangle(Point& _a, Point& _b, Point& _c);
    ~Triangle();

    double GetPerimeter() override;
    double GetSquare() override;
};

