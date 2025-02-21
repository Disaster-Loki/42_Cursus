/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:48:20 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 13:48:22 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(std::string const & type);
		virtual ~AMateria();
		AMateria(const AMateria &copy);
		AMateria &operator=(const AMateria &copy);
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
