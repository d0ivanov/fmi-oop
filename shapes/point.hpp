#ifndef __POINT_HPP__
#define __POINT_HPP__

#include<istream>
#include<ostream>
#include<iomanip>

struct Point
{
    double x, y, z;

    Point(double, double, double);
    Point();

    Point& operator+=(Point& other);
    Point& operator*=(double scalar);
};

std::istream& operator>>(std::istream&, Point&);
std::ostream& operator<<(std::ostream&, const Point&);

#endif
