#include "Warlock.hpp"

Warlock::Warlock(std::string const & name_, std::string const & title_) : name(name_), title(title_)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
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
    book.learnSpell(spellPtr);
}

void Warlock::forgetSpell(std::string spell)
{
    book.forgetSpell(spell);
}

void Warlock::launchSpell(std::string spell, ATarget const & target)
{
    // it not possible to check for NULL on a const &, so target must EXIST
    if (book.createSpell(spell))
        book.createSpell(spell)->launch(target);
}