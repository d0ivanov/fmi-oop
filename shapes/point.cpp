#include "point.hpp"

Point::Point(double x, double y, double z)
    : x(x),
      y(y),
      z(z)
{}

Point::Point()
    : x(0.0),
      y(0.0),
      z(0.0)
{}

Point& Point::operator+=(Point& other)
{
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

Point& Point::operator*=(double scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}


std::istream& operator>>(std::istream& istr, Point& p)
{
    istr >> std::fixed >> std::setprecision(2) >> p.x;
    istr >> std::fixed >> std::setprecision(2) >> p.y;
    istr >> std::fixed >> std::setprecision(2) >> p.z;

    return istr;
}

std::ostream& operator<<(std::ostream& ostr, const Point& p)
{
    ostr <<  p.x << " " <<  p.y << " " <<  p.z;

    return ostr;
}
