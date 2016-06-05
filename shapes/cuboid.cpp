#include<iomanip>

#include "cuboid.hpp"

Cuboid::Cuboid()
{}

Cuboid::Cuboid(Point points[2])
{
    for(size_t i = 0; i < 2; i++)
    {
        this->points[i] = points[i];
    }
}

Cuboid::~Cuboid()
{}

bool Cuboid::contains_point(const Point& p) const
{
    return p.x >= points[0].x && p.x <= points[1].x &&
           p.y >= points[0].y && p.y <= points[1].y &&
           p.z >= points[0].z && p.z <= points[1].z;
}

Shape* Cuboid::clone() const
{
    return new Cuboid(*this);
}

Point* Cuboid::get_points()
{
    return points;
}

const Point* Cuboid::get_points() const
{
    return points;
}

size_t Cuboid::get_point_count() const
{
    return Cuboid::POINT_COUNT;
}

const char* Cuboid::get_name() const
{
    return "cuboid";
}
