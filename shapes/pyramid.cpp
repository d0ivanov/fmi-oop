#include<iomanip>

#include "pyramid.hpp"

Pyramid::Pyramid()
{}

Pyramid::Pyramid(Point points[4])
{
    for(size_t i = 0; i < Pyramid::POINT_COUNT; i++)
    {
        this->points[i] = points[i];
    }
}

Pyramid::~Pyramid()
{}


bool Pyramid::contains_point(const Point& p) const
{
    return true;
}

Shape* Pyramid::clone() const
{
    return new Pyramid(*this);
}

Point* Pyramid::get_points()
{
   return this->points;
}

const Point* Pyramid::get_points() const
{
    return points;
}

size_t Pyramid::get_point_count() const
{
    return Pyramid::POINT_COUNT;
}

const char* Pyramid::get_name() const
{
    return "pyramid";
}
