/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:23:23 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/18 12:24:48 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() : type("") {}

Weapon::Weapon(std::string type) : type(type) {}

std::string	Weapon::getType() { return (type); }

void Weapon::setType(const std::string& newtype) { type = newtype; }