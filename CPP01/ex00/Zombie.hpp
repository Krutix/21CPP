#pragma once
#include <string>
#include <iostream>

class Zombie
{
public:
    Zombie(std::string const& name = "");
    ~Zombie();
    void announce() const;
private:
    std::string name;
};

inline Zombie* newZombie(std::string const& name);
inline void randomChump(std::string const& name);

#include "Zombie.inl"
