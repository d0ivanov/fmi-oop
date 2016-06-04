#include<iomanip>
#include<istream>

#include "sphere.hpp"

Sphere::Sphere()
    : radious(0)
{}

Sphere::Sphere(const Point& p, double radious)
    : radious(radious)
{
    points[0] = p;
}

Sphere::~Sphere() {}

void Sphere::parse(std::istream& is)
{
    Shape::parse(is);
    is >> std::fixed >> std::setprecision(2) >> radious;
}

void Sphere::print(std::ostream& os) const
{
    Shape::print(os);
    os << std::fixed << std::setprecision(2) << radious;
}

bool Sphere::contains_point(const Point& p) const
{
    return ( (this->points[0].x - p.x) * (this->points[0].x - p.x) +
         (this->points[0].y - p.y) * (this->points[0].y - p.y) +
         (this->points[0].z - p.z) * (this->points[0].z - p.z) ) <= (radious * radious);
}

Shape* Sphere::clone() const
{
    return new Sphere(*this);
}

Point* Sphere::get_points()
{
    return points;
}

const Point* Sphere::get_points() const
{
    return points;
}

size_t Sphere::get_point_count() const
{
    return Sphere::POINT_COUNT;
}

const char* Sphere::get_name() const
{
    return "sphere";
}
