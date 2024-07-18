#pragma once

#include "ATarget.hpp"

class BrickWall : public ATarget {
public:
    BrickWall();
    BrickWall(std::string const & type_); // To create a specified type
    ~BrickWall();

    virtual ATarget * clone () const;
};