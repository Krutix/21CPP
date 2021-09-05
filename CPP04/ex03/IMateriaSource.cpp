#include "IMateriaSource.hpp"
#include "AMateria.hpp"

void MateriaSource::learnMateria(AMateria* learn)
{
    delete m_learn;
    m_learn = learn->clone();
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    if (type != m_learn->getType())
        return NULL;

    return m_learn->clone();
}
