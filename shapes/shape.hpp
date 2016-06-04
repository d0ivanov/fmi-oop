#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include<istream>
#include<ostream>

#include "point.hpp"

class Shape
{
    public:
        Shape();
        virtual ~Shape();

        virtual void print(std::ostream&) const;
        virtual void parse(std::istream&);
        virtual void scale(Point&, double);
        virtual bool contains_point(const Point&) const = 0;

        virtual Shape* clone() const = 0;

    protected:
        virtual Point* get_points() = 0;
        virtual const Point* get_points() const = 0;
        virtual size_t get_point_count() const = 0;
        virtual const char* get_name() const = 0;
};

std::ostream& operator<<(std::ostream&, const Shape&);
std::istream& operator>>(std::istream&, Shape&);

#endif
