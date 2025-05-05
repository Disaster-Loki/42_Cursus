/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:24:24 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/30 16:24:26 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <vector>
#include <sstream>

class RPN
{
    private:
        unsigned int value;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &copy);
        RPN(const std::string &args);
        RPN &operator=(const RPN &copy);
        int tokens(const std::string str, char del) const;
        std::vector<std::string> split(const std::string str, char del) const;
        void processingRPN(const std::string &args) const;
        unsigned int getValue();
        std::string trim(const std::string& str) const;
};

std::ofstream &operator<<(std::ofstream &out, const RPN &rpn);

#endif

