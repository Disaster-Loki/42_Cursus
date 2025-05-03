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

BitcoinExchange::BitcoinExchange() {
    BitcoinExchange::loadDatabase("data.csv");
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
    if (this != &copy) {
        this->database = copy.database;
    }
    return (*this);
}

std::string BitcoinExchange::trim(const std::string& str) const{
    size_t start = 0;
    size_t end = str.size() - 1;

    while (start < str.size() && std::isspace(str[start])) {
        start++;
    }
    while (end > start && std::isspace(str[end])) {
        end--;
    }
    return str.substr(start, end - start + 1);
}

void BitcoinExchange::showDatabase() const {
    std::map<std::string, double>::const_iterator it;
    if (database.empty()) {
        std::cout << "Database is empty." << std::endl;
        return;
    }
    for (it = database.begin(); it != database.end(); ++it) {
        std::cout << "Date: " << it->first << ", Value: "
                  << std::fixed << std::setprecision(2) << it->second << std::endl;
    }
}

std::list<std::string> BitcoinExchange::split(std::string s, char del) const {
    std::list<std::string> result;
    std::stringstream ss(s);
    std::string word;
    while (std::getline(ss, word, del)) {
        word = BitcoinExchange::trim(word);
        result.push_back(word);
    }
    return result;
}

void BitcoinExchange::loadDatabase(const std::string filename) {
    std::string line;
    std::list<std::string> split;
    std::ifstream input(filename.c_str());

    if (!input.is_open()) {
        std::cout << "Error: Could not open file" << std::endl;
        return;
    }
    std::getline(input, line);
    while (std::getline(input, line)) {
        split = BitcoinExchange::split(line, ',');
        if (split.size() == 2) {
            std::string date = split.front();
            std::string value_str = split.back();
            double value = std::atof(value_str.c_str());

            if (value >= 0) {
                this->database[date] = value;
            } else {
                std::cout << "Invalid value: " << value_str << std::endl;
            }
        } else {
            std::cout << "Invalid line: " << line << std::endl;
        }
    }
}

int BitcoinExchange::openFile(const std::string filename) {
    std::string line;
    std::list<std::string> split;
    std::ifstream input(filename.c_str());

    if (!input.is_open()) {
        throw std::runtime_error("Error: Could not open file");
    }
    std::getline(input, line);
    while (std::getline(input, line)) {
        split = BitcoinExchange::split(line, '|');
        std::cout << "Line: " << line << std::endl;
        if (split.size() == 2) {
            std::string date = split.front();
            std::string value_str = split.back();
            std::cout << "Date: " << date << std::endl;
            std::cout << "Value: " << value_str << std::endl;
            double value = std::atof(value_str.c_str());
            if (value > 0 && value <= 1000) {
                this->file[date] = value;
            } else {
                std::cout << "Error: not a positive number." << std::endl;
                return 1;
            }
        } else {
            std::cout << "Error: bad input => " << line << std::endl;
            return 1;
        }
    }
    input.close();
    return 0;
}

double BitcoinExchange::getValue(std::string date) const {
    if (database.empty()) return -1;

    std::map<std::string, double>::const_iterator it = database.find(date);
    if (it != database.end()) {
        return it->second;
    }

    std::list<std::string> split = BitcoinExchange::split(date, '-');
    std::list<std::string>::iterator it_split = split.begin();
    int year = std::atoi(it_split->c_str());
    ++it_split;
    int month = std::atoi(it_split->c_str());
    ++it_split;
    int day = std::atoi(it_split->c_str());

    std::string closestDate;
    double closestValue = -1;
    while (closestValue == -1) {
        if (day > 1) {
            day--;
        } else {
            day = 31;
            if (month > 1) {
                month--;
            } else {
                month = 12;
                year--;
            }
        }
        std::stringstream ss;
        ss << year;
        std::string year_str = ss.str();
        std::stringstream month_stream, day_stream;
        month_stream << (month < 10 ? "0" : "") << month;
        day_stream << (day < 10 ? "0" : "") << day;

        closestDate = year_str + "-" + month_stream.str() + "-" + day_stream.str();

        it = database.find(closestDate);
        if (it != database.end()) {
            closestValue = it->second;
            return closestValue;
        }

        if (year < 0) {
            break;
        }
    }
    return -1;
}

void BitcoinExchange::showPriceBitcoin() const {
    std::map<std::string, double>::const_iterator it;
    if (file.empty()) {
        std::cout << "File is empty." << std::endl;
        return;
    }
    for (it = file.begin(); it != file.end(); ++it) {
        std::string date = it->first;
        double value = BitcoinExchange::getValue(date);
        double price = it->second * value;
        if (price == -1) {
            std::cout << "Error 404: Not Found" << std::endl;
            return;
        }
        //std::cout << it->first << " => " << it->second << " = " << price << std::endl;
    }
}
