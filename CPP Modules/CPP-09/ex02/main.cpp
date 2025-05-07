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
    int i = -1;
    ++args;
    while (args[++i]);
    return (i);
}

int ft_strlen(char *str)
{
    int i = -1;
    while (str[++i]);
    return (i);
}

bool is_valid_number(char **args)
{
    int i = -1;

    ++args;
    while (args[++i])
    {
        int k = 0;
        if (args[i][0] == '-' || args[i][0] == '+')
            k++;
        if (i == ft_strlen(args[i]))
            return (false);
        std::string str = args[i];
        for (; k < ft_strlen(args[i]); ++k)
            if (!isdigit(args[i][k]))
                return false;
    }
    return (true);
}

void    error_handler(int av, char **args)
{
    if (av < 2)
        throw std::runtime_error("Error: Missing parameters");
    int num = number_alguments(args);
    std::cout << num << std::endl;
    std::cout << is_valid_number(args) << std::endl;
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
