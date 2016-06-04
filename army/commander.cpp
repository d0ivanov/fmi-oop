#include<stdexcept>

#include "commander.hpp"

Commander::Commander()
	: BasicWarrior(),
	mags(NULL),
	size(0),
	capacity(0)
{}

Commander::Commander(const char* name, int age, int skill, double salary)
	:BasicWarrior(name, age, skill, salary),
	size(0),
	capacity(16)
{
	this->mags = new Mag*[capacity];
}

Commander::~Commander()
{
	for (size_t i = 0; i < size; i++)
	{
		delete mags[i];
	}

	delete[] mags;
}

Commander& Commander::operator=(const Commander& other) { return *this; }

int Commander::maxSpellCastCount() const
{
	int count = 0;
	for (size_t i = 0; i < size; i++)
	{
		count += mags[i]->maxSpellCastCount();
	}

	return count;
}

void Commander::addMag(Mag* mag)
{
	if (mag == NULL || mag->getSkill() > skill)
	{
		throw std::invalid_argument("");
	}

	if (size + 1 >= capacity)
	{
		resize();
	}
	mags[size++] = mag;
}

size_t Commander::armyCount() const
{
	size_t size = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		size += mags[i]->unitCount();
	}

	return size + 1;
}

int Commander::armySpellPower() const
{
	int spellPower = 0;
	for (size_t i = 0; i < size; i++)
	{
		spellPower += mags[i]->getMana();
	}

	return  spellPower;
}

double Commander::avarageArmySpellPower() const
{
	if (this->size == 0)
	{
		return 0;
	}
	return (double)armySpellPower() / (double) this->size;
}

long Commander::armySkillLevel() const
{
	long skillLevel = this->skill;
	for (size_t i = 0; i < size; i++)
	{
		skillLevel += mags[i]->unitSkillLevel();
	}

	return skillLevel;
}

double Commander::avarageArmySkillLevel() const
{
	return (double)armySkillLevel() / (double) armyCount();
}

double Commander::armyCost() const
{
	double cost = this->salary;
	for (size_t i = 0; i < size; i++)
	{
		cost += mags[i]->unitCost();
	}

	return cost;
}

void Commander::resize()
{
	capacity *= 2;
	Mag** newCollection = new Mag*[capacity];

	for (size_t i = 0; i < size; i++)
	{
		newCollection[i] = mags[i];
	}

	delete[] mags;
	mags = newCollection;
}