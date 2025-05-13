/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:25:51 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/30 16:25:53 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <cctype>
#include <deque>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <climits>
#include <set>
#include <list>
#include <utility>
#include <ctime>
#include <sys/time.h>
#include <iomanip>

class PmergeMe
{
    private:
        std::deque<int> deque;
        std::list<int> list;
    public:
        PmergeMe();
        PmergeMe(int av, char **args);
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);
        std::string trim(const std::string& str) const;
        std::string *split(const std::string str, char del) const;
        void masterProgram(int av, char **args);
        void errorHandler(int av, char **args);
        void valSingleArgument(char *args);
        void valMultipleArguments(char **args);
        int valSpace(char *s);
        int isValInteger(std::string s);
        int hasDuplicates(std::string *s);
        int countLine(char **args);
        std::string *transformInput(char **args);
        std::deque<int> formDeque(std::string *input);
        void mergeInsertionSort(std::deque<int> & vec);
        std::pair<int, int> formPares(int x, int y);
        void mergeSort(std::deque<int> & vec);
        template <typename T>
        void swap(T& a, T& b);
        double currentTime(void);
        void insertionContainer(std::deque<int> & M, std::deque<int> & m);
};

#endif