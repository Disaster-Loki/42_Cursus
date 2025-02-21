/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:02:26 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/21 09:02:29 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const & name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = NULL;
}

Character::Character(const Character& copy) : name(copy.name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = copy.inventory[i] ? copy.inventory[i]->clone() : NULL;
}

Character& Character::operator=(const Character& copy)
{
    if (this != &copy)
    {
        name = copy.name;
        for (int i = 0; i < 4; i++)
        {
            delete inventory[i];
            inventory[i] = copy.inventory[i] ? copy.inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
        delete inventory[i];
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!inventory[i])
        {
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx])
        inventory[idx]->use(target);
}