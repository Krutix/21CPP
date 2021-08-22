#include "ClapTrap.hpp"

class ScavTrap : ClapTrap
{
protected:
	static int const _def_hitpoints = 100;
	static int const _def_energypoints = 50;
	static int const _def_damage = 20;

public:
	ScavTrap(std::string const& name = "-");
	ScavTrap(ScavTrap const& other);
	ScavTrap const& operator=(ClapTrap const& other);
	~ScavTrap();
};
