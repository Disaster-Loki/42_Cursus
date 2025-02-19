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

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "===== TESTE 1: Criando DiamondTrap =====" << std::endl;
    DiamondTrap diamond("Diamondy");
    diamond.attack("Target");
    diamond.whoAmI();

    std::cout << "\n===== TESTE 2: Energia e Vida Zeradas =====" << std::endl;
    DiamondTrap weakDiamond("WeakDiamond");
    weakDiamond.attack("Ghost");
    weakDiamond.whoAmI();

    std::cout << "\n===== TESTE 3: Cópia e Atribuição =====" << std::endl;
    DiamondTrap copyDiamond(diamond);
    DiamondTrap assignedDiamond = diamond;
    copyDiamond.attack("CopyTarget");
    assignedDiamond.whoAmI();

    std::cout << "\n===== TESTE 4: Destruição =====" << std::endl;
    return 0;
}
