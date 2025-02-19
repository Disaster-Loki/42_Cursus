/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:03:40 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/19 11:03:42 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
    {
        std::cout << "hit_point: " << FragTrap::hit_point << std::endl;
        std::cout << "energy_point: " << FragTrap::energy_point << std::endl;
        std::cout << "attack_damage: " << FragTrap::attack_damage << std::endl;
        std::cout << "hit_point: " << ScavTrap::hit_point << std::endl;
        std::cout << "energy_point: " << ScavTrap::energy_point << std::endl;
        std::cout << "attack_damage: " << ScavTrap::attack_damage << std::endl;
        std::cout << "hit_point: " << ClapTrap::hit_point << std::endl;
        std::cout << "energy_point: " << ClapTrap::energy_point << std::endl;
        std::cout << "attack_damage: " << ClapTrap::attack_damage << std::endl;
    	this->hit_point = FragTrap::hit_point;
    	this->energy_point = ScavTrap::energy_point;
    	this->attack_damage = FragTrap::attack_damage;
    	std::cout << "DiamondTrap " << this->name << " created!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->name << " destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    *this = copy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
    if (this != &copy)
    {
        this->name = copy.name;
        this->hit_point = copy.hit_point;
        this->energy_point = copy.energy_point;
        this->attack_damage = copy.attack_damage;
    }
    return (*this);
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am " << this->name << ", and my ClapTrap name is " << ClapTrap::name << "!" << std::endl;
}
