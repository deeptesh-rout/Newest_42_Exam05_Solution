#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::BrickWall(std::string const & type_) : ATarget(type_) {} 

BrickWall::~BrickWall() {}

ATarget * BrickWall::clone() const
{
    return new BrickWall;
}