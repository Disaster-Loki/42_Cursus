/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:38:59 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/12 15:39:01 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "===== TESTE 1: Criando ClapTrap =====" << std::endl;
    ClapTrap clap("Clappy");
    clap.attack("Enemy");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n===== TESTE 2: Criando ScavTrap =====" << std::endl;
    ScavTrap scav("Scavvy");
    scav.attack("Intruder");
    scav.takeDamage(30);
    scav.beRepaired(15);
    scav.guardGate();

    std::cout << "\n===== TESTE 3: Criando FragTrap =====" << std::endl;
    FragTrap frag("Fraggy");
    frag.attack("Villain");
    frag.takeDamage(40);
    frag.beRepaired(20);
    frag.highFivesGuys();

    std::cout << "\n===== TESTE 4: Energia e Vida Zeradas =====" << std::endl;
    FragTrap weakFrag("WeakFrag");
    weakFrag.takeDamage(100);
    weakFrag.attack("Ghost");
    weakFrag.beRepaired(50);
    weakFrag.highFivesGuys();

    std::cout << "\n===== TESTE 5: Cópia e Atribuição =====" << std::endl;
    FragTrap fragCopy(frag);
    FragTrap fragAssigned = frag;
    fragCopy.attack("CopyTarget");
    fragAssigned.highFivesGuys();

    std::cout << "\n===== TESTE 6: Destruição =====" << std::endl;
    return 0;
}
