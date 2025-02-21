/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:53:56 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 09:53:59 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal()
{
    this->type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
    brain = new Brain();
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*copy.brain);
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
        delete brain;
        brain = new Brain(*copy.brain);
    }
    std::cout << this->getType() << " copy assignment operator called" << std::endl;
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << this->getType() << ": Woof woof woof woof!" << std::endl;
}

std::string Dog::getType() const
{
    return (this->type);
}
