#include "ClapTrap.hpp"

ClapTrap::ClapTrap(
	std::string const& name,
	int hitpoints,
	int energypoints,
	int damage)
	: _name(name),
	  _hitpoints(hitpoints),
	  _energypoints(energypoints),
	  _damage(damage)
{
	std::cout << "ClapTrap " << _name << " constructor called\n";
}

ClapTrap::ClapTrap(ClapTrap const& other)
	: _name(other._name),
	  _hitpoints(other._hitpoints),
	  _energypoints(other._energypoints),
	  _damage(other._damage)
{
	std::cout << "ClapTrap " << _name << " copy constructor called\n";
}

ClapTrap::ClapTrap(std::string const& name)
	: _name(name),
	  _hitpoints(HIT_POINTS),
	  _energypoints(ENERGY_POINTS),
	  _damage(DAMAGE)
{
	std::cout << "ClapTrap " << _name << " constructor called\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called\n";
}

ClapTrap& ClapTrap::operator=(ClapTrap const& other)
{
	_name = other._name;
	_hitpoints = other._hitpoints;
	_energypoints = other._energypoints;
	_damage = other._damage;
	std::cout << "ClapTrap " << _name << " assigment operator called\n";
	return *this;
}

void ClapTrap::attack(std::string const & target) const
{
	std::cout << "ClapTrap " << _name << " attack "
		<< target << " causing "
		<< _damage  << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " take "
			<< amount << " damage\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " be repaired by "
			<< amount << " hitpoints\n";
}
