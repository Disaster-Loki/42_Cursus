/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:30:45 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/11 13:41:14 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private: std::string name;
	public:
		 Zombie();
		 ~Zombie();
		 void announce(void);
		 void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif
