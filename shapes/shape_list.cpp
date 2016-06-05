#include<stdexcept>

#include "shape_list.hpp"
#include<iostream>
using namespace std;

ShapeList::ShapeList()
    : len(0),
      cap(16)
{
    shapes = new Shape*[cap];
}

ShapeList::ShapeList(const ShapeList& other)
    : len(other.len),
      cap(other.cap)
{
    shapes = new Shape*[cap];

    for(size_t i = 0; i < len; i++)
    {
        shapes[i] = other.shapes[i]->clone();
    }
}

ShapeList& ShapeList::operator=(const ShapeList& other)
{
    for(size_t i = 0; i < len; i++)
    {
        delete shapes[i];
    }
    delete [] shapes;

    this->len = other.len;
    this->cap = other.cap;
    shapes = new Shape*[cap];
    for(size_t i = 0; i < len; i++)
    {
        shapes[i] = other.shapes[i]->clone();
    }

    return *this;
}

ShapeList::~ShapeList()
{
    for(size_t i = 0; i < len; i++)
    {
        delete shapes[i];
    }

    delete [] shapes;
}

void ShapeList::add(Shape* shape)
{
    if(len + 1 >= cap)
    {
        resize();
    }
    shapes[len++] = shape;
}

Shape* ShapeList::operator[](size_t i)
{
    if(i >= len)
    {
        throw std::invalid_argument("");
    }

    return shapes[i];
}

const Shape* ShapeList::operator[](size_t i) const
{
    if(i >= len)
    {
        throw std::invalid_argument("");
    }

    return shapes[i];
}

ShapeList ShapeList::get_containing(const Point& p) const
{
    ShapeList result;
    for(size_t i = 0; i < len; i++)
    {
        if(shapes[i]->contains_point(p))
        {
            result.add(shapes[i]->clone());
        }
    }

    return result;
}

size_t ShapeList::get_len() const
{
    return len;
}

void ShapeList::resize()
{
    cap *= 2;
    Shape** newShapes = new Shape*[cap];

    for(size_t i = 0; i < len; i++)
    {
        newShapes[i] = shapes[i];
    }

    delete [] shapes;
    shapes = newShapes;
}
