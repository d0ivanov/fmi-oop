#ifndef __PYRAMID_HPP__
#define __PYRAMID_HPP__

#include "point.hpp"
#include "shape.hpp"

class Pyramid : public Shape
{
    private:
        static const size_t POINT_COUNT = 4;
        Point points[4];

    public:
        Pyramid();
        Pyramid(Point[4]);
        virtual ~Pyramid();

        virtual bool contains_point(const Point&) const;
        virtual Shape* clone() const;

     protected:
        virtual Point* get_points();
        virtual const Point* get_points() const;
        virtual size_t get_point_count() const;
        virtual const char* get_name() const;
};

#endif
