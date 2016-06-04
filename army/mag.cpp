#include<stdexcept>

#include "mag.hpp"

Mag::Mag()
	: BasicWarrior(),
	sargents(NULL),
	size(0),
	capacity(0),
	mana(0),
	spellBook()
{}

Mag::Mag(const char* name, int age, int skill, double salary, int mana,
		 const SpellBook& spellBook)
	:BasicWarrior(name, age, skill, salary),
	size(0),
	capacity(16)
{
	if (mana < 0)
	{
		throw std::invalid_argument("Mag must have at leas some mana!");
	}

	this->sargents = new Sargent*[capacity];
	this->mana = mana;
	this->spellBook = spellBook;
}

Mag::~Mag()
{
	for (size_t i = 0; i < size; i++)
	{
		delete sargents[i];
	}

	delete[] sargents;
}

Mag& Mag::operator=(const Mag& other) { return *this; }

void Mag::learnSpell(const Spell& spell)
{
	spellBook.writePage(spell);
}

int Mag::maxSpellCastCount()
{
	spellBook.sortByMana();
	int spellCount = 0;
	int requiredMana = 0;
	size_t i = 0;
	while (requiredMana <= mana && i < spellBook.pageCount() - 1)
	{
		requiredMana += spellBook[i++]->getMana();
		++spellCount;
	}

	return spellCount;
}

void Mag::addSargent(Sargent* sargent)
{
	if (sargent == NULL || sargent->getSkill() > skill)
	{
		throw std::invalid_argument("");
	}

	if (size + 1 >= capacity)
	{
		resize();
	}
	sargents[size++] = sargent;
}

size_t Mag::unitCount() const
{
	size_t size = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		size += sargents[i]->unitCount();
	}
	
	return size +  1;
}

long Mag::unitSkillLevel() const
{
	long skillLevel = this->skill;
	for (size_t i = 0; i < size; i++)
	{
		skillLevel += sargents[i]->unitSkillLevel();
	}
	return skillLevel;
}

double Mag::unitCost() const
{
	double cost = this->salary;
	for (size_t i = 0; i < size; i++)
	{
		cost += sargents[i]->unitCost();
	}

	return cost;
}

int Mag::getMana() const
{
	return this->mana;
}

void Mag::resize()
{
	capacity *= 2;
	Sargent** newCollection = new Sargent*[capacity];

	for (size_t i = 0; i < size; i++)
	{
		newCollection[i] = sargents[i];
	}

	delete[] sargents;
	sargents = newCollection;
}