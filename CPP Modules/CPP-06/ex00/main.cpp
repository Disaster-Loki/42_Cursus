/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:41:12 by sde-carv          #+#    #+#             */
/*   Updated: 2025/04/15 11:41:38 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int av, char **args)
{
    if (av != 2)
    {
        std::cout << "convert [string]" << std::endl;
        return (1);
    }
    ScalarConverter sc;
    sc.convert(args[1]);
    return (0);
}
