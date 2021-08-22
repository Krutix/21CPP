#include "ScavTrap.hpp"

int main()
{
	{
		ClapTrap cl("Billi Milligan");
		ClapTrap cl2("Miya Atsumu");
		cl.attack("cl2");
		cl2.takeDamage(0);
		cl.beRepaired(10);
	}
	{
		ScavTrap st("Serena");
		st.beRepaired(10);
		st.attack("Dillyuk");
		st.guardGate();
	}
}
