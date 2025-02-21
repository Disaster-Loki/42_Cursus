/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:54:05 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 09:54:06 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		~Cat();
		Cat &operator=(const Cat &copy);
		Cat(const Cat &copy);
		void makeSound() const;
		std::string getType() const;
};

#endif

