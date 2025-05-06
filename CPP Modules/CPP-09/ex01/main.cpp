/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:24:07 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/30 16:24:08 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int av, char **args)
{
    if (av != 2)
    {
        std::cout << "Error: Poorly formatted arguments" << std::endl;
        return (1);
    }
    try
    {
        RPN rpn;
        std::string arg = args[1];
        rpn.processingRPN(arg);
        std::cout << "Result: " << rpn.getValue() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);   
}