#include "ATarget.hpp"

ATarget::ATarget(std::string const & type_) : type(type_){}

ATarget::ATarget(ATarget const & other)
{
    *this = other;
}

ATarget & ATarget::operator=(ATarget const & other)
{
    type = other.type;
    return *this;
}

ATarget::~ATarget() {}

std::string const & ATarget::getType() const
{
    return type;
}

void ATarget::getHitBySpell(ASpell const & spellObj) const
{
    std::cout << type << " has been " << spellObj.getEffects() << "!\n";
}

