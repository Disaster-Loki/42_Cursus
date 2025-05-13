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

void printList(const std::list<int>& dq)
{
    for (std::list<int>::const_iterator it = dq.begin(); it != dq.end(); ++it)
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
        this->list = copy.list;
    }
    return (*this);
}

void PmergeMe::swap(int& a, int& b)
{
    int tmp = a;
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

std::list<int> PmergeMe::formList(std::string *input)
{
    size_t i = 0;
    std::list<int> list;
    while (!input[i].empty())
    {
        int n = std::atoi(input[i].c_str());
        list.push_back(n);
        i++;
    }
    return (list);
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

bool PmergeMe::isSorted(const std::list<int>& vec)
{
    if (vec.size() < 2)
        return true;

    std::list<int>::const_iterator it = vec.begin();
    std::list<int>::const_iterator next = it;
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

bool PmergeMe::isSorted2(const std::deque<int>& vec)
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

std::list<int> PmergeMe::dividy_by_range(const std::list<int> vec, int start, int end)
{
    std::list<int> result;
    if (start < 0 || end <= start || start >= static_cast<int>(vec.size()))
        return result;

    int i = 0;
    std::list<int>::const_iterator it = vec.begin();
    while (it != vec.end() && i < end)
    {
        if (i >= start)
            result.push_back(*it);
        ++it;
        ++i;
    }
    return result;
}

std::deque<int> PmergeMe::dividy_by_range2(std::deque<int> vec, int start, int end)
{
    int i = start;
    std::deque<int> array;
    while (i < end)
        array.push_back(vec[i++]);
    return (array);
}

void PmergeMe::merge(std::list<int>& array, std::list<int>& left, std::list<int>& right)
{
    array.clear();
    std::list<int>::iterator it_left = left.begin();
    std::list<int>::iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end())
    {
        if (*it_left < *it_right)
        {
            array.push_back(*it_left);
            ++it_left;
        }
        else
        {
            array.push_back(*it_right);
            ++it_right;
        }
    }
    while (it_left != left.end())
    {
        array.push_back(*it_left);
        ++it_left;
    }
    while (it_right != right.end())
    {
        array.push_back(*it_right);
        ++it_right;
    }
}

void PmergeMe::merge2(std::deque<int> & array, std::deque<int> & left, std::deque<int> & right)
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

void PmergeMe::mergeSort(std::list<int> & vec)
{
   if (vec.size() > 1)
   {
        if (isSorted(vec))
            return ;
        int mid = (vec.size() / 2);
        std::list<int> left = dividy_by_range(vec, 0, mid);
        std::list<int> right = dividy_by_range(vec, mid, vec.size());
        mergeSort(left);
        mergeSort(right);
        merge(vec, left, right);
   }
}

void PmergeMe::mergeSort2(std::deque<int> & vec)
{
   if (vec.size() > 1)
   {
        if (isSorted2(vec))
            return ;
        int mid = (vec.size() / 2);
        std::deque<int> left = dividy_by_range2(vec, 0, mid);
        std::deque<int> right = dividy_by_range2(vec, mid, vec.size());
        mergeSort2(left);
        mergeSort2(right);
        merge2(vec, left, right);
   }
}

void PmergeMe::binaryTree(std::list<int> vec, int start, int end, std::list<int>& order)
{
    if (start > end)
        return;

    int mid = (start + end) / 2;
    std::list<int>::iterator it = vec.begin();
    std::advance(it, mid);

    order.push_back(*it);

    binaryTree(vec, start, mid - 1, order);
    binaryTree(vec, mid + 1, end, order);
}

void PmergeMe::binaryTree2(std::deque<int> vec, int start, int end, std::deque<int> & order)
{
    if (start > end) return ;

    int mid = (start + end) / 2;
    order.push_back(vec[mid]);

    binaryTree2(vec, start, mid - 1, order);
    binaryTree2(vec, mid + 1, end, order);
}

std::list<int> PmergeMe::order(std::list<int> & vec)
{
    std::list<int> order;
    int start = 0;
    int end = vec.size() - 1;
    binaryTree(vec, start, end, order);
    return (order);
}

std::deque<int> PmergeMe::order2(std::deque<int> & vec)
{
    std::deque<int> order;
    int start = 0;
    int end = vec.size() - 1;
    binaryTree2(vec, start, end, order);
    return (order);
}

int PmergeMe::binarySearchIndex(std::list<int>& lst, int key)
{
    int left = 0;
    int right = lst.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        std::list<int>::const_iterator it = lst.begin();
        std::advance(it, mid);

        if (*it < key)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}


int PmergeMe::binarySearchIndex2(std::deque<int>& dq, int key)
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

void PmergeMe::insertionContainer(std::list<int>& M, std::list<int>& m)
{
    mergeSort(m);
    m = order(m);

    for (std::list<int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        int index = binarySearchIndex(M, *it);
        std::list<int>::iterator insertPos = M.begin();
        std::advance(insertPos, index);
        M.insert(insertPos, *it);
    }
    this->list = M;
}


void PmergeMe::insertionContainer2(std::deque<int> & M, std::deque<int> & m)
{
    size_t i = -1;

    mergeSort2(m);
    m = order2(m);
    while (++i < m.size())
    {
        int index = binarySearchIndex2(M, m[i]);
        M.insert(M.begin() + index, m[i]);
    }
    this->deque = M;
}

void PmergeMe::mergeInsertionSort2(std::deque<int> & vec)
{
    if (vec.size() <= 1)
        return ;
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
    PmergeMe::mergeSort2(M);
    insertionContainer2(M, m);
    if (aux)
    {
        int index = binarySearchIndex2(this->deque, aux);
        this->deque.insert(deque.begin() + index, aux);
    }
}

void PmergeMe::mergeInsertionSort(std::list<int> & vec)
{
    if (vec.size() <= 1)
        return ;
    size_t aux;
    std::list<int> M;
    std::list<int> m;
    size_t len = vec.size() / 2;
    std::pair<int, int> p[len];
    size_t i = -1;
    if (vec.size() % 2 == 1)
        aux = vec.back();
    std::list<int>::const_iterator it = vec.begin();
    std::list<int>::const_iterator next = it;
    next++;
    while (++i < len)
    {
        p[i] = PmergeMe::formPares(*it, *next);
        if (p[i].first > p[i].second)
            swap(p[i].first, p[i].second);
        m.push_back(p[i].first);
        M.push_back(p[i].second);
        ++it; ++it;
        ++next; ++next;
    }
    PmergeMe::mergeSort(M);
    insertionContainer(M, m);
    if (aux)
    {
        int index = binarySearchIndex(this->list, aux);
        std::list<int>::iterator it = this->list.begin();
        std::advance(it, index);
        this->list.insert(it, aux);
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
    this->list = PmergeMe::formList(res);
    std::cout << "Before: "; printList(this->list);
    mergeInsertionSort(this->list);
    std::cout << "After: "; printList(this->list);
    endTime = currentTime() - startTime;
    std::cout << "Time to process a range of " << this->list.size()
                << " elements with std::list : " << std::fixed << std::setprecision(5)
                    << endTime << " us" << std::endl;
    startTime = currentTime();
    this->deque = PmergeMe::formDeque(res);
    mergeInsertionSort2(this->deque);
    delete[] res;
    endTime = currentTime() - startTime;
    std::cout << "Time to process a range of " << this->deque.size()
                << " elements with std::deque : " << std::fixed << std::setprecision(5)
                    << endTime << " us" << std::endl;
}
