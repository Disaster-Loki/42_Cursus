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

void printDeque(const std::deque<int>& dq)
{
    for (std::deque<int>::const_iterator it = dq.begin(); it != dq.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void printRes(const std::string *res)
{
    int i = -1;
    std::cout << "Esteve aqui\n";
    std::cout << res[i + 2] << " ";
    while (!res[++i].empty())
    {
        std::cout << "Line" << std::endl;
        std::cout << res[i] << " ";
    }
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int av, char **args)
{
    (void)av;
    (void)args;
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
    std::string *split = new std::string[len + 1];
    while (std::getline(ss, line, del))
    {
        line = PmergeMe::trim(line);
        split[i++] = line;
    }
    split[i] = "";
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
    size_t i = 0;
    if (s.empty())
        return 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i >= s.size())
        return 0;
    while (i < s.size())
    {
        if (!isdigit(s[i]))
            return 0;
        i++;
    }
    std::istringstream iss(s);
    long val; iss >> val;
    if (iss.fail() || !iss.eof() || val < INT_MIN || val > INT_MAX || val < 1)
        return 0;
    return 1;
}

int PmergeMe::hasDuplicates(std::string *s)
{
    std::set<int> seen;
    for (int i = 0; !s[i].empty(); ++i)
    {
        int num = std::atoi(s[i].c_str());
        if (seen.count(num))
            return 1;
        seen.insert(num);
    }
    return 0;
}

void PmergeMe::valSingleArgument(char *arg)
{
    size_t	i = 0;
	std::string	*split;
    std::string str = arg;
	if (*arg == '\0')
		throw std::invalid_argument("Error");
	if (valSpace(arg))
        throw std::invalid_argument("Error");
	split = PmergeMe::split(str.c_str(), ' ');
	while (!split[i].empty())
	{
		if (!PmergeMe::isValInteger(split[i]))
        {
            delete[] split;
            throw std::invalid_argument("Error");
        }
        i++;
	}
	if (PmergeMe::hasDuplicates(split))
    {
        delete[] split;
        throw std::invalid_argument("Error");
    }
	delete[] split;
}

int PmergeMe::countLine(char **args)
{
    int i = 0;

    while (args[++i]);
    return (i);
}

std::string *PmergeMe::transformInput(char **args)
{
    int i = 0;
    int len = PmergeMe::countLine(args);
    std::cout << "Len: " << len << std::endl;
    std::string *res = new std::string[len + 1];
    while (args[i])
    {
        std::string line = args[i];
        res[i] = line.c_str();
        i++;
    }
    res[i] = "";
    return (res);
}

void PmergeMe::valMultipleArguments(char **args)
{
    size_t i = 0;
    while (args[++i])
	{
        std::string line = args[i];
		if (!PmergeMe::isValInteger(line.c_str()))
            throw std::invalid_argument("Error");
	}
    std::string *res = PmergeMe::transformInput(args);
	if (PmergeMe::hasDuplicates(res))
    {
        std::cout << "Here\n";
        delete[] res;
        throw std::invalid_argument("Error");
    }
	delete[] res;
}

void PmergeMe::errorHandler(int av, char **args)
{
    if (av == 2)
        PmergeMe::valSingleArgument(args[1]);
    else
        PmergeMe::valMultipleArguments(args);
}

std::deque<int> PmergeMe::formDeque(std::string *input)
{
    size_t i = 0;
    std::deque<int> dq;
    while (!input[i].empty())
    {
        int n = std::atoi(input[i].c_str());
        std::cout << "N: " << n << std::endl;
        dq.push_back(n);
    }
    return (dq);
}

char **PmergeMe::dup(char **args)
{
    int len = PmergeMe::countLine(args);
    char **dup = new char*[len + 1];

    int i = 0;
    int j = 1;
    while (args[j])
        dup[i++] = args[j++];
    dup[i] = NULL;
    return dup;
}

void PmergeMe::masterProgram(int av, char **args)
{
    PmergeMe::errorHandler(av, args);
    this->args = PmergeMe::dup(args);

    std::cout << "Called transform" << std::endl;
    std::string *res = PmergeMe::transformInput(args);
    //printRes(res);
    //std::cout << "Inputs" << std::endl;
    //this->deque = PmergeMe::formDeque(res);
    //printDeque(this->deque);
    delete[] res;
}
