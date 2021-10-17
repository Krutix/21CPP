#include "Zombie.hpp"

inline Zombie::Zombie(std::string const& name) : name(name) {}
inline void Zombie::announce() const { std::cout << name << " BraiiiiiiinnnzzzZ\n"; }

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
