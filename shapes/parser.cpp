#include<cstring>
#include<stdexcept>

#include "shape_list.hpp"
#include "parser.hpp"
#include "shape.hpp"
#include "pyramid.hpp"
#include "sphere.hpp"
#include "cuboid.hpp"
#include "shape_group.hpp"

ShapeList Parser::parse(std::istream& istr) const
{
    ShapeList shapes;
    while(!istr.eof())
    {
        const char* object_type = get_object(istr);
        if(istr.eof())
            break;
        if(strcmp(object_type, "group") == 0)
        {
            if(istr.get() == 'i')
            {
                istr.get();
            }
            else
            {
                istr.get();
                istr.get();

                return shapes;
            }
        }

        Shape* shape = get_shape(object_type);
        shape->parse(istr);
        shapes.add(shape);
    }
    return shapes;
}

Shape* Parser::get_shape(const char* name) const
{
    if(strcmp(name, "sphere") == 0)
    {
        return new Sphere();
    }
    else if(strcmp(name, "cuboid") == 0)
    {
        return new Cuboid();
    }
    else if(strcmp(name, "pyramid") == 0)
    {
        return new Pyramid();
    }
    else if(strcmp(name, "group") == 0)
    {
        return new ShapeGroup(Parser());
    }

    throw std::invalid_argument(name);
}

const char* Parser::get_object(std::istream& istr) const
{
    size_t len = 0;
    size_t cap = 6;
    char* buffer = new char[cap + 1];
    char c;

    while(c != ' ' && !istr.eof())
    {
        c = istr.get();
        if(len >= cap + 1)
        {
            cap *= 2;
            char* new_buff = new char[cap];
            for(size_t i = 0; i < len; i++)
            {
                new_buff[i] = buffer[i];
            }
            delete [] buffer;
            buffer = new_buff;
        }

        if(c != ' ' && c != '\n')
            buffer[len++] = c;
    }

    buffer[len] = '\0';
    return buffer;
}
