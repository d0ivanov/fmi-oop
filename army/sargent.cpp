#include<stdexcept>

#include "sargent.hpp"

Sargent::Sargent()
	: BasicWarrior(),
	  warriors(NULL),
	  size(0),
	  capacity(0)
{}

Sargent::Sargent(const char* name, int age, int skill, double salary)
	: BasicWarrior(name, age, skill, salary),
	  size(0),
	  capacity(1)
{
	this->warriors = new Warrior*[capacity];
}

Sargent::Sargent(const Sargent& other) 
	: BasicWarrior(other)
{}

Sargent& Sargent::operator=(const Sargent* other)
{
	return *this;
}

Sargent::~Sargent()
{
	for (size_t i = 0; i < size; i++)
	{
		delete warriors[i];
	}

	delete[] warriors;
}

void Sargent::addWarrior(Warrior* warrior)
{
	if (warrior == NULL || warrior->getSkill() > skill)
	{
		throw std::invalid_argument("");
	}

	if (size + 1 >= capacity)
	{
		resize();
	}
	warriors[size++] = warrior;
}

size_t Sargent::unitCount() const
{
	return this->size + 1;
}

long Sargent::unitSkillLevel() const
{
	long skillLevel = this->skill;
	for (size_t i = 0; i < size; i++)
	{
		skillLevel += warriors[i]->getSkill();
	}
	return skillLevel;
}

double Sargent::unitCost() const
{
	double cost = this->salary;
	for (size_t i = 0; i < size; i++)
	{
		cost += warriors[i]->getSalary();
	}

	return cost;
}

void Sargent::resize()
{
	capacity *= 2;
	Warrior** newCollection = new Warrior*[capacity];
	
	for (size_t i = 0; i < size; i++)
	{
		newCollection[i] = warriors[i];
	}

	delete[] warriors;
	warriors = newCollection;
}