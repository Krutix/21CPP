#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(std::string const& type) : m_type(type) {}
AMateria::~AMateria() {}
std::string const& AMateria::getType() const { return m_type; }

Ice::Ice() : AMateria("ice") {}

AMateria* Ice::clone() const
{
    return new Ice();
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Cure::Cure() : AMateria("cure") {}

AMateria* Cure::clone() const
{
    return new Cure();
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *\n";
}
