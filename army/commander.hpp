#ifndef __COMMANDER_HPP__
#define __COMMANDER_HPP__

#include "mag.hpp"

class Commander : public BasicWarrior
{
private:
	Mag** mags;
	size_t size;
	size_t capacity;
	
public:
	Commander();
	Commander(const char*, int, int, double);
	~Commander();

	void addMag(Mag*);

	int maxSpellCastCount() const;
	size_t armyCount() const;
	
	int armySpellPower() const;
	double avarageArmySpellPower() const;
	
	long armySkillLevel() const;
	double avarageArmySkillLevel() const;
	
	double armyCost() const;

private:
	Commander(const Commander&);
	Commander& operator=(const Commander&);
	void resize();

};

#endif