#include "Zombie.hpp"

inline Zombie::Zombie(std::string const& name) : name(name) {}
inline Zombie::~Zombie() { std::cout << name << " destructed\n"; }
inline void Zombie::announce() const { std::cout << name << " BraiiiiiiinnnzzzZ\n"; }

inline Zombie* newZombie(std::string const& name)
{
    return new Zombie(name);
}

inline void randomChump(std::string const& name)
{
    Zombie(name).announce();
}