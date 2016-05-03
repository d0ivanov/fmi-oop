all: easter_bunny

egg.o: egg.cpp egg.hpp
egg_basket.o: egg_basket.cpp egg_basket.hpp egg.hpp
solution.o: solution.cpp egg_basket.hpp egg.hpp

easter_bunny: solution.o egg_basket.o egg.o
		g++ solution.o egg_basket.o egg.o -o easter_bunny

clean:
		rm -f *.o easter_bunny
