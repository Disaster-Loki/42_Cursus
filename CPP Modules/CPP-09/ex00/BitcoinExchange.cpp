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

BitcoinExchange::BitcoinExchange(const std::string & file) {
    BitcoinExchange::loadDatabase(file);
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

    while (start < str.size() && std::isspace(str[start]))
        start++;
    while (end > start && std::isspace(str[end]))
        end--;
    return (str.substr(start, end - start + 1));
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

std::vector<std::string> BitcoinExchange::split(std::string s, char del) const {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string word;
    while (std::getline(ss, word, del)) {
        word = BitcoinExchange::trim(word);
        result.push_back(word);
    }
    return result;
}

void BitcoinExchange::loadDatabase(const std::string filename)
{
    std::string line;
    std::vector<std::string> split;
    std::ifstream input(filename.c_str());

    if (!input.is_open()) {
        throw std::runtime_error("Error: Could not open database file");
    }
    if (std::getline(input, line))
    {
        if (line.find(',') == std::string::npos)
            throw std::runtime_error("Error: Missing ',' in line: " + line);
        split = BitcoinExchange::split(line, ',');
        if (split[0].empty() || split[1].empty())
            throw std::runtime_error("Error: Invalid line in database");
        if (split[0] != "date" || split[1] != "exchange_rate")
            throw std::runtime_error("Error: Invalid first line in database");
    }
    if (line.empty())
        throw std::runtime_error("Error: Empty dateabase");
    line = "";
    while (std::getline(input, line)) {
        split = BitcoinExchange::split(line, ',');
        if (split.size() == 2) {
            std::string date = split.front();
            std::string value_str = split.back();
            double value = std::atof(value_str.c_str());

            if (value >= 0) {
                this->database[date] = value;
            } else {
                throw std::runtime_error("Error: Invalid value: " + value_str + "in database");
            }
        } else {
            throw std::runtime_error("Error: Invalid line: " + line + " in database");
        }
    }
    if (line.empty())
        throw std::runtime_error("Error: Empty data in dateabase");
}

double BitcoinExchange::getValue(std::string date) const
{
    if (database.empty()) return -1;

    std::map<std::string, double>::const_iterator it = database.find(date);
    if (it != database.end()) {
        return it->second;
    }

    std::vector<std::string> split = BitcoinExchange::split(date, '-');
    std::vector<std::string>::iterator it_split = split.begin();
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

int BitcoinExchange::showPriceBitcoin(const std::string filename) const
{
    double value;
    double price;
    std::string line;
    std::string date;
    std::string value_str;
    std::vector<std::string> split;
    std::ifstream input(filename.c_str());

    if (!input.is_open()) {
        throw std::runtime_error("Error: Could not open file.");
    }
    if (database.empty()){
        throw std::runtime_error("Error: Not found database");
    }
    if (std::getline(input, line))
    {
        if (line.find('|') == std::string::npos)
            throw std::runtime_error("Error: Missing '|' in line: " + line);
        std::vector<std::string> spl = BitcoinExchange::split(line, '|');
        if (spl[0].empty() || spl[1].empty())
            throw std::runtime_error("Error: Invalid line in file");
        if (spl[0] != "date" || spl[1] != "value")
            throw std::runtime_error("Error: First line invalid");
    }
    if (line.empty())
        throw std::runtime_error("Error: Empty file");
    line = "";
    while (std::getline(input, line)) {
        split = BitcoinExchange::split(line, '|');
        if (split.size() == 2)
        {
            date = split.front();
            value_str = split.back();
            value = std::atof(value_str.c_str());
            if (value > 0 && value <= 1000)
            {
                price = value * BitcoinExchange::getValue(date);
                if (price < 0)
                    std::cout << "Error: value not found" << std::endl;
                else 
                    std::cout << date << " => " << value << " = " << price << std::endl;
            }
            else if (value == 0)
                std::cout << "Error: neutral number" << std::endl;
            else if (value > 1000)
                std::cout << "Error: too large a number." << std::endl;
            else if ( value < 0)
                std::cout << "Error: not a positive number." << std::endl;
        }
        else
        {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }
    if (line.empty())
        throw std::runtime_error("Error: Empty data");
    input.close();
    return 0;
}
