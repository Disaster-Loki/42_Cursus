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

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name)
{
    this->hit_point = FragTrap::hit_point;       // ou: 100
    this->hit_point = 100;                       // ou: 100
    std::cout << "Hit_point: " << this->hit_point << std::endl;
    this->energy_point = ScavTrap::energy_point; // ou: 50
    this->energy_point = 50;                     // ou: 50
    std::cout << "Energy_point: " << this->energy_point << std::endl;
    this->attack_damage = FragTrap::attack_damage; // ou: 30
    this->attack_damage = 30;                      // ou: 30
    std::cout << "Attack_damage: " << this->attack_damage << std::endl;
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
