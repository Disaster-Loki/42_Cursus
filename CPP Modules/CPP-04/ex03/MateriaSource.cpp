/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:04:45 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/21 09:04:47 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        materials[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete materials[i];
}

void MateriaSource::learnMateria(AMateria* materia)
{
    for (int i = 0; i < 4; i++)
    {
        if (!materials[i])
        {
            materials[i] = materia;
            return ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materials[i] && materials[i]->getType() == type)
            return (materials[i]->clone());
    }
    return (0);
}

