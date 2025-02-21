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
    std::cout << "FragTrap copy assignment operator called for " << copy.name << std::endl;
    if (this != &copy)
    {
        ClapTrap::operator=(copy);
    }
    return (*this);
}

void FragTrap::attack(const std::string& target)
{
    std::cout << "FragTrap " << this->name << " attacks "
              << target << ", causing " << this->attack_damage
              << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    this->hit_point -= amount;
    if (this->hit_point < 0)
        this->hit_point = 0;
    std::cout << "FragTrap " << this->name << " takes "
              << amount << " points of damage!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (this->energy_point > 0 && this->hit_point > 0)
    {
        this->hit_point += amount;
        this->energy_point -= 1;
        std::cout << "FragTrap " << this->name << " repairs itself, recovering "
                  << amount << " hit points!" << std::endl;
    }
    else
        std::cout << "FragTrap " << this->name << " has no energy to repair!" << std::endl;
}
