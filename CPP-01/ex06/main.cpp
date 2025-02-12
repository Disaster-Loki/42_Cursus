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

int main(int argc, char **argv) 
{
    if (argc != 2) {
        std::cout << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }
    Harl harl;
    harl.complain(argv[1]);

    return 0;
}