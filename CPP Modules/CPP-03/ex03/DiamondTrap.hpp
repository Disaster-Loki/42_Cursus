/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:03:34 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/19 11:03:36 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
	    std::string name;
	public:
	    DiamondTrap(std::string name);
	    ~DiamondTrap();
	    DiamondTrap(const DiamondTrap &copy);
	    DiamondTrap &operator=(const DiamondTrap &copy);
	    void attack(const std::string &target);
	    void whoAmI();
};

#endif