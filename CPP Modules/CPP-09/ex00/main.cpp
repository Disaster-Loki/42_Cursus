/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:22:09 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/30 16:22:11 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int av, char **args) {
    if (av != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    try {
        BitcoinExchange bitcoin;
        std::string file = args[1];
        bitcoin.openFile(file);
        bitcoin.showPriceBitcoin();
        //bitcoin.showDatabase();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}

