#include <iostream>
#include "ATarget.hpp"
#include "BrickWall.hpp"
#include <map>

class TargetGenerator {
private:
    TargetGenerator(TargetGenerator const & other);
    TargetGenerator &operator=(TargetGenerator const & other);

    std::map<std::string, ATarget *> book;

public:
    TargetGenerator();
    ~TargetGenerator();
    void learnTargetType(ATarget*);
    void forgetTargetType(std::string const & type);
    ATarget * createTarget(std::string const & type);
};