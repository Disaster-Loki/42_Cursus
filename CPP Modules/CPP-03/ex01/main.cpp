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

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

    std::cout << "\n===== TESTE 3: Energia e Vida Zeradas =====" << std::endl;
    ClapTrap weak("WeakTrap");
    weak.takeDamage(15);
    weak.attack("Ghost");
    weak.beRepaired(5);

    std::cout << "\n===== TESTE 4: Cópia e Atribuição =====" << std::endl;
    ScavTrap scavCopy(scav);
    ScavTrap scavAssigned = scav;
    scavCopy.attack("CopyTarget");
    scavAssigned.guardGate();

    std::cout << "\n===== TESTE 5: Destruição =====" << std::endl;
    return 0;
}