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
        std::cout << "Error: Missing arguments" << std::endl;
        return (1);
    }
    RPN rpn;
    std::string arg = args[1];
    rpn.processingRPN(arg);
    return (0);   
}