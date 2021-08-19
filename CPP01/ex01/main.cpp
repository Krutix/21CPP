#include "Zombie.hpp"

int main()
{
    Zombie champ("Champ");
    champ.announce();
    Zombie* ptr = newZombie("Jeff");
    ptr->announce();
    delete ptr;
    randomChump("Donald");
    ptr = zombieHorde(3, "Jack");
    ptr[0].announce();
    ptr[1].announce();
    ptr[2].announce();
    delete[] ptr;
}
