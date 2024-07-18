#include "Warlock.hpp"

Warlock::Warlock(std::string const & name_, std::string const & title_) : name(name_), title(title_)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
    std::map<std::string, ASpell *>::iterator it = book.begin();
    while (it != book.end())
    {
        delete it->second;
        ++it;
    }
    book.clear();
}

std::string const & Warlock::getName() const
{
    return name;
}

std::string const & Warlock::getTitle() const
{
    return title;
}

void Warlock::setTitle(std::string const & title_)
{
    title = title_;
}

void Warlock::introduce() const
{
    std::cout << name << ": I am " << name << ", " << title << "!\n";
}

void Warlock::learnSpell(ASpell * spellPtr)
{
    if (spellPtr)
        book.insert(std::pair<std::string, ASpell *>(spellPtr->getName(), spellPtr->clone())); // insert does nothing if key(spell) already exists. For [] you have to check if it exists yourself.
}

void Warlock::forgetSpell(std::string spell)
{
    if (book.find(spell) != book.end())
        delete book[spell];
    book.erase(spell);
}

void Warlock::launchSpell(std::string spell, ATarget const & target)
{
    if (book.find(spell) != book.end())
        book[spell]->launch(target);
}