#ifndef __SPELL_BOOK_HPP__
#define __SPELL_BOOK_HPP__

#include "spell.hpp"

class SpellBook
{
private:
	Spell** spells;
	size_t pages;
public:
	SpellBook();
	SpellBook(const SpellBook&);
	SpellBook& operator=(const SpellBook&);
	~SpellBook();

	bool isEmpty() const;
	size_t pageCount() const;
	Spell* operator[](size_t);
	const Spell* operator[](size_t) const;
	void sortByMana();

	void writePage(const Spell&);
	Spell* readPage(size_t);
};

#endif
