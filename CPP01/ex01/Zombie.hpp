#pragma once
#include <string>
#include <iostream>

class Zombie
{
public:
    Zombie(std::string const& name = "") : name(name) {}
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

inline Zombie* zombieHorde(int n, std::string const& name)
{
    Zombie* ptr = new Zombie[n];
    for (int i = 0; i < n; i++)
        ::new (&ptr[i])Zombie(name);
    return ptr;
}
