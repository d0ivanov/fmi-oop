#include "shape.hpp"

Shape::Shape() {}

Shape::~Shape() {}

void Shape::print(std::ostream& os) const
{
    const Point* points = get_points();
    size_t point_count = get_point_count();

    os << get_name() << " ";
    for(size_t i = 0; i < point_count; i++)
    {
        os << std::fixed << std::setprecision(2) << points[i] << " ";
    }
}

void Shape::parse(std::istream& is)
{
    Point* points = get_points();
    size_t point_count = get_point_count();

    for(size_t i = 0; i < point_count; i++)
    {
        is >> std::fixed >> std::setprecision(2) >> points[i];
    }
}

void Shape::scale(Point& p, double scalar)
{
    Point* points = get_points();
    size_t point_count = get_point_count();

    for(size_t i = 0; i < point_count; i++)
    {
        points[i] *= scalar;
        points[i] += p;
    }
}

std::ostream& operator<<(std::ostream& os, const Shape& shape)
{

    shape.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Shape& shape)
{
    shape.parse(is);
    return is;
}
