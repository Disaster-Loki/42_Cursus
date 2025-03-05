/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:56:57 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 13:56:59 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called " << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called " << std::endl; 
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
	std::cout << "Cure copy construtor called" << std::endl;
	*this = copy;
}

Cure &Cure::operator=(const Cure &copy)
{
	if (this != &copy)
	    this->type = copy.type;
	std::cout << "Cure copy assignment operator called" << std::endl;
	return (*this);
}

const std::string &Cure::getType() const { return (type); }

AMateria* Cure::clone() const { return (new Cure(*this)); }

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << " 's wounds *" << std::endl;
}