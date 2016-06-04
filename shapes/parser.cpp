#include<cstring>
#include<stdexcept>

#include "shape_list.hpp"
#include "parser.hpp"
#include "sphere.hpp"
#include "cuboid.hpp"
#include "shape.hpp"
#include "pyramid.hpp"

ShapeList Parser::parse(std::istream& istr) const
{
    ShapeList shapes;
    while(!istr.eof())
    {
        const char* object_type = get_object(istr);
        if(istr.eof())
            break;

        if(strcmp(object_type, "group in") == 0)
        {
            parse_group(istr, shapes);
        }
        else
        {
            parse_shape(object_type, istr, shapes);
        }
    }
    return shapes;
}

void Parser::parse_group(std::istream& istr, ShapeList& shapes) const
{
    Point p;
    double scalar;
    size_t current_len = shapes.get_len() - 1;

    istr >> p;
    istr >> scalar;
    const char* object_type = get_object(istr);
    while(!istr.eof() && strcmp(object_type, "group out") != 0)
    {
        parse_shape(object_type, istr, shapes);
        object_type = get_object(istr);
    }

    for(size_t i = current_len; i < shapes.get_len(); i++)
    {
        shapes[i]->scale(p, scalar);
    }
}

void Parser::parse_shape(const char* name, std::istream& istr, ShapeList& shapes) const
{
    Shape* shape = get_shape(name);
    shape->parse(istr);
    shapes.add(shape);
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

    throw std::invalid_argument(name);
}

const char* Parser::get_object(std::istream& istr) const
{
    size_t len = 0;
    size_t cap = 6;
    char* buffer = new char[cap + 1];
    char c;

    while(!istr.eof())
    {
        c = istr.get();
        if(c != '\n' && c != '\t')
        {
            if(c == ' ' && istr.peek() != 'i')
                continue;
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

            if((c >= '0' && c <= '9') || c == '-')
            {
                istr.putback(c);
                buffer[len] = '\0';
                return buffer;
            }
            else
            {
                buffer[len++] = c;
            }
        }
    }

    buffer[len] = '\0';
    return buffer;
}
