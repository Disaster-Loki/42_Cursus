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

void BitcoinExchange::validate_date(std::ifstream &input) const
{
    std::string line;
    std::vector<std::string> split;
    std::vector<std::string> split2;
    std::streampos initial_pos = input.tellg();
    std::getline(input, line);
    while (std::getline(input, line))
    {
        split = BitcoinExchange::split(line, '|');
        std::string date = split.front();
        if (date.find('-') == std::string::npos)
            throw std::invalid_argument("Error: Invalid Format on Date");
        std::vector<std::string> split2 = BitcoinExchange::split(date, '-');
        std::vector<std::string>::iterator it_split = split2.begin();
        if (split2.size() != 3)
            throw std::runtime_error("Error: Invalid Format on Date");
        int year = std::atoi(it_split->c_str()); ++it_split;
        int month = std::atoi(it_split->c_str()); ++it_split;
        int day = std::atoi(it_split->c_str());

        if (day < 1 || day > 31)
            throw std::invalid_argument("Error: Invalid day on Date");
        if (month < 1 || month > 12)
            throw std::invalid_argument("Error: Invalid month on Date");
        std::time_t t = std::time(NULL);
        std::tm* now = std::localtime(&t);
        if (year < 0 || year > now->tm_year + 1900)
            throw std::invalid_argument("Error: Invalid year on Date");
    }
    input.seekg(initial_pos);
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
    std::getline(input, line);
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
                std::cout << date << " => " << value << " = " << price << std::endl;
            }
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
    input.close();
    return 0;
}
