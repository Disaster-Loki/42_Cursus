/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:22:39 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/30 16:22:40 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {}

unsigned int BitcoinExchange::open_file(const std::string filename)
{
    std::ifstream input (filename.c_str());
    if (!input.is_open())
    {
        std::cout << "Error: Could not open file" << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(input, line))
    {
        
    }
    return (0);
}