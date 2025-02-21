/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:06:59 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 11:07:01 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = "None WrongAnimal";
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    *this = copy;
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a generic sound!" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}