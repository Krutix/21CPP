#include "ICharacter.hpp"
#include "AMateria.hpp"

Character::Character(std::string const& name)
        : m_name(name)
{
    m_next_id = 0;
    for (size_t idx = 0; idx < 4; idx++)
        m_materia[idx] = NULL;
}

std::string const& Character::getName() const
{
    return m_name;
}

void Character::equip(AMateria* m)
{
    if (!(m_next_id < 4))
        return ;
    m_materia[m_next_id++] = m;
}
void Character::unequip(int idx)
{
    if (!(0 <= idx && idx < 4))
        return ;
    m_next_id -= m_materia[idx] == NULL;
    m_materia[idx] = NULL;
    for ((void)idx; idx < 4 - 1; idx++)
        m_materia[idx] = m_materia[idx + 1];
}

void Character::use(int idx, ICharacter& target)
{
    if (!(0 <= idx && idx < 4))
        return ;
    if (m_materia[idx])
        m_materia[idx]->use(target);
}
