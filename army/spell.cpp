#include<cstring>
#include<stdexcept>

#include "spell.hpp"

Spell::Spell()
	: description(NULL),
	mana(0),
	type(FIRE)
{}

Spell::Spell(const Spell& other)
	: mana(other.mana),
	  type(other.type)
{
	setDescription(other.description);
}

Spell::Spell(SpellType type, const char* description, int mana)
	: type(type),
	  mana(mana)
{
	setDescription(description);
}

Spell& Spell::operator=(const Spell& other)
{
    if(this != &other)
    {
        setDescription(other.description);
        this->mana = other.mana;
        this->type = other.type;
    }

    return *this;
}

Spell::~Spell()
{
	delete[] description;
}

const char* Spell::getDescription() const
{
	return this->description;
}

void Spell::setDescription(const char* description)
{
	if (description == NULL)
	{
		throw std::invalid_argument("");
	}

	this->description = new char[strlen(description) + 1];
	strcpy(this->description, description);
}

int Spell::getMana() const
{
	return this->mana;
}

void Spell::setMana(int mana)
{
	this->mana = mana;
}

SpellType Spell::getType() const
{
	return this->type;
}

void Spell::setType(SpellType type)
{
	this->type = type;
}

bool Spell::operator==(const Spell& other)
{
	return strcmp(this->description, other.description) == 0 &&
		this->mana == other.mana && this->type == other.type;
}
