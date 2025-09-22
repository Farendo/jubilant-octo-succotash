#include "shape.h"
#include <iostream>

using namespace std;


int main()
{
    Point a(1, 1);
    Point b(200, 200);
    Point c(1.5, 1.5);
    Triangle x(a, b, c);
    cout << x.GetSquare() << '\n' << x.GetPerimeter();
    return 0;
}