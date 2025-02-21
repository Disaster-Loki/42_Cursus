/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:56:40 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 13:56:42 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		virtual ~Ice();
		Ice(const Ice &copy);
		Ice &operator=(const Ice &copy);
		const std::string &getType() const;
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif