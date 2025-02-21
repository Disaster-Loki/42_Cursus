/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:39:13 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/12 15:39:16 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAPTRAP_HPP
#define	CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
	private:
		std::string name;
		int hit_point;
		int energy_point;
		int attack_damage;
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &copy);
		ClapTrap &operator=(const ClapTrap &copy);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
