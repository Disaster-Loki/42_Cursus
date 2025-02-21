/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 11:06:52 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 11:06:55 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal
{
	protected:
	    std::string type;
	public:
	    WrongAnimal();
	    virtual ~WrongAnimal();
	    WrongAnimal(const WrongAnimal &copy);
	    WrongAnimal &operator=(const WrongAnimal &copy);
	    void makeSound() const;
	    std::string getType() const;
};

#endif