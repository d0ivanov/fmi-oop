all: shape_parser

shape.o: shape.cpp shape.hpp
point.o: point.cpp point.hpp
sphere.o: sphere.cpp shape.hpp sphere.hpp
pyramid.o: pyramid.cpp shape.hpp pyramid.hpp
cuboid.o: cuboid.cpp shape.hpp cuboid.hpp
parser.o: parser.cpp parser.hpp shape.hpp sphere.hpp pyramid.hpp cuboid.hpp shape_list.hpp
shape_group.o: shape.hpp shape_group.hpp shape_group.cpp
shape_list.o: shape.hpp sphere.hpp pyramid.hpp cuboid.hpp shape_list.hpp

main.o: main.cpp parser.hpp shape.hpp sphere.hpp pyramid.hpp cuboid.hpp shape_list.hpp shape_group.hpp

shape_parser: main.o shape_list.o parser.o cuboid.o pyramid.o sphere.o shape.o point.o shape_group.o
		g++ main.o shape_list.o parser.o cuboid.o pyramid.o sphere.o shape.o point.o shape_group.o -o shape_parser

clean:
		rm -f *.o shape_parser
