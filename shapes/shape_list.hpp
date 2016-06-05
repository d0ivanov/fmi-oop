#ifndef __SHAPE_LIST_HPP__
#define __SHAPE_LIST_HPP__

#include "shape.hpp"

class ShapeList
{
    private:
        Shape** shapes;
        size_t len;
        size_t cap;

    public:
        ShapeList();
        ShapeList(const ShapeList&);
        ShapeList& operator=(const ShapeList&);
        ~ShapeList();

        void add(Shape*);

        Shape* operator[](size_t);
        const Shape* operator[](size_t) const;

        ShapeList get_containing(const Point&) const;

        size_t get_len() const;

    private:
        void resize();
};

#endif
