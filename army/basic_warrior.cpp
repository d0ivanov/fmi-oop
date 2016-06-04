#include "basic_warrior.hpp"

#include<string.h>
#include<stdexcept>

BasicWarrior::BasicWarrior()
	: name(NULL),
	skill(0),
	age(0),
	salary(0.0)
{}

BasicWarrior::BasicWarrior(const char* name, int age, int skill, double salary)
{
	if (name == NULL || age < 0 || skill < 0 || salary < 0.0)
	{
		throw std::invalid_argument("");
	}

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->age = age;
	this->skill = skill;
	this->salary = salary;
}

BasicWarrior::BasicWarrior(const BasicWarrior& other) {}
BasicWarrior& BasicWarrior::operator=(const BasicWarrior& other) { return *this; }

BasicWarrior::~BasicWarrior()
{
	delete[] name;
}

const char* BasicWarrior::getName() const
{
	return this->name;
}

void BasicWarrior::setName(const char* name)
{
	if (name == NULL)
	{
		throw std::invalid_argument("");
	}

	delete[]  this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

int BasicWarrior::getSkill() const
{
	return this->skill;
}

void BasicWarrior::setSkill(int skill)
{
	if (skill < 0)
	{
		throw std::invalid_argument("");
	}
	this->skill = skill;
}

int BasicWarrior::getAge() const
{
	return this->age;
}

void BasicWarrior::setAge(int age)
{
	if (age < 0)
	{
		throw std::invalid_argument("");
	}
	this->age = age;
}

double BasicWarrior::getSalary() const
{
	return this->salary;
}

void BasicWarrior::setSalary(double salary)
{
	if (salary < 0.0)
	{
		throw std::invalid_argument("");
	}
}