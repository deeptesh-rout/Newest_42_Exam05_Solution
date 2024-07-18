#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
#include <map>

class Warlock {
private:
    std::string name;
    std::string title;

    Warlock();
    Warlock(Warlock const &);
    Warlock &operator=(Warlock const &);

    SpellBook book;

public:
    Warlock(std::string const & name_, std::string const & title_);
    ~Warlock();
    
    std::string const & getName() const;
    std::string const & getTitle() const;
    
    void setTitle(std::string const & title_);
    void introduce() const;

    void learnSpell(ASpell * spellPtr);
    void forgetSpell(std::string spell);
    void launchSpell(std::string spell, ATarget const & target);
};