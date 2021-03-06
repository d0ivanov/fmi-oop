#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include<istream>

#include "shape.hpp"
#include "shape_list.hpp"

class Parser
{
    public:
        ShapeList parse(std::istream&) const;

    private:
        Shape* get_shape(const char*) const;
        const char* get_object(std::istream&) const;
};

#endif
