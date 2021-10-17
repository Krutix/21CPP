#pragma once
#include <string>
#include <iostream>

class Weapon
{
public:
    Weapon(std::string const& type);
    void setType(std::string const& type);
    std::string const& getType() const;
private:
    std::string type;
};

class HumanA
{
public:
    HumanA(std::string const& name, Weapon& weapon);

    void attack() const;
    void setWeapon(Weapon& weapon);
private:
    std::string name;
    Weapon& weapon;
};

class HumanB
{
public:
    HumanB(std::string const& name);

    void attack() const;
    void setWeapon(Weapon& weapon);
private:
    std::string name;
    Weapon* weapon;
};

#include "Human.inl"
