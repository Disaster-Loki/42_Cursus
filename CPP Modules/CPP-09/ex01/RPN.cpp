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

#include "RPN.hpp"

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
    std::stringstream ss(RPN::trim(str));
    std::vector<std::string> split;
    while (std::getline(ss, line, del))
    {
        line = RPN::trim(line);
        split.push_back(line);
    }
    return split;
}

int RPN::getValue() const { return (this->value); }

int RPN::is_operators(char c) const
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::processingRPN(const std::string &args)
{
    if (args.empty())
        throw std::runtime_error("Error: Empty argument");

    int i = 0;
    std::stack<int> stack;
    while (i < static_cast<int>(args.size()))
    {
        if (args[i] != ' ' && !is_operators(args[i]) && !isdigit(args[i]) && (args[i] != '-'))
        {
            throw std::invalid_argument("Error");
        }
        i++;
    }

    std::vector<std::string> vec = split(args, ' ');
    int len = static_cast<int>(vec.size());

    if (len < 3)
        throw std::runtime_error("Error: Incomplete parameters on the string");

    i = 0;
    while (i < len) {
        if (is_operators(vec[i][0]))
        {
            if (stack.size() < 2)
            {
                throw std::runtime_error("Error: Not enough operands for operation");
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            if (vec[i] == "+") stack.push(a + b);
            else if (vec[i] == "-") stack.push(a - b);
            else if (vec[i] == "*") stack.push(a * b);
            else if (vec[i] == "/")
            {
                if (b == 0)
                    throw std::runtime_error("Error: Division by zero");
                stack.push(a / b);
            }
        }
        else
        {
            int n;
            try
            {
                std::stringstream(vec[i]) >> n;
            } catch (...)
            {
                throw std::runtime_error("Error: Invalid number format");
            }
            stack.push(n);
        }
        i++;
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error: Invalid RPN expression");

    this->value = stack.top();
}

std::ostream &operator<<(std::ostream &out, const RPN &rpn)
{
    out << rpn.getValue();
    return (out);
}


