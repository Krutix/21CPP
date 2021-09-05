#pragma once
#include <string>

class ICharacter;

class AMateria
{
public:
    AMateria(std::string const& type);
    virtual ~AMateria();
    std::string const& getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target) = 0;

protected:
    std::string m_type;
};

class Ice : public AMateria
{
public:
    Ice();
    AMateria* clone() const;
    void use(ICharacter& target);
};

class Cure : public AMateria
{
public:
    Cure();
    AMateria* clone() const;
    void use(ICharacter& target);
};
