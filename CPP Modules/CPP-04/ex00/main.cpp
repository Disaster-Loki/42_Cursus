/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:37:56 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 09:37:58 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "----- Testing Animal, Cat & Dog -----" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;

    std::cout << "----- Testing WrongAnimal & WrongCat -----" << std::endl;
    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    std::cout << wc->getType() << " " << std::endl;
    wc->makeSound();
    wa->makeSound();

    delete wa;
    delete wc;

    return (0);
}
