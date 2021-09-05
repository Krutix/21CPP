#pragma once
#include <string>

class AMateria;

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;
};

class MateriaSource : public IMateriaSource
{
public:
    void learnMateria(AMateria* learn);
    AMateria* createMateria(std::string const& type);

private:
    AMateria* m_learn;
};
