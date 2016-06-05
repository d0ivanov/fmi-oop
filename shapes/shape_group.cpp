#include<cstring>

#include "shape_group.hpp"

ShapeGroup::ShapeGroup(const Parser& parser)
    : parser(parser)
{}

ShapeGroup::ShapeGroup(const ShapeGroup& other)
    : shapes(other.shapes),
      parser(other.parser)
{}

ShapeGroup::~ShapeGroup()
{}

void ShapeGroup::print(std::ostream& ostr) const
{
    for(size_t i = 0; i < shapes.get_len(); i++)
    {
        ostr << *shapes[i] << std::endl;
    }
}

void ShapeGroup::parse(std::istream& is)
{
    Point p;
    double scalar;
    is >> p;
    is >> scalar;

    shapes = parser.parse(is);

    for(size_t i = 0; i < shapes.get_len(); i++)
    {
        shapes[i]->scale(p, scalar);
    }
}

void ShapeGroup::scale(Point& point, double scalar)
{
    for(size_t i = 0; i < shapes.get_len(); i++)
    {
        shapes[i]->scale(point, scalar);
    }
}

bool ShapeGroup::contains_point(const Point& point) const
{
    for(size_t i = 0; i < shapes.get_len(); i++)
    {
        if(shapes[i]->contains_point(point))
        {
            return true;
        }
    }
    return false;
}

Shape* ShapeGroup::clone() const
{
    return new ShapeGroup(*this);
}

Point* ShapeGroup::get_points()
{
    return NULL;
}

const Point* ShapeGroup::get_points() const
{
    return NULL;
}

size_t ShapeGroup::get_point_count() const
{
    return 0;
}

const char* ShapeGroup::get_name() const
{
    return "group";
}
