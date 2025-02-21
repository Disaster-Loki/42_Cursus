/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:53:51 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 09:53:53 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		~Dog();
		Dog &operator=(const Dog &copy);
		Dog(const Dog &copy);
		void makeSound() const;
		std::string getType() const;
};

#endif

