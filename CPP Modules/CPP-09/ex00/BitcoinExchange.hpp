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

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cctype>

class BitcoinExchange {
private:
    std::map<std::string, double> database;
    std::map<std::string, double> file;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& copy);
    BitcoinExchange& operator=(const BitcoinExchange& copy);

    void showDatabase() const;
    std::list<std::string> split(std::string s, char del) const;
    void loadDatabase(const std::string filename);
    int openFile(const std::string filename);
    double getValue(std::string date) const;
    void showPriceBitcoin() const;
    std::string trim(const std::string& str) const;
};

#endif