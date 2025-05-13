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

        int valSpace(char *s);
        double currentTime(void);
        void swap(int& a, int& b);
        int countLine(char **args);
        int isValInteger(std::string s);
        int hasDuplicates(std::string *s);
        void valSingleArgument(char *args);
        void valMultipleArguments(char **args);
        void errorHandler(int av, char **args);
        void masterProgram(int av, char **args);
        std::string *transformInput(char **args);
        std::pair<int, int> formPares(int x, int y);
        std::deque<int> formDeque(std::string *input);
        std::list<int> formList(std::string *input);
        void mergeInsertionSort(std::list<int> & vec);
        void mergeInsertionSort2(std::deque<int> & vec);
        bool isSorted2(const std::deque<int>& vec);
        bool isSorted(const std::list<int>& vec);
        std::deque<int> dividy_by_range2(std::deque<int> vec, int start, int end);
        std::list<int> dividy_by_range(std::list<int> vec, int start, int end);
        void merge2(std::deque<int> & array, std::deque<int> & left, std::deque<int> & right);
        void merge(std::list<int> & array, std::list<int> & left, std::list<int> & right);
        void insertionContainer2(std::deque<int> & M, std::deque<int> & m);
        void insertionContainer(std::list<int> & M, std::list<int> & m);
        void binaryTree2(std::deque<int> vec, int start, int end, std::deque<int> & order);
        void binaryTree(std::list<int> vec, int start, int end, std::list<int> & order);
        int binarySearchIndex2(std::deque<int>& dq, int key);
        int binarySearchIndex(std::list<int>& lst, int key);
        std::deque<int> order2(std::deque<int> & vec);
        std::list<int> order(std::list<int> & vec);



        void mergeSort2(std::deque<int> & vec);
        void mergeSort(std::list<int> & vec);

        
        

};

#endif