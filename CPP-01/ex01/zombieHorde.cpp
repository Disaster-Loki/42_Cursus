/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:38:06 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/11 13:48:19 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i] = Zombie(name);
	return (&horde[N-N]);
}
