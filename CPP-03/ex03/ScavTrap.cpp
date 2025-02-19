/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:05:43 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/18 11:05:44 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hit_point = 100;
    this->energy_point = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << this->name << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called for " << copy.name << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "ScavTrap copy assignment operator called for " << copy.name << std::endl;
    if (this != &copy)
    {
        ClapTrap::operator=(copy);
    }
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    std::cout << "ScavTrap " << this->name<< " attacks "
              << target << ", causing " << this->attack_damage
              << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    this->hit_point = this->hit_point - amount;
    if (this->hit_point < 0)
        this->hit_point = 0;
    std::cout << "ScavTrap " << this->name << " takes "
              << amount << " points of damage!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (this->energy_point > 0 && this->hit_point > 0)
    {
        this->hit_point += amount;
        this->energy_point -= 1;
        std::cout << "ScavTrap " << this->name << " repairs itself, recovering "
                  << amount << " hit points!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->name << " has no energy to repair!" << std::endl;
}
