/***************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/26 11:52:18 by sde-carv          #+#    #+#              #
#    Updated: 2024/12/26 20:40:02 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int main(int av, char **args)
{
    if (av == 1)
        return ((std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n"), 1);
    while (*(++args))
    {
        while (**args)
            std::cout << (char)std::toupper(*((*args)++));
    }
    std::cout << std::endl;
    return (0);
}