/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:25:38 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/18 14:30:32 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    std::cout << "[DEBUG]" << std::endl;
    harl.complain("DEBUG");
    std::cout << "[INFO]" << std::endl;
    harl.complain("INFO");
    std::cout << "[WARNING]" << std::endl;
    harl.complain("WARNING");
    std::cout << "[ERROR]" << std::endl;
    harl.complain("ERROR");
    return 0;
}