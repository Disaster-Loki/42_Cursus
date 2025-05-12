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

class PmergeMe
{
    private:
        char **args;
        std::deque<int> deque;
        //forward_list<int> forward_list;
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
        char **dup(char **args);
        std::string *transformInput(char **args);
        std::deque<int> formDeque(std::string *input);
};

#endif