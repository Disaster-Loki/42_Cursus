/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:48:25 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 13:48:48 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): type(type)
{
	std::cout << "Default constructor called " << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Destructor called " << std::endl; 
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << "Copy construtor called" << std::endl;
	*this = copy;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	if (this != &copy)
	    this->type = copy.type;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

std::string const & AMateria::getType() const { return (type); }

void AMateria::use(ICharacter& target) { (void)target; }
