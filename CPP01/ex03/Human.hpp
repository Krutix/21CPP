#include <string>
#include <iostream>

class Weapon
{
public:
    Weapon(std::string const& type) : type(type) {}
    void setType(std::string const& type) { this->type = type; }
    std::string const& getType() const { return type; }
private:
    std::string type;
};

class HumanA
{
public:
    HumanA(std::string const& name, Weapon& weapon) : name(name), weapon(weapon) {}

    void attack() const
    {
        std::cout << name << " attacks with his " << weapon.getType() << '\n';
    }

    void setWeapon(Weapon& weapon) { this->weapon = weapon; }
private:
    std::string name;
    Weapon& weapon;
};

class HumanB
{
public:
    HumanB(std::string const& name) : name(name), weapon(NULL) {}

    void attack() const
    {
        std::cout << name << " attacks with his ";
        if (weapon)
            std::cout << weapon->getType() << '\n';
        else
            std::cout << "arms" << '\n';
    }

    void setWeapon(Weapon& weapon) { this->weapon = &weapon; }
private:
    std::string name;
    Weapon* weapon;
};
