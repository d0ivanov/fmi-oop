#ifndef __SPELL_HPP__
#define __SPELL_HPP__

enum SpellType {FIRE, WATER, AIR, EARTH};

class Spell
{
private:
	char* description;
	int mana;
	SpellType type;

public:
	Spell();
	Spell(const Spell&);
	Spell(SpellType, const char*, int);
	Spell& operator=(const Spell&);
	~Spell();

	const char* getDescription() const;
	void setDescription(const char*);


	int getMana() const;
	void setMana(int);

	SpellType getType() const;
	void setType(SpellType);

	bool operator==(const Spell&);
};

#endif
