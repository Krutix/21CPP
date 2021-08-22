#include "ClapTrap.hpp"

int main()
{
	ClapTrap cl("Billi Milligan");
	ClapTrap cl2(cl);
	cl.attack("cl2");
	cl2.takeDamage(0);
	cl.beRepaired(10);
}
