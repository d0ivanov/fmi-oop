#ifndef __CUBOID_HPP__
#define __CUBOID_HPP__

#include "shape.hpp"

class Cuboid : public Shape
{
    private:
        static const size_t POINT_COUNT = 2;
        Point points[2];

    public:
        Cuboid();
        Cuboid(Point[2]);
        virtual ~Cuboid();

        virtual bool contains_point(const Point&) const;
        virtual Shape* clone() const;

    protected:
        virtual Point* get_points();
        virtual const Point* get_points() const;
        virtual size_t get_point_count() const;
        virtual const char* get_name() const;
};
#endif
