/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:39:24 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/12 15:39:26 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name), hit_point(100), energy_point(100), attack_damage(30)
{
	std::cout << "Default constructor called " << name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called " << name << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy construtor called " << name << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
	    this->name = copy.name;
	    this->hit_point = copy.hit_point;
	    this->energy_point = copy.energy_point;
	    this->attack_damage = copy.attack_damage;
        std::cout << "Copy assignment operator called " << name << std::endl;
	}
	return (*this);
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->hit_point -= amount;
    if (this->hit_point < 0)
        this->hit_point = 0;
    std::cout << "ClapTrap " << this->name << " takes "
              << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energy_point > 0 && this->hit_point > 0)
    {
        this->hit_point += amount;
        this->energy_point -= 1;
        std::cout << "ClapTrap " << this->name << " repairs itself, recovering "
                  << amount << " hit points!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " has no energy to repair!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energy_point > 0 && this->hit_point > 0)
    {
        this->energy_point -= 1;
        std::cout << "ClapTrap " << this->name << " attacks "
                  << target << ", causing " << this->attack_damage
                  << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << this->name << " has no energy to attack!" << std::endl;
}