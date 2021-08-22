#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string const& name)
	: ClapTrap(name, HIT_POINTS,
		ENERGY_POINTS, DAMAGE)
{
	std::cout << "ScavTrap " << _name << " constructor called\n";
}

ScavTrap::ScavTrap(ScavTrap const& other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap " << _name << " copy constructor called\n";
}

ScavTrap& ScavTrap::operator=(ScavTrap const& other)
{
	std::cout << "ScavTrap " << _name << " assigment operator called\n";
	this->ClapTrap::operator=(other);
	return *this;
}

void ScavTrap::attack(std::string const& target) const
{
	std::cout << "ScavTrap " << _name << " hug "
		<< target << " causing "
		<< _damage  << " points of damage!\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << _name << " destructor called\n";
}

void ScavTrap::guardGate() const
{
	std::cout << "ScavTrap " << _name << " have enterred in Gate keeper mode\n";
	std::cout << "      |\\ _..--.._ /|\n"
				 "      |############|\n"
				 "       )##########(\n"
				 "    ._/##.'//\\\\'.##\\_.\n"
				 "     .__)#((()))#(__.\n"
				 "      \\##'.\\//.'##/\n"
				 "       \\####\\/####/\n"
				 "       /,.######.,\\\n"
				 "      (  \\##__##/  )\n"
				 "          \"(\\/)\"\n"
				 "            )(\n";

}
