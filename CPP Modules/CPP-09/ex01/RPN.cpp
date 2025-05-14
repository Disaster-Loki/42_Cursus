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

size_t RPN::tokens(const std::string str, char del) const
{
        size_t  len = -1;
        len = std::count(str.begin(), str.end(), del);
        return (str.size() - len);
}

std::string *RPN::split(const std::string str, char del, size_t& size) const
{
    int i = 0;
    std::string line;
    size_t len = tokens(str, del);
    std::stringstream ss(RPN::trim(str));
    std::string *split = new std::string[len + 1];
    while (std::getline(ss, line, del))
    {
        line = RPN::trim(line);
        split[i++] = line;
    }
    split[i] = "";
    size = i;
    return (split);
}

int RPN::getValue() const { return (this->value); }

int RPN::is_operators(std::string c) const
{
    return (c == "+" || c == "-" || c == "*" || c == "/");
}

bool RPN::is_valid_number(const std::string& s)
{
    if (s.empty()) return false;

    size_t i = 0;
    if (s[0] == '-' || s[0] == '+') i++;
    if (i == s.size()) return false;
    for (; i < s.size(); ++i)
    {
        if (!isdigit(s[i])) return false;
    }
    return true;
}

void RPN::processingRPN(const std::string &args)
{
    if (args.empty())
        throw std::runtime_error("Error: Empty argument");

    size_t i = 0;
    std::stack<int> stack;

    while (i < args.size())
    {
        std::string str(1, args[i]);
        if (str != " " && !is_operators(str)
                && !isdigit(args[i]) && !is_valid_number(str))
            throw std::invalid_argument("Error");
        i++;
    }
    size_t len = 0;
    std::string *spt = RPN::split(args, ' ', len);

    if (len < 3)
    {
        delete[] spt;
        throw std::runtime_error("Error: Incomplete parameters on the string");
    }
    i = 0;
    while (i < len)
    {
        if (is_operators(spt[i]))
        {
            if (stack.size() < 2)
            {
                delete[] spt;
                throw std::runtime_error("Error: Not enough operands for operation");
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            if (spt[i] == "+") stack.push(a + b);
            else if (spt[i] == "-") stack.push(a - b);
            else if (spt[i] == "*") stack.push(a * b);
            else if (spt[i] == "/")
            {
                if (b == 0)
                {
                    delete[] spt;
                    throw std::runtime_error("Error: Division by zero");
                }
                stack.push(a / b);
            }
        }
        else
        {
            if (!is_valid_number(spt[i]))
            {
                delete[] spt;
                throw std::runtime_error("Error: Invalid number format");
            }

            int n;
            std::stringstream ss(spt[i]);
            ss >> n;
            stack.push(n);
        }
        i++;
    }
    if (stack.size() != 1)
    {
        delete[] spt;
        throw std::runtime_error("Error: Invalid RPN expression");
    }
    delete[] spt;
    this->value = stack.top();
}


std::ostream &operator<<(std::ostream &out, const RPN &rpn)
{
    out << rpn.getValue();
    return (out);
}


