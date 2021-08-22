#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	enum DefaultValues
	{
		HIT_POINTS    = 100,
		ENERGY_POINTS = 50,
		DAMAGE        = 20
	};

public:
	ScavTrap(std::string const& name = "-");
	ScavTrap(ScavTrap const& other);
	ScavTrap& operator=(ScavTrap const& other);
	~ScavTrap();
	void attack(std::string const& target) const;
	void guardGate() const;
};
