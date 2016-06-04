#include "warrior.hpp"

Warrior::Warrior()
	: BasicWarrior()
{}

Warrior::Warrior(const char* name, int age, int skill, double salary)
	: BasicWarrior(name, age, skill, salary)
{}

Warrior::Warrior(const Warrior& other)
	: BasicWarrior(other)
{}

Warrior& Warrior::operator=(const Warrior& other) { return *this; }