#include "shape.hpp"
#include <cmath>

using namespace std;


Point::Point() { x = 0; y = 0; };
Point::Point(double _x, double _y) : x(_x), y(_y) {};
Point::~Point() {};
double Point::GetX() { return x; }
double Point::GetY() { return y; }
void Point::SetX(double _x) { x = _x; }
void Point::SetY(double _y) { y = _y; }



double calculateDistance(Point p1, Point p2) {
	return sqrt(pow(p2.GetX() - p1.GetX(), 2) + pow(p2.GetY() - p1.GetY(), 2));
}



Shape::Shape() {};
Shape::~Shape() {};
double Shape::GetPerimeter() { return 0.0; }
double Shape::GetSquare() { return 0.0; }



Circle::Circle() = default;
Circle::Circle(Point& _centre, double _r) : r(_r), centre(_centre) {};
Circle::~Circle() {};

double Circle::GetPerimeter() { return 2 * M_PI * r; }
double Circle::GetSquare() { return M_PI * r * r; }



Rectangle::Rectangle() = default;
Rectangle::Rectangle(Point& _a, Point& _b, Point& _c) : a(_a), b(_b), c(_c)
{
	firstSide = calculateDistance(a, b);
	secondSide = calculateDistance(b, c);
};
Rectangle::~Rectangle() {};

double Rectangle::GetPerimeter() { return 2 * (firstSide + secondSide); }
double Rectangle::GetSquare() { return firstSide * secondSide; }



Triangle::Triangle() = default;
Triangle::Triangle(Point& _a, Point& _b, Point& _c) : a(_a), b(_b), c(_c)
{
	firstSide = calculateDistance(a, b);
	secondSide = calculateDistance(b, c);
	thirdSide = calculateDistance(c, a);

	if ((firstSide + secondSide <= thirdSide) ||
		(firstSide + thirdSide <= secondSide) ||
		(secondSide + thirdSide <= firstSide))
	{
		cout << "wrong triangle! he dont create";

	}
}
Triangle::~Triangle() {};

double Triangle::GetPerimeter() { return firstSide + secondSide + thirdSide; }
double Triangle::GetSquare()
{
	double p = (firstSide + secondSide + thirdSide) / 2.0;
	return sqrt(p * (p - firstSide) * (p - secondSide) * (p - thirdSide));
}

