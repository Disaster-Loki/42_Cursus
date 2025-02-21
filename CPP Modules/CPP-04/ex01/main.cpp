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
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    std::cout << "\n----- Testing Brain, Dog & Cat -----" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i; 

    std::cout << "\n----- Testing WrongAnimal & WrongCat -----" << std::endl;
    const WrongAnimal* wa = new WrongAnimal();
    const WrongAnimal* wc = new WrongCat();

    std::cout << wc->getType() << " " << std::endl;
    wc->makeSound();
    wa->makeSound();

    delete wa;
    delete wc;

    std::cout << "\n----- Testing Deep Copy -----" << std::endl;

    Dog original;
    original.makeSound();

    Dog copy(original);
    copy.makeSound();

    std::cout << "\n----- Testing Array of Animals -----" << std::endl;

    Animal* animals[4];
    for (int i = 0; i < 2; i++)
        animals[i] = new Dog();
    for (int i = 2; i < 4; i++)
        animals[i] = new Cat();
    std::cout << "\n----- Testing Delete Array of Animals -----" << std::endl;
    for (int i = 0; i < 4; i++)
        delete animals[i];
    return (0);
}
