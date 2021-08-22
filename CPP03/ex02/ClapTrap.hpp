#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
public:
	ClapTrap(std::string const& name = "-");

	ClapTrap(ClapTrap const& other);

	ClapTrap& operator=(ClapTrap const& other);

	virtual ~ClapTrap();

	virtual void attack(std::string const & target) const;

	virtual void takeDamage(unsigned int amount);

	virtual void beRepaired(unsigned int amount);

protected:
	enum DefaultValues
	{
		HIT_POINTS = 10,
		ENERGY_POINTS = 10,
		DAMAGE = 0
	};

	std::string	_name;
	int			_hitpoints;
	int			_energypoints;
	int			_damage;

	ClapTrap(
		std::string const& name,
		int hitpoints,
		int energypoints,
		int damage);
};
