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
