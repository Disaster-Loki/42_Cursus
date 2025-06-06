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

int main(int av, char **args)
{
    if (av < 2)
    {
        std::cout << "Error" << std::endl;
        return (1);
    }
    try
    {
        PmergeMe pmergeMe(av, args);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
