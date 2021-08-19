#include "Zombie.hpp"

int main()
{
    Zombie champ("Champ");
    champ.announce();
    Zombie* ptr = newZombie("Jeff");
    ptr->announce();
    delete ptr;
    randomChump("Donald");
}
