#include<iostream>
#include<string>

#include "commander.hpp"

using namespace std;

int main()
{
	for (int i = 0; i < 0; i++)
	{
		cout << "test" << endl;
	}
	Commander* c = new Commander("Illidan", 250, 999, 250.00);
	for (int i = 0; i < 5; i++)
	{
		Mag* mag = new Mag("Koleca", 25, 100, 400.25, 1500, SpellBook());
		for (int j = 0; j < 3; j++)
		{
			Sargent* sargent = new Sargent("Mishoka", 21, 90, 370.00);
			for (int k = 0; k < 5; k++)
			{
				Warrior* warrior = new Warrior("Some dude", 18, 10, 120.0);
				sargent->addWarrior(warrior);
			}
			mag->addSargent(sargent);
		}
		for (int m = 0; m < 20; m++)
		{
			mag->learnSpell(Spell(SpellType(m % 4), "Just that spell", 10 * m));
		}
		c->addMag(mag);
	}

	cout << "The size of this army: " << c->armyCount() << endl
		<< "The cost per month to run it: " << c->armyCost() << endl
		<< "Total skill level: " << c->armySkillLevel() << endl
		<< "Avarage skill level: " << c->avarageArmySkillLevel() << endl
		<< "Total spell power: " << c->armySpellPower() << endl
		<< "Avarage spell power: " << c->avarageArmySpellPower() << endl
		<< "This army can cast no more than: " << c->maxSpellCastCount() << " spells" << endl;

	delete c;
	return 0;
}