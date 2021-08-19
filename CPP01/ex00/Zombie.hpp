#pragma once
#include <string>
#include <iostream>

class Zombie
{
public:
    Zombie(std::string const& name = "") : name(name) {}
    ~Zombie() { std::cout << name << "destructed\n"; }
    void announce() const { std::cout << name << " BraiiiiiiinnnzzzZ\n"; }
private:
    std::string name;
};

inline Zombie* newZombie(std::string const& name)
{
    return new Zombie(name);
}

inline void randomChump(std::string const& name)
{
    Zombie(name).announce();
}
