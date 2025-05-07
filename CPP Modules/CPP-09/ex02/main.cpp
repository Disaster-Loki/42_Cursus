/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:25:31 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/30 16:25:34 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int number_alguments(char **args)
{
    int i = 0;
    while (args[i]) i++;
    return (i);
}

void    error_handler(int av, char **args)
{
    if (av < 2)
        throw std::runtime_error("Error: Missing parameters");
    int i = 0;
    int num = number_alguments(args);
    while (++i < num)
    {
        int j = 0;
        
    }
}

int main(int av, char **args)
{
    try
    {
        error_handler(av, args);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return (0);
}
