#include "FragTrap.hpp"

FragTrap::FragTrap(std::string const& name)
	: ClapTrap(name, HIT_POINTS,
		ENERGY_POINTS, DAMAGE)
{
	std::cout << "FragTrap " << _name << " constructor called\n";
}

FragTrap::FragTrap(FragTrap const& other)
	: ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " copy constructor called\n";
}

FragTrap& FragTrap::operator=(FragTrap const& other)
{
	std::cout << "FragTrap " << _name << " assigment operator called\n";
	this->ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " destructor called\n";
}

void FragTrap::highFivesGuys() const
{
	std::cout << "FragTrap " << _name << " request high fives\n";
	std::cout << "( ⌒o⌒)人(⌒-⌒ )v\n";

}
