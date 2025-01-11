/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:18:21 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/11 11:58:55 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class Zombie
{
	private: std::string name;

	public:
		 Zombie(std::string name);
		 ~Zombie(); 
		 void	 announce( void );
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
