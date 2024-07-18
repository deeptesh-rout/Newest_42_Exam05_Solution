#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() 
{
    std::map<std::string, ATarget *>::iterator it = book.begin();
    while (it != book.end())
    {
        delete it->second;
        ++it;
    }
    book.clear();
}

void TargetGenerator::learnTargetType(ATarget * spellPtr)
{
    if (spellPtr)
        book.insert(std::pair<std::string, ATarget *>(spellPtr->getType(), spellPtr->clone()));
}

void TargetGenerator::forgetTargetType(std::string const & type)
{
    if (book.find(type) != book.end())
        delete book[type];
    book.erase(type);
}

ATarget * TargetGenerator::createTarget(std::string const & type)
{
    if (book.find(type) != book.end())
        return book[type];
    return new BrickWall(type); // This funtion, as the class name implies (Target Generator),
                                // is to CREATE A TARGET OF THE SPECIFIED TYPE. Which means it
                                // may or may NOT CORRESPOND with an already existing type, if
                                // it doesn't, the specified one should be created and returned.
                                // For this reason we need a name constructor for either the Dummy
                                // or the BrickWall class that will use the ATarget name constructor.
}