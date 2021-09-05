#pragma once
#include <string>

class AMateria;

class ICharacter
{
public:
    virtual ~ICharacter() {};
    virtual std::string const& getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
public:
    Character(std::string const& name);

    std::string const& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);

private:
    std::string m_name;
    AMateria*   m_materia[4];
    size_t      m_next_id;
};
