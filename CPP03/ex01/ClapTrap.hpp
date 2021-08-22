#include <iostream>
#include <string>

class ClapTrapBase
{
public:
	void attack(std::string const & target) const;

	void takeDamage(unsigned int amount);

	void beRepaired(unsigned int amount);
protected:
	std::string	_name;
	int		_max_hitpoints;
	int		_hitpoints;
	int		_energypoints;
	int		_damage;

	ClapTrapBase(
		std::string const& name,
		int hitpoints,
		int energypoints,
		int damage);

	ClapTrapBase(ClapTrapBase const&);

	virtual ClapTrapBase const& operator=(ClapTrapBase const& other) = 0;

	virtual ~ClapTrapBase() = 0;
};

class ClapTrap : public ClapTrapBase
{
public:
	ClapTrap(std::string const& name = "-");

	ClapTrap(ClapTrap const& other);

	ClapTrap const& operator=(ClapTrap const& other);

	~ClapTrap();

protected:
	static int const _def_hitpoints = 10;
	static int const _def_energypoints = 10;
	static int const _def_damage = 0;

protected:
	ClapTrap(
		std::string const& name,
		int hitpoints,
		int energypoints,
		int damage);
};
