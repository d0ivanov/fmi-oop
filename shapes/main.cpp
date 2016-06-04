#include<iostream>

#include "shape.hpp"
#include "sphere.hpp"
#include "cuboid.hpp"
#include "pyramid.hpp"
#include "parser.hpp"

using namespace std;

int main()
{
    ShapeList shapes = Parser().parse(cin);

    for(size_t i = 0; i < shapes.get_len(); i++)
    {
        cout << *shapes[i] << endl;
    }

    return 0;
}
