/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:36:09 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/18 12:36:15 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {}

void HumanB::setWeapon(Weapon &weapon)
{
    humanB = weapon;
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << humanB.getType() << std::endl;
}

