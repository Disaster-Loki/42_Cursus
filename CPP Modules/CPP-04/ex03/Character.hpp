/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:19:45 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 15:19:47 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
	    std::string name;
	    AMateria* inventory[4];
	public:
	    Character(std::string const & name);
	    Character(const Character& other);
	    Character& operator=(const Character& other);
	    virtual ~Character();
	    std::string const & getName() const;
	    void equip(AMateria* m);
	    void unequip(int idx);
	    void use(int idx, ICharacter& target);
};

#endif