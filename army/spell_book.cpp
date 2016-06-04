#include<stdexcept>

#include "spell_book.hpp"

SpellBook::SpellBook()
	: pages(1)
{
	spells = new Spell*[pages];
	spells[0] = NULL;
}

SpellBook::SpellBook(const SpellBook& other)
	: pages(other.pages)
{
	spells = new Spell*[pages];
	for (size_t i = 0; i < pages - 1; i++)
	{
		spells[i] = new Spell(*other.spells[i]);
	}
}

SpellBook& SpellBook::operator=(const SpellBook& other)
{
    if(this != &other)
    {
        pages = other.pages;
        delete[] spells;

        this->spells = new Spell*[pages];
        for (size_t i = 0; i < pages - 1; i++)
        {
            this->spells[i] = new Spell(*other.spells[i]);
        }
        spells[pages - 1] = NULL;
    }

    return *this;
}

SpellBook::~SpellBook()
{
	for (size_t i = 0; i < pages; i++)
	{
		delete spells[i];
	}

	delete[] spells;
}

bool SpellBook::isEmpty() const
{
	return pages == 0;
}

size_t SpellBook::pageCount() const
{
	return pages;
}

Spell* SpellBook::operator[](size_t i)
{
	if (i >= pages)
	{
		throw std::out_of_range("");
	}

	return spells[i];
}

const Spell* SpellBook::operator[](size_t i) const
{
	if (i >= pages)
	{
		throw std::out_of_range("");
	}

	return spells[i];
}

void SpellBook::writePage(const Spell& spell)
{
	Spell** newBook = new Spell*[pages + 1];
	for (size_t i = 0; i < pages; i++)
	{   // The new spell is inserted at the end of the book
		if (i == pages - 1)
		{
			newBook[i] = new Spell(spell);
		}
		else
		{   // Previously existing spell
			newBook[i] = spells[i];
		}
	}
	newBook[pages++] = NULL;
	
	delete[] spells;
	spells = newBook;
}

Spell* SpellBook::readPage(size_t page)
{
	if (page >= pages - 1)
	{
		throw std::out_of_range("");
	}

	Spell* spell = spells[page];
	Spell** newBook = new Spell*[pages - 1];
	for (size_t i = 0, j = 0; i < pages - 1; i++)
	{
		if (i != page)
		{
			newBook[j++] = spells[i];
		}
	}
	newBook[pages - 2] = NULL;
	delete[] spells;

	spells = newBook;
	--pages;
	
	return spell;
}

void SpellBook::sortByMana()
{
	if (pages == 1)
	{
		return;
	}
	bool swapped = true;
	size_t j = 0;
	Spell* tmp;
	while (swapped) {
		swapped = false;
		j++;
		for (size_t i = 0; i < (pages - 1 - j); i++) {
			if (spells[i]->getMana() > spells[i + 1]->getMana()) {
				tmp = spells[i];
				spells[i] = spells[i + 1];
				spells[i + 1] = tmp;
				swapped = true;
			}
		}
	}
}
