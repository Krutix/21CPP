#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
protected:
	enum DefaultValues
	{
		HIT_POINTS = 100,
		ENERGY_POINTS = 100,
		DAMAGE = 30
	};

public:
	FragTrap(std::string const& name = "-");
	FragTrap(FragTrap const& other);
	FragTrap& operator=(FragTrap const& other);
	~FragTrap();
	void highFivesGuys() const;
};
