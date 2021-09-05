#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    ICharacter* me = new Character("me");

    AMateria* tmp;
    src->learnMateria(tmp = new Ice());
    delete tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    src->learnMateria(tmp = new Cure());
    delete tmp;
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
    delete bob;
    delete me;
    delete src;
    return 0;
}