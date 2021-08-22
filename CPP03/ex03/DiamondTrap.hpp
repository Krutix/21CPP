#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
protected:
	enum DefaultValues
	{
		HIT_POINTS =    FragTrap::HIT_POINTS,
		ENERGY_POINTS = ScavTrap::ENERGY_POINTS,
		DAMAGE =        FragTrap::DAMAGE
	};

public:
	DiamondTrap(std::string const& name = "-");
	DiamondTrap(DiamondTrap const& other);
	DiamondTrap& operator=(DiamondTrap const& other);
	~DiamondTrap();

	void attack(std::string const& target) const;

	void whoAmI() const;
private:
	std::string _name;
};
