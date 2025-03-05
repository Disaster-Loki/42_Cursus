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
    std::cout << "M-Source default constructor called "<< std::endl;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete materials[i];
    std::cout << "M-Source destructor called "<< std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    *this = copy;
    std::cout << "M-Source copy constructor called" << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 4; i++)
        {
            delete materials[i];
            materials[i] = NULL;
        }
        for (int i = 0; i < 4; i++)
        {
            if (copy.materials[i])
                materials[i] = copy.materials[i]->clone();
            else
                materials[i] = NULL;
        }
        std::cout << "M-Source copy assignment operator called" << std::endl;
    }
    return *this;
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

