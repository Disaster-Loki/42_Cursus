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
    masterProgram(av, args);
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

template <typename T>
void PmergeMe::swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
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
    int i = -1;
    int len = PmergeMe::countLine(args);
    std::string *res = new std::string[len + 1];
    while (args[++i])
    {
        std::string line = args[i];
        res[i] = line.c_str();
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

    mergeSort(m);
    m = order(m);
    while (++i < m.size())
    {
        int index = binarySearchIndex(M, m[i]);
        M.insert(M.begin() + index, m[i]);
    }
    this->deque = M;
}

void PmergeMe::mergeInsertionSort(std::deque<int> & vec)
{
    if (vec.size() > 1)
    {
        size_t aux;
        std::deque<int> M;
        std::deque<int> m;
        size_t len = vec.size() / 2;
        std::pair<int, int> p[len];
        size_t i = -1, j = 0;
        if (vec.size() % 2 == 1)
            aux = vec.back();
        while (++i < len)
        {
            p[i] = PmergeMe::formPares(vec[j], vec[j + 1]);
            if (p[i].first > p[i].second)
                swap(p[i].first, p[i].second);
            m.push_back(p[i].first);
            M.push_back(p[i].second);
            j += 2;
        }
        PmergeMe::mergeSort(M);
        insertionContainer(M, m);
        if (aux)
        {
            int index = binarySearchIndex(this->deque, aux);
            this->deque.insert(deque.begin() + index, aux);
        }
    }
}

double PmergeMe::currentTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}

void PmergeMe::masterProgram(int av, char **args)
{
    double startTime, endTime;
    PmergeMe::errorHandler(av, args);
    std::string *res = PmergeMe::transformInput(args);
    startTime = currentTime();
    this->deque = PmergeMe::formDeque(res);
    std::cout << "Before: "; printDeque(this->deque);
    mergeInsertionSort(this->deque);
    std::cout << "After: "; printDeque(this->deque);
    delete[] res;
    endTime = currentTime() - startTime;
    std::cout << "Time to process a range of " << this->deque.size()
                << " elements with std::deque : " << std::fixed << std::setprecision(5)
                    << endTime << " us" << std::endl;
}
