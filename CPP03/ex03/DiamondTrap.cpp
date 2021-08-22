#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string const& name)
	: ClapTrap(name + "_clap_name", HIT_POINTS,
		ENERGY_POINTS, DAMAGE), FragTrap(name), ScavTrap(name),
		_name(name)
{
	std::cout << "DiamondTrap " << _name << " constructor called\n";
}

DiamondTrap::DiamondTrap(DiamondTrap const& other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
	std::cout << "DiamondTrap " << _name << " copy constructor called\n";
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& other)
{
	std::cout << "DiamondTrap " << _name << " assigment operator called\n";
	this->ClapTrap::operator=(other);
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << _name << " destructor called\n";
}

void DiamondTrap::whoAmI() const
{
	std::cout << "I am DiamondTrap " << _name
		<< " with ClapTrap name as " << ClapTrap::_name << "\n";
}

void DiamondTrap::attack(std::string const& target) const
{
	this->ScavTrap::attack(target);
}
