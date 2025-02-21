/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:56:34 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 13:56:36 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called " << std::endl;
}

Ice::~Ice()
{
	std::cout << "Destructor called " << std::endl; 
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
	std::cout << "Copy construtor called" << std::endl;
	*this = copy;
}

Ice &Ice::operator=(const Ice &copy)
{
	if (this != &copy)
	    this->type = copy.type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

const std::string &Ice::getType() const { return (type); }

AMateria* Ice::clone() const { return (new Ice(*this)); }

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
