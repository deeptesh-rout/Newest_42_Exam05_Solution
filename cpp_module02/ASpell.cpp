#include "ASpell.hpp"

ASpell::ASpell(std::string const & name_, std::string const & effects_) : name(name_), effects(effects_) {}

ASpell::ASpell(ASpell const & other)
{
    *this = other;
}

ASpell & ASpell::operator=(ASpell const & other)
{
    name = other.name;
    effects = other.effects;
    return *this;
}

ASpell::~ASpell() {}

std::string ASpell::getName() const
{
    return name;
}

std::string ASpell::getEffects() const
{
    return effects;
}


void ASpell::launch(ATarget const & target)
{
    target.getHitBySpell(*this);
}