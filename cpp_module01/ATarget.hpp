#pragma once 

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
protected:
    std::string type;

public:
    ATarget(std::string const & type_);
    ATarget(ATarget const & other);
    ATarget &operator=(ATarget const & other);
    virtual ~ATarget();

    std::string const & getType() const;

    virtual ATarget * clone() const = 0;

    void getHitBySpell(ASpell const & spellObj) const;
};