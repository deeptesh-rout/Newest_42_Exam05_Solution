#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() 
{
    std::map<std::string, ASpell *>::iterator it = book.begin();
    while (it != book.end())
    {
        delete it->second;
        ++it;
    }
    book.clear();
}

void SpellBook::learnSpell(ASpell * spellPtr)
{
    if (spellPtr)
        book.insert(std::pair<std::string, ASpell *>(spellPtr->getName(), spellPtr->clone()));

}

void SpellBook::forgetSpell(std::string const & spell)
{
    if (book.find(spell) != book.end())
        delete book[spell];
    book.erase(spell);
}

ASpell * SpellBook::createSpell(std::string const & spell)
{
    if (book.find(spell) != book.end())
        return book[spell];
    return NULL;  // This passes becasue this function is to receive
                  // a STRING CORRESPONDING TO THE NAME OF A SPELL, create it, and return it.
                  // Which means we can always assume the spell would already exist.
}