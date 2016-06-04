#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

#include "point.hpp"
#include "shape.hpp"

class Sphere : public Shape
{
    static const size_t POINT_COUNT = 1;

    private:

        Point points[1];
        double radious;

    public:
        Sphere();
        Sphere(const Point&, double);
        virtual ~Sphere();

        virtual void parse(std::istream&);
        virtual void print(std::ostream&) const;
        virtual bool contains_point(const Point&) const;
        virtual Shape* clone() const;

    protected:
        virtual Point* get_points();
        virtual const Point* get_points() const;
        virtual size_t get_point_count() const;
        virtual const char* get_name() const;
};

#endif
