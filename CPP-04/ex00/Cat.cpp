/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:54:09 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 09:54:11 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
    this->type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
        Animal::operator=(copy);
    std::cout << this->getType() << " copy assignment operator called" << std::endl;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << this->getType() << ": Meow meow meow meow!" << std::endl;
}

std::string Cat::getType() const
{
    return (this->type);
}

