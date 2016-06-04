#ifndef __SARGENT_HPP__
#define __SARGENT_HPP__

#include<stddef.h>

#include "basic_warrior.hpp"
#include "warrior.hpp"

class Sargent : public BasicWarrior
{
private:
	Warrior** warriors;
	size_t size;
	size_t capacity;
public:
	Sargent();
	Sargent(const char*, int, int, double);
	~Sargent();

	void addWarrior(Warrior*);
	size_t unitCount() const;
	long unitSkillLevel() const;
	double unitCost() const;

private:
	Sargent(const Sargent&);
	Sargent& operator=(const Sargent*);
	void resize();
};

#endif
