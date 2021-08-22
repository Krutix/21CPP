#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const& name = "-")
	: ClapTrap(
		name,
		_def_damage,
		_def_energypoints,
		_def_damage)
{
	std::cout << "ScavTrap " << _name << " constructor called\n";
}

ScavTrap::ScavTrap(ScavTrap const& other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " copy constructor called\n";
}

ScavTrap const& ScavTrap::operator=(ClapTrap const& other)
{
	std::cout << "ScavTrap " << _name << " assigment operator called\n";
	ClapTrapBase::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructor called\n";
}
