#ifndef __WARRIOR_HPP__
#define __WARRIOR_HPP__

#include "basic_warrior.hpp"

class Warrior : public BasicWarrior
{
public:
	Warrior();
	Warrior(const char*, int, int, double);

private:
	Warrior(const Warrior&);
	Warrior& operator=(const Warrior&);
};

#endif
