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
    while (!res[++i].empty())
    {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
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
    while (args[i])
	{
        std::string line = args[i];
		if (!PmergeMe::isValInteger(line.c_str()))
            throw std::invalid_argument("Error");
        i++;
	}
    std::string *res = PmergeMe::transformInput(args);
	if (PmergeMe::hasDuplicates(res))
    {
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
        dq.push_back(n);
        i++;
    }
    return (dq);
}

std::pair<int, int> PmergeMe::formPares(int x, int y)
{
    std::pair<int, int> p;
    p.first = x;
    p.second = y;
    return (p);
}

void printPares(std::pair<int, int> p[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << "Pairs: "
                  << p[i].first << ", "
                  << p[i].second << std::endl;
    }
}

bool is_sorted(const std::deque<int>& vec)
{
    if (vec.size() < 2)
        return true;

    std::deque<int>::const_iterator it = vec.begin();
    std::deque<int>::const_iterator next = it;
    ++next;

    while (next != vec.end())
    {
        if (*it > *next)
            return false;
        ++it;
        ++next;
    }
    return true;
}

std::deque<int> dividy_by_range(std::deque<int> vec, int start, int end)
{
    int i = start;
    std::deque<int> array;
    while (i < end)
        array.push_back(vec[i++]);
    return (array);
}

void merge(std::deque<int> & array, std::deque<int> & left, std::deque<int> & right)
{
    size_t i, j, k; i = j = k = 0;

    while (j < left.size() && k < right.size())
    {
        if (left[j] < right[k])
            array[i++] = left[j++];
        else if (left[j] > right[k])
            array[i++] = right[k++];
    }

    while (j < left.size())
        array[i++] = left[j++];

    while (k < right.size())
        array[i++] = right[k++];
}

void PmergeMe::mergeSort(std::deque<int> & vec)
{
   if (vec.size() > 1)
   {
        if (is_sorted(vec))
            return ;
        int mid = (vec.size() / 2);
        std::deque<int> left = dividy_by_range(vec, 0, mid);
        std::deque<int> right = dividy_by_range(vec, mid, vec.size());
        mergeSort(left);
        mergeSort(right);

        merge(vec, left, right);
   }
}

void binaryTree(std::deque<int> vec, int start, int end, std::deque<int> & order)
{
    if (start > end) return ;

    int mid = (start + end) / 2;
    order.push_back(vec[mid]);

    binaryTree(vec, start, mid - 1, order);
    binaryTree(vec, mid + 1, end, order);
}

std::deque<int> order(std::deque<int> & vec)
{
    std::deque<int> order;
    int start = 0;
    int end = vec.size() - 1;
    binaryTree(vec, start, end, order);
    return (order);
}

int binarySearchIndex(std::deque<int>& dq, int key)
{
    int left = 0;
    int right = dq.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (dq[mid] < key)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void PmergeMe::insertionContainer(std::deque<int> & M, std::deque<int> & m)
{
    size_t i = -1;
    std::deque<int> list;

    while (++i < M.size())
        list.push_back(M[i]);
    std::cout << "List - M" << std::endl;
    printDeque(list);
    i = -1;
    mergeSort(m);
    m = order(m);
    std::cout << "Order" << std::endl;
    printDeque(m); std::cout << std::endl;
    while (++i < m.size())
    {
        std::cout << "Buscando o index" << std::endl;
        int index = binarySearchIndex(list, m[i]);
        std::cout << "Index["<< index << "]: " << m[i] << std::endl; 
        list.insert(list.begin() + index, m[i]);
        std::cout << "List:";
        printDeque(list); std::cout << std::endl;
    }
    std::cout << "Ford-John Order" << std::endl;
    printDeque(list); std::cout << std::endl;
}


void PmergeMe::mergeInsertionSort(std::deque<int> & vec)
{
    if (vec.size() > 1)
    {
        int len = vec.size() / 2;
        std::pair<int, int> p[len];
        int i = -1, j = 0;
        std::cout << "Fase 1 - Formar Pares" << std::endl;
        if (vec.size() % 2 == 0)
        {
            while (++i < len)
            {
                p[i] = PmergeMe::formPares(vec[j], vec[j + 1]);
                j += 2;
            }
        }
        printPares(p, len);
        std::cout << "Fase 2 - Ordenar os pares e separar os numeros > e <" << std::endl;
        i = -1;
        while (++i < len)
        {
            if (p[i].first > p[i].second)
            {
                int tmp = p[i].first;
                p[i].first = p[i].second;
                p[i].second = tmp;
            }
        }
        std::cout << "Ordenado" << std::endl;
        printPares(p, len);
        std::cout << "Len: " << len << std::endl;
        std::deque<int> M;
        std::deque<int> m;
        i = -1;
        while (++i < len)
        {
            m.push_back(p[i].first);
            M.push_back(p[i].second);
        }
        std::cout << "m: "; printDeque(m);
        std::cout << "M: "; printDeque(M);
        std::cout << "Fase 3 - Ordenar o vector M" << std::endl;
        PmergeMe::mergeSort(M);
        std::cout << "M: "; printDeque(M); std::cout << std::endl;
        std::cout << "Fase 4 - Inserir m em M um por um" << std::endl;
        insertionContainer(M, m);
    }
}

void PmergeMe::masterProgram(int av, char **args)
{
    if (av > 2)
        args = &args[1];
    PmergeMe::errorHandler(av, args);
    std::string *res = PmergeMe::transformInput(args);
    printRes(res);
    std::cout << "Inputs" << std::endl;
    this->deque = PmergeMe::formDeque(res);
    mergeInsertionSort(this->deque);
    //printDeque(this->deque);
    delete[] res;
}
