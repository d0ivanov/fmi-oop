#ifndef __MAG_HPP__
#define __MAG_HPP__

#include "sargent.hpp"
#include "spell_book.hpp"

class Mag : public BasicWarrior
{
private:
	Sargent** sargents;
	size_t size;
	size_t capacity;
	int mana;
	SpellBook spellBook;

public:
	Mag();
	Mag(const char* , int, int, double, int, const SpellBook&);
	~Mag();

	void learnSpell(const Spell&);
	int maxSpellCastCount();
	
	void addSargent(Sargent*);

	size_t unitCount() const;
	long unitSkillLevel() const;
	double unitCost() const;
	int getMana() const;

private:
	Mag(const Mag&);
	Mag& operator=(const Mag&);
	void resize();

};

#endif
