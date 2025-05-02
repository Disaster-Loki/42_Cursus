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

int	main(void)
{
	ClapTrap A("Toki");
	A.attack("Hami");
	A.beRepaired(1);
	A.beRepaired(2);
	A.beRepaired(3);

	std::cout << "---- Testing default constructor ----" << std::endl;
	ClapTrap B;
	B.attack("Enemy");

	std::cout << "---- Testing copy constructor ----" << std::endl;
	ClapTrap C(A);

	std::cout << "---- Testing copy assignment ----" << std::endl;
	B = C;
	B.attack("Someone");

	return 0;
}
