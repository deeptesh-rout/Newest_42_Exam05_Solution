#pragma once

#include <iostream>

class Warlock {
private:
    std::string name;
    std::string title;

    Warlock();
    Warlock(Warlock const &);
    Warlock &operator=(Warlock const &);

public:
    Warlock(std::string const & name_, std::string const & title_);
    ~Warlock();
    
    std::string const & getName() const;
    std::string const & getTitle() const;
    
    void setTitle(std::string const & title_);
    void introduce() const;

};