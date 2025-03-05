/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:04:06 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/21 09:04:08 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
	    AMateria* materials[4];
	public:
	    MateriaSource();
	    virtual ~MateriaSource();
	    MateriaSource(const MateriaSource &copy);
		MateriaSource &operator=(const MateriaSource &copy);
	    void learnMateria(AMateria* materia);
	    AMateria* createMateria(std::string const & type);
};

#endif