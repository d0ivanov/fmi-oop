#ifndef __SHAPE_GROUP_HPP__
#define __SHAPE_GROUP_HPP__

#include "shape.hpp"
#include "shape_list.hpp"
#include "parser.hpp"

class ShapeGroup : public Shape
{
    private:
        ShapeList shapes;
        Parser parser;

    public:
        ShapeGroup(const Parser&);
        ShapeGroup(const ShapeGroup&);
        virtual ~ShapeGroup();
        virtual void print(std::ostream&) const;
        virtual void parse(std::istream&);
        virtual void scale(Point&, double);
        virtual bool contains_point(const Point&) const;

        virtual Shape* clone() const;

    protected:
        virtual const char* get_name() const;

    private:
        virtual Point* get_points();
        virtual const Point* get_points() const;
        virtual size_t get_point_count() const;
};

#endif
