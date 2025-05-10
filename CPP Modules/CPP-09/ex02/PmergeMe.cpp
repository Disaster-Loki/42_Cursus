/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:25:58 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/30 16:26:01 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **numbers)
{
    (void)numbers;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    if (this != &copy)
    {
        this->deque = copy.deque;
        //this->forward_list = copy.forward_list;
    }
    return (*this);
}

std::string PmergeMe::trim(const std::string& str) const{
    size_t start = 0;
    size_t end = str.size() - 1;

    while (start < str.size() && std::isspace(str[start]))
        start++;
    while (end > start && std::isspace(str[end]))
        end--;
    return (str.substr(start, end - start + 1));
}

size_t tokens(const std::string str, char del)
{
        size_t  len = -1;
        len = std::count(str.begin(), str.end(), del);
        return (str.size() - len);
}

std::string *PmergeMe::split(const std::string str, char del) const
{
    int i = 0;
    std::string line;
    int len = tokens(str, del);
    std::stringstream ss(PmergeMe::trim(str));
    std::string *split = new std::string[len];
    while (std::getline(ss, line, del))
    {
        line = PmergeMe::trim(line);
        split[i++] = line;
    }
    return (split);
}

int PmergeMe::valSpace(char *s)
{
    while (*s && *s == ' ')
        s++;
    if (*s == '\0')
        return (1);
    return (0);
}

int PmergeMe::isValInteger(std::string s)
{
    int i = 0;
    long num = 0;
    int sign = 1;

    if (s.empty())
        return 0;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign = -1;
        i++;
    }
    if (i >= (int)s.size())
        return 0;
    while (i < (int)s.size())
    {
        if (!isdigit(s[i]))
            return 0;
        num = num * 10 + (s[i] - '0');
        if ((sign == 1 && num > INT_MAX) || (sign == -1 && -num < INT_MIN))
            return 0;
        i++;
    }
    return 1;
}

int PmergeMe::hasDuplicates(std::string *s)
{
    int	i;
	int	j;

	i = -1;
	while (s[++i].empty())
	{
		j = i + 1;
		while (s[j].empty())
		{
			if (std::atoi(s[i].c_str()) == std::atoi(s[j].c_str()))
				return (1);
			j++;
		}
	}
	return (0);
}

void PmergeMe::valSingleArgument(char *arg)
{
    int		i = -1;
	std::string	*split;
    std::string str = arg;

	if (*arg == '\0')
		throw std::invalid_argument("Error");
	if (valSpace(arg))
        throw std::invalid_argument("Error");
	split = PmergeMe::split(str.c_str(), ' ');
	while (split[++i].empty())
	{
		if (!PmergeMe::isValInteger(split[i]))
            throw std::invalid_argument("Error");
	}
	if (PmergeMe::hasDuplicates(split))
        throw std::invalid_argument("Error");
	delete[] split;
}

void PmergeMe::errorHandler(int av, char **args)
{
    if (av == 2)
        PmergeMe::valSingleArgument(args[1]);
    //else
    //    PmergeMe::valMultipleArguments(args);
}

void PmergeMe::masterProgram(int av, char **args)
{
    PmergeMe::errorHandler(av, args);
}
