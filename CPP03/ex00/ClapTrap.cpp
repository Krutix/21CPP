#include "ClapTrap.hpp"

ClapTrapBase::ClapTrapBase(
	std::string const& name,
	int hitpoints,
	int energypoints,
	int damage)
	: _name(name),
	  _max_hitpoints(hitpoints),
	  _hitpoints(hitpoints),
	  _energypoints(energypoints),
	  _damage(damage) {}

ClapTrapBase::ClapTrapBase(ClapTrapBase const& other)
	: _name(other._name),
	  _max_hitpoints(other._max_hitpoints),
	  _hitpoints(other._hitpoints),
	  _energypoints(other._energypoints),
	  _damage(other._damage) {}


ClapTrapBase const& ClapTrapBase::operator=(ClapTrapBase const& other)
{
	_name = other._name;
	_max_hitpoints = other._max_hitpoints;
	_hitpoints = other._hitpoints;
	_energypoints = other._energypoints;
	_damage = other._damage;
	return *this;
}

void ClapTrapBase::attack(std::string const & target) const
{
	std::cout << "ClapTrap " << _name << " attack "
		<< target << " causing "
		<< _damage  << " points of damage!\n";
}

void ClapTrapBase::takeDamage(unsigned int amount)
{
	_hitpoints -= amount;
	std::cout << "ClapTrap " << _name << " take "
			<< amount << " damage\n";
}

void ClapTrapBase::beRepaired(unsigned int amount)
{
	_hitpoints -= amount;
	std::cout << "ClapTrap " << _name << " be repaired "
			<< amount << " hp\n";
	_hitpoints += amount;
	_hitpoints = std::min(_hitpoints, _max_hitpoints);
}

ClapTrapBase::~ClapTrapBase() {}

ClapTrap::ClapTrap(std::string const& name)
	: ClapTrapBase(
		name,
		_def_damage,
		_def_energypoints,
		_def_damage)
{
	std::cout << "ClapTrap " << _name << " constructor called\n";
}

ClapTrap::ClapTrap(ClapTrap const& other)
	: ClapTrapBase(other)
{
	std::cout << "ClapTrap " << _name << " copy constructor called\n";
}

ClapTrap const& ClapTrap::operator=(ClapTrap const& other)
{
	std::cout << "ClapTrap " << _name << " assigment operator called\n";
	ClapTrapBase::operator=(other);
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " destructor called\n";
}

ClapTrap::ClapTrap(
	std::string const& name,
	int hitpoints,
	int energypoints,
	int damage)
	: ClapTrapBase(
		name,
		hitpoints,
		energypoints,
		damage) {}
