/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:19:40 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 15:19:42 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

class AMateria;

class ICharacter
{
	public:
	    virtual ~ICharacter() {}
	    virtual std::string const & getName() const = 0;
	    virtual void equip(AMateria* m) = 0;
	    virtual void unequip(int idx) = 0;
	    virtual void use(int idx, ICharacter& target) = 0;
};

#endif