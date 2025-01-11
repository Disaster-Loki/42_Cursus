/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:16:38 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/11 12:26:13 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string var = "HI THIS IS BRAIN";
	std::string *stringPTR = &var;
	std::string& stringREF = var;

	std::cout << &var << std::endl;
	std::cout << &(*stringPTR) << std::endl;
	std::cout << stringREF << std::endl;
	std::cout << var << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << std::endl;
	return (0);
}
