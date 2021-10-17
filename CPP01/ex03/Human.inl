#include "Human.hpp"

inline Weapon::Weapon(std::string const& type) : type(type) {}
inline void Weapon::setType(std::string const& type) { this->type = type; }
inline std::string const& Weapon::getType() const { return type; }

inline HumanA::HumanA(std::string const& name, Weapon& weapon) : name(name), weapon(weapon) {}

inline void HumanA::attack() const
{
    std::cout << name << " attacks with his " << weapon.getType() << '\n';
}

inline void HumanA::setWeapon(Weapon& weapon) { this->weapon = weapon; }

inline HumanB::HumanB(std::string const& name) : name(name), weapon(NULL) {}

inline void HumanB::attack() const
{
    std::cout << name << " attacks with his ";
    if (weapon)
        std::cout << weapon->getType() << '\n';
    else
        std::cout << "arms" << '\n';
}

inline void HumanB::setWeapon(Weapon& weapon) { this->weapon = &weapon; }
