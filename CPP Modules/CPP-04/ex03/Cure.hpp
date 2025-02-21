/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:56:51 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 13:56:53 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		virtual ~Cure();
		Cure(const Cure &copy);
		Cure &operator=(const Cure &copy);
		virtual AMateria* clone() const;
		const std::string &getType() const;
		virtual void use(ICharacter& target);
};

#endif
