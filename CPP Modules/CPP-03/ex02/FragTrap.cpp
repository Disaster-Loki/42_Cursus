/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:36:12 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/19 10:36:15 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    this->hit_point = 100;
    this->energy_point = 100;
    this->attack_damage = 30;
	std::cout << "FragTrap default constructor called " << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hit_point = 100;
    this->energy_point = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap constructor called for " << name << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << this->name << std::endl;
}

void FragTrap::highFivesGuys()
{
	  std::cout << "FragTrap " << this->name << " ask for a high five! ✋😃" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor called for " << copy.name << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    if (this != &copy)
    {
        ClapTrap::operator=(copy);
         std::cout << "FragTrap copy assignment operator called for " << copy.name << std::endl;
    }
    return (*this);
}

void FragTrap::attack(const std::string& target)
{
    if (this->energy_point > 0 && this->hit_point > 0)
    {
        this->energy_point -= 1;
        std::cout << "FragTrap " << this->name << " attacks "
              << target << ", causing " << this->attack_damage
              << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->name << " has no energy to attack!" << std::endl;
}