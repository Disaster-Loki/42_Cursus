/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:22:35 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/30 16:22:37 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <string>
#include <ctime>
#include <vector>
#include <map>

class BitcoinExchange {
private:
    std::map<std::string, double> database;
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const std::string & file);
    BitcoinExchange(const BitcoinExchange& copy);
    BitcoinExchange& operator=(const BitcoinExchange& copy);

    void showDatabase() const;
    std::vector<std::string> split(std::string s, char del) const;
    void loadDatabase(const std::string filename);
    double getValue(std::string date) const;
    int showPriceBitcoin(const std::string filename) const;
    std::string trim(const std::string& str) const;
};

#endif