#include "IMateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaList::MateriaList(AMateria* materia, MateriaList* next)
    : materia(materia), next(next) {}

MateriaSource::MateriaList::~MateriaList()
{
    delete next;
    delete materia;
}

void MateriaSource::learnMateria(AMateria* learn)
{
    m_learn = new MateriaList(learn, m_learn);
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    MateriaList* t = m_learn;
    while (t)
    {
        if (t->materia->getType() == type)
            return t->materia->clone();
        t = t->next;
    }
    return NULL;
}

MateriaSource::~MateriaSource()
{
    delete m_learn;
}
