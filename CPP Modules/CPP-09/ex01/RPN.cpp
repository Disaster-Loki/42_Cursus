#include "RPN.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:24:19 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/30 16:24:20 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

RPN::RPN(): value (0) {}
RPN::~RPN() {}

RPN::RPN(const std::string &args)
{
    RPN::processingRPN(args);
}

RPN::RPN(const RPN &copy) { *this = copy; }

RPN &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
        this->value = copy.value;
    return (*this);
}

std::string RPN::trim(const std::string& str) const{
    size_t start = 0;
    size_t end = str.size() - 1;

    while (start < str.size() && std::isspace(str[start]))
        start++;
    while (end > start && std::isspace(str[end]))
        end--;
    return (str.substr(start, end - start + 1));
}

std::vector<std::string> RPN::split(const std::string str, char del) const
{
    std::string line;
    std::stringstream ss(str);
    std::vector<std::string> split;
    while (std::getline(ss, line, del))
    {
        line = RPN::trim(line);
        split.push_back(line);
    }
    return split;
}

unsigned int RPN::getValue() { return (this->value); }

void RPN::processingRPN(const std::string &args) const
{
    std::cout << "Estamos aqui: " << args << std::endl;
    std::vector<std::string> vec = RPN::split(args, ' ');
    size_t i = -1;
    while (++i < vec.size())
    {
        std::cout << vec[i] << std::endl;
    }
}

