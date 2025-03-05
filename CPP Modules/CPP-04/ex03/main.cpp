/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:16:05 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/20 13:16:09 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void testMateriaSource()
{
    std::cout << "\n----- Testing MateriaSource -----" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    AMateria* tmp1 = src->createMateria("ice");
    AMateria* tmp2 = src->createMateria("cure");
    AMateria* tmp3 = src->createMateria("unknown");
    
    std::cout << "Materia created: " << (tmp1 ? tmp1->getType() : "NULL") << std::endl;
    std::cout << "Materia created: " << (tmp2 ? tmp2->getType() : "NULL") << std::endl;
    std::cout << "Materia created: " << (tmp3 ? tmp3->getType() : "NULL") << std::endl;
    
    delete tmp1;
    delete tmp2;
    delete src;
}

void testCharacter()
{
    std::cout << "\n----- Testing Character -----" << std::endl;
    ICharacter* me = new Character("me");
    ICharacter* bob = new Character("bob");
    
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    
    me->equip(ice);
    me->equip(cure);
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
}

void testInventory()
{
    std::cout << "\n----- Testing Inventory Limits -----" << std::endl;
    ICharacter* player = new Character("player");
    
    AMateria* ice1 = new Ice();
    AMateria* ice2 = new Ice();
    AMateria* cure1 = new Cure();
    AMateria* cure2 = new Cure();
    AMateria* extra = new Ice();
    
    player->equip(ice1);
    player->equip(ice2);
    player->equip(cure1);
    player->equip(cure2);
    player->equip(extra);
    
    player->use(0, *player);
    player->use(1, *player);
    player->use(2, *player);
    player->use(3, *player);
    player->use(4, *player);
    
    player->unequip(2);
    player->unequip(3);
    player->unequip(4);
    
    delete extra;
    delete player;
}

void testDeepCopy()
{
    std::cout << "\n----- Testing Deep Copy -----" << std::endl;
    Character original("Original");
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    original.equip(ice);
    original.equip(cure);
    
    Character copy(original);
    
    std::cout << "Original using materia:" << std::endl;
    original.use(0, original);
    original.use(1, original);
    
    std::cout << "Copy using materia:" << std::endl;
    copy.use(0, copy);
    copy.use(1, copy);
}

int main()
{
    std::cout << "\n----- Testing Subject -----" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
    testMateriaSource();
    testCharacter();
    testInventory();
    testDeepCopy();
    return 0;
}
